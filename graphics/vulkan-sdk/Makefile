# $FreeBSD$

PORTNAME=	vulkan-sdk
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.0.57.0
CATEGORIES=	graphics devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Vulkan SDK (Headers, ICD Loader, Validation Layers)

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
	${LOCALBASE}/include/spirv-tools/libspirv.h:devel/spirv-tools \
	glslangValidator:devel/glslang

USES=	cmake:outsource compiler:c++11-lib python:build pkgconfig

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-LoaderAndValidationLayers

CMAKE_ARGS+=	-DBUILD_TESTS:BOOL=OFF \
							-DCMAKE_SKIP_RPATH:BOOL=ON \
							-DBUILD_WSI_MIR_SUPPORT:BOOL=OFF

OPTIONS_DEFINE=	XLIB XCB WAYLAND DEMOS
OPTIONS_DEFAULT=	XLIB XCB DEMOS
OPTIONS_SUB=	yes

XLIB_DESC=	Build Xlib WSI (Window System Integration) support
XCB_DESC=	Build XCB WSI (Window System Integration) support
WAYLAND_DESC=	Build Wayland WSI (Window System Integration) support
DEMOS_DESC=	Build demos (including vulkaninfo)

XLIB_CMAKE_BOOL=	BUILD_WSI_XLIB_SUPPORT
XLIB_LIB_DEPENDS=	libX11.so:x11/libX11 \
		libXrandr.so:x11/libXrandr
XCB_CMAKE_BOOL=	BUILD_WSI_XCB_SUPPORT
XCB_LIB_DEPENDS=	libX11-xcb.so:x11/libX11 \
		libxcb.so:x11/libxcb
WAYLAND_CMAKE_BOOL=	BUILD_WSI_WAYLAND_SUPPORT
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libwayland-server.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libwayland-egl.so:graphics/mesa-libs
DEMOS_CMAKE_BOOL=	BUILD_DEMOS

.include <bsd.port.mk>
