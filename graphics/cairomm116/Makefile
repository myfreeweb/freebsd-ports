# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairomm
PORTVERSION=	1.15.5
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMESUFFIX=	116
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LICENSE=	LGPL20

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c++17-lang gmake gnome libtool pathfix perl5 pkgconfig
USE_CXXSTD=	c++17
USE_GNOME=	cairo libsigc++30
USE_PERL5=	build
USE_XORG=	x11 xext xrender

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ARGS_OFF=	--disable-documentation

#post-configure-DOCS-off:
#	@${TOUCH} -f ${WRKSRC}/docs/reference/html/index.html

.include <bsd.port.mk>
