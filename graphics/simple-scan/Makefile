# $FreeBSD$

PORTNAME=	simple-scan
DISTVERSION=	3.36.1
CATEGORIES=	graphics gnome

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GNOME scanning application using SANE

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libsane.so:graphics/sane-backends \
		libgusb.so:devel/libgusb \
		libcolord.so:graphics/colord \
		libwebp.so:graphics/webp

USES=		pkgconfig python:3.5+ gnome gettext-tools meson
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	f2f427fb39a634476e953525fb1048cf266e6c87
USE_GNOME=	glib20 gtk30 gdkpixbuf2 cairo
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.SimpleScan.gschema.xml

.include <bsd.port.mk>
