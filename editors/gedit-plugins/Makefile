# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD: head/editors/gedit-plugins/Makefile 412346 2016-04-01 14:00:51Z mat $

PORTNAME=	gedit-plugins
PORTVERSION=	3.22.0
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gedit>=0:editors/gedit \
		valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libgit2-glib-1.0.so:devel/libgit2-glib
RUN_DEPENDS=	gedit>=0:editors/gedit

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		python:3.3+ tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 gtksourceview3 intlhack introspection
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml

USES+=		python
BUILD_DEPENDS+=	py3?-dbus>=0:devel/py3-dbus
LIB_DEPENDS+=	libgucharmap_2_90.so:deskutils/gucharmap
RUN_DEPENDS+=	py3?-dbus>=0:devel/py3-dbus \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py3-libpeas
USE_GNOME+=	vte3
CONFIGURE_ARGS+=--enable-python
GLIB_SCHEMAS+=	org.gnome.gedit.plugins.terminal.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's| \\t\\r\\n\\f|[:space:]|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
