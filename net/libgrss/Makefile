# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	libgrss
PORTVERSION=	0.7.0
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for easy management of RSS/Atom/Pie feeds

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libxml2.so:${PORTSDIR}/textproc/libxml2

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	glib20 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
