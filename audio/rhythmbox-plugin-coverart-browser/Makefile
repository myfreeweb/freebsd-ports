# $FreeBSD$

PORTNAME=		coverart-browser
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.2
CATEGORIES=		audio
PKGNAMEPREFIX=		rhythmbox-plugin-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Cover art browser plugin for Rhythmbox

LICENSE=	GPLv3+

RUN_DEPENDS=	rhythmbox:audio/rhythmbox \
		${LOCALBASE}/lib/rhythmbox/plugins/coverart_search_providers/coverart_search_providers.py:audio/rhythmbox-plugin-coverart-search-providers \

USES=		python:3 gettext-tools pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fossfreedom

USE_GNOME=	gtk30 py3gobject3
GLIB_SCHEMAS=	org.gnome.rhythmbox.plugins.coverart_browser.gschema.xml

pre-install:
	${SED} -i '' -e "s|/usr/|${LOCALBASE}/|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
