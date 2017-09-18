# Created by: ade, archie
# $FreeBSD$

PORTNAME=	nautilus
PORTVERSION=	3.22.2
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libexempi.so:textproc/exempi \
		libgnome-autoar-0.so:archivers/gnome-autoar
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool libarchive \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 intlhack gnomedesktop3 libxml2 gvfs \
		introspection:build
USE_LDCONFIG=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-packagekit \
		--disable-selinux
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=TRACKER
TRACKER_DESC=	Tracker support
TRACKER_LIB_DEPENDS=	libtracker-control-1.0.so:sysutils/tracker
TRACKER_CONFIGURE_ENABLE=	tracker

.include <bsd.port.mk>
