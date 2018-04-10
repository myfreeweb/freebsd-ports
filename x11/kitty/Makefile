# $FreeBSD$

PORTNAME=		kitty
DISTVERSIONPREFIX=	v
DISTVERSION=		0.8.2
CATEGORIES=		x11

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GPU-accelerated terminal emulator

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libxkbcommon.so:x11/libxkbcommon \
		libwayland-egl.so:graphics/wayland \
		libepoll-shim.so:devel/libepoll-shim \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	kovidgoyal

USES=		python:3.5+ pkgconfig terminfo
USE_GL=	gl
USE_XORG=	xcursor xinerama xrandr
CFLAGS+=	-Wno-macro-redefined -I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim -lthr
# /usr/local/include/python3.6m/pyconfig.h redefines '_POSIX_C_SOURCE'

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} setup.py linux-package

do-install:
	cd ${WRKSRC}/linux-package/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/linux-package/lib/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/linux-package/share/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/share
	${INSTALL_DATA} ${WRKSRC}/terminfo/kitty.terminfo ${STAGEDIR}${PREFIX}/share/misc

.include <bsd.port.mk>
