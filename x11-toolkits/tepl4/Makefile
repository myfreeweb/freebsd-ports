# $FreeBSD$

PORTNAME=	tepl
PORTVERSION=	4.0.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	4
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Feature library for GtkSourceView based text editors

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USES=		compiler:c11 gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 glib20 gtksourceview4 introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-introspection
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
