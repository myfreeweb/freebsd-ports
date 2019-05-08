# $FreeBSD$

PORTNAME=	pangox-compat
PORTVERSION=	0.0.2
CATEGORIES=	x11-toolkits linux
MASTER_SITES=	EPEL7/p

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Compatibility library for pangox (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
ONLY_FOR_ARCHS=	amd64
RPMVERSION=	2.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	gtk2 pango
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
