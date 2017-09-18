# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gobject-introspection
PORTVERSION=	1.54.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

LICENSE=	LGPL20+ GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL2+=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_GPLv2+=	${WRKSRC}/COPYING.GPL

# we need cairo otherwise the generated Cairo gir is broken
BUILD_DEPENDS=	cairo-trace:graphics/cairo
LIB_DEPENDS=	libffi.so:devel/libffi

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake gnome libtool localbase pathfix \
		pkgconfig python:3 tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-doctool
INSTALL_TARGET=	install-strip

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|'gcc'|'cc'|g' \
		${WRKSRC}/giscanner/dumper.py

.include <bsd.port.mk>
