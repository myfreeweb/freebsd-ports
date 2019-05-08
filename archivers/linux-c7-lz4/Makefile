# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	1.7.5
CATEGORIES=	archivers linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Extremely fast compression algorithm (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../liblz4/pkg-descr
ONLY_FOR_ARCHS=	amd64
RPMVERSION=	2.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	7

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
