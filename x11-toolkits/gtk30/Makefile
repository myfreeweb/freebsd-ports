# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# Please keep gtk30 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes

PORTNAME=	gtk
PORTVERSION=	3.24.29
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	3
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/commit/
PATCHFILES+=	70064c52f445ca83f83e0f7f2c6a90e00279b095.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	04ffe8e9a68cdf0e39aae6bc814c4227f281cbc9.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	ee6243393334f1134b1f03f54c90d27838bb5fe9.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	d5bcf6ab9479e21bf7c9776c985af89f61e23f62.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	d57313f9a4fa129e80a48bf26d37ab89f7f10e71.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1117
PATCHFILES+=	5b1824edc4726ad48106c3a7969746f43978886d.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1562
PATCHFILES+=	0bad120c2029b93fd3139211908daf63849d26f9.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1562
PATCHFILES+=	717e08fe45c52f07ff216b04d0eac943afdbbe2b.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1562
PATCHFILES+=	be0989f0f511ea99b0392563ac72c286143697e7.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1562
PATCHFILES+=	ae89e8e8551ec3b28b28f0e9d1f3013da7674467.patch:-p1 # https://gitlab.gnome.org/GNOME/gtk/-/merge_requests/1562

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LICENSE=	LGPL20

PORTSCOUT=	limit:1,even

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS+=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme

USE_PERL5=	build
USE_LDCONFIG=	yes
USE_GNOME=	atk cairo gdkpixbuf2 introspection:build pango \
		librsvg2:run
USES=		compiler:c11 gettext gnome meson localbase:ldflags \
		pathfix perl5 python:3.5+ pkgconfig shared-mime-info tar:xz
CPPFLAGS+=	-fno-omit-frame-pointer
INSTALLS_ICONS=	yes

LIBVERSION=	0.2404.25
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.EmojiChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	ATK_BRIDGE CUPS CLOUDPRINT COLORD DEBUG BROADWAY WAYLAND X11
OPTIONS_DEFAULT=ATK_BRIDGE CUPS COLORD BROADWAY WAYLAND X11
OPTIONS_SUB=	yes

ATK_BRIDGE_DESC=AT-SPI ATK bridge support (requires X11)
ATK_BRIDGE_LIB_DEPENDS=	libatk-bridge-2.0.so:accessibility/at-spi2-atk
ATK_BRIDGE_IMPLIES=	X11

BROADWAY_DESC=	Enable GDK Broadway backend for showing GTK+ in the webbrowser using HTML5 and web sockets.
BROADWAY_MESON_TRUE=	broadway_backend

COLORD_DESC=	Color profile support
COLORD_MESON_YES=colord
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_ENABLE=	cups

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_MESON_ON=	
CLOUDPRINT_USE=		gnome=libxml2
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:devel/librest \
			libsoup-2.4.so:devel/libsoup \
			libjson-glib-1.0.so:devel/json-glib

WAYLAND_DESC=		GDK Wayland backend
WAYLAND_MESON_TRUE=	wayland_backend
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_USES=		gl
WAYLAND_USE=		GL=egl

X11_DESC=		GDK X11 backend
X11_MESON_TRUE=	x11_backend
X11_USES=		xorg
X11_USE=		XORG=x11,xcomposite,xcursor,xdamage,xext,xfixes,xi,xinerama,xrandr,xrender

.include <bsd.port.options.mk>

PRINT_BACKENDS+=	file
.if ${PORT_OPTIONS:MCUPS}
PRINT_BACKENDS+=	cups
.endif
.if ${PORT_OPTIONS:MCLOUDPRINT}
PRINT_BACKENDS+=	cloudprint
.endif

MESON_ARGS+=	-Dprint_backends="${PRINT_BACKENDS:ts,}"

pre-configure-X11-on:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi

post-patch:
	${REINPLACE_CMD} \
		"s/find_program('check-version.py')/find_program('echo')/" \
		${WRKSRC}/meson.build

pre-build:
	@${RM} -r ${WRKSRC}/docs/gtk.info*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/engines
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-3.0/${GTK3_VERSION}/loaders
	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-3.0.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
