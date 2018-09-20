# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pitivi
PORTVERSION=	0.999
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

LICENSE=	LGPL21+

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgsttranscoder-1.0.so:multimedia/gst-transcoder
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.14.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYNUMPY}

USES=		gettext gnome meson pkgconfig python:3.3+ shebangfix tar:xz \
		desktop-file-utils shared-mime-info
SHEBANG_FILES=	bin/pitivi.in getenvvar.py
USE_GNOME=	cairo intltool gdkpixbuf2 gsound gtk30 pygobject3
USE_GSTREAMER1=	editing-services gdkpixbuf good gtk
INSTALLS_ICONS=	yes

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

.include <bsd.port.mk>
