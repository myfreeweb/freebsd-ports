# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME?=	gimp-app
DISTVERSION=	2.99.0-20180311
PORTEPOCH?=	1
CATEGORIES?=	graphics gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Image Manipulation Program

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		liblcms2.so:graphics/lcms2 \
		libgegl-0.4.so:graphics/gegl \
		libmypaint-2.0.so:graphics/libmypaint \
		libbabl-0.1.so:x11/babl \
		libwebp.so:graphics/webp \
		libgexiv2.so:graphics/gexiv2 \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes

USE_GITHUB=	yes
GH_ACCOUNT=	GNOME
GH_PROJECT=	gimp
GH_TAGNAME=	78c6be7ffbb

USES+=		cpe gettext meson jpeg libtool \
		pathfix pkgconfig shebangfix
USE_XORG=	ice sm xcursor xext xfixes xmu xpm xt x11
USE_GNOME+=	cairo gtk30 librsvg2 intlhack
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dsysconfdir=${PREFIX}/etc \
						-Dwith-python=false \
						-Dwith-alsa=false \
						-Dwith-linux-input=false \
						-Dwith-xvfb-run=false
CPE_PRODUCT=	gimp
CPE_VENDOR=	gnu

PLIST_SUB+=	LIBVER=0.9900.0

.if !defined(GIMP_SLAVE)

USES+=		desktop-file-utils

OPTIONS_DEFINE?=	AA GHOSTSCRIPT HELPBROWSER JASPER \
			LIBMNG POPPLER WMF OPENEXR
OPTIONS_DEFAULT=	AA GHOSTSCRIPT JASPER \
			LIBMNG POPPLER WMF OPENEXR
OPTIONS_SUB=		yes
AA_DESC=		Ascii-art Plug-in
HELPBROWSER_DESC=	Internal help browser

.endif

.if defined(GIMP_SLAVE)
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GIMP_LIBS=	`${PKG_CONFIG} --libs gimp-2.0`
GIMP_THUMB_LIBS=`${PKG_CONFIG} --libs gimpthumb-2.0`
GIMP_UI_LIBS=	`${PKG_CONFIG} --libs gimpui-2.0`

LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app

.else

AA_LIB_DEPENDS=		libaa.so:graphics/aalib
AA_MESON_OFF=	-Dwith-aa=false

GHOSTSCRIPT_USES=		ghostscript
GHOSTSCRIPT_MESON_OFF=	-Dwith-ghostscript=false

HELPBROWSER_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
				libsoup-2.4.so:devel/libsoup
HELPBROWSER_MESON_ON=	-Dwith-webkit=true

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_MESON_OFF=	-Dwith-jasper=false

LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng
LIBMNG_MESON_OFF=	-Dwith-mng=false

POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
POPPLER_MESON_OFF=	-Dwith-poppler=false

WMF_LIB_DEPENDS=	libwmf.so:graphics/libwmf
WMF_MESON_OFF=	-Dwith-wmf=false

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/OpenEXR
OPENEXR_MESON_OFF=	-Dwith-openexr=false

.endif

.include <bsd.port.mk>
