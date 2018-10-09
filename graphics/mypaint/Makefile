# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
DISTVERSION=	1.2.1-726
DISTVERSIONSUFFIX=	-ge474dd2
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast painting/scribbling program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		${PYNUMPY}
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2 \
		libmypaint-2.0.so:graphics/libmypaint \
		libpng16.so:graphics/png
RUN_DEPENDS=	${PYNUMPY}

# XXX Embed RPATH via USES=fortran for py-numpy to load libgcc_s.so from ports
USES=		desktop-file-utils fortran gettext gnome localbase \
		pkgconfig python:2.7 scons tar:xz
BINARY_ALIAS=	swig=swig3.0
USE_GNOME=	gtk30 pygobject3 cairo librsvg2:run
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-std=c99
MAKE_ARGS=	prefix=${PREFIX} \
		enable_profiling=False \
		use_sharedlib=True \
		python_binary="${PYTHON_CMD}" \
		python_config="${PYTHON_CMD}-config"
INSTALL_TARGET=	${STAGEDIR} --install-sandbox=${STAGEDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GITHUB=	yes
GH_PROJECT=	mypaint

OPTIONS_DEFINE=		GEGL OPENMP
OPTIONS_DEFAULT=	OPENMP
OPTIONS_SUB=		yes

GEGL_DESC=		Graph based image processing framework support
GEGL_LIB_DEPENDS=	libgegl-0.4.so:graphics/gegl
GEGL_MAKE_ARGS=		enable_gegl=True

OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler # XXX ports/199603
OPENMP_MAKE_ARGS_OFF=	enable_openmp=False

.include <bsd.port.mk>
