# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	four-in-a-row
PORTVERSION=	3.38.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Make lines of the same color

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		vala:lang/vala \
		appstream-util:devel/appstream-glib

PORTSCOUT=	limitw:1,even

USES=		canberra:gtk3 gettext gmake gnome localbase meson pathfix \
		pkgconfig tar:xz xorg
INSTALLS_ICONS=	yes
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build gsound
USE_XORG=	x11

GLIB_SCHEMAS=	org.gnome.Four-in-a-row.gschema.xml

.include <bsd.port.mk>
