# $FreeBSD$

PORTNAME=		cli11
DISTVERSIONPREFIX=	v
DISTVERSION=		1.6.1
CATEGORIES=		devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Command line parser for C++11 without dependencies

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	CLIUtils
GH_PROJECT=	CLI11

CMAKE_OFF=	CLI11_TESTING CLI11_EXAMPLES

.include <bsd.port.mk>
