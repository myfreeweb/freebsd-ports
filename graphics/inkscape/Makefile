# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inkscape
DISTVERSION=	1.0alpha
CATEGORIES=	graphics gnome
MASTER_SITES=	https://inkscape.org/gallery/item/13331/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Full featured open source SVG editor

LICENSE=	GPLv2+ GPLv3+ LGPL21 MPL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/GPL2.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/GPL3.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libpopt.so:devel/popt \
		libgc.so:devel/boehm-gc \
		libgdl-3.so:x11-toolkits/gdl \
		libgsl.so:math/gsl \
		libgtkspell3-3.so:textproc/gtkspell3 \
		liblcms2.so:graphics/lcms2 \
		libfribidi.so:converters/fribidi \
		libaspell.so:textproc/aspell \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpotrace.so:graphics/libpotrace \
		libpng.so:graphics/png \
<<<<<<< HEAD
=======
		libMagick++-6.so:graphics/ImageMagick6 \
>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3
		libsoup-2.4.so:devel/libsoup \
		libenchant-2.so:textproc/enchant2 \
		libyaml.so:textproc/libyaml

USES=		compiler:c++11-lib cmake cpe desktop-file-utils gnome \
<<<<<<< HEAD
		iconv:wchar_t jpeg pathfix pkgconfig python:2.7,build \
		shebangfix tar:bzip2
USE_GNOME=	gtkmm30 libxml2 libxslt gvfs
USE_XORG=	x11 sm ice xext
=======
		iconv:wchar_t jpeg pathfix pkgconfig python:2.7 \
		shebangfix tar:bzip2 xorg
USE_GNOME=	gtkmm30 gvfs libxml2 libxslt
USE_XORG=	x11 sm ice xext # XXX

>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3
INSTALLS_ICONS=	yes

USE_GITLAB=	nodefault
GL_TUPLE=	${PORTNAME}:extensions:962aaed9c92965739493da981f6e80062b572358:extensions/share/extensions

python_CMD?=	${LOCALBASE}/bin/python2
SHEBANG_FILES=	share/extensions/*.py share/extensions/genpofiles.sh \
								share/templates/create_defaults.pl man/fix-roff-punct

OPTIONS_DEFINE=	POPPLER VISIO CDR DBUS WPG
OPTIONS_DEFAULT=POPPLER VISIO CDR WPG GM
OPTIONS_SINGLE=		IMAGICK
OPTIONS_SINGLE_IMAGICK=	IMAGICK6 GM
OPTIONS_SUB=	yes

CDR_DESC=		Support for CorelDRAW diagrams
CDR_CMAKE_BOOL=		WITH_LIBCDR
CDR_LIB_DEPENDS=	librevenge-stream-0.0.so:textproc/librevenge \
			libcdr-0.1.so:graphics/libcdr01

DBUS_CMAKE_BOOL=	WITH_DBUS
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
			libdbus-1.so:devel/dbus

#OPENMP_USES=		compiler:openmp
#OPENMP_USES_OFF=	compiler:c++11-lib
#OPENMP_CMAKE_BOOL=	WITH_OPENMP
CMAKE_ARGS+=		-DWITH_OPENMP:BOOL=NO

POPPLER_DESC=		PDF preview rendering
POPPLER_CMAKE_BOOL=	ENABLE_POPPLER ENABLE_POPPLER_CAIRO
POPPLER_LIB_DEPENDS=	libpoppler.so:graphics/poppler \
			libpoppler-glib.so:graphics/poppler-glib

VISIO_DESC=		Support for Microsoft Visio diagrams
VISIO_CMAKE_BOOL=	WITH_LIBVISIO
VISIO_LIB_DEPENDS=	librevenge-stream-0.0.so:textproc/librevenge \
			libvisio-0.1.so:textproc/libvisio01

WPG_DESC=		Support for WordPerfect graphics
WPG_CMAKE_BOOL=		WITH_LIBWPG
WPG_LIB_DEPENDS=	libwpg-0.3.so:graphics/libwpg03

IMAGICK_DESC=		Raster image format library
IMAGICK6_DESC=	Use ImageMagick6
IMAGICK6_LIB_DEPENDS=	libMagick++-6.so:graphics/ImageMagick6
GM_DESC=	Use GraphicsMagick
GM_LIB_DEPENDS=		libGraphicsMagick.so:graphics/GraphicsMagick
GM_CMAKE_OFF=	WITH_IMAGE_MAGICK

# temporary until the build works for the !NLS case
USES+=			gettext
#NLS_CMAKE_BOOL=		WITH_NLS
#NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|COMMAND python|COMMAND ${PYTHON_VERSION}|g' \
		${WRKSRC}/share/*/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|web-set-att|web_set_att|g' \
		${WRKSRC}/po/*
	@${REINPLACE_CMD} -e 's|web-transmit-att|web_transmit_att|g' \
		${WRKSRC}/po/*
	@${TOUCH} ${WRKSRC}/share/extensions/gcodetools_check_for_updates.inx.h

.include <bsd.port.mk>
