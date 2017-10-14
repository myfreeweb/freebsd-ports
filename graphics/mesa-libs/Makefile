# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mesa-libs
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	OpenGL libraries that support GLX and EGL clients

USE_XORG=	dri2proto dri3proto glproto presentproto x11 xcb xdamage xext \
		xfixes xshmfence xxf86vm

OPTIONS_DEFINE=	WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>
.include "${.CURDIR:H:H}/graphics/mesa-dri/Makefile.common"

CONFIGURE_ARGS+=	--with-dri-drivers="" --with-gallium-drivers=""

MESA_BUILD_WRKSRC=	src/mapi
MESA_INSTALL_WRKSRC=	src/mapi

.if ${PORT_OPTIONS:MWAYLAND}
MESA_BUILD_WRKSRC+=	src/util src/egl/wayland/wayland-drm src/egl/wayland/wayland-egl
MESA_INSTALL_WRKSRC+=	src/egl/wayland/wayland-egl
.endif

MESA_BUILD_WRKSRC+=	src/gbm src/glx
MESA_INSTALL_WRKSRC+=	src/gbm src/glx

.if "${MESA_LLVM_VER}" != ""
MESA_BUILD_WRKSRC+=	src/egl
MESA_INSTALL_WRKSRC+=	src/egl
.endif

.include "${MASTERDIR}/Makefile.targets"

post-install:
	@cd ${WRKSRC}/src && ${SETENV} DESTDIR=${STAGEDIR} \
		${MAKE_CMD} install-pkgconfigDATA install-glHEADERS install-glxHEADERS

.include <bsd.port.post.mk>
