# $FreeBSD$

PORTNAME=	mull
PORTVERSION=	g20181014
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	LLVM-based mutation testing system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${LLVM_VERSION:C/([1-9])([0-9])/\1.\2/}.so:devel/llvm${LLVM_VERSION}

USES=		compiler:c++11-lang cmake:outsource pkgconfig sqlite:3
USE_GITHUB=	yes
GH_ACCOUNT=	mull-project
GH_TAGNAME=	c6edda7fd6a61317bdd924f9acacff69bf9400af

LLVM_VERSION?=	60
CMAKE_ARGS=	-DLLVMROOT=${LOCALBASE}/llvm${LLVM_VERSION}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/mull-driver \
		bin/mull-reporter \
		lib/libmull.a

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	# New CMake considers '(some dependency name)_ROOT' special and ignores it
	${REINPLACE_CMD} -e 's/LLVM_ROOT/LLVMROOT/g' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${RM} ${STAGEDIR}${EXAMPLESDIR}/*/.gitignore

.include <bsd.port.mk>
