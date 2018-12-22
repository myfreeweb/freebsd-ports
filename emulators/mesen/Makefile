# $FreeBSD$

PORTNAME=	mesen
DISTVERSION=	0.9.7
CATEGORIES=	emulators

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Cross-platform Nintendo Entertainment System (NES/Famicom) emulator

LICENSE=	GPLv3

# ARM/MIPS are only supported on Android
ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libgdiplus.so:x11-toolkits/libgdiplus

USES=		compiler:c++14-lang gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	SourMesen
GH_PROJECT=	Mesen
USE_SDL=	sdl2
MAKEFILE=	makefile
MAKE_ARGS=	MESENPLATFORM=${MESEN_ARCH} LTO=true SYSTEM_LIBEVDEV=true FSLIB=-lc++experimental
MESEN_ARCH=	${ARCH:S/amd64/x64/:S/i386/x86/}

OPTIONS_MULTI=			FRONTENDS
OPTIONS_MULTI_FRONTENDS=	MONO LIBRETRO
OPTIONS_DEFAULT=		MONO LIBRETRO
OPTIONS_SUB=			yes

MONO_DESC=	Mono based GUI frontend
LIBRETRO_DESC=	Libretro core

MONO_ALL_TARGET=	ui
MONO_BUILD_DEPENDS=	mono:lang/mono
MONO_RUN_DEPENDS=	mono:lang/mono
MONO_DESKTOP_ENTRIES=	"Mesen" "NES/Famicom Emulator" \
			"${PORTNAME}" "${PORTNAME}" "emulator;Nintendo;NES;Famicom;" false

LIBRETRO_ALL_TARGET=	libretro

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MMONO}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/mesen
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/
	${INSTALL_LIB} ${WRKSRC}/bin/${MESEN_ARCH}/Release/Dependencies/libMesenCore.${MESEN_ARCH}.dll \
			${STAGEDIR}${PREFIX}/libexec/mesen/libMesenCore.dll
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${MESEN_ARCH}/Release/Mesen.exe \
			${STAGEDIR}${PREFIX}/libexec/mesen/
	${INSTALL_DATA} ${WRKSRC}/GUI.NET/Resources/MesenIcon.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/mesen.png
	${INSTALL_DATA} ${WRKSRC}/GUI.NET/Resources/MesenIconMedium.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/mesen.png
	${INSTALL_DATA} ${WRKSRC}/GUI.NET/Resources/MesenIconSmall.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/mesen.png
	${INSTALL_SCRIPT} ${FILESDIR}/launch.sh ${STAGEDIR}${PREFIX}/bin/mesen
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' ${STAGEDIR}${PREFIX}/bin/mesen
.endif
.if ${PORT_OPTIONS:MLIBRETRO}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/libretro
	${INSTALL_LIB} ${WRKSRC}/bin/mesen_libretro.${MESEN_ARCH}.so \
			${STAGEDIR}${PREFIX}/lib/libretro/mesen_libretro.so
.endif

.include <bsd.port.mk>
