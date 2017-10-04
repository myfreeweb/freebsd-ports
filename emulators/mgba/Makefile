# $FreeBSD$

PORTNAME=	mgba
DISTVERSION=	0.6.1
CATEGORIES=	emulators

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Game Boy Advance (GBA) emulator/debugger

LICENSE=	MPL20 BSD3CLAUSE LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/src/third-party/inih/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	mgba-emu

USES=		cmake:outsource compiler:c++11-lang pkgconfig sqlite:3
USE_GL=	gl glu
USE_SDL=	sdl2
CMAKE_ARGS+=	-DUSE_MINIZIP:BOOL=OFF \
	-DUSE_LIBZIP:BOOL=OFF \
	-DUSE_ZLIB:BOOL=ON \
	-DUSE_LZMA:BOOL=ON \
	-DUSE_SQLITE3:BOOL=ON \
	-DBUILD_GL:BOOL=ON \
	-DBUILD_GLES2:BOOL=OFF
LDFLAGS+=	-Wl,--as-needed # glu
LDFLAGS+=	-L/usr/local/lib # sqlite3

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libpng16.so:graphics/png

OPTIONS_DEFINE=	DEBUGGERS FFMPEG MAGICK QT
OPTIONS_DEFAULT=	DEBUGGERS FFMPEG MAGICK QT
OPTIONS_SUB=yes

DEBUGGERS_DESC=		Debugging infrastructure (CLI debugger, GDB remote stub)
DEBUGGERS_CMAKE_BOOL=		USE_DEBUGGERS USE_EDITLINE USE_GDB_STUB

FFMPEG_DESC=		FFmpeg video recording support
FFMPEG_CMAKE_BOOL=	USE_FFMPEG
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavresample.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg

MAGICK_DESC=		ImageMagick GIF recording support
MAGICK_CMAKE_BOOL=	USE_MAGICK
MAGICK_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick \
		libMagickCore-6.so:graphics/ImageMagick

QT_DESC=		Qt frontend
QT_CMAKE_BOOL=		BUILD_QT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUGGERS}
USES+=	libedit
.endif

.if ${PORT_OPTIONS:MQT}
USE_QT5=		qmake_build buildtools_build core gui widgets network opengl multimedia
USES+=			desktop-file-utils
INSTALLS_ICONS=	yes
.endif

.include <bsd.port.mk>
