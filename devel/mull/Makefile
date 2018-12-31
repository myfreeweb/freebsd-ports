# $FreeBSD$

PORTNAME=	mull
DISTVERSION=	0.1.0-17
DISTVERSIONSUFFIX=	-g3a9a76e
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	LLVM-based mutation testing system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libLLVM-${LLVM_VERSION:C/([1-9])([0-9])/\1/}.so:devel/llvm${LLVM_VERSION}

USES=		compiler:c++11-lang cmake pkgconfig gnome ncurses sqlite:3
USE_GNOME=	libxml2
USE_GITHUB=	yes
GH_ACCOUNT=	mull-project
GH_TUPLE=	AlexDenisov:LibEBC:357abc139e72138856160be0796193e5755e5854:LibEBC/vendor/LibEBC

LLVM_VERSION?=	80
CMAKE_ARGS=	-DPATH_TO_LLVM=${LOCALBASE}/llvm${LLVM_VERSION}

PORTEXAMPLES=	*
PLIST_FILES=	bin/mull-cxx \
		bin/mull-driver \
		lib/libmull.a

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${RM} ${STAGEDIR}${EXAMPLESDIR}/*/.gitignore

.include <bsd.port.mk>
