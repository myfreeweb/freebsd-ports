# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gobject-introspection
PORTVERSION=	1.60.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL

# we need cairo otherwise the generated Cairo gir is broken
BUILD_DEPENDS=	cairo-trace:graphics/cairo
LIB_DEPENDS=	libffi.so:devel/libffi

PORTSCOUT=	limitw:1,even

USES=		bison gettext gnome localbase meson \
		pkgconfig python:3.4+ tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|@PYTHON_CMD@|/usr/bin/env ${PYTHON_VERSION}|g' \
		${WRKSRC}/tools/g-ir-tool-template.in

GIRLIBDIR=	${PREFIX}/lib/gobject-introspection/giscanner

post-install:
# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
	@${FIND} ${STAGEDIR}${PREFIX} -name \*.pyc -delete
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${GIRLIBDIR} -f ${GIRLIBDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${GIRLIBDIR} -f ${GIRLIBDIR:S;${PREFIX}/;;})

.include <bsd.port.mk>
