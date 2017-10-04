# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/mail/geary/Makefile 20050 2014-11-10 09:22:41Z gusi $

PORTNAME=	geary
PORTVERSION=	0.11.1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME 3

LICENSE=	LGPL21 CCA3 PORTER
LICENSE_COMB=	dual
LICENSE_FILE_CCA3=	${WRKSRC}/COPYING.icons
LICENSE_NAME_CCA3=	Creative Common Attribution 3.0 Unported License
LICENSE_PERMS_CCA3=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_PORTER=	${WRKSRC}/COPYING.snowball
LICENSE_NAME_PORTER=	Martin Porter, Richard Boulton
LICENSE_PERMS_PORTER=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	vapigen:lang/vala
LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libnotify.so:devel/libnotify \
		libgee-0.8.so:devel/libgee \
		libgcr-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libsoup-2.4.so:devel/libsoup

USES=		cmake:outsource desktop-file-utils gettext \
		libtool pkgconfig shebangfix sqlite tar:xz
USE_GNOME=	cairo gnomedocutils gnomeprefix gtk30 intlhack introspection
SHEBANG_FILES=	desktop/geary-attach
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS=	-DNO_FATAL_WARNINGS:BOOL=ON

GLIB_SCHEMAS=	org.yorba.geary.gschema.xml

.include <bsd.port.mk>
