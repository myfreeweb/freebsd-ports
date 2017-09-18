# $FreeBSD: head/devel/gnome-builder/Makefile 430235 2017-01-01 03:45:12Z sunpoet $

PORTNAME=	gnome-builder
PORTVERSION=	3.24.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	rm@FreeBSD.org
COMMENT=	IDE for writing software for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libpeas-1.0.so:devel/libpeas \
		libenchant.so:textproc/enchant \
		libgspell-1.so:textproc/gspell \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libdevhelp-3.so:devel/devhelp \
		libgit2.so:devel/libgit2 \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libpcre.so:devel/pcre \
		libpcre2-8.so:devel/pcre2 \
		libgnutls.so:security/gnutls \
		libvala-0.30.so:lang/vala
RUN_DEPENDS=	llvm-config${LLVM_VER}:devel/llvm${LLVM_VER}

LLVM_VER=	40

PORTSCOUT=	limitw:1,even
PORTDOCS=	*

CONFLICTS_BUILD=	gnome-builder-3.16.*

USES=		compiler:c++11-lang cpe desktop-file-utils gmake libtool localbase pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 gtksourceview3 vte3 py3gobject3 libxml2
USE_GNOME+=	introspection
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-flatpak-plugin \
		--disable-jhbuild-plugin
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

PLIST_SUB+=	PORTVER=${PORTVERSION}

GLIB_SCHEMAS=	org.gnome.builder.build.gschema.xml \
		org.gnome.builder.code-insight.gschema.xml \
		org.gnome.builder.editor.gschema.xml \
		org.gnome.builder.editor.language.gschema.xml \
		org.gnome.builder.extension-type.gschema.xml \
		org.gnome.builder.gnome-code-assistance.gschema.xml \
		org.gnome.builder.gschema.xml \
		org.gnome.builder.plugin.gschema.xml \
		org.gnome.builder.plugins.color_picker_plugin.gschema.xml \
		org.gnome.builder.plugins.eslint.gschema.xml \
		org.gnome.builder.project-tree.gschema.xml \
		org.gnome.builder.terminal.gschema.xml \
		org.gnome.builder.workbench.gschema.xml

OPTIONS_SUB=	YES
OPTIONS_DEFINE=	CPLUSCPLUS
OPTIONS_DEFAULT=

CPLUSCPLUS_CONFIGURE_ARGS=	idemm
# xxx sort these
CPLUSCPLUS_USE=	GNOME=atkmm,cairomm,glibmm,gtkmm30,libsigc++20,pangomm

.include <bsd.port.mk>
