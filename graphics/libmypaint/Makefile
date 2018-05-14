# $FreeBSD$

PORTNAME=	libmypaint
DISTVERSION=	1.3.0-89
DISTVERSIONSUFFIX=	-ga67661b
CATEGORIES=	graphics

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Brush library from the MyPaint project

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		gmake gnome libtool localbase pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	mypaint

USE_GNOME=	glib20 intltool introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_TARGET=	check

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS GEGL
OPTIONS_DEFAULT=GEGL

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GEGL_DESC=		Graph based image processing framework support
GEGL_LIB_DEPENDS=	libgegl-0.3.so:graphics/gegl3 \
	libbabl-0.1.so:x11/babl \
	libjson-glib-1.0.so:devel/json-glib
GEGL_CONFIGURE_ENABLE=	gegl

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh --noconfig)

.include <bsd.port.mk>
