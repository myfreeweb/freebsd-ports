# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairomm
PORTVERSION=	1.12.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LICENSE=	LGPL20

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		compiler:c++11-lang gmake gnome libtool pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	cairo libxml++26
USE_XORG=	x11 xext xrender
CONFIGURE_ENV=	AUTOMAKE="${TRUE}" AUTOCONF="${TRUE}" DOXYGEN="${TRUE}"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ARGS_OFF=	--disable-documentation

post-configure-DOCS-off:
	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html

.include <bsd.port.mk>
