# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-initial-setup
PORTVERSION=	3.24.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	First boot setup tool for GNOME 3

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gdm>=3.0.0:x11/gdm \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libaccountsservice.so:sysutils/accountsservice \
		libgeocode-glib.so:net/geocode-glib \
		libpwquality.so:security/libpwquality \
		libpolkit-gobject-1.so:sysutils/polkit \
		libcheese.so:multimedia/cheese \
		librest-0.7.so:devel/librest \
		libjson-glib-1.0.so:devel/json-glib \
		libibus-1.0.so:textproc/ibus \
		libsecret-1.so:security/libsecret \
		libgweather-3.so:net/libgweather
RUN_DEPENDS=	gdm>=3.0.0:x11/gdm \
		iso-codes>=0:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	gnomedesktop3 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-software-sources
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	KERBEROS
OPTIONS_DEFAULT=KERBEROS

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MKERBEROS}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-gnome-initial-setup_gis-account-page.c \
			${FILESDIR}/patch-gnome-initial-setup_gis-account-page.ui
.endif

post-patch:
		@${REINPLACE_CMD} -e 's|krb5/krb5.h|krb5.h|g' \
			${WRKSRC}/gnome-initial-setup/pages/account/um-realm-manager.c

.include <bsd.port.mk>
