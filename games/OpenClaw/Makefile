# $FreeBSD$

PORTNAME=		OpenClaw
DISTVERSION=		1.0-29
DISTVERSIONSUFFIX=	-g49c28d9
CATEGORIES=		games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Reimplementation of Captain Claw (1997) platformer

LICENSE=	GPLv3

LIB_DEPENDS=	libtinyxml.so:textproc/tinyxml

USES=		cmake:outsource compiler:c++11-lang pkgconfig localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	pjasicek

USE_SDL=	image2 mixer2 ttf2 gfx2

SUB_FILES=	pkg-message
DATADIR=	${LOCALBASE}/share/openclaw

do-install:
	${INSTALL} -s ${WRKSRC}/../Build_Release/openclaw \
			${STAGEDIR}${PREFIX}/bin/openclaw
	${INSTALL} ${WRKSRC}/Build_Release/ClawLauncher.exe \
			${STAGEDIR}${PREFIX}/bin/ClawLauncher.exe
	${SED} -e 's|/usr/share/openclaw|${DATADIR}|g' \
		${WRKSRC}/Build_Release/clawlauncher > \
		${WRKSRC}/Build_Release/clawlauncher_freebsd
	${INSTALL} ${WRKSRC}/Build_Release/clawlauncher_freebsd \
			${STAGEDIR}${PREFIX}/bin/clawlauncher
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Build_Release/ASSETS.ZIP \
			${STAGEDIR}${DATADIR}/ASSETS.ZIP
	${INSTALL_DATA} ${WRKSRC}/Build_Release/clacon.ttf \
			${STAGEDIR}${DATADIR}/clacon.ttf
	${INSTALL_DATA} ${WRKSRC}/Build_Release/console02.tga \
			${STAGEDIR}${DATADIR}/console02.tga
	${INSTALL_DATA} ${WRKSRC}/Build_Release/SAVES.XML \
			${STAGEDIR}${DATADIR}/SAVES.XML
	${SED} -e 's|/usr/share/openclaw|${DATADIR}|g' \
			${WRKSRC}/Build_Release/config_linux_release.xml > \
			${WRKSRC}/Build_Release/config_freebsd_release.xml
	${INSTALL_DATA} ${WRKSRC}/Build_Release/config_freebsd_release.xml \
			${STAGEDIR}${DATADIR}/config.xml

.include <bsd.port.mk>
