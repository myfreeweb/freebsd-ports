# $FreeBSD$

PORTNAME=	neovim-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.8
CATEGORIES=	editors

MAINTAINER=	chuck@tuffli.net
COMMENT=	Neovim client library and GUI, in Qt5

LICENSE=	ISCL

BUILD_DEPENDS=	neovim>=0:editors/neovim
LIB_DEPENDS=	libmsgpackc.so:devel/msgpack
RUN_DEPENDS=	neovim>=0:editors/neovim

USES=		cmake desktop-file-utils
CMAKE_ARGS=	-DUSE_SYSTEM_MSGPACK:BOOL=ON

USE_QT5=	buildtools_build core qmake_build testlib network gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	equalsraf

.include <bsd.port.mk>
