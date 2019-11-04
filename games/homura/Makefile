# Created by: Alexander Vereeken <Alexander88207@protonmail.com>
# $FreeBSD$

PORTNAME=	homura
PORTVERSION=	2.6
CATEGORIES=	games

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=        Windows Games Launcher for FreeBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=   zenity:x11/zenity xdg-open:devel/xdg-utils curl:ftp/curl bash:shells/bash 7z:archivers/p7zip webfonts>=0:x11-fonts/webfonts winetricks:emulators/winetricks vulkaninfo:devel/vulkan-tools glxinfo:graphics/mesa-demos

USE_GITHUB=	yes
GH_ACCOUNT=	the-homura-project

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=    /usr/local/bin/Homura

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Homura ${STAGEDIR}/usr/local/bin

.include <bsd.port.mk>


