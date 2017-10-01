# $FreeBSD$

PORTNAME=		goxel
DISTVERSIONPREFIX=	v
DISTVERSION=		0.7.1-70
DISTVERSIONSUFFIX=	-g193eded
CATEGORIES=		graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Free and Open Source 3D Voxel Editor

LICENSE=	GPLv3

LIB_DEPENDS=	libglfw.so:graphics/glfw \
		libargp.so:devel/argp-standalone \
		libpng16.so:graphics/png

USES=		scons compiler:c++11-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	guillaumechereau

USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_GL=	gl

INSTALLS_ICONS=	yes

MAKE_ARGS+=	clang=1 debug=0

do-install:
	${INSTALL} -s ${WRKSRC}/goxel ${STAGEDIR}${PREFIX}/bin/goxel
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/osx/goxel/goxel/Assets.xcassets/AppIcon.appiconset/32.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/goxel.png
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	${INSTALL_DATA} ${WRKSRC}/osx/goxel/goxel/Assets.xcassets/AppIcon.appiconset/64.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/64x64/apps/goxel.png
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	${INSTALL_DATA} ${WRKSRC}/osx/goxel/goxel/Assets.xcassets/AppIcon.appiconset/256.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/goxel.png
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
