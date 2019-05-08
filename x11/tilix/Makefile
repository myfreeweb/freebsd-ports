# $FreeBSD$

PORTNAME=	tilix
DISTVERSION=	1.9.3-38
DISTVERSIONSUFFIX=	-g3617018
CATEGORIES=	x11

MAINTAINER=	greg@unrelenting.technology
COMMENT=	A tiling terminal emulator using GTK+ 3

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2 \
		libphobos2-ldc-shared.so:lang/ldc \
		libunwind.so:devel/libunwind \
		libvted-3.so:x11-toolkits/gtkd-3

USES=		gettext-tools gnome meson pkgconfig python:3.6+,build \
		shebangfix
USE_XORG=	x11
USE_GNOME=	cairo gdkpixbuf2 gtk30 librsvg2 vte3
USE_GITHUB=	yes
GH_ACCOUNT=	gnunn1
SSP_UNSAFE=	yes # not understood by ldc2 and not removed by meson yet
LDFLAGS+=	-link-defaultlib-shared -L-Wl,--as-needed
SHEBANG_FILES=	data/scripts/tilix_int.sh
GLIB_SCHEMAS=	com.gexperts.Tilix.gschema.xml

BINARY_ALIAS+=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
