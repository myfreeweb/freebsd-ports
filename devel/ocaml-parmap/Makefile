# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>

PORTNAME=	parmap
DISTVERSION=	1.1.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	Minimalistic library allowing to exploit multicore architecture

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	jbuilder:devel/ocaml-dune

USE_GITHUB=	yes
GH_ACCOUNT=	rdicosmo

USES=			gmake
USE_OCAML=		yes
USE_OCAML_LDCONFIG=	yes
ALL_TARGET=	default
MAKE_ARGS+=	LIBDIR=${OCAML_LIBDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/parmap/*.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/stublibs/*.so

.include <bsd.port.mk>
