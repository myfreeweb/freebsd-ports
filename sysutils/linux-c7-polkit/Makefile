# $FreeBSD$

PORTNAME=	polkit
PORTVERSION=	0.112
CATEGORIES=	sysutils linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	An authorization framework (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
ONLY_FOR_ARCHS=	amd64
RPMVERSION=	18.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	systemd-libs gtk2
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	7

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
