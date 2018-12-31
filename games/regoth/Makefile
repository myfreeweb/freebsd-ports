# $FreeBSD$

PORTNAME=		regoth
DISTVERSIONPREFIX=	nightly-
DISTVERSION=		0.4.189
CATEGORIES=		games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Reimplementation of zEngine, the Gothic and Gothic II engine

LICENSE=	GPLv3

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lib openal

USE_GITHUB=	yes
GH_ACCOUNT=	REGoth-project
GH_PROJECT=	REGoth
GH_TUPLE=	ataulien:bgfx-cmake:9a9b596:bgfxcmake/lib/bgfx-cmake \
		bkaradzic:bgfx:c0cf484:bgfx \
		bkaradzic:bimg:224aa80:bimg \
		bkaradzic:bx:4b4b3e7:bx \
		ataulien:ZenLib:3a8e919:zenlib/lib/ZenLib \
		tito:libsquish:f5e44a3:libsquish \
		REGoth-project:physfs:4174d6a:physfs \
		g-truc:glm:06f0840:glm/lib/glm \
		glfw:glfw:0f488ac:glfw/lib/glfw \
		cxong:tinydir:0862ba9:tinydir/lib/tinydir \
		bulletphysics:bullet3:fb51c3f:bullet3/lib/bullet3 \
		frabert:libdmusic:e193ef4:libdmusic/lib/libdmusic \
		erikd:libsndfile:cf7a818:libsndfile \
		gocha:sf2cute:fcaf333:sf2cute \
		REGoth-project:CAB-Installer-Extractor:a311fea:cab/lib/CAB-Installer-Extractor

USE_XORG=	sm ice xext x11 xrandr xinerama xcursor
USE_GL=		gl glu
LLD_UNSAFE=	yes # OpenAL https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=219089
CMAKE_ARGS+=	-DREGOTH_BUILD_WITH_SYSTEM_OPENAL:BOOL=YES

post-extract:
	${MV} ${WRKSRC_bgfx}/* ${WRKSRC}/lib/bgfx-cmake/bgfx
	${MV} ${WRKSRC_bimg}/* ${WRKSRC}/lib/bgfx-cmake/bimg
	${MV} ${WRKSRC_bx}/* ${WRKSRC}/lib/bgfx-cmake/bx
	${MV} ${WRKSRC_libsquish}/* ${WRKSRC}/lib/ZenLib/lib/libsquish
	${MV} ${WRKSRC_physfs}/* ${WRKSRC}/lib/ZenLib/lib/physfs
	${MV} ${WRKSRC_libsndfile}/* ${WRKSRC}/lib/libdmusic/utils/dls2sf/lib/libsndfile
	${MV} ${WRKSRC_sf2cute}/* ${WRKSRC}/lib/libdmusic/utils/dls2sf/lib/sf2cute

post-patch:
	${RM} ${WRKSRC}/lib/bgfx-cmake/bx/include/compat/freebsd/dirent.h # the real one is needed by tinydir

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/shaders/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/REGoth ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/bin/shaders/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/shaders/)
	${CAT} ${FILESDIR}/launcher.sh | ${SED} -e "s|%%DATADIR%%|${DATADIR}|" > \
		${STAGEDIR}${PREFIX}/bin/REGoth
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/REGoth

.include <bsd.port.mk>
