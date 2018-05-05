# $FreeBSD$

PORTNAME=	shaderc
PORTVERSION=	20180420
CATEGORIES=	graphics devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GLSL/HLSL to SPIR-V shader compiler

LICENSE=	APACHE20

USES=	cmake:outsource compiler:c++11-lib pkgconfig

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	shaderc
GH_TAGNAME=	5fd1b25
GH_TUPLE=	KhronosGroup:glslang:3bb4c48:glslang/third_party/glslang \
		KhronosGroup:SPIRV-Headers:3a4dbdd:headers \
		KhronosGroup:SPIRV-Tools:7a59283:tools/third_party/spirv-tools

CMAKE_ARGS+=	-DSHADERC_SKIP_TESTS:BOOL=ON
CFLAGS+=	-Wno-ignored-attributes

post-extract:
	${MKDIR} ${WRKSRC}/third_party/spirv-tools/external/spirv-headers
	${MV} ${WRKSRC_headers}/* ${WRKSRC}/third_party/spirv-tools/external/spirv-headers

.include <bsd.port.mk>
