# Created by: Bill Fumerola <billf@chc-chimes.com>

PORTNAME=	stamp
PORTVERSION=	2.0.8
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adds a graphical, configurable timestamp to a grayscale image

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: DefaultNetbuf
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: DefaultNetbuf

USES=		jpeg
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local/share/stamp#${DATADIR}#' \
		${WRKSRC}/configure

.include <bsd.port.mk>
