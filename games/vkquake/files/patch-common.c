--- common.c.orig	2017-09-09 21:55:23 UTC
+++ common.c
@@ -2231,7 +2231,7 @@ void COM_InitFilesystem (void) //johnfitz -- modified 
 	if (i && i < com_argc-1)
 		q_strlcpy (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	else
-		q_strlcpy (com_basedir, host_parms->basedir, sizeof(com_basedir));
+		q_strlcpy (com_basedir, DATADIR, sizeof(com_basedir));
 
 	j = strlen (com_basedir);
 	if (j < 1) Sys_Error("Bad argument to -basedir");
a20329dc5121fc99f62f2df4c6dfaa68
echo x - vkquake/Makefile
sed 's/^X//' >vkquake/Makefile << '9394640baa729ab12429364dd9c4d8fa'
# $FreeBSD$

PORTNAME=	vkquake
DISTVERSION=	0.96.2
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Quake 1 port using Vulkan instead of OpenGL, based on QuakeSpasm

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libSDL2.so:devel/sdl20 \
		libX11-xcb.so:x11/libX11 \
		libvulkan.so:graphics/vulkan-sdk

WRKSRC_SUBDIR=	Quake

USES=	gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Novum
GH_PROJECT=	vkQuake

ALL_TARGET=
MAKE_ARGS+=	prefix=${LOCALBASE} bindir=${LOCALBASE}/bin

.include "${.CURDIR}/../quake-data/Makefile.include"

CFLAGS+=	-DDATADIR='\"${Q1DIR}\"'

OPTIONS_DEFINE=	USERDIRS WAVE FLAC MP3 VORBIS OPUS
OPTIONS_RADIO=	MODPLAYER
OPTIONS_RADIO_MODPLAYER=	MIKMOD XMP MODPLUG
OPTIONS_DEFAULT=	USERDIRS WAVE FLAC VORBIS OPUS MODPLUG

USERDIRS_DESC=	Enable support for loading game files from user directories (~/.vkquake)
WAVE_DESC=	Enable support for Wave music
FLAC_DESC=	Enable support for FLAC music
MP3_DESC=	Enable support for MP3 music
VORBIS_DESC=	Enable support for Ogg Vorbis music
OPUS_DESC=	Enable support for Opus music
MIKMOD_DESC=	Enable support for tracker module music using MikMod
XMP_DESC=	Enable support for tracker module music using XMP
MODPLUG_DESC=	Enable support for tracker module music using ModPlug

USERDIRS_MAKE_ARGS=	DO_USERDIRS=1
USERDIRS_MAKE_ARGS_OFF=	DO_USERDIRS=0

WAVE_MAKE_ARGS=	USE_CODEC_WAVE=1
WAVE_MAKE_ARGS_OFF=	USE_CODEC_WAVE=0

FLAC_MAKE_ARGS=	USE_CODEC_FLAC=1
FLAC_MAKE_ARGS_OFF=	USE_CODEC_FLAC=0
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac

MP3_MAKE_ARGS=	USE_CODEC_MP3=1 MP3LIB=mad
MP3_MAKE_ARGS_OFF=	USE_CODEC_MP3=0
MP3_LIB_DEPENDS=	libmad.so:audio/libmad

VORBIS_MAKE_ARGS=	USE_CODEC_VORBIS=1 VORBISLIB=vorbis
VORBIS_MAKE_ARGS_OFF=	USE_CODEC_VORBIS=0
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libogg.so:audio/libogg

OPUS_MAKE_ARGS=	USE_CODEC_OPUS=1
OPUS_MAKE_ARGS_OFF=	USE_CODEC_OPUS=0
OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
		libopusfile.so:audio/opusfile

MIKMOD_MAKE_ARGS=	USE_CODEC_MIKMOD=1
MIKMOD_MAKE_ARGS_OFF=	USE_CODEC_MIKMOD=0
MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod

XMP_MAKE_ARGS=	USE_CODEC_XMP=1
XMP_MAKE_ARGS_OFF=	USE_CODEC_XMP=0
XMP_LIB_DEPENDS=	libxmp.so:audio/xmp

MODPLUG_MAKE_ARGS=	USE_CODEC_MODPLUG=1
MODPLUG_MAKE_ARGS_OFF=	USE_CODEC_MODPLUG=0
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug

post-install:
	${MKDIR} ${STAGEDIR}${Q1DIR}
	${INSTALL_DATA} ${WRKSRC}/vkquake.pak ${STAGEDIR}${Q1DIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${FILESDIR}/vkquake.png ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${FILESDIR}/vkquake.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/vkquake.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
