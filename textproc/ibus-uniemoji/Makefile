# $FreeBSD$

PORTNAME=		ibus-uniemoji
DISTVERSIONPREFIX=	v
DISTVERSION=		0.6.0
CATEGORIES=		textproc

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Input method for entering unicode symbols and emoji by name

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-Levenshtein>0:devel/py-python-Levenshtein@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${LOCALBASE}/share/gir-1.0/IBus-1.0.gir:textproc/ibus

USES=		gmake shebangfix python:3.4+
SHEBANG_GLOB=	*.py
USE_GITHUB=	yes
GH_ACCOUNT=	salty-horse
USE_GNOME=	glib20 pygobject3
MAKE_ENV+=	PYTHON=${PYTHON_CMD} SYSCONFDIR=${PREFIX}/etc

.include <bsd.port.mk>
