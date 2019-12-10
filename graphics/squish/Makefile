# Created by: Reinier de Blois <rddeblois@gmail.com>
# $FreeBSD$

PORTNAME=	squish
DISTNAME=	libsquish-${PORTVERSION}
PORTVERSION=	1.15
CATEGORIES=	graphics
MASTER_SITES=	SOURCEFORGE/libsquish
WRKSRC=	${WRKDIR}

MAINTAINER=	rddeblois@gmail.com
COMMENT=	Open source DXT compression library

BROKEN=		unfetchable

LICENSE=	MIT

USES=		uidfix tar:tgz
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX}
PLIST_FILES=	include/squish.h \
		lib/libsquish.a lib/libsquish.so.1 lib/libsquish.so
MAKEFILE=	${FILESDIR}/BSDmakefile
USE_LDCONFIG=	yes

OPTIONS_RADIO=	RG1
OPTIONS_RADIO_RG1=	ALTIVEC SSE
OPTIONS_DEFAULT_amd64=	SSE
ALTIVEC_DESC=	Use Altivec instructions
RG1_DESC=	Optimizations Selection

ALTIVEC_CXXFLAGS=	-DSQUISH_USE_ALTIVEC=1 -maltivec
SSE_CXXFLAGS=		-DSQUISH_USE_SSE=2 -msse2

.include <bsd.port.mk>
