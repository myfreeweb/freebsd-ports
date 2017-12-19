# $FreeBSD$

PORTNAME=	ponyc
PORTVERSION=	0.21.0
CATEGORIES=	lang

MAINTAINER=	franz@bett.ag
COMMENT=	Pony language compiler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libunwind.so:devel/libunwind
BUILD_DEPENDS=	llvm-link39:devel/llvm39
RUN_DEPENDS=	llvm-link39:devel/llvm39

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		gmake ncurses compiler:c++11-lang
MAKE_ARGS=	config=release

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	ponylang
GH_PROJECT=	ponyc

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Undefined reference to __atomic_compare_exchange_8
BROKEN_FreeBSD_10=	Undefined reference to __atomic_compare_exchange

PORTDOCS=	*.md

MAKE_ENV=	destdir=${STAGEDIR} prefix=${PREFIX} verbose=true

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pony/${PORTVERSION}/bin/ponyc

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
