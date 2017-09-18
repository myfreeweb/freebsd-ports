# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD: head/deskutils/bijiben/Makefile 441071 2017-05-17 09:45:20Z kwm $

PORTNAME=	bijiben
PORTVERSION=	3.24.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libtracker-control-1.0.so:sysutils/tracker \
		libsoup-2.4.so:devel/libsoup \
		libicuuc.so:devel/icu \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libical.so:devel/libical \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libsecret-1.so:security/libsecret \
		libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib desktop-file-utils gettext gmake gnome \
		libtool localbase pathfix pkgconfig shared-mime-info tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo evolutiondataserver3 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-Werror
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.bijiben.gschema.xml

.include <bsd.port.mk>
