# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimp
PORTREVISION=	0
PORTEPOCH=	0
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GIMP python plugin

GIMP_SLAVE=	pygimp

USES=		python:2.7
USE_GNOME=	pygtk2

BUILD_DEPENDS+=	py27-gobject3>0:devel/py-gobject3@py27

BINARY_ALIAS=	python=${PYTHON_CMD}

MESON_ARGS=	-Dwith-python=true
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/plug-ins/pygimp
INSTALL_WRKSRC=	${WRKSRC}/plug-ins/pygimp

MASTERDIR=	${.CURDIR}/../../graphics/gimp-app

.include "${MASTERDIR}/Makefile"
