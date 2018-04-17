# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libechonest
PORTVERSION=	2.3.1
PORTREVISION=	3
CATEGORIES=	audio
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Collection of C++/Qt classes designed to use the APIs of The Echo Nest

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt4 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	lfranchi

.if ${FLAVOR} == qt4
USE_QT4=	corelib qmake_build moc_build network xml rcc_build
LIB_DEPENDS=	libqjson.so:devel/qjson@qt4
CMAKE_ON+=	BUILD_WITH_QT4
.else
USE_QT5=	core buildtools_build qmake_build network
LIB_DEPENDS=	libqjson-qt5.so:devel/qjson@qt5
CMAKE_OFF+=	BUILD_WITH_QT4
QTVER_SUFFIX=	5
.endif

PLIST_SUB=	PORTVERSION=${PORTVERSION} QTVER_SUFFIX="${QTVER_SUFFIX}"

OPTIONS_DEFINE=	TEST

.if ${FLAVOR} == qt4
TEST_USE=	QT4=qtestlib_build
.else
TEST_USE=	QT5=testlib_build
.endif
TEST_CMAKE_BOOL=ECHONEST_BUILD_TESTS

.include <bsd.port.mk>
