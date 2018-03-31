# $FreeBSD$

PORTNAME=	simple-scan
DISTVERSION=	3.28.0
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

USES=		pkgconfig gettext-tools meson
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	ad909692450643b18635801fb5ee561163ea2b90
USE_GNOME=	glib20 gtk30 gdkpixbuf2 cairo
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.SimpleScan.gschema.xml

.include <bsd.port.mk>
