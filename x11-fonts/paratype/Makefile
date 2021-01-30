# Created by: Alexey Illarionov <littlesavage@rambler.ru>

PORTNAME=	paratype
PORTVERSION=	59384
CATEGORIES=	x11-fonts
MASTER_SITES=	https://api.paratype.com/api/editions/ofl/download/
DISTFILES=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}
# Unfortunately there is no public version number,
# the only usable number is the download ID from the link.

MAINTAINER=	greg@unrelenting.technology
COMMENT=	PT Public Pack font collection

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		fonts zip

FETCH_ENV+=	HTTP_REFERER=https://www.paratype.com

FONTNAME=	ParaType
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/PT/PT/*/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
