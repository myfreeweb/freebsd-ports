# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
RUN_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		meson localbase pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	intel

LDFLAGS+=	-lpthread
# prevent types conflict: videodev2.h vs. drm.h
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES

OPTIONS_DEFINE?=	DEBUG X11 WAYLAND
OPTIONS_DEFAULT=X11 WAYLAND
WAYLAND_DESC=	Support Wayland protocol
OPTIONS_SUB=	yes

X11_MESON_YES=	with_x11
X11_USE=	xorg=xorgproto,pciaccess,x11,xext,xfixes

WAYLAND_MESON_YES=	with_wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland

.include <bsd.port.options.mk>

.if defined(LIBVA_SLAVE) && ${LIBVA_SLAVE} == "glx"
USES+=	gl
LIB_DEPENDS+=	libva-x11.so:multimedia/libva
MESON_ARGS+=	-Dwith_wayland=no \
		-Dwith_x11=yes
.else
MESON_ARGS+=	-Dwith_glx=no
.endif

.include <bsd.port.mk>
