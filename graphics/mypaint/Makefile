# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
DISTVERSION=	1.2.1-717
DISTVERSIONSUFFIX=	-g82ce454
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast painting/scribbling program

LICENSE=	GPLv2+
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig3.0:devel/swig30 \
		${PYNUMPY}
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2 \
		libmypaint-2.0.so:graphics/libmypaint \
		libpng16.so:graphics/png
RUN_DEPENDS=	${PYNUMPY}

BINARY_ALIAS=	swig=swig3.0
USE_GNOME=	gtk30 pygobject3 cairo librsvg2:run
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-std=c99
MAKE_ARGS=	prefix=${PREFIX} \
		enable_profiling=False \
		use_sharedlib=True \
		python_binary="${PYTHON_CMD}" \
		python_config="${PYTHON_CMD}-config"
# XXX Embed RPATH via USES=fortran for py-numpy to load libgcc_s.so from ports
USES=		desktop-file-utils fortran compiler gettext localbase \
		pkgconfig python:2.7 scons tar:xz
INSTALL_TARGET=	${STAGEDIR} --install-sandbox=${STAGEDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

USE_GITHUB=	yes
GH_PROJECT=	mypaint

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && ${CHOSEN_COMPILER_TYPE} == clang
# Enable OpenMP support with Clang 6.0.
LLVM_VER=	60
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}

CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

# Depend on devel/openmp instead of the full LLVM at runtime. Required
# for a consistent libomp experience.
LIB_DEPENDS+=	libomp.so.0:devel/openmp
.endif

.include <bsd.port.post.mk>
