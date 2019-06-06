# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	geary
PORTVERSION=	3.38.0.1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME 3

LICENSE=	BSD2CLAUSE CC-BY-3.0 LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	vapigen:lang/vala \
		appstream-util:devel/appstream-glib \
		itstool:textproc/itstool
LIB_DEPENDS=	libgmime-3.0.so:mail/gmime30 \
		libsoup-2.4.so:devel/libsoup \
		libunwind.so:devel/libunwind \
		libjson-glib-1.0.so:devel/json-glib \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libytnef.so:converters/ytnef \
		libgee-0.8.so:devel/libgee \
		libgcr-base-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libfolks.so:net-im/folks \
		libpeas-1.0.so:devel/libpeas \
		libhandy-1.so:x11-toolkits/libhandy \
		libgspell-1.so:textproc/gspell \
		libenchant-2.so:textproc/enchant2

USES=		compiler:c11 desktop-file-utils gettext gnome meson \
		pkgconfig python:3.5+,build shebangfix sqlite tar:xz
USE_GNOME=	cairo gsound gtk30 libxml2

USE_LDCONFIG=	yes

SHEBANG_FILES=	desktop/geary-attach
INSTALLS_ICONS=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.Geary.gschema.xml

.include <bsd.port.mk>
