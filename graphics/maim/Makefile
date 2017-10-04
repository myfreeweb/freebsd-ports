# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	5.4.68
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 libicuuc.so:devel/icu libpng16.so:graphics/png libslopy.so:x11/slop

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof

USES=		cmake jpeg
USE_GL=		gl
USE_XORG=	ice sm x11 xcomposite xext xrandr xrender xfixes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
