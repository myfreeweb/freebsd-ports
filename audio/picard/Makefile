# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=		picard
DISTVERSION=		2.0.0dev6
CATEGORIES=		audio python

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Next generation MusicBrainz Tagger

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}discid>=0.5.2:audio/py-discid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.37:audio/py-mutagen@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	metabrainz

USES=		gettext pyqt:5 python:3.5+ desktop-file-utils
USE_PYQT=	core_run gui_run widgets_run network_run xml_run sip
USE_PYTHON=	distutils
PYDISTUTILS_INSTALLNOSINGLE=	yes
MAKE_ENV=	LC_ALL=en_US.UTF-8 # https://github.com/pypa/setuptools/issues/1062

OPTIONS_DEFINE=		ACOUSTID PLUGINS
OPTIONS_DEFAULT=	PLUGINS

ACOUSTID_RUN_DEPENDS=	fpcalc:audio/chromaprint

PLUGINS_DESC=		Install various plugins to extend functionality
PLUGINS_RUN_DEPENDS=	picard-plugins>0:audio/picard-plugins

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/picard/util/_astrcmp.so

.include <bsd.port.mk>
