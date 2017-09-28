# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	vcmi
DISTVERSION=	0.99-615
DISTVERSIONSUFFIX=	-gec2bef40
CATEGORIES=	games

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open-source engine for Heroes of Might and Magic III

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libavcodec.so:multimedia/ffmpeg \
		libminizip.so:archivers/minizip \
		libfuzzylite.so:devel/fuzzylite
RUN_DEPENDS=	innoextract:archivers/innoextract

USE_GITHUB=	yes

SHEBANG_FILES=	vcmibuilder
USES=		cmake:outsource compiler:c++11-lang pkgconfig shebangfix
USE_QT5=	buildtools_build core gui network qmake_build widgets
USE_SDL=	image2 mixer2 ttf2
USE_LDCONFIG=	${PREFIX}/lib/vcmi
INSTALLS_ICONS=	yes

CMAKE_BUILD_TYPE=	RelWithDebInfo # This is REQUIRED. Release build crashes when starting a game.
CMAKE_ARGS+=	-DFORCE_BUNDLED_FL:BOOL=OFF \
	-DENABLE_TEST:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 39
CFLAGS+=	-Wno-error=varargs
.endif

.include <bsd.port.post.mk>
