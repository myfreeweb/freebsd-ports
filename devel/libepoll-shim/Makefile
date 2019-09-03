# Created by: Johannes Lundberg <johalun0@gmail.com>
# $FreeBSD$

PORTNAME=	libepoll-shim
PORTVERSION=	0.0.20190623
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	epoll shim implemented using kevent

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_PROJECT=	epoll-shim
GH_TAGNAME=	a790d8d0998c7ca0dd243ad658dcfe7c4f355121

USE_LDCONFIG=	yes

USES=		cmake compiler uidfix

.include <bsd.port.pre.mk>

pre-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/libepoll-shim/sys

.include <bsd.port.post.mk>
