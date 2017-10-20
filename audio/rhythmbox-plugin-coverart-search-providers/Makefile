# $FreeBSD$

PORTNAME=		coverart-search-providers
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.2
CATEGORIES=		audio
PKGNAMEPREFIX=		rhythmbox-plugin-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Cover art search plugin for Rhythmbox

LICENSE=	GPLv3+

RUN_DEPENDS=	rhythmbox:audio/rhythmbox \
		${PYTHON_SITELIBDIR}/PIL:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}gdbm>0:databases/py-gdbm \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml

USES=		python:3 gettext-tools pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fossfreedom

USE_GNOME=	gtk30 py3gobject3
GLIB_SCHEMAS=	org.gnome.rhythmbox.plugins.coverart_search_providers.gschema.xml

pre-install:
	${SED} -i '' -e "s|/usr/|${LOCALBASE}/|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
