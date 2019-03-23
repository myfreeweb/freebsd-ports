# $FreeBSD$

PORTNAME=	gnome-usage
PORTVERSION=	3.32.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Information about use of system resources for GNOME

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop \
		libdazzle-1.0.so:x11-toolkits/libdazzle

USES=		gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gtk30

INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.Usage.gschema.xml

.include <bsd.port.mk>
