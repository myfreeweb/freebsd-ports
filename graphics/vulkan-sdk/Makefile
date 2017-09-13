# $FreeBSD$

PORTNAME=	vulkan-sdk
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.0.57.0
CATEGORIES=	graphics devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Vulkan SDK (Headers, ICD Loader, Validation Layers)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
	${LOCALBASE}/include/spirv-tools/libspirv.h:devel/spirv-tools-devel \
	glslangValidator:devel/glslang-devel

USES=	cmake:outsource compiler:c++11-lang python:3 pkgconfig

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

XLIB_CMAKE_ON=	-DBUILD_WSI_XLIB_SUPPORT:BOOL=ON
XLIB_CMAKE_OFF=	-DBUILD_WSI_XLIB_SUPPORT:BOOL=OFF
XLIB_LIB_DEPENDS=	libX11.so:x11/libX11
XCB_CMAKE_ON=	-DBUILD_WSI_XCB_SUPPORT:BOOL=ON
XCB_CMAKE_OFF=	-DBUILD_WSI_XCB_SUPPORT:BOOL=OFF
XCB_LIB_DEPENDS=	libX11-xcb.so:x11/libX11 \
		libxcb.so:x11/libxcb
WAYLAND_CMAKE_ON=	-DBUILD_WSI_WAYLAND_SUPPORT:BOOL=ON
WAYLAND_CMAKE_OFF=	-DBUILD_WSI_WAYLAND_SUPPORT:BOOL=OFF
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libwayland-server.so:graphics/wayland \
		libwayland-cursor.so:graphics/wayland \
		libwayland-egl.so:graphics/mesa-libs
DEMOS_CMAKE_ON=	-DBUILD_DEMOS:BOOL=ON
DEMOS_CMAKE_OFF=	-DBUILD_DEMOS:BOOL=OFF

.include <bsd.port.mk>
