# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD: head/irc/polari/Makefile 408881 2016-02-14 18:57:53Z kwm $

PORTNAME=	polari
PORTVERSION=	3.22.2
CATEGORIES=	irc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Internet Relay Chat (IRC) client designed for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		gjs-console:lang/gjs \
		itstool:textproc/itstool
LIB_DEPENDS=	libtelepathy-glib.so:net-im/telepathy-glib \
		libsecret-1.so:security/libsecret \
		libtelepathy-logger.so:net-im/telepathy-logger
RUN_DEPENDS=	gjs-console:lang/gjs

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool localbase \
		pathfix pkgconfig tar:xz
USE_GNOME=	cairo gnomedesktop3 gtk30 intlhack introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Polari.gschema.xml

.include <bsd.port.mk>
