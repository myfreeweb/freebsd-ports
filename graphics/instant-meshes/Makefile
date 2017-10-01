# $FreeBSD$

PORTNAME=	instant-meshes
PORTVERSION=	0
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Interactive field-aligned mesh generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	zenity:x11/zenity

USES=		cmake:outsource compiler:c++11-lang pkgconfig
USE_GL=	gl
USE_XORG+=	xxf86vm xrandr xinerama xcursor xi x11

USE_GITHUB=	yes
GH_ACCOUNT=	wjakob
GH_TAGNAME=	4a083f4
GH_TUPLE=	wjakob:nanogui:2a61f03:nanogui/ext/nanogui \
	libigl:eigen:c34a913:eigen \
	wjakob:glfw:0ff30d6:glfw \
	wjakob:nanovg:ac15b84:nanovg \
	pybind:pybind11:c01a1c1:pybind11 \
	wjakob:pcg32:0ef13e6:pcg32/ext/pcg32 \
	wjakob:dset:7967ef0:dset/ext/dset \
	wjakob:tbb:550c18b:tbb/ext/tbb \
	wjakob:pss:a91da33:pss/ext/pss

post-extract:
	@${MV} ${WRKSRC_eigen}/* ${WRKSRC}/ext/nanogui/ext/eigen
	@${MV} ${WRKSRC_glfw}/* ${WRKSRC}/ext/nanogui/ext/glfw
	@${MV} ${WRKSRC_nanovg}/* ${WRKSRC}/ext/nanogui/ext/nanovg
	@${MV} ${WRKSRC_pybind11}/* ${WRKSRC}/ext/nanogui/ext/pybind11

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/instant-meshes.png
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
