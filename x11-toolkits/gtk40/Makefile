# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$
# Please keep gtk40 in sync with the following ports:
# misc/gtk-gettext (shared gettext files)
# Theme ports:
# adwaita-icon-theme, gnome-themes-standard and mate-themes
# when gnome is ported to gtk4

PORTNAME=	gtk
PORTVERSION=	3.94.0
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMESUFFIX=	4
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
#COMMENT=	Gimp Toolkit for X11 GUI (current stable version)
COMMENT=	Gimp Toolkit for X11 GUI (current unstable version)

LICENSE=	LGPL20

PORTSCOUT=	limit:1,even

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libgraphene-1.0.so:graphics/graphene \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
#RUN_DEPENDS+=	hicolor-icon-theme>=0:misc/hicolor-icon-theme \
BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
#		adwaita-icon-theme>=0:x11-themes/adwaita-icon-theme \
#		at-spi2-atk>=0:accessibility/at-spi2-atk

# optional?

USE_LDCONFIG=	yes
#USE_GNOME=	atk cairo gdkpixbuf2 introspection:build pango
USE_GNOME=	atk cairo gdkpixbuf2 pango
USES=		compiler:c11 gettext gnome localbase:ldflags meson \
		pathfix perl5 python:3.5+ pkgconfig tar:xz
USE_PERL5=	build
MESON_ARGS=	-Dwin32-backend=false \
		-Dquartz-backend=false \
		-Db_lundef=false
#INSTALLS_ICONS=	yes

LIBVERSION=	0.9400.0
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

BINARY_ALIAS=	python3=${PYTHON_VERSION}

# TODO?
# meson:
# documentation, man-pages

#CLOUDPROVIDERS
OPTIONS_DEFINE=	CUPS COLORD VULKAN GSTREAMER
OPTIONS_DEFAULT=CUPS COLORD BROADWAY X11 WAYLAND VULKAN GSTREAMER
OPTIONS_SUB=	yes

BACKEND_DESC=	GDK backends
OPTIONS_MULTI=	BACKEND
OPTIONS_MULTI_BACKEND=	BROADWAY WAYLAND X11

BROADWAY_DESC=	Broadway (HTML5) GDK backend
BROADWAY_MESON_TRUE=	broadway-backend

COLORD_DESC=	Color profile support
COLORD_LIB_DEPENDS=	libcolord.so:graphics/colord
COLORD_MESON_YES=	colord

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_MESON_ON=		-Dprint-backends=cups,file
CUPS_MESON_OFF=		-Dprint-backends=file

MESON_ARGS+=-Dcloudproviders=false
#CLOUDPROVIDERS_DESC=		Cloudproviders suport
#CLOUDPROVIDERS_MESON_TRUE=	cloudproviders
#CLOUDPROVIDERS_LIB_DEPENDS=	librest-0.7.so:devel/librest \
#				libjson-glib-1.0.so:devel/json-glib

GSTREAMER_MESON_ON=	-Dmedia=gstreamer
GSTREAMER_MESON_OFF=	-Dmedia=none
GSTREAMER_USE=		gstreamer1=bad

WAYLAND_DESC=		Wayland GDK backend (support Wayland applications)
WAYLAND_MESON_TRUE=	wayland-backend
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_USE=		GL=egl

X11_DESC=		X11 GDK backend (support X.org applications)
X11_MESON_TRUE=		x11-backend
X11_MESON_YES=		xinerama
X11_USE=		XORG=x11,xcomposite,xcursor,xdamage,xext,xfixes,xi,xinerama,xrandr

VULKAN_DESC=		Vulkan GSK backend
VULKAN_MESON_YES=	vulkan
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

DEBUG_DESC=	Debug related
OPTIONS_GROUP=	DEBUG
OPTIONS_GROUP_DEBUG=	DEMOS BUILDEXAMPLES BUILDTEST INSTALLTEST

DEMOS_DESC=		Build demos and example programs
DEMOS_MESON_TRUE=	demos

#BUILDEXAMPLES=	#

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

#post-install:
#	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/modules
#	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/engines
#	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gtk-4.0/${GTK4_VERSION}/loaders
##	${INSTALL_MAN} ${WRKSRC}/docs/reference/gtk/gtk-query-immodules-4.0.1 \
##		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
