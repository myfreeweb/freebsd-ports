# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libechonest
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Collection of C++/Qt classes designed to use the APIs of The Echo Nest

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	lfranchi

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.if defined(PKGNAMESUFFIX)
CMAKE_ARGS+=	-DBUILD_WITH_QT4=OFF
LIB_DEPENDS=	libqjson-qt5.so:devel/qjson@qt5
USE_QT5=	core buildtools_build qmake_build network
TEST_USE=	qt5=testlib_build
.else
LIB_DEPENDS=	libqjson.so:devel/qjson@qt4
USE_QT4=	corelib qmake_build moc_build network xml rcc_build
TEST_USE=	qt4=qtestlib_build
.endif

OPTIONS_DEFINE=	TEST

TEST_CMAKE_BOOL=ECHONEST_BUILD_TESTS

.include <bsd.port.mk>
