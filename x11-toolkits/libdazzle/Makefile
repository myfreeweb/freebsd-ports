# $FreeBSD$

PORTNAME=	libdazzle
PORTVERSION=	3.27.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Staging and stabilizing for facy Glib and Gtk+ features

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		gnome meson tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

.include <bsd.port.mk>
