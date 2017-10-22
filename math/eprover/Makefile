# $FreeBSD$

PORTNAME=		eprover
DISTVERSIONPREFIX=	E-
DISTVERSION=		2.0
CATEGORIES=		math

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Theorem prover for full first-order logic with equality

LICENSE=	LGPL20+ GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man
RUN_DEPENDS=	bash:shells/bash

USES=	shebangfix

SHEBANG_FILES=	PROVER/eproof PROVER/eproof_ram

USE_GITHUB=	yes
GH_ACCOUNT=	eprover

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${STAGEDIR}${PREFIX}/bin/ --man-prefix=${STAGEDIR}${PREFIX}/man/man1/

post-build:
	cd ${WRKSRC} && ${MAKE} man
	${REINPLACE_CMD} -e 's|EXECPATH=.|EXECPATH=${PREFIX}/bin|' \
			${WRKSRC}/PROVER/eproof ${WRKSRC}/PROVER/eproof_ram

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/eprover \
		${STAGEDIR}${PREFIX}/bin/epclextract \
		${STAGEDIR}${PREFIX}/bin/e_deduction_server \
		${STAGEDIR}${PREFIX}/bin/ekb_delete \
		${STAGEDIR}${PREFIX}/bin/e_axfilter \
		${STAGEDIR}${PREFIX}/bin/ekb_create \
		${STAGEDIR}${PREFIX}/bin/e_ltb_runner \
		${STAGEDIR}${PREFIX}/bin/eground \
		${STAGEDIR}${PREFIX}/bin/ekb_ginsert \
		${STAGEDIR}${PREFIX}/bin/checkproof \
		${STAGEDIR}${PREFIX}/bin/ekb_insert

.include <bsd.port.mk>
