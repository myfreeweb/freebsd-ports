# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	fuzzylite
PORTVERSION=	6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Fuzzy logic control library in C++

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}

USE_GITHUB=	yes
USES=		compiler cmake
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 39
CFLAGS+=	-Wno-error=varargs
.endif

.include <bsd.port.post.mk>
