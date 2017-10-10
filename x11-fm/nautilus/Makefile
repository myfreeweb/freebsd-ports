# Created by: ade, archie
# $FreeBSD$

PORTNAME=	nautilus
PORTVERSION=	3.26.0
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libgnome-autoar-0.so:archivers/gnome-autoar \
		libtracker-sparql-1.0.so:sysutils/tracker
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome \
		localbase meson pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 introspection:build
USE_LDCONFIG=	yes
USE_XORG=	x11
MESON_ARGS=	-Denable-packagekit=false \
		-Denable-selinux=false

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EXIF XMP

EXIF_DESC=		Exchangeable image file format, metadata
EXIF_MESON_TRUE=	enable-exif
EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

XMP_DESC=		Adobe's Extensible Metadata Platform
XMP_MESON_TRUE=		enable-xmp
XMP_LIB_DEPENDS=	libexempi.so:textproc/exempi

.include <bsd.port.mk>
