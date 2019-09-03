# Created by: Johannes Lundberg <johalun0@gmail.com>
# $FreeBSD$

PORTNAME=	libepoll-shim
PORTVERSION=	0.0.20190903
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	epoll shim implemented using kevent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_PROJECT=	epoll-shim
GH_TAGNAME=	872ce7e04267049473f7b55dbd2d54b31920a1f3

USE_LDCONFIG=	yes

USES=		cmake compiler:c11
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
