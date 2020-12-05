# $FreeBSD$

CATEGORIES=	audio devel
PKGNAMESUFFIX=	-pulse
PORTREVISION=	0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec (pulse backend)

MASTERDIR=	${.CURDIR}/../../audio/libcanberra
PLIST=		${.CURDIR}/pkg-plist

do-build:
	cd ${BUILD_WRKSRC}/src && ${GMAKE} libcanberra${PKGNAMESUFFIX}.la

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${PORTVERSION} && \
		${INSTALL_LIB} ${BUILD_WRKSRC}/src/.libs/libcanberra${PKGNAMESUFFIX}.so \
			${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${PORTVERSION}/

.include "${MASTERDIR}/Makefile"
