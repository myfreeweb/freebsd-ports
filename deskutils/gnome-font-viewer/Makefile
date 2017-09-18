# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-font-viewer
PORTVERSION=	3.22.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 font viewer utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz

CONFLICTS=	gnome-utils-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake localbase pathfix \
		pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	cairo intlhack gtk30 gnomedesktop3
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
