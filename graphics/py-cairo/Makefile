# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.14.1
CATEGORIES=	graphics python
MASTER_SITES=	https://github.com/pygobject/pycairo/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 2 bindings for Cairo

USES=		gnome pkgconfig python:2 shebangfix
USE_PYTHON=	distutils
USE_GNOME=	cairo

PLIST_SUB=	PORTVER=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cairo/_cairo.so

.include <bsd.port.mk>
