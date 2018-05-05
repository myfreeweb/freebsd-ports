# $FreeBSD$

PORTNAME=		gnome-twitch
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.1-147
DISTVERSIONSUFFIX=	-gbbca68b
CATEGORIES=		multimedia

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Twitch livestream player

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL3

LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libjson-glib-1.0.so:devel/json-glib \
		libpeas-1.0.so:devel/libpeas \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c11 meson pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	vinszent

USE_GNOME=	gtk30
USE_XORG=	x11
LDFLAGS+=	-Wl,--as-needed # prevent the stray USE_GNOME=gdkpixbuf2
GLIB_SCHEMAS=	com.vinszent.GnomeTwitch.gschema.xml
INSTALLS_ICONS=	yes

OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	MPV_OPENGL GSTREAMER_CAIRO GSTREAMER_OPENGL GSTREAMER_CLUTTER
OPTIONS_DEFAULT=	MPV_OPENGL
OPTIONS_SUB=		yes

MPV_OPENGL_DESC=	MPV decoding + OpenGL drawing backend
GSTREAMER_CAIRO_DESC=	GStreamer decoding + Cairo drawing backend
GSTREAMER_OPENGL_DESC=	GStreamer decoding + OpenGL drawing backend
GSTREAMER_CLUTTER_DESC=	GStreamer decoding + Clutter drawing backend

MPV_OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
			libmpv.so:multimedia/mpv

GSTREAMER_CLUTTER_LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
				libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
				libclutter-gst-3.0.so:multimedia/clutter-gst3

GSTREAMER_CAIRO_USE=	gstreamer1=hls,cairo
GSTREAMER_OPENGL_USE=	gstreamer1=hls
GSTREAMER_CLUTTER_USE=	gstreamer1=hls

MESON_ARGS=		-Dbuild-player-backends=${OPTIONS_MULTI_BACKEND_SELECTED:tl:S/_/-/:ts,}

.include <bsd.port.mk>
