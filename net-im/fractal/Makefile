# $FreeBSD$

PORTNAME=	fractal
DISTVERSION=	0.1.30
CATEGORIES=	net-im
MASTER_SITES=	https://gitlab.gnome.org/World/fractal/uploads/${GL_HASH}/

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Matrix IM client

LICENSE=	GPLv3+

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgspell-1.so:textproc/gspell \
		libgmp.so:math/gmp
BUILD_DEPENDS=	cargo:lang/rust

GL_HASH=	307ea6fe16f617750490a359b727aebb

USES=		ssl gettext meson shebangfix tar:xz
USE_GNOME=	gtk30 cairo
INSTALLS_ICONS=	yes
SHEBANG_FILES=	${WRKSRC}/scripts/*.sh
MAKE_ENV+=	GETTEXT_BIN_DIR=${PREFIX}/bin \
		GETTEXT_LIB_DIR=${PREFIX}/lib \
		GETTEXT_INCLUDE_DIR=${PREFIX}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fractal

.include <bsd.port.mk>
