# $FreeBSD$

PORTNAME=	gir-to-d
DISTVERSION=	0.20.0-21
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-g02cbb6e
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Generator of D bindings from GObject introspection files

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ldc2:lang/ldc
# NOTE: statically linked binary is smaller than with -link-defaultlib-shared

USES=		meson
USE_GITHUB=	yes
GH_ACCOUNT=	gtkd-developers
SSP_UNSAFE=	yes # not understood by ldc2
PLIST_FILES=	bin/girtod

.include <bsd.port.mk>
