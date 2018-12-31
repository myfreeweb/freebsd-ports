PORTNAME=		solvespace
DISTVERSIONPREFIX=	v
CATEGORIES=	cad
DISTVERSION=		2.1.rc1-739
DISTVERSIONSUFFIX=	-g188b2e2
CATEGORIES=		cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parametric 2d/3d CAD

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libjson-c.so:devel/json-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_TUPLE=	solvespace:libdxfrw:03fa5f30f:libdxfrw/extlib/libdxfrw \
		q3k:q3d:880db1d3:q3d/extlib/q3d \
		microsoft:mimalloc:07c6e60a:mimalloc/extlib/mimalloc \
		google:flatbuffers:f73d205b:flatbuffers/extlib/flatbuffers

USES=		cmake compiler:c++11-lang gl gnome pkgconfig xorg \
			desktop-file-utils shared-mime-info

USE_GL=		gl glu glew
USE_GNOME=	atkmm pangomm
USE_XORG=	x11
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

LDFLAGS=	-lexecinfo

post-patch:
	${REINPLACE_CMD} -e '/-stdlib=libc++/d' ${WRKSRC}/CMakeLists.txt

OPTIONS_RADIO=		GTK
OPTIONS_RADIO_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

GTK2_USE=		GNOME=gtk20
GTK2_LIB_DEPENDS=	libgtkmm-2.4.so:x11-toolkits/gtkmm24

GTK3_USE=		GNOME=gtk30
GTK3_LIB_DEPENDS=	libgtkmm-3.0.so:x11-toolkits/gtkmm30
GTK3_CMAKE_ON=		-DGUI=gtk3

.include <bsd.port.mk>
