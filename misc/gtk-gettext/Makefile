# $FreeBSD$

PORTNAME=	gtk-gettext
PORTVERSION=	3.94.0
CATEGORIES=	misc
MASTER_SITES=	GNOME/sources/gtk+/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common gettext files shared between gtk+ versions

USES=		meson tar:xz

NO_CONFIGURE=	yes
NO_BUILD=	yes

GLIB_SCHEMAS=   org.gtk.Settings.ColorChooser.gschema.xml \
                org.gtk.Settings.Debug.gschema.xml \
                org.gtk.Settings.EmojiChooser.gschema.xml \
                org.gtk.Settings.FileChooser.gschema.xml

PLIST_FILES=	share/gettext/its/gtkbuilder.its \
		share/gettext/its/gtkbuilder.loc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gettext/its
	cd ${WRKSRC}/gtk && ${INSTALL_DATA} gtkbuilder.its gtkbuilder.loc \
		${STAGEDIR}${PREFIX}/share/gettext/its

.include <bsd.port.mk>
