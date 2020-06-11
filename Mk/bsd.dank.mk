# DankBSD lightweight hardening
# Mostly based on HardenedBSD, but doesn't use USES, OPTIONS etc.

_USE_HARDENING=

.if defined(PORTNAME)

.if ${PORTNAME:Mlib*} && ${PORTNAME:Mlibre*} == ""
_USE_HARDENING+=	lib
.endif
.if ${PORTNAME:M*kmod*}
_USE_HARDENING+=	kmod
.endif

# tries to reuse object files for static binary
.if ${PORTNAME} == "pkg"
PIE_UNSAFE=yes
.endif

# configure fails
.if ${PORTNAME} == "gcc"
PIE_UNSAFE=yes
.endif

# doesn't apply to '/usr/local/llvm10/bin/clang -c -o typegen.o  typegen.c'
.if ${PORTNAME} == "netpbm"
PIE_UNSAFE=yes
.endif

# relocation errors; does its own pie?
.if ${PORTNAME} == "intel-graphics-compiler"
PIE_UNSAFE=yes
.endif

# Werror about unused 'pie' flag - sticks ldflags into cflags?
.if ${PORTNAME} == "cmrtlib" || ${PORTNAME} == "opencolorio"
PIE_UNSAFE=yes
.endif

# seems to do its own, our thing breaks very early
.if ${PORTNAME} == "ocaml"
PIE_UNSAFE=yes
.endif

# idk even
.if ${PORTNAME} == "nvme-cli"
PIE_UNSAFE=yes
.endif

# tries to static link zlib, ends up with libz instead of libz_p
.if ${PORTNAME} == "mozjpeg"
PIE_UNSAFE=yes
.endif

# ??? sticks ldflags into cflags?
.if ${PORTNAME} == "ucpp"
LDFLAGS+=		-fPIC
.endif

# configure tests only uses ldflags for a compile+link simple command
# also builds some files without cxxflags????
.if ${PORTNAME} == "soundtouch"
PIE_UNSAFE=yes
.endif

# hmm
.if ${PORTNAME} == "universal-ctags"
LDFLAGS+=		-fPIC
.endif

.endif

.if defined(PKGNAMEPREFIX)
.if ${PKGNAMEPREFIX:Mlib}
_USE_HARDENING+=	lib
.endif
.endif

.if defined(PKGNAMESUFFIX)
.if ${PKGNAMESUFFIX:M-lib*}
_USE_HARDENING+=	lib
.endif
.if ${PKGNAMESUFFIX:M*-static}
_USE_HARDENING+=	static
.endif
.endif

.if defined(USES)
.if ${USES:Mkmod}
_USE_HARDENING+=	kmod
.endif
.if ${USES:Mfortran}
_USE_HARDENING+=	fortran
.endif
.endif

.if defined(CATEGORIES)
.if ${CATEGORIES:Mlinux}
_USE_HARDENING+=	linux
.endif
.endif

.if defined(NO_BUILD) || defined(NO_ARCH)
_USE_HARDENING+=	static
.endif

.if ${_USE_HARDENING:Mlib}
CFLAGS+=		-fPIC
CXXFLAGS+=		-fPIC
.endif

.if defined(PIE_UNSAFE) || ${_USE_HARDENING:Mlib} || ${_USE_HARDENING:Mkmod} || ${_USE_HARDENING:Mfortran} || ${_USE_HARDENING:Mlinux} || ${_USE_HARDENING:Mstatic}
# skip
.else
.if defined(PORTNAME) && ${PORTNAME:M*openjdk*}
CONFIGURE_ARGS+=	--with-extra-cflags="-fPIE -fPIC" \
			--with-extra-cxxflags="-fPIE -fPIC" \
			--with-extra-ldflags="-pie"
.else
CFLAGS+=		-fPIE -fPIC
CXXFLAGS+=		-fPIE -fPIC
LDFLAGS+=		-pie
CMAKE_ARGS+=	-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
# bizzare: /usr/local/share/cmake/Modules/CheckTypeSize.cmake (used in e.g. graphics/poppler)
# would pick up -pie but not -fPIC without the cmake-specific line !!! silly cmake
.endif
.endif

.if defined(RELRO_UNSAFE) || ${_USE_HARDENING:Mlib} || ${_USE_HARDENING:Mkmod} || ${_USE_HARDENING:Mfortran} || ${_USE_HARDENING:Mlinux} || ${_USE_HARDENING:Mstatic}
# skip
.else
LDFLAGS+=	-Wl,-z,relro -Wl,-z,now
.endif
