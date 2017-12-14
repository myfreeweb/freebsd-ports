# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
DISTVERSION=	1.2.1-610
DISTVERSIONSUFFIX=	-g59977ec
PORTREVISION=	4
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast painting/scribbling program

LICENSE=	GPLv2+
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		${PYNUMPY}
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2 \
		libmypaint-2.0.so:graphics/libmypaint
RUN_DEPENDS=	${PYNUMPY}

BINARY_ALIAS=	swig=swig3.0
USE_GNOME=	gtk30 pygobject3 librsvg2:run
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-std=c99
MAKE_ARGS=	prefix=${PREFIX} \
		enable_profiling=False \
		use_sharedlib=True \
		python_binary="${PYTHON_CMD}" \
		python_config="${PYTHON_CMD}-config"
# XXX Embed RPATH via USES=fortran for py-numpy to load libgcc_s.so from ports
USES=		desktop-file-utils fortran gettext localbase \
		pkgconfig python:2 scons tar:xz
INSTALL_TARGET=	${STAGEDIR} --install-sandbox=${STAGEDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_PROJECT=	mypaint

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP
OPTIONS_SUB=		yes

OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler # XXX ports/199603
OPENMP_MAKE_ARGS_OFF=	enable_openmp=False

.include <bsd.port.mk>
