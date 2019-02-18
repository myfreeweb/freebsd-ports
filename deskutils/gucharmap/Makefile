# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gucharmap
PORTVERSION=	11.0.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		UCD>=11:textproc/UCD
LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		desktop-file-utils gettext gmake gnome \
		libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unicode-data=${LOCALBASE}/share/unicode/ucd/
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml \
		org.gnome.Charmap.gschema.xml

.include <bsd.port.mk>
