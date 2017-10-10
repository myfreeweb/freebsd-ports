# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD: head/lang/spidermonkey38/Makefile 449591 2017-09-10 20:55:38Z gerald $

PORTNAME=	spidermonkey
PORTVERSION=	52.4.0
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${PORTVERSION}esr/source
DISTNAME=	firefox-${PORTVERSION}esr.source
PKGNAMESUFFIX=	${SP_VER}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 52-esr

BUILD_DEPENDS=	autoconf-2.13:devel/autoconf213
LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libffi.so:devel/libffi \
		libicudata.so:devel/icu

HAS_CONFIGURE=	yes
USES=		compiler:c++14-lang gmake pathfix pkgconfig \
		python:2.7,build tar:xz
#USE_PERL5=	build
USE_LDCONFIG=	yes
SP_VER=		52

WRKSRC=		${WRKDIR}/firefox-${PORTVERSION}esr/js/src
PATCH_WRKSRC=	${WRKDIR}/firefox-${PORTVERSION}esr/

CONFIGURE_ARGS=	--with-pthreads \
		--target=${CONFIGURE_TARGET} \
		--with-intl-api \
		--with-system-zlib \
		--disable-gold \
		--with-system-icu \
		--with-system-nspr
#		--enable-system-ffi \

#CONFIGURE_ARGS+=\
#		--disable-optimize \
#		--enable-ctypes \
#		--enable-gcgenerational \
#		--enable-pie \

#  --enable-application      Application to build. Same as --enable-project.
#  --enable-project          Project to build [js]
#  --with-external-source-dir
#                            External directory containing additional build files
#  --enable-update-channel   Select application update channel [default]
#  --enable-artifact-builds  Download and use prebuilt binary artifacts.
#  --enable-artifact-build-symbols
#                            Download symbols when artifact builds are enabled.
#  --disable-compile-environment
#                            Disable compiler/library checks
#  --disable-tests           Do not build test libraries & programs
#  --enable-debug            Enable building with developer debug info (using the given compiler flags).
#  --with-android-ndk        location where the Android NDK can be found
#  --with-android-toolchain

OPTIONS_DEFINE=	DEBUG GCZEAL JEMALLOC METHODJIT OPTIMIZE READLINE \
		THREADSAFE TRACEJIT UTF8 DTRACE
OPTIONS_DEFAULT=METHODJIT OPTIMIZE READLINE THREADSAFE TRACEJIT
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug debug-symbols
DEBUG_CONFIGURE_DISABLE=debug

DTRACE_CONFIGURE_ENABLE=dtrace profiling
DTRACE_LIBS=	-lelf

GCZEAL_DESC=	Enable Zealous garbage collecting
GCZEAL_CONFIGURE_ENABLE=gczeal

JEMALLOC_DESC=	Use jemalloc as memory allocator
JEMALLOC_CONFIGURE_ENABLE=	jemalloc

#METHODJIT_DESC=	Enable method JIT support
#METHODJIT_CONFIGURE_ENABLE=	methodjit

OPTIMIZE_DESC=	Enable compiler optimizations
OPTIMIZE_CONFIGURE_ENABLE=	optimize

#READLINE_DESC=	Link js shell to system readline library
#READLINE_CONFIGURE_ENABLE=	readline

#THREADSAFE_DESC=Enable multiple thread support
#THREADSAFE_CONFIGURE_ENABLE=	threadsafe

#TRACEJIT_DESC=	Enable tracing JIT support
#TRACEJIT_CONFIGURE_ENABLE=	tracejit

UTF8_DESC=	Treat strings as UTF8 instead of ISO-8859-1
UTF8_CFLAGS=	-DJS_C_STRINGS_ARE_UTF8

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.endif

post-patch:
# Skip some tests because bundled icu differs from system
	@${RM}  ${WRKSRC}/tests/test262/intl402/ch10/10.2/10.2.3_b.js \
		${WRKSRC}/tests/Intl/DateTimeFormat/format.js \
		${WRKSRC}/tests/ecma_6/String/normalize-generateddata-part1-not-listed.js

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	-d -s --no-progress ./js/src/shell/js
.if ${PORT_OPTIONS:MMETHODJIT} || ${PORT_OPTIONS:MTRACEJIT}
	@${ECHO_MSG} -n "===> Running jit_test.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} jit-test/jit_test.py \
	-d -s --no-progress --jitflags=,m,j,mj,mjp,am,amj,amjp,amd ./js/src/shell/js
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
.if ! ${PORT_OPTIONS:MDTRACE}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js${SP_VER}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*
.endif

.include <bsd.port.post.mk>
