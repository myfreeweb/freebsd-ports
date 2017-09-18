# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-session
PORTVERSION=	3.24.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 3 desktop

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libjson-glib-1.0.so:devel/json-glib \
		libepoxy.so:graphics/libepoxy
RUN_DEPENDS=	${LOCALBASE}/sbin/console-kit-daemon:sysutils/consolekit2

PORTSCOUT=	limitw:1,even

USES=		execinfo gettext gmake gnome localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo gnomedesktop3 intlhack libxslt:build
USE_XORG=	ice sm x11 xau xcomposite xext xrender xtrans xtst
USE_GL=		egl gl glesv2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--enable-consolekit \
		--enable-gconf=no \
		--disable-systemd

GLIB_SCHEMAS=	org.gnome.SessionManager.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|gconf-2.0|gconf-disabled|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
