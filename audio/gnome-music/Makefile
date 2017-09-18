# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	gnome-music
PORTVERSION=	3.22.2
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME music playing application

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgrilo-0.3.so:net/grilo \
		libmediaart-2.0.so:multimedia/libmediaart

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool pathfix pkgconfig python:3 tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomedesktop3 gtk30 intltool introspection:build
GNU_CONFIGURE=	yes
USE_GSTREAMER1=	ogg mpg123
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Music.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|grilo-0.2|grilo-0.3|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
