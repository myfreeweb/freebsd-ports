# $FreeBSD$

PORTNAME=	wx
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	31-${FLAVOR}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI toolkit (wxWidgets) with GTK+ bindings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/gpl.txt

FLAVORS=	gtk2 gtk3
FLAVOR?=	${FLAVORS:[1]}

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjbig.so:graphics/jbigkit \
		libnotify.so:devel/libnotify \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libtiff.so:graphics/tiff \

USES=		compiler:c++11-lib gmake iconv jpeg localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	wxWidgets
GH_PROJECT=	wxWidgets
GNU_CONFIGURE=	yes
USE_XORG=	x11 sm xxf86vm xtst
USE_GL=		gl glu
USE_GNOME=	cairo gdkpixbuf2
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
CONFIGURE_ARGS=	--with-libpng=sys \
		--with-libjpeg=sys \
		--with-libtiff=sys \
		--with-zlib=sys \
		--with-expat=sys \
		--with-opengl \
		--without-gnomevfs \
		--disable-epollloop \
		--disable-joystick \
		--enable-backtrace \
		--enable-ipv6 \
		--enable-optimise \
		--enable-utf8 \
		--enable-graphics_ctx \
		--enable-compat28 \
		--enable-compat30
CONFIGURE_ENV=	X11BASE="${LOCALBASE}" \
		ac_cv_header_sys_inotify_h=no
PLIST_SUB=	FLAVOR="${FLAVOR}"

OPTIONS_DEFINE=		GSTREAMER MSPACK NLS WEBKIT
OPTIONS_DEFAULT=	GSTREAMER MSPACK WEBKIT
MSPACK_DESC=		Microsoft archives support
OPTIONS_SUB=		yes

NLS_USES=			gettext

GSTREAMER_CONFIGURE_ENABLE=	mediactrl
GSTREAMER_USE=			GNOME=gconf2 GSTREAMER1=bad

MSPACK_CONFIGURE_WITH=		libmspack
MSPACK_LIB_DEPENDS=		libmspack.so:archivers/libmspack

WEBKIT_CONFIGURE_ENABLE=	webview

.if ${FLAVOR} == gtk2
CONFIGURE_ARGS+=	--with-gtk=2
USE_GNOME+=		gtk20
PLIST_SUB+=		GTK2="" GTK3="@comment "
WEBKIT_LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2
.else
CONFIGURE_ARGS+=	--with-gtk=3
USE_GNOME+=		gtk30
PLIST_SUB+=		GTK2="@comment " GTK3=""
WEBKIT_LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
.endif

.include <bsd.port.pre.mk>

# PR 196703, 197031
.if ${CHOSEN_COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=--disable-precomp-headers
.endif

post-build-NLS-on:
	@${DO_MAKE_BUILD} allmo -C ${BUILD_WRKSRC}/locale

.include <bsd.port.post.mk>
