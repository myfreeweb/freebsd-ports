# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-user-share
PORTVERSION=	3.18.1
CATEGORIES=	www deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Personal file-sharing service for the GNOME Desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libnotify.so:devel/libnotify \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libunique-1.0.so:x11-toolkits/unique
RUN_DEPENDS=	ap*-mod_dnssd>=0:www/mod_dnssd \
		console-kit-daemon:sysutils/consolekit2

USES=		gettext gmake libtool localbase pkgconfig tar:xz
USE_APACHE=	22+
USE_XORG=	sm x11
USE_GNOME=	cairo gnomeprefix gtk30 intlhack nautilus3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-modules-path=${LOCALBASE}/${APACHEMODDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.desktop.file-sharing.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/httpd/modules|${LOCALBASE}/${APACHEMODDIR}|g' \
		${WRKSRC}/data/dav_user_*.conf

.include <bsd.port.mk>
