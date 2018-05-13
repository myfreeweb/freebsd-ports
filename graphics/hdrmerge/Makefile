# $FreeBSD$

PORTNAME=		hdrmerge
DISTVERSIONPREFIX=	v
DISTVERSION=		0.5.0-95-ge160591
CATEGORIES=		graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	HDR exposure merging application

LICENSE=	GPLv3

LIB_DEPENDS=	libalglib.so:math/alglib \
		libraw_r.so:graphics/libraw \
		libexiv2.so:graphics/exiv2

USES=		cmake:outsource compiler:c++11-lib pkgconfig gettext-runtime desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	jcelaya

USE_QT5=	core gui widgets

INSTALLS_ICONS=	yes
CMAKE_ARGS+=	-DALGLIB_INCLUDES=${LOCALBASE}/include/libalglib
PLIST_FILES=	bin/hdrmerge \
		${DESKTOPDIR:S,${PREFIX}/,,}/hdrmerge.desktop \
		share/icons/hicolor/128x128/apps/hdrmerge-icon.png

post-install: 
	${INSTALL_DATA} ${WRKDIR}/.build/hdrmerge.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/data/images/icon.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/hdrmerge-icon.png

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

# Last but not least, there is a second change or regression in CMake
# 3.4.x: CMAKE_EXE_LINKER_FLAGS is not passed to TRY_COMPILE by default
# anymore. The CMP0056 policy must be explicitly set to NEW to ensure
# linker flags are passed.
# See: https://cmake.org/cmake/help/v3.4/policy/CMP0056.html
CMAKE_ARGS+=	-DCMAKE_POLICY_DEFAULT_CMP0056:STRING=NEW
.endif

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

.include <bsd.port.post.mk>
