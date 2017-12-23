# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-documents
PORTVERSION=	3.24.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Document manager application designed to work with GNOME 3

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libevview3.so:graphics/evince \
		libgdata.so:devel/libgdata \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgjs.so:lang/gjs \
		libtracker-sparql-1.0.so:sysutils/tracker \
		libgepub.so:textproc/libgepub \
		libzapojit-0.0.so:net/libzapojit
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		gnome-online-miners>=0:net/gnome-online-miners \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		unoconv:textproc/unoconv

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome libtool localbase \
		pathfix pkgconfig python:2.7 tar:xz
USE_GNOME=	cairo gdkpixbuf2 gnomedesktop3 intltool introspection librsvg2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Documents.enums.xml \
		org.gnome.books.gschema.xml \
		org.gnome.documents.gschema.xml

.include <bsd.port.mk>
