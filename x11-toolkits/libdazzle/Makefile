# $FreeBSD$

PORTNAME=	libdazzle
PORTVERSION=	3.27.3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Companion library to GObject and Gtk+

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 introspection
USE_LDCONFIG=	yes
CPE_VENDOR=	gnome

.include <bsd.port.mk>
