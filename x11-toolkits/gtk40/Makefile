# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
# Please keep gtk40 in sync with the following x11-themes ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes
# when gnome is ported to gtk4

PORTNAME=	gtk
PORTVERSION=	3.93.0
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	4
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
#COMMENT=	Gimp Toolkit for X11 GUI (current stable version)
COMMENT=	Gimp Toolkit for X11 GUI (current unstable version)

LICENSE=	LGPL20

USES=		tar:xz

.if defined(REFERENCE_PORT)
PORTSCOUT=	ignore:1
.else
PORTSCOUT=	limit:1,even

BUILD_DEPENDS+=	at-spi2-atk>=0:accessibility/at-spi2-atk
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libgraphene-1.0.so:graphics/graphene \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS+=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
		at-spi2-atk>=0:accessibility/at-spi2-atk

USE_PERL5=	build
USE_LDCONFIG=	yes
USE_GNOME=	atk cairo gdkpixbuf2 introspection:build pango
USES+=		compiler:c11 gettext gnome localbase:ldflags meson \
		pathfix perl5 pkgconfig
MESON_ARGS=	-Denable-mir-backend=false \
		-Denable-win32-backend=false \
		-Denable-papi-print-backend=no \
		-Denable-vulkan=no \
		-Denable-quartz-backend=false
#INSTALLS_ICONS=	yes

LIBVERSION=	0.9300.0
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

GLIB_SCHEMAS=	org.gtk.Demo.gschema.xml \
		org.gtk.Settings.ColorChooser.gschema.xml \
		org.gtk.Settings.Debug.gschema.xml \
		org.gtk.Settings.EmojiChooser.gschema.xml \
		org.gtk.Settings.FileChooser.gschema.xml

# DOCS

OPTIONS_DEFINE=	CUPS CLOUDPRINT COLORD
OPTIONS_DEFAULT=CUPS COLORD BROADWAY X11
OPTIONS_SUB=	yes

BACKEND_DESC=	GDK backends
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	BROADWAY WAYLAND X11

BROADWAY_DESC=	Broadway (HTML5) GDK backend
BROADWAY_MESON_TRUE=	enable-broadway-backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_YES=	enable-colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_YES=	enable-cups-print-backend

CLOUDPRINT_DESC=	Cloud printing support
CLOUDPRINT_MESON_YES=	enable-cloudprint-print-backend
CLOUDPRINT_LIB_DEPENDS=	librest-0.7.so:devel/librest \
			libjson-glib-1.0.so:devel/json-glib

WAYLAND_DESC=		Wayland GDK backend (support Wayland applications)
WAYLAND_MESON_TRUE=	enable-wayland-backend
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols \
			v4l_compat>=0:multimedia/v4l_compat
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_RUN_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_USE=		GL=egl

X11_DESC=		X11 GDK backend (support X.org applications)
X11_MESON_TRUE=		enable-x11-backend
X11_USE=		XORG=x11,xcomposite,xcursor,xdamage,xext,xfixes,xi,xinerama,xrandr

DEBUG_DESC=	Debug related
OPTIONS_GROUP=	DEBUG
OPTIONS_GROUP_DEBUG=	DEMOS BUILDTEST INSTALLTEST

DEMOS_DESC=		Build demos and example programs
DEMOS_MESON_TRUE=	demos

BUILDTEST_DESC=		Build tests
BUILDTEST_MESON_TRUE=	build-tests

INSTALLTEST_DESC=	Install tests
INSTALLTEST_MESON_TRUE=	install-tests
INSTALLTEST_IMPLIES=	BUILDTEST

.include <bsd.port.options.mk>

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-xlib; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with X11 support enabled."; \
		${FALSE}; \
	fi
.if ${PORT_OPTIONS:MWAYLAND}
	@if ! pkg-config --exists wayland-egl; then \
		${ECHO_MSG} "${PKGNAME}: Needs mesa-libs build with wayland support enabled."; \
		${FALSE}; \
	fi
.endif

#post-install:
#	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/modules
#	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/engines
#	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/loaders
##	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-4.0.1 \
##		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

.endif
