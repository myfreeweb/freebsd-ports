# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairomm
PORTVERSION=	1.12.2
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LICENSE=	LGPL20

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gmake gnome libtool pathfix pkgconfig xorg
USE_CXXSTD=	c++11
USE_GNOME=	cairo libxml++26
USE_XORG=	x11 xext xrender

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" DOXYGEN="${TRUE}"

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_OFF=	--disable-documentation

post-configure-DOCS-off:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcairomm-1.0.so.1.4.0

.include <bsd.port.mk>
