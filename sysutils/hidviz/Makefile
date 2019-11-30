# $FreeBSD$

PORTNAME=	hidviz
DISTVERSION=	0.1.4-5
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-gfec32d6
CATEGORIES=	sysutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GUI for in-depth analysis of USB HID class devices

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++14-lang pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	ondrejbudai
GH_TUPLE=	ondrejbudai:libhidx:25588b0:libhidx/libhidx \
		chriskohlhoff:asio:asio-1-10-8:asio/asio

USE_QT=		core gui widgets buildtools_build qmake_build

PLIST_FILES=	bin/hidviz \
		libexec/libhidx_server_daemon

post-patch:
	${REINPLACE_CMD} -e 's|ifdef __linux|ifdef __unix|' \
		${WRKSRC_libhidx}/libhidx_server/src/Server.cc \
		${WRKSRC_libhidx}/libhidx/include/libhidx/LibHidx.hh \
		${WRKSRC_libhidx}/libhidx/src/Connector.cc \
		${WRKSRC_libhidx}/libhidx/src/Connector.hh \
		${WRKSRC_libhidx}/libhidx/src/LibHidx.cc \
		${WRKSRC}/hidviz/src/Window.cc

.include <bsd.port.mk>
