# $FreeBSD$

PORTNAME=	instant-meshes
DISTVERSION=	0.0-42
DISTVERSIONSUFFIX=	-g4a083f4
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Interactive field-aligned mesh generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	convert:graphics/ImageMagick
RUN_DEPENDS=	zenity:x11/zenity

USES=		cmake:outsource compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TUPLE=	wjakob:nanogui:2a61f03:nanogui/ext/nanogui \
	libigl:eigen:c34a913:eigen \
	wjakob:glfw:0ff30d6:glfw \
	wjakob:nanovg:ac15b84:nanovg \
	pybind:pybind11:c01a1c1:pybind11 \
	wjakob:pcg32:0ef13e6:pcg32/ext/pcg32 \
	wjakob:dset:7967ef0:dset/ext/dset \
	wjakob:tbb:550c18b:tbb/ext/tbb \
	wjakob:pss:a91da33:pss/ext/pss

USE_GL=	gl
USE_XORG+=	xxf86vm xrandr xinerama xcursor xi x11

PLIST_FILES=		"bin/Instant Meshes"
DESKTOP_ENTRIES=	"Instant Meshes" \
		"An interactive field-aligned mesh generator" \
		"${PORTNAME}" \
		"env LIBGL_DRI3_DISABLE=1 \"Instant Meshes\"" \
		"Graphics;3DGraphics;" \
		true
# radeonsi_dri crash with DRI3

post-extract:
	${MV} ${WRKSRC_eigen}/* ${WRKSRC}/ext/nanogui/ext/eigen
	${MV} ${WRKSRC_glfw}/* ${WRKSRC}/ext/nanogui/ext/glfw
	${MV} ${WRKSRC_nanovg}/* ${WRKSRC}/ext/nanogui/ext/nanovg
	${MV} ${WRKSRC_pybind11}/* ${WRKSRC}/ext/nanogui/ext/pybind11

post-build:
	convert -verbose -resize 500x500 -gravity center -background none -extent 512x512 \
		${WRKSRC}/resources/icon.png ${WRKDIR}/icon_512x512.png
.for size in 128x128 192x192 256x256
	convert -verbose -resize ${size} ${WRKDIR}/icon_512x512.png ${WRKDIR}/icon_${size}.png
.endfor
.for size in 16x16 24x24 32x32 48x48 64x64 96x96
	convert -verbose -resize ${size} ${WRKDIR}/icon_512x512.png -unsharp 0x6 ${WRKDIR}/icon_${size}.png
.endfor

post-install:
.for size in 16x16 24x24 32x32 48x48 64x64 96x96 128x128 192x192 256x256 512x512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps
	${INSTALL_DATA} ${WRKDIR}/icon_${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}/apps/${PORTNAME}.png
	${ECHO_CMD} share/icons/hicolor/${size}/apps/${PORTNAME}.png >>${TMPPLIST}
.endfor

.include <bsd.port.mk>
