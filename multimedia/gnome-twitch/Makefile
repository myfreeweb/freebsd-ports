# $FreeBSD$

PORTNAME=		gnome-twitch
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.1
CATEGORIES=		multimedia

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Twitch livestream player

LICENSE=	GPLv3+

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libpeas-1.0.so:devel/libpeas \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c11 meson pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	vinszent

USE_GNOME=	gtk30
USE_XORG+=	x11
GLIB_SCHEMAS=	com.vinszent.GnomeTwitch.gschema.xml
INSTALLS_ICONS=	yes
LDFLAGS+=	-Wl,--as-needed # gdkpixbuf2

OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	MPV_OPENGL
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MPV_OPENGL GSTREAMER_CAIRO GSTREAMER_OPENGL GSTREAMER_CLUTTER

MPV_OPENGL_DESC=	MPV decoding + OpenGL drawing backend
GSTREAMER_CAIRO_DESC=	GStreamer decoding + Cairo drawing backend
GSTREAMER_OPENGL_DESC=	GStreamer decoding + OpenGL drawing backend
GSTREAMER_CLUTTER_DESC=	GStreamer decoding + Clutter drawing backend

MPV_OPENGL_LIB_DEPENDS=	libmpv.so:multimedia/mpv \
			libepoxy.so:graphics/libepoxy

GSTREAMER_CLUTTER_LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
				libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
				libclutter-gst-3.0.so:multimedia/clutter-gst3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER_CAIRO} || ${PORT_OPTIONS:MGSTREAMER_OPENGL} || ${PORT_OPTIONS:MGSTREAMER_CLUTTER}
USE_GSTREAMER1=	yes
.endif

BACKENDS=
.if ${PORT_OPTIONS:MMPV_OPENGL}
BACKENDS+=	mpv-opengl
.endif
.if ${PORT_OPTIONS:MGSTREAMER_CAIRO}
BACKENDS+=	gstreamer-cairo
.endif
.if ${PORT_OPTIONS:MGSTREAMER_OPENGL}
BACKENDS+=	gstreamer-opengl
.endif
.if ${PORT_OPTIONS:MGSTREAMER_CLUTTER}
BACKENDS+=	gstreamer-clutter
.endif

MESON_ARGS+=	-Dbuild-player-backends=${BACKENDS:ts,}

.include <bsd.port.mk>
