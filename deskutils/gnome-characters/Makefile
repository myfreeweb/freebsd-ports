# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-characters
PORTVERSION=	3.22.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	find and insert unusual characters for GNOME 3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgjs.so:lang/gjs \
		libunistring.so:devel/libunistring \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Characters.gschema.xml

.include <bsd.port.mk>
