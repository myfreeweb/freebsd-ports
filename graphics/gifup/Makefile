# $FreeBSD$

PORTNAME=	gifup
DISTVERSION=	0.0.21
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Create GIFs from video files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	vala:lang/vala
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		gettext gnome meson pkgconfig python:3.5+,build
USE_GITHUB=	yes
GH_ACCOUNT=	BharatKalluri
GH_PROJECT=	Gifup
USE_GNOME=	cairo pango glib20 gtk30
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
