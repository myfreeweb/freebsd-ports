# $FreeBSD$

PORTNAME=	libgusb
DISTVERSION=	0.3.0
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GObject wrapper for libusb1

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala

USES=		pkgconfig meson
USE_GITHUB=	yes
GH_ACCOUNT=	hughsie
USE_GNOME=	glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
