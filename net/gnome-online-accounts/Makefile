# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-online-accounts
PORTVERSION=	3.26.1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interface provider to access the user's online accounts

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		librest-0.7.so:devel/librest \
		libp11-kit.so:security/p11-kit \
		libgck-1.so:security/gcr

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib gettext gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection:build libxml2 libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-lastfm

GLIB_SCHEMAS=	org.gnome.online-accounts.gschema.xml

CONFIGURE_ARGS+=--enable-kerberos=no

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	TELEPATHY
OPTIONS_DEFAULT=

TELEPATHY_DESC=			Foo
TELEPATHY_CONFIGURE_ENABLE=	telepathy
TELEPATHY_LIB_DEPENDS=		libtelepathy-glib.so:net-im/telepathy-glib

# disable telepaty by default
# + flickr

.include <bsd.port.mk>
