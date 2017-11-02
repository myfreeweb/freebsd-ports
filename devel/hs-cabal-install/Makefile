# $FreeBSD$

PORTNAME=	cabal-install
PORTVERSION=	2.0.0.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage

LICENSE=	BSD3CLAUSE

USE_CABAL=	async base16-bytestring cryptohash-sha256 echo edit-distance \
		hackage-security hashable HTTP mtl network network-uri old-time random stm \
		tar zlib

STANDALONE=	yes
EXECUTABLE=	cabal

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
