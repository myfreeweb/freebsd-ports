# $FreeBSD$

PORTNAME=		alternative-toolbar
DISTVERSIONPREFIX=	v
DISTVERSION=		0.17.5
CATEGORIES=		audio
PKGNAMEPREFIX=		rhythmbox-plugin-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Enhanced play controls and interface for Rhythmbox

LICENSE=	GPLv3+

RUN_DEPENDS=	rhythmbox:audio/rhythmbox

USES=		python:3 pkgconfig autoreconf gmake

USE_GITHUB=	yes
GH_ACCOUNT=	fossfreedom

GNU_CONFIGURE=	yes

USE_GNOME=	gtk30 py3gobject3 intltool
GLIB_SCHEMAS=	org.gnome.rhythmbox.plugins.alternative_toolbar.gschema.xml

.include <bsd.port.mk>
