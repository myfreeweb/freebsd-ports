# Created by: Anton tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	libvterm
DISTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/${PORTNAME}/

MAINTAINER=	dem.procopiou@gmail.com
COMMENT=	Implementation of a VT220/xterm/ECMA-48 terminal emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool:build pathfix perl5
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
MAKE_ARGS=	PREFIX=${PREFIX}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/unterm
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-ctrl
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-dump
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvterm.so

.include <bsd.port.mk>
