# Created by: Ade Lovett <ade@lovett.com>
# $FreeBSD$

PORTNAME=	gdk-pixbuf
PORTVERSION=	2.36.11
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Graphic library for GTK+

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:3.4+,build shared-mime-info shebangfix tar:xz
USE_XORG=	xt xi x11
CPE_VENDOR=	gnome
USE_GNOME+=	glib20 introspection:build libxslt:build
USE_LDCONFIG=	yes
SHEBANG_FILES=	build-aux/gen-thumbnailer.py

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	JASPER JPEG PNG TIFF
OPTIONS_DEFAULT=JPEG PNG TIFF

JASPER_MESON_TRUE=	enable_jasper
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper

JPEG_MESON_TRUE=	enable_jpeg
JPEG_USES=		jpeg

PNG_MESON_TRUE=		enable_png
PNG_LIB_DEPENDS=	libpng.so:graphics/png

TIFF_MESON_TRUE=	enable_tiff
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

#post-install:
#	${RM} -rf ${STAGEDIR}${PREFIX}/libexec/installed-tests
#	${RM} -rf ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
