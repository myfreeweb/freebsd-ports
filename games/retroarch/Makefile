# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	RetroArch
PORTVERSION=	1.7.5 # sync with games/libretro-core-info
DISTVERSIONPREFIX=	v
CATEGORIES=	games emulators

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform entertainment system based on libretro API

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libdrm.so:graphics/libdrm \
		libass.so:multimedia/libass
RUN_DEPENDS=	retroarch-assets<=0:games/retroarch-assets

BROKEN_powerpc64=	fails to compile: features_cpu.c: undefined reference to __mftb

OPTIONS_DEFINE=	FFMPEG OSS JACK PULSEAUDIO ALSA SDL OPENGL OPENAL PYTHON V4L FREETYPE WAYLAND UDEV QT
OPTIONS_DEFAULT=FFMPEG OSS PULSEAUDIO SDL OPENGL OPENAL PYTHON V4L FREETYPE WAYLAND UDEV QT
FFMPEG_DESC=	On-the-fly recording of gameplay with libavcodec
PYTHON_DESC=	Script support in shaders
WAYLAND_DESC=	Wayland display support
UDEV_DESC=	udev device hotplug support
QT_DESC=	Qt based desktop-style GUI

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=ffmpeg
OSS_CONFIGURE_ENABLE=	oss
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
SDL_USE=		SDL=sdl2,image2
SDL_CONFIGURE_ON=	--disable-sdl --enable-sdl2
SDL_CONFIGURE_OFF=	--disable-sdl --disable-sdl2
OPENGL_USES=		gl
OPENGL_USE=		GL=gl,egl,gbm
OPENGL_CONFIGURE_ENABLE=opengl
OPENAL_USES=		openal:soft
OPENAL_CONFIGURE_ENABLE=al
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python:3.6
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=	v4l2
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
			${LOCALBASE}/include/linux/kd.h:graphics/svgalib
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libwayland-server.so:graphics/wayland \
			libwayland-egl.so:graphics/mesa-libs
WAYLAND_CONFIGURE_ENABLE=	wayland
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
			libepoll-shim.so:devel/libepoll-shim
UDEV_CFLAGS=		-I${LOCALBASE}/include/libepoll-shim
UDEV_LDFLAGS=		-lepoll-shim
UDEV_CONFIGURE_ENABLE=	udev
QT_USES=		qt:5
QT_USE=			QT=core,gui,widgets,concurrent,network
QT_CONFIGURE_ENABLE=	qt

CONFIGURE_ARGS+=--enable-threads --disable-discord
CONFIGURE_ENV+=	MAN_DIR=${MANPREFIX}/man

USES=		compiler:c++11-lib gmake pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	libretro
SUB_FILES=	pkg-message
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--global-config-dir=${LOCALBASE}/etc
USE_XORG=	x11 xcb xext xinerama xv xxf86vm
LLD_UNSAFE=	yes
CFLAGS=		-fPIC
SHEBANG_FILES=	libretro-common/glsym/glgen.py libretro-common/glsym/rglgen.py tools/cg2glsl.py tools/vulkan_loader_generator.py

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c \
		${WRKSRC}/gfx/drivers/*.c \
		${WRKSRC}/libretro-common/libco/armeabi.c \
		${WRKSRC}/memory/wii/mem2_manager.c
	@${REINPLACE_CMD} -e 's|<asm/types.h>|<sys/types.h>|' \
		${WRKSRC}/camera/drivers/video4linux2.c
	@${REINPLACE_CMD} -e '/^add_define_make DYLIB_LIB/s|$$|;\
		add_include_dirs ${LOCALBASE}/include;\
		add_library_dirs ${LOCALBASE}/lib| ; \
		/^check_lib OSS_LIB/d' \
		${WRKSRC}/qb/config.libs.sh

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e '/check_pkgconf PYTHON/s/python3/python-${PYTHON_VER}/' \
		${WRKSRC}/qb/config.libs.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/retroarch
	@${REINPLACE_CMD} \
		-e 's|# libretro_directory =|libretro_directory = "${PREFIX}/lib/libretro"|' \
		-e 's|# libretro_info_path =|libretro_info_path = "${PREFIX}/share/libretro/info"|' \
		-e 's|# assets_directory =|assets_directory = "${PREFIX}/share/libretro/assets"|' \
		-e 's|# video_shader_dir =|video_shader_dir = "${PREFIX}/share/libretro/shaders"|' \
		-e 's|# video_filter_dir =|video_filter_dir = "${PREFIX}/lib/retroarch/filters/video"|' \
		-e 's|# audio_filter_dir =|audio_filter_dir = "${PREFIX}/lib/retroarch/filters/audio"|' \
		-e 's|# joypad_autoconfig_dir =|joypad_autoconfig_dir = "${PREFIX}/share/retroarch/autoconfig"|' \
		-e 's|# menu_show_core_updater = true|menu_show_core_updater = false|' \
		${STAGEDIR}${PREFIX}/etc/retroarch.cfg

.include <bsd.port.mk>
