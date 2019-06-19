# $FreeBSD$

PORTNAME=	ldc
PORTVERSION=	1.15.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The LLVM-based D compiler

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	llvm60>0:devel/llvm60 \
		ninja:devel/ninja
RUN_DEPENDS=	llvm60>0:devel/llvm60
LIB_DEPENDS=	libconfig.so:devel/libconfig

BROKEN_armv6=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_armv7=		fails to compile: Error: undefined identifier _jmp_buf, did you mean alias jmp_buf?
BROKEN_i386=		function core.bitop.bsf (uint v) is not callable using argument types (ulong)
BROKEN_powerpc64=	fails to compile: cc1plus: error: unrecognized command line option "-std=c++11"

USES=		cmake:insource
USE_GITHUB=     yes
GH_ACCOUNT=     ldc-developers
GH_PROJECT=     ldc
GH_TUPLE=       ldc-developers:ldc:d442f9f:tree/ltsmaster \
		ldc-developers:druntime:13b1ccf:druntimelts/ltsmaster/runtime/druntime \
		ldc-developers:phobos:1d758b2:phoboslts/ltsmaster/runtime/phobos \
		ldc-developers:druntime:8a85f37:druntime/runtime/druntime \
		ldc-developers:phobos:981412b:phobos/runtime/phobos

CMAKE_ARGS+=	-DD_COMPILER:STRING="${WRKSRC}/ltsmaster/bin/ldmd2" \
		-DBUILD_SHARED_LIBS:STRING="BOTH"

CC=		clang60
CXX=		clang++60

BOOTVER=	0.17.6
LLVM_CONFIG=	llvm-config60
LDCVER=		${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "aarch64"
CFLAGS+=	-fPIC
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1200029
EXTRA_PATCHES=	${PATCHDIR}/fbsd12-*
.endif

post-patch:
	${REINPLACE_CMD} -e 's|$${llvm_config_names}|${LLVM_CONFIG}|g' \
		${WRKSRC}/ltsmaster/cmake/Modules/FindLLVM.cmake \
		${WRKSRC}/cmake/Modules/FindLLVM.cmake

pre-configure:
	@cd ${WRKSRC}/ltsmaster && \
	    ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} -GNinja .
	@cd ${WRKSRC}/ltsmaster && \
	    ${SETENV} ${MAKE_ENV} ninja

.include <bsd.port.post.mk>
