# $FreeBSD$

PORTNAME=		woff2
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.2
CATEGORIES=		www converters

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Library and converter tools for WOFF 2.0 web font format

LICENSE=	MIT

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli

USES=		compiler cmake:outsource pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

OPTIONS_DEFINE=		CONV
OPTIONS_DEFAULT=	CONV
OPTIONS_SUB=		yes

CONV_DESC=		Install command line converter tools
CONV_EXTRA_PATCHES=	${FILESDIR}/extra-patch-install-converters

.include <bsd.port.mk>
