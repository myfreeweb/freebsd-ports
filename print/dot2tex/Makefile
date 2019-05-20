# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dot2tex
PORTVERSION=	2.11.3
CATEGORIES=	print

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Graphviz to LaTeX converter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>=1.4.8:devel/py-pyparsing@${PY_FLAVOR} \
		dot:graphics/graphviz

NO_ARCH=	yes
USES=	python:3.5+
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	kjellmf

.include <bsd.port.mk>
