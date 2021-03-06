# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>

PORTNAME=	camlp5
PORTVERSION=	8.00+alpha06
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Preprocessor-pretty-printer of OCaml

LICENSE=	INRIA
LICENSE_NAME=	INRIA permissive license with copyright notice requirements
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake tar:tgz
USE_GITHUB=	yes
GH_TAGNAME=	rel${PORTVERSION}
USE_OCAML=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}
ALL_TARGET=	world.opt
MAKE_JOBS_UNSAFE=yes

OPTIONS_SINGLE=		MODE
OPTIONS_SINGLE_MODE=	TRANSITIONAL STRICT
OPTIONS_DEFAULT=	STRICT
TRANSITIONAL_DESC=	Compatible syntax tree with old versions
STRICT_DESC=		New syntax tree quotations kit

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES DEVEL ICHANGES MODE UPGRADING

STRICT_CONFIGURE_ON=	--strict
TRANSITIONAL_CONFIGURE_ON=	--transitional

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/META \
	    ${STAGEDIR}${PREFIX}/lib/ocaml/camlp5
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/camlp5*.opt \
	    ${STAGEDIR}${PREFIX}/${OCAML_LIBDIR}/camlp5/*.o

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
