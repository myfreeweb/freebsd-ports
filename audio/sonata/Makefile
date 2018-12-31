# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=		sonata
DISTVERSION=		1.7b1-14
DISTVERSIONSUFFIX=	-g0a1d630
CATEGORIES=		audio python

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Elegant music player for MPD

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpd2:audio/py-mpd2@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	multani

USES=		gettext pkgconfig python:3.5+
USE_GNOME=	pygobject3
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS MMKEYS MPD TAGLIB ZSI
OPTIONS_DEFAULT=	MPD
MMKEYS_DESC=	Enable instance single support for mmkeys
MPD_DESC=	Install Music Player Daemon
TAGLIB_DESC=	Install support for editing metadata
ZSI_DESC=	Install support for automatic lyrics fetching
OPTIONS_SUB=	yes

MPD_RUN_DEPENDS+=	musicpd:audio/musicpd
MMKEYS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:devel/py-dbus@${FLAVOR}
TAGLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tagpy>=0.94.5:audio/py-tagpy@${FLAVOR}
ZSI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zsi>=2.0,1:net/py-zsi@${FLAVOR}

.include <bsd.port.mk>
