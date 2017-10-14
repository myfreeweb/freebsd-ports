# $FreeBSD$

PORTNAME=		apitrace
DISTVERSION=		7.1-455
DISTVERSIONSUFFIX=	-g7c76b90
CATEGORIES=		devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools for tracing OpenGL and other graphics APIs

LICENSE=	MIT

LIB_DEPENDS=	libunwind.so:devel/libunwind \
		libpng16.so:graphics/png

USES=		cmake:outsource compiler:c++11-lang pkgconfig python:2.7 shebangfix

USE_GITHUB=	yes
USE_XORG=	x11

SHEBANG_REGEX=	./scripts/.*\.py

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR:STRING="${DOCSDIR}"

OPTIONS_DEFINE=	QT5
OPTIONS_DEFAULT=	QT5
OPTIONS_SUB=		yes

QT5_DESC=		Qt 5 frontend

QT5_CMAKE_BOOL=	ENABLE_GUI
QT5_USE=		qt5=qmake_build,buildtools_build,core,gui,widgets,network
QT5_USES=		desktop-file-utils
QT5_VARS=		installs_icons=yes

post-install-QT5-on:
	${INSTALL_DATA} ${FILESDIR}/qapitrace.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
