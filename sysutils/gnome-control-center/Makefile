# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-control-center
PORTVERSION=	3.24.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcups.so:print/cups \
		libpulse.so:audio/pulseaudio \
		libfontconfig.so:x11-fonts/fontconfig \
		libjson-glib-1.0.so:devel/json-glib \
		libfreetype.so:print/freetype2 \
		libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libupower-glib.so:sysutils/upower \
		libaccountsservice.so:sysutils/accountsservice \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libibus-1.0.so:textproc/ibus \
		libgoa-1.0.so:net/gnome-online-accounts \
		libpwquality.so:security/libpwquality \
		libgtop-2.0.so:devel/libgtop \
		libgrilo-0.3.so:net/grilo \
		libpolkit-gobject-1.so:sysutils/polkit \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gnome-settings-daemon>=3.4.0:sysutils/gnome-settings-daemon \
		gsettings-desktop-schemas>=3.2.2:devel/gsettings-desktop-schemas \
		gcm-calibrate:graphics/gnome-color-manager

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome localbase pathfix \
		pkgconfig samba:lib ssl tar:xz
USE_GNOME=	cairo gnomedesktop3 intltool libxml2
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE

CHEESE_DESC=	Cheese webcam support
CHEESE_LIB_DEPENDS=	libcheese.so:multimedia/cheese
CHEESE_CONFIGURE_WITH=	cheese

post-patch:
	@${REINPLACE_CMD} -e 's|gdk-wayland-3.0|gdk-wayland-3.0-disabled|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|HAVE_WAYLAND|DON_WANT_WAYLAND|g' \
		${WRKSRC}/panels/common/gnome-settings-bus.h

.include <bsd.port.mk>
