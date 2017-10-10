# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtksourceview
PORTVERSION=	3.24.5
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text widget that adds syntax highlighting to the GtkTextView widget

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	vala:lang/vala

USES+=		gettext gmake gnome libtool localbase pathfix pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 intlhack \
		introspection:build libxml2 referencehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-compile-warnings=no \
		--enable-glade-catalog=no \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-introspection
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|--warn-all||g' \
		${WRKSRC}/gtksourceview/Makefile.in

.include <bsd.port.mk>

.endif
