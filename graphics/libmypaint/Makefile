# $FreeBSD$

PORTNAME=	libmypaint
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.0-alpha.1
CATEGORIES=	graphics

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Brush library from the MyPaint project

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=		compiler:c11 gmake gnome libtool localbase pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	mypaint

USE_GNOME=	glib20 intltool introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

TEST_TARGET=	check

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS OPENMP
OPTIONS_DEFAULT=	OPENMP

NLS_USES=	gettext
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls i18n

OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler:c11
OPENMP_CONFIGURE_ENABLE=	openmp

# Run bundled autogen.sh instead of relying on USES=autoreconf which
# leads to errors like
# config.status: error: po/Makefile.in.in was not created by intltoolize.
pre-configure:
				@cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
