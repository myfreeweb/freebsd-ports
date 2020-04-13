# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	clutter
PORTVERSION=	1.26.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwayland-egl.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon \
		libgudev-1.0.so:devel/libgudev \
		libudev.so:devel/libudev-devd \
		libinput.so:x11/libinput \
		libcogl.so:graphics/cogl

PORTSCOUT=	limit:1,even

USES=		gettext gl gnome localbase meson pkgconfig \
		tar:xz
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 pango introspection:build
USE_GL=		egl
USE_LDCONFIG=	yes
MESON_ARGS=	-Dwayland_compositor=false \
		-Ddocumentation=false \
		-Dbuild_examples=false

# TODO: fix compositor support in cogl

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

X11_USES=		xorg
X11_USE=		XORG=x11,xcomposite,xdamage,xext,xfixes,xi,xrandr
X11_MESON_ON=	-Dbackends=x11,gdk,wayland,eglnative
X11_MESON_OFF=	-Dbackends=gdk,wayland,eglnative

.include <bsd.port.mk>
