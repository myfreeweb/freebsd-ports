# $FreeBSD$

PORTNAME=	loudness-scanner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1-45
DISTVERSIONSUFFIX=	-gde149a1
CATEGORIES=	audio

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Scans your music files and tags them with loudness information

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libebur128.so:audio/libebur128 \
		libmpcdec.so:audio/musepack \
		libmpg123.so:audio/mpg123 \
		libsndfile.so:audio/libsndfile \
		libtag.so:audio/taglib

USES=		cmake compiler:c++11-lang gnome localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_TUPLE=	jiixyj:filewalk:38422e6:filewalk/scanner/filetree

USE_LDCONFIG=	yes
USE_GNOME=	glib20 librsvg2
CMAKE_ARGS+=	-DDISABLE_GSTREAMER:BOOL=YES \
		-DDISABLE_GTK2:BOOL=YES \
		-DDISABLE_QT4:BOOL=YES \
		-DDISABLE_QT5:BOOL=YES \
		-DEBUR128_INCLUDE_DIR:STRING="${LOCALBASE}/include"
PLIST_FILES=	bin/loudness \
		lib/loudness/libinput_ffmpeg.so \
		lib/loudness/libinput_mpg123.so \
		lib/loudness/libinput_musepack.so \
		lib/loudness/libinput_sndfile.so

post-extract:
	${MKDIR} ${WRKSRC}/ebur128/ebur128
	${TOUCH} ${WRKSRC}/ebur128/ebur128/CMakeLists.txt

.include <bsd.port.mk>
