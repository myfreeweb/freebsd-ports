# Created by: Johannes Lundberg <johalun0@gmail.com>
# $FreeBSD$

PORTNAME=	weston
PORTVERSION=	1.12.0
CATEGORIES=	x11-wm wayland
MASTER_SITES=	http://wayland.freedesktop.org/releases/
MAINTAINER=	x11@freebsd.org
COMMENT=	Wayland Reference Compositor

LICENSE=	MIT

USES=		autoreconf alias gmake pathfix jpeg libtool pkgconfig tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XORG=	x11 xcb xcursor
USE_GL=		egl gbm glesv2

GROUPS=		weston-launch

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SUID CLIENTS CLIENTS_INSTALL XWAYLAND
SUID_DESC=	Install weston-launch binary with setuid bit set
OPTIONS_MULTI= COMPOSITORS
OPTIONS_MULTI_COMPOSITORS= X11 DRM WAYLAND SCFB
OPTIONS_SINGLE=	CAIRO
OPTIONS_SINGLE_CAIRO= CAIROIMAGE CAIROGL CAIROGLESV2
CAIRO_DESC=	Cairo backend
CAIROIMAGE_DESC= Image (Recommended)
CAIROGL_DESC= GL (enabled in cairo by default)
CAIROGLESV2_DESC= GLESv2 (requires cairo built with --enable-glesv2)
CLIENTS_DESC= Build Weston clients
CLIENTS_INSTALL_DESC= Install Weston clients
XWAYLAND_DESC= Support running X clients in Weston
X11_DESC= Run Weston as X11 client (good for testing)
WAYLAND_DESC= Nested Weston compositors
DRM_DESC= Hardware accelerated compositor backend
SCFB_DESC= Software rendered compositor backend

OPTIONS_DEFAULT= SUID CAIROIMAGE CLIENTS CLIENTS_INSTALL XWAYLAND X11 DRM WAYLAND SCFB

DRM_LIB_DEPENDS= libdrm.so:${PORTSDIR}/graphics/libdrm

LIB_DEPENDS= \
		libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon		\
		libpixman-1.so:${PORTSDIR}/x11/pixman				\
		libcairo.so:${PORTSDIR}/graphics/cairo				\
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango		\
		libcolord.so:${PORTSDIR}/graphics/colord			\
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig	\
		libfreetype.so:${PORTSDIR}/print/freetype2			\
		libwayland-server.so:${PORTSDIR}/graphics/wayland	\
		libwayland-client.so:${PORTSDIR}/graphics/wayland	\
		libwayland-cursor.so:${PORTSDIR}/graphics/wayland	\
		libwayland-egl.so:${PORTSDIR}/graphics/mesa-libs		\
		libevent.so:${PORTSDIR}/devel/libevent				\
		libpng.so:${PORTSDIR}/graphics/png					\
		libwebp.so:${PORTSDIR}/graphics/webp				\
		libffi.so:${PORTSDIR}/devel/libffi					\
		libepoll-shim.so:${PORTSDIR}/devel/libepoll-shim	\
		libudev.so:${PORTSDIR}/devel/libudev-devd			\
		libunwind.so:${PORTSDIR}/devel/libunwind			\
		libevdev.so:${PORTSDIR}/devel/libevdev				\
		libinput.so:${PORTSDIR}/x11/libinput			\
		libmtdev.so:${PORTSDIR}/devel/libmtdev

BUILD_DEPENDS+=	wayland-protocols>=1.7:${PORTSDIR}/graphics/wayland-protocols
BUILD_DEPENDS+=	wayland-scanner:${PORTSDIR}/graphics/wayland

RUN_DEPENDS= ${LOCALBASE}/lib/libglapi.so.0:${PORTSDIR}/graphics/mesa-libs

CPPFLAGS+= -I${LOCALBASE}/include -I${LOCALBASE}/include/libepoll-shim
LDFLAGS+= -L${LOCALBASE}/lib

CLIENTS_CONFIGURE_ENABLE= 			clients
CLIENTS_INSTALL_CONFIGURE_ENABLE= 	demo-clients-install
XWAYLAND_CONFIGURE_ENABLE=			xwayland
X11_CONFIGURE_ENABLE=				x11-compositor
DRM_CONFIGURE_ENABLE=				drm-compositor
SCFB_CONFIGURE_ENABLE=				scfb-compositor
WAYLAND_CONFIGURE_ENABLE=			wayland-compositor

CONFIGURE_ARGS+=	--enable-weston-launch
CONFIGURE_ARGS+=	--disable-fbdev-compositor
CONFIGURE_ARGS+=	--disable-vaapi-recorder
CONFIGURE_ARGS+=	--disable-xwayland-test

GNU_CONFIGURE=	YES

# We handle setuid in the plist. This allows to build as a user.
CONFIGURE_ARGS+=	--disable-setuid-install

CONFIGURE_ENV+= LIBS="-lepoll-shim -lrt -lEGL"
CONFIGURE_ENV+= EGL_TESTS_LIBS="-lwayland-client -lGLESv2 -lwayland-egl -lwayland-client"
CONFIGURE_ENV+= EGL_TESTS_CFLAGS="-L${STAGEDIR}${PREFIX}/lib -I${STAGEDIR}${PREFIX}/include"


.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MCAIROIMAGE}
CONFIGURE_ARGS+=	--with-cairo=image
.endif
.if ${PORT_OPTIONS:MCAIROGL}
CONFIGURE_ARGS+=	--with-cairo=gl
.endif
.if ${PORT_OPTIONS:MCAIROGLESV2}
CONFIGURE_ARGS+=	--with-cairo=glesv2 --with-cairo-glesv2
.endif

PATHFIX_MAKEFILEIN?=	Makefile.am

# Should not have to do this. "make" should find them in $WAYLAND_PROTOCOLS_DATADIR set by automake...
WAYLAND_PROTOCOLS_DATADIR=`pkg-config --variable=pkgdatadir wayland-protocols`
pre-configure:
	@cp ${WAYLAND_PROTOCOLS_DATADIR}/stable/*/* ${WRKSRC}/protocol/
	@cp ${WAYLAND_PROTOCOLS_DATADIR}/unstable/*/* ${WRKSRC}/protocol/


.include <bsd.port.mk>
