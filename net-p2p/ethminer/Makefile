# $FreeBSD$

PORTNAME=		ethminer
DISTVERSIONPREFIX=	v
DISTVERSION=		0.15.0
CATEGORIES=		net-p2p

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Ethereum/Ethash GPU miner with OpenCL and stratum support

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl \
		cli11>=0:devel/cli11 \
		ethash<0.3.0:devel/ethash
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libjsoncpp.so:devel/jsoncpp \
		libjsonrpccpp-client.so:net/libjson-rpc-cpp \
		libboost_system.so:devel/boost-libs
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		ssl compiler:c++11-lang cmake:outsource pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	ethereum-mining
GH_TUPLE=	ethereum:cable:69a5abc:cable/cmake/cable \
		hunter-packages:disabled-mode:5f88a3d:hunter/cmake/Hunter/disabled-mode \
		hunter-packages:mongoose:10dff70:mongoose/libapicore/mongoose

CMAKE_OFF=	HUNTER_ENABLED ETHASHCUDA

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_CMAKE_BOOL=	ETHDBUS
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

post-extract:
	${CP} ${FILESDIR}/Findjsoncpp.cmake ${WRKSRC}/cmake/
	${CP} ${FILESDIR}/jsoncppConfig.cmake ${WRKSRC}/cmake/Hunter/disabled-mode/

pre-build:
	${TOUCH} ${BUILD_WRKSRC}/gitinfo.txt

.include <bsd.port.mk>
