# $FreeBSD$

PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2018.0-6
DISTVERSIONSUFFIX=	-g9e19fc0
CATEGORIES=	devel graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools for processing SPIR-V intermediate shader language modules

LICENSE=	APACHE20

USES=		cmake:outsource compiler:c++11-lib python:build shebangfix
SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:ce309203d:headers/external/spirv-headers

CMAKE_ARGS+=	-DSPIRV_SKIP_TESTS:BOOL=ON \
		-DSPIRV_WERROR:BOOL=OFF

.include <bsd.port.mk>
