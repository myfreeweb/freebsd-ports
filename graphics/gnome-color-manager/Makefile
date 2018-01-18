# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-color-manager
PORTVERSION=	3.26.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session framework for the GNOME desktop to manage color profiles

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook2man:textproc/docbook-utils \
		itstool:textproc/itstool \
		docbook-sgml>0:textproc/docbook-sgml
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libpcre2-8.so:devel/pcre2 \
		libtiff.so:graphics/tiff \
		libgnutls.so:security/gnutls \
		libexif.so:graphics/libexif

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome localbase:ldflags \
		meson pkgconfig tar:xz
USE_XORG=	x11 xrandr
USE_GNOME=	cairo gnomedesktop3 gtk30 intlhack vte3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Denable-tests=false \
		-Denable-packagekit=false

OPTIONS_DEFINE=	RAW
OPTIONS_DEFAULT=RAW
OPTIONS_SUB=	yes

RAW_DESC=	Enable RAW EXIF support
RAW_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
RAW_MESON_TRUE=	enable-exiv

post-patch:
	@${REINPLACE_CMD} -e "s|'share/man/man1'|'man/man1'|g" \
		${WRKSRC}/man/meson.build

.include <bsd.port.mk>
