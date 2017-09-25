# $FreeBSD$

PORTNAME=	xcape
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-58
DISTVERSIONSUFFIX=	-g6ded5b4
CATEGORIES=	x11

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Utility to configure modifier keys to act as other keys when pressed on their own

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	alols

USE_XORG=	x11 xtst
USES=	pkgconfig

MAKE_ARGS=	PREFIX=${PREFIX} MANDIR=/man/man1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xcape

.include <bsd.port.mk>
