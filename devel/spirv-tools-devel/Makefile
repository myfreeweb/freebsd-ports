# $FreeBSD$

PORTNAME=	spirv-tools-devel
DISTVERSION=	v2016.7-dev
CATEGORIES=	devel graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools for processing SPIR-V intermediate shader language modules

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cmake:outsource compiler:c++11-lang python:2

USE_GITHUB=	yes
GH_TUPLE=	KhronosGroup:SPIRV-Tools:f0fe601d \
		KhronosGroup:SPIRV-Headers:2bb92e6f:headers/external/spirv-headers

CMAKE_ARGS+=	-DSPIRV_SKIP_TESTS:BOOL=ON \
		-DSPIRV_WERROR:BOOL=OFF

.include <bsd.port.mk>
