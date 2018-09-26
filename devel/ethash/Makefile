# $FreeBSD$

PORTNAME=		ethash
DISTVERSIONPREFIX=	v
DISTVERSION=		0.2.0
CATEGORIES=		devel security net-p2p

MAINTAINER=	greg@unrelenting.technology
COMMENT=	C/C++ implementation of Ethash, the Ethereum Proof of Work algorithm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	chfast

CMAKE_OFF=	HUNTER_ENABLED ETHASH_BUILD_TESTS

.include <bsd.port.mk>
