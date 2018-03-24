# $FreeBSD$

PORTNAME=		solvespace
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.rc1-417
DISTVERSIONSUFFIX=	-gc6fc012
CATEGORIES=		cad

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Parametric 2d/3d CAD

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libjson-c.so:devel/json-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++11"

USE_GITHUB=	yes
GH_PROJECT=	libdxfrw:libdxfrw
GH_TAGNAME=	87ff108:libdxfrw
GH_SUBDIR=	extlib/libdxfrw:libdxfrw

USES=		cmake:outsource pkgconfig
USE_GL=		gl glu glew
USE_GNOME=	atkmm pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_RADIO=		GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

GTK2_USE=		GNOME=gtk20
GTK2_LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

GTK3_USE=		GNOME=gtk30
GTK3_LIB_DEPENDS=	libgtkmm-3.0.so:x11-toolkits/gtkmm30
GTK3_CMAKE_ON=		-DGUI=gtk3

.include <bsd.port.mk>
