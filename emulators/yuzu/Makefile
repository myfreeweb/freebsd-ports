# $FreeBSD$

PORTNAME=	yuzu
PORTVERSION=	s20180724
PORTREVISION?=	0
CATEGORIES=	emulators

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Nintendo Switch emulator/debugger

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSL GPLv2+ UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/externals/fmt/LICENSE.rst
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/externals/inih/inih/LICENSE.txt
LICENSE_FILE_BSL=	${WRKSRC}/externals/catch/LICENSE.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/license.txt

BROKEN_FreeBSD_10=	libc++ does not support C++17 features e.g., weak_from_this

BUILD_DEPENDS=	boost-libs>=1.66:devel/boost-libs \
		gmake:devel/gmake

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	https://github.com/MerryMage/dynarmic/issues/35

USE_GITHUB=	yes
GH_ACCOUNT=	yuzu-emu
GH_TAGNAME=	316c994f
GH_TUPLE=	MerryMage:dynarmic:fc6b73bd:dynarmic/externals/dynarmic \
		benhoyt:inih:r40:inih/externals/inih/inih \
		catchorg:Catch2:v2.2.3:catch/externals/catch \
		fmtlib:fmt:5.1.0:fmt/externals/fmt \
		lz4:lz4:v1.8.2:lz4/externals/lz4 \
		yuzu-emu:unicorn:73f4573:unicorn/externals/unicorn \
		herumi:xbyak:v5.65:xbyak/externals/xbyak

USES=		cmake compiler:c++14-lang iconv localbase:ldflags
USE_SDL=	sdl2
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # Qt5Network

OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	QT5 SDL
OPTIONS_SLAVE?=	SDL
OPTIONS_EXCLUDE:=	${OPTIONS_MULTI_GUI}

SDL_CMAKE_BOOL=	ENABLE_SDL2
SDL_PLIST_FILES=bin/${PORTNAME}-cmd

USE_QT=	qmake_build buildtools_build concurrent_build core gui multimedia opengl widgets
QT5_USES=	qt:5 desktop-file-utils shared-mime-info
QT5_CMAKE_BOOL=	ENABLE_QT
QT5_PLIST_FILES=bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/scalable/apps/${PORTNAME}.svg \
		share/mime/packages/${PORTNAME}.xml

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,' \
		-e '/check_submodules_present()/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's/@GIT_BRANCH@/master/' \
		-e 's/@GIT_DESC@/${GH_TAGNAME}/' \
		${WRKSRC}/src/common/scm_rev.cpp.in

.include <bsd.port.mk>
