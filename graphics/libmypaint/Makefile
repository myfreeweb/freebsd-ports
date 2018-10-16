# $FreeBSD$

PORTNAME=	libmypaint
DISTVERSION=	1.3.0-96
DISTVERSIONSUFFIX=	-g0c07191
CATEGORIES=	graphics

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Brush library from the MyPaint project

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/automake:devel/automake

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		compiler:c11 gmake gnome libtool:build localbase pkgconfig tar:xz python:2.7,build

USE_GITHUB=	yes
GH_ACCOUNT=	mypaint

USE_GNOME=	glib20 intltool introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_TARGET=	check

BINARY_ALIAS=	python2=${PYTHON_CMD}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS GEGL
OPTIONS_DEFAULT=GEGL

NLS_USES=	gettext
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls i18n

GEGL_DESC=		Graph based image processing framework support
GEGL_LIB_DEPENDS=	libgegl-0.3.so:graphics/gegl3 \
	libbabl-0.1.so:x11/babl \
	libjson-glib-1.0.so:devel/json-glib
GEGL_CONFIGURE_ENABLE=	gegl

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh --noconfig)

.include <bsd.port.mk>
