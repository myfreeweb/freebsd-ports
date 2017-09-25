# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-todo
PORTVERSION=	3.18.1
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small application to manage your personal tasks

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libgoa-1.0.so:net/gnome-online-accounts \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libical.so:devel/libical

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo evolutiondataserver3 gnomedesktop3 gtk30 \
		intlhack introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.todo.gschema.xml

.include <bsd.port.mk>
