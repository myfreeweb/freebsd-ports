# $FreeBSD$

PORTNAME=	libmypaint
DISTVERSION=	1.3.0-84
DISTVERSIONSUFFIX=	-g040310c
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	A library for making brush strokes

LICENSE=	ISCL

BUILD_DEPENDS=	gobject-introspection>=1.0:devel/gobject-introspection
LIB_DEPENDS=	libjson-c.so:devel/json-c

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intltool
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-std=c99
CONFIGURE_ARGS=	--disable-profiling
USES=		gettext autoreconf libtool localbase pkgconfig python:2.7 gmake tar:xz
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mypaint

OPTIONS_DEFINE=		GEGL OPENMP
OPTIONS_DEFAULT=	OPENMP
OPTIONS_SUB=		yes

GEGL_DESC=		Graph based image processing framework support
GEGL_LIB_DEPENDS=	libgegl-0.3.so:graphics/gegl3 \
	libbabl-0.1.so:x11/babl \
	libjson-glib-1.0.so:devel/json-glib
GEGL_CONFIGURE_ENABLE=	gegl

OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler # XXX ports/199603
OPENMP_CONFIGURE_ENABLE=	openmp

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh --noconfig)

.include <bsd.port.mk>
