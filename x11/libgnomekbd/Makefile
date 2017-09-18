# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libgnomekbd
PORTVERSION=	3.22.0.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	libxklavier>=5.2:x11/libxklavier
LIB_DEPENDS=	libxklavier.so:x11/libxklavier

USES=		gettext gmake libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gnomeprefix gtk30 intltool introspection:build \
		libxml2
GNU_CONFIGURE=	yes
USE_XORG=	ice x11
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.libgnomekbd.desktop.gschema.xml \
		org.gnome.libgnomekbd.gschema.xml \
		org.gnome.libgnomekbd.keyboard.gschema.xml

.include <bsd.port.mk>
