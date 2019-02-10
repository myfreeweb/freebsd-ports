# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib-networking
PORTVERSION=	2.60.3
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Network-related security giomodules for glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libdbus-1.so:devel/dbus \
		libproxy.so:net/libproxy
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:3.6+,build tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_VERSION}

# While this ports supports both gnutls and openssl. Base (default for USES=ssl)
# doesn't have a pkgconfig file. And Meson doesn't have pkg-config overwrites 
# like autoconf has.

#OPTIONS_SUB=	yes
#OPTIONS_SINGLE=	BACKEND
#OPTIONS_SINGLE_BACKEND=	GNUTLS OPENSSL
#OPTIONS_DEFAULT=	GNUTLS

#GNUTLS_MESON_ON=	-Dgnutls=enabled
#GNUTLS_MESON_OFF=	-Dgnutls=disabled
#GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

#OPENSSL_MESON_ON=	-Dopenssl=enabled
#OPENSSL_MESON_OFF=	-Dopenssl=disabled
#OPENSSL_USES=		ssl:openssl

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd
	${RM} -r ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
