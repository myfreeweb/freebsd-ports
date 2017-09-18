# $FreeBSD$

PORTNAME=	glslang
DISTVERSION=	3.0-1516
DISTVERSIONSUFFIX=	-gd5aedc19
CATEGORIES=	devel graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	OpenGL and OpenGL ES shader front end and validator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/LICENSE

USES=		cmake:outsource compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	glslang

post-extract:
	${SED} '/^$$/,$$d' ${WRKSRC}/${PORTNAME}/Include/Types.h \
			>${WRKDIR}/LICENSE

.include <bsd.port.mk>
