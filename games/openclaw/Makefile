# $FreeBSD$

PORTNAME=	openclaw
DISTVERSION=	1.0-29
DISTVERSIONSUFFIX=	-g49c28d9
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Reimplementation of Captain Claw (1997) platformer

LICENSE=	GPLv3

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml

USE_GITHUB=	yes
GH_ACCOUNT=	pjasicek
GH_PROJECT=	OpenClaw

USES=		cmake compiler:c++11-lib pkgconfig localbase:ldflags
USE_SDL=	image2 mixer2 ttf2 gfx2

PLIST_FILES=	bin/ClawLauncher.exe \
		bin/clawlauncher \
		bin/openclaw
PORTDATA=	ASSETS.ZIP SAVES.XML clacon.ttf config.xml console02.tga
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} '/CMAKE_RUNTIME_OUTPUT_DIRECTORY/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/share/openclaw|${DATADIR}|g' \
		${WRKSRC}/Build_Release/clawlauncher \
		${WRKSRC}/Build_Release/config_linux_release.xml

pre-build:
	cd ${WRKSRC}/Build_Release; ${CP} config_linux_release.xml config.xml

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Build_Release/clawlauncher \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Build_Release/ClawLauncher.exe \
		${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/Build_Release && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
