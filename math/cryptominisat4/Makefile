# $FreeBSD$

PORTNAME=	cryptominisat
PKGNAMESUFFIX=	4
PORTVERSION=	4.5.3
CATEGORIES=	math

MAINTAINER=	greg@unrelenting.technology
COMMENT=	General-purpose award-winning SAT solver

LICENSE=	LGPL3

BUILD_DEPENDS=	xxd:editors/vim-lite # for xxd tool
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	msoos

USES=		cmake:outsource compiler:c++11-lib
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DNOM4RI=1 -DENABLE_PYTHON_INTERFACE=OFF

.include <bsd.port.mk>
