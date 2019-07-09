# $FreeBSD$

PORTNAME=		ldc
PORTVERSION=		1.18.0
DISTVERSIONPREFIX=	v
CATEGORIES=		lang

# link to libexecinfo, use PIC by default
PATCH_SITES=	https://github.com/myfreeweb/ldc/commit/
PATCHFILES=	3df77e9bf1c8acee4b0bc0ce66766461a3318361.patch:-p1 \
	573cb1456b1074bb4ab604a838658f30beb6a797.patch:-p1

MAINTAINER=		acm@FreeBSD.org
COMMENT=		The LLVM-based D compiler
LICENSE=		BSD3CLAUSE
USES= 			ninja cmake:insource compiler:c++14-lang

OPTIONS_GROUP=		BOOTSTRAP
BOOTSTRAP_DESC=		Force using ltsmaster to bootstrap
OPTIONS_GROUP_BOOTSTRAP=LTSMASTER

LLVM_VERSION=	90
BUILD_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	llvm${LLVM_VERSION}>0:devel/llvm${LLVM_VERSION}

CC=			${LOCALBASE}/bin/clang${LLVM_VERSION}
CXX=			${LOCALBASE}/bin/clang++${LLVM_VERSION}
LLVM_CONFIG=		${LOCALBASE}/bin/llvm-config${LLVM_VERSION}
LDCVER=			${PORTVERSION}

PLIST_SUB=		LOCALBASE=${LOCALBASE} SOVERSION=88

BROKEN_armv6=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_i386=		function core.bitop.bsf (uint v) is not callable using argument types (ulong)

USE_GITHUB=		yes
GH_ACCOUNT=		ldc-developers
GH_PROJECT=		ldc
GH_TUPLE=		ldc-developers:druntime:ad2324e:druntime/runtime/druntime \
			ldc-developers:phobos:b60fda9:phobos/runtime/phobos

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "aarch64"
CFLAGS+=		-fPIC
.endif

# Search for a usable bootstrap compiler or fall back to building ltsmaster
DRUNTIME_MINVER=	20680

DCOMPILERS=		ldmd2 gdmd dmd

.if empty(PORT_OPTIONS:MLTSMASTER)
.for DC_TRY in ${DCOMPILERS}
.if !defined(DC_HOST)
VERSION!=		`which ${DC_TRY}` --version | ${SED} -n 's!^.*DMD.*v\([0-9]\).\([0-9][0-9][0-9]\).\([0-9]\).*!\1\2\3!p'
.if ${VERSION} > ${DRUNTIME_MINVER}
DC_HOST!=		which ${DC_TRY}
BUILD_BOOTSTRAP=	no
.endif
.endif
.endfor
.endif

# falling back to creating bootstrap d-compiler
.if !defined (DC_HOST)
BUILD_BOOTSTRAP=        yes
BOOTSTRAP_DIR=		${WRKDIRPREFIX}${.CURDIR}/work-bootstrap
DC_HOST=		${BOOTSTRAP_DIR}/ltsmaster/bin/ldmd2
BUILD_BOOTSTRAP=	yes
.endif

CMAKE_ARGS+=		-DLDC_INSTALL_PREFIX="${PREFIX}" \
			-DD_COMPILER:STRING="${DC_HOST}" \
			-DCMAKE_C_COMPILER:STRING="${CC}" \
			-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
			-DLLVM_CONFIG:PATH=${LLVM_CONFIG} \
			-DBUILD_SHARED_LIBS:STRING="BOTH"

pre-build:
	@echo "DEBUG: bootstrap:${BUILD_BOOTSTRAP} dmd:${DC_HOST} ver:${VERSION} options:${PORT_OPTIONS}"

.if ${BUILD_BOOTSTRAP} == "yes"
pre-configure:
	@echo "Building Bootstrap d-compiler..."
	${MAKE} -f Makefile.bootstrap FLAVOR=bootstrap
.else
	@echo "Reusing pre-existing d-compiler..."
.endif

.include <bsd.port.post.mk>
