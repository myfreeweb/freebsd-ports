# $FreeBSD$

PORTNAME=	pict
PORTVERSION=	20180915
CATEGORIES=	textproc devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Pairwise Independent Combinatorial Testing tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
GH_TAGNAME=	64d482a218de4e4683b46146486f2e10ad26e930
USE_LDCONFIG=	yes

PLIST_FILES=	bin/pict lib/libpict.so

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pict ${STAGEDIR}${PREFIX}/bin
		${INSTALL_LIB} ${WRKSRC}/libpict.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
