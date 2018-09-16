# $FreeBSD$

PORTNAME=	gst-transcoder
DISTVERSION=	1.14
CATEGORIES=	multimedia

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GStreamer Transcoding API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.3+,build pkgconfig meson
USE_GITHUB=	yes
GH_ACCOUNT=	pitivi
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER1=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
