# $FreeBSD$

PORTNAME=		kitty
DISTVERSIONPREFIX=	v
DISTVERSION=		0.13.1
CATEGORIES=		x11

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GPU-accelerated terminal emulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libxkbcommon.so:x11/libxkbcommon \
		libdbus-1.so:devel/dbus \
		libwayland-egl.so:graphics/wayland \
		libepoll-shim.so:devel/libepoll-shim \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	kovidgoyal

USES=		python:3.5+ pkgconfig gl terminfo gettext-runtime shebangfix
USE_GL=	gl
USE_XORG=	x11 xcb xcursor xinerama xrandr
CFLAGS+=	-Wno-macro-redefined -I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-lepoll-shim -lthr
# /usr/local/include/python3.6m/pyconfig.h redefines '_POSIX_C_SOURCE'

SHEBANG_FILES=	lib/kitty/__main__.py lib/kitty/**/*.py

do-build:
	cd ${WRKSRC} && ${MAKE_ENV} MAKE=${GMAKE} ${PYTHON_CMD} setup.py linux-package

do-install:
	cd ${WRKSRC}/linux-package/bin/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/linux-package/lib/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC}/linux-package/share/ && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/share
	${INSTALL_DATA} ${WRKSRC}/terminfo/kitty.terminfo ${STAGEDIR}${PREFIX}/share/misc

.include <bsd.port.mk>
