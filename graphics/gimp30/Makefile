# $FreeBSD$

PORTNAME=	gimp
PKGNAMESUFFIX=  30
DISTVERSION=	2.99.4
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GNU Image Manipulation Program

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		glib-networking>=0:net/glib-networking \
		xsltproc:textproc/libxslt \
		bash:shells/bash \
		mypaint-brushes>0:graphics/mypaint-brushes
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libappstream-glib.so:devel/appstream-glib \
		libasound.so:audio/alsa-lib \
		liblcms2.so:graphics/lcms2 \
		libgegl-0.4.so:graphics/gegl \
		libbabl-0.1.so:x11/babl \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libpoppler-glib.so:graphics/poppler-glib \
		libgexiv2.so:graphics/gexiv2 \
		libjson-c.so:devel/json-c \
		libmypaint.so:graphics/libmypaint \
		libfreetype.so:print/freetype2 \
		libheif.so:graphics/libheif \
		libIlmImf.so:graphics/openexr \
		libIex.so:graphics/ilmbase \
		libopenjp2.so:graphics/openjpeg \
		libwebp.so:graphics/webp \
		libwmf.so:graphics/libwmf \
		libgudev-1.0.so:devel/libgudev

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		glib-networking>=0:net/glib-networking \
		gjs-console:lang/gjs \
		mypaint-brushes>0:graphics/mypaint-brushes

LIB_DEPENDS+=	libjson-glib-1.0.so:devel/json-glib \
		${LIB_DEPENDS_${ARCH}}

LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind

MESON_ARGS=	-Dgtk-doc=false \
		-Dicc-directory=/usr/local/share/color/icc \
		-Dcheck-update=false \
		-Dlua=true \
		-Djavascript=true \
		-Dpython=true \
		-Dcairo-pdf=enabled \
		-Dgudev=enabled \
		-Dheif=enabled \
		-Djpeg=enabled \
		-Djpeg2000=enabled \
		-Dmng=disabled \
		-Dopenexr=enabled \
		-Dpng=enabled \
		-Dprint=true \
		-Dscreenshot=enabled \
		-Dtiff=enabled \
		-Dwebkit=disabled \
		-Dwebp=enabled \
		-Dwmf=enabled \
		-Dxcursor=enabled \
		-Dxpm=enabled \
		-Dlinux-input=enabled

USES+=		compiler:c++14-lang cpe desktop-file-utils gettext ghostscript gnome jpeg \
		libarchive localbase meson pkgconfig perl5 python:3.5+ shebangfix xorg
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME
GL_COMMIT=	db996f218da437beecee233a25e5444169d41939
USE_GNOME+=	cairo gtk30 intltool librsvg2 pygobject3
USE_XORG=	xcursor xpm x11 xmu xext xfixes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}
SHEBANG_FILES=	plug-ins/*/*.py plug-ins/*/*/*.py extensions/*/*.js app/tests/*.sh
SHEBANG_LANG=	gjs

CPE_PRODUCT=	gimp
CPE_VENDOR=	gnu

.include <bsd.port.mk>
