# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-system-monitor
PORTVERSION=	3.32.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME system monitor program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:devel/libgtop

PORTSCOUT=	limitw:1,even

USES=		alias compiler:c++11-lang gettext gnome localbase \
		meson pkgconfig python:3.5+,build tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30 intlhack librsvg2 libxml2
INSTALL_TARGET=	install-strip
MESON_ARGS=	-Dsystemd=false

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.gnome-system-monitor.enums.xml \
		org.gnome.gnome-system-monitor.gschema.xml

.include <bsd.port.mk>
