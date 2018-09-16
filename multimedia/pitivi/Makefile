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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.10.0:math/py-numpy@${PY_FLAVOR}

USES=		gettext gnome meson pkgconfig python:3.3+ shebangfix tar:xz \
		desktop-file-utils shared-mime-info
SHEBANG_FILES=	bin/pitivi.in
USE_GNOME=	intltool cairo gdkpixbuf2 gtk30 pygobject3
USE_GSTREAMER1=	editing-services good
INSTALLS_ICONS=	yes

PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

.include <bsd.port.mk>
