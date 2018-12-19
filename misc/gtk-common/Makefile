# $FreeBSD$

PORTNAME=	gtk-common
PORTVERSION=	3.94.0
CATEGORIES=	misc
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome


# merge graphics/gtk-update-cache


MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common gettext files shared between gtk+ versions

# most of these are build time only stuff... Fix bsd.gnome.mk!
LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libgraphene-1.0.so:graphics/graphene

USES=		gettext gnome meson pkgconfig python:3.4+,build tar:xz
USE_GNOME=	atk cairo gdkpixbuf2 glib20 pango

MESON_ARGS=	-Dprint-backends=file \
		-Dwayland-backend=false \
		-Dmedia=none \
		-Dintrospection=false
#		-Dx11-backend=false \
#X11_MESON_TRUE=         x11-backend
#X11_MESON_YES=          xinerama
#X11_USE=                
USE_XORG=		x11 xcomposite xcursor xdamage xext xfixes xi xinerama xrandr


GLIB_SCHEMAS=   org.gtk.Settings.ColorChooser.gschema.xml \
                org.gtk.Settings.Debug.gschema.xml \
                org.gtk.Settings.EmojiChooser.gschema.xml \
                org.gtk.Settings.FileChooser.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_FILES=	bin/gtk-update-icon-cache \
		share/gettext/its/gtkbuilder.its \
		share/gettext/its/gtkbuilder.loc

do-build:
	cd ${WRKSRC}/_build && ${DO_MAKE_BUILD} gtk/gtk4-update-icon-cache

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gettext/its
	cd ${WRKSRC}/gtk && ${INSTALL_DATA} gtkbuilder.its gtkbuilder.loc \
		${STAGEDIR}${PREFIX}/share/gettext/its
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas
	cd ${WRKSRC}/gtk && ${INSTALL_DATA} *.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	cd ${WRKSRC}/_build/gtk && ${INSTALL_PROGRAM} gtk4-update-icon-cache \
		${STAGEDIR}${PREFIX}/bin/gtk-update-icon-cache

.include <bsd.port.mk>
