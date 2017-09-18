# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-gst
PORTVERSION=	3.0.22
CATEGORIES=	multimedia
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libcogl-path.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib

USES=		gettext-runtime gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz
USE_GNOME=	atk cairo gdkpixbuf2 gnomeprefix introspection:build pango
GNU_CONFIGURE=	yes
USE_GL=		gl egl
USE_GSTREAMER1=	yes
USE_XORG=	xcomposite xdamage xext xfixes xi xp xrandr x11
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

# The clutter-gst gstreamer plugin is not parrallel installable with
# the 2.0 version. Don't install it (see @comment in plist) until
# all users can be ported (upstream task) to the 3.0 version.

.include <bsd.port.mk>
