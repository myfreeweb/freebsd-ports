# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-dictionary
PORTVERSION=	3.24.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 dictionary lookup application

LICENSE=GPLv2 LGPL21
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.libs

#BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intltool introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.dictionary.gschema.xml

.include <bsd.port.mk>
