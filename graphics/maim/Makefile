# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	5.4.68
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

BUILD_DEPENDS=  ${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libicuuc.so:devel/icu libImlib2.so:graphics/imlib2 libslopy.so:x11/slop

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof

USES=		cmake
USE_XORG=	x11 xcomposite xrandr xfixes
PLIST_FILES=	bin/${PORTNAME} share/man/man1/maim.1.gz

.include <bsd.port.mk>
