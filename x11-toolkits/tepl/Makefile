# $FreeBSD$

PORTNAME=	tepl
PORTVERSION=	4.0.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor product line

LIB_DEPENDS=	libuchardet.so:textproc/uchardet

USES=		gettext gmake gnome libtool tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtksourceview4 libxml2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
