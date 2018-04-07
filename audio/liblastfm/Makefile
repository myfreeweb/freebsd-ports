# Created by: Matt Tosto <datahead4@gmail.com>
# $FreeBSD$

PORTNAME=	liblastfm
DISTVERSION=	1.1.0-3
DISTVERSIONSUFFIX=	-g4433165
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Qt C++ library for the Last.fm webservices

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	lastfm

USES=		cmake pkgconfig
USE_LDCONFIG=	yes


.if defined(PKGNAMESUFFIX)
USE_QT5=	core dbus network sql xml \
		buildtools_build qmake_build
TEST_USE=		QT5=testlib_build
.else
CMAKE_ARGS=	-DBUILD_WITH_QT4:BOOL=ON
USE_QT4=	corelib dbus network sql xml \
		moc_build qmake_build rcc_build
TEST_USE=		QT4=qtestlib_build
.endif

OPTIONS_DEFINE=		FINGERPRINT TEST
OPTIONS_DEFAULT=	FINGERPRINT
OPTIONS_SUB=		yes

FINGERPRINT_DESC=	Build the lastfm-fingerprint library
FINGERPRINT_LIB_DEPENDS=libsamplerate.so:audio/libsamplerate \
			libfftw3f.so:math/fftw3-float
FINGERPRINT_CMAKE_BOOL=	BUILD_FINGERPRINT
# We only need fftw3.h from math/fftw3; no need to install
FINGERPRINT_BUILD_DEPENDS=	${NONEXISTENT}:math/fftw3:patch
FINGERPRINT_CMAKE_ON=	-DLIBFFTW3_INCLUDE_DIR:PATH=`${MAKE} -C ${PORTSDIR}/math/fftw3 -VWRKSRC`/api

TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TARGET=		test

.include <bsd.port.mk>
