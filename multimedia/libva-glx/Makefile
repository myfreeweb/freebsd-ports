# $FreeBSD$

PKGNAMESUFFIX=	-glx
COMMENT=	VAAPI wrapper for GLX

OPTIONS_DEFINE=	DEBUG

USE_XORG=	xorgproto pciaccess x11 xext xfixes
USE_GL=	gl

MASTERDIR=	${.CURDIR:H}/libva
PLIST=	${.CURDIR}/pkg-plist

LIBVA_SLAVE=	glx

.include "${MASTERDIR}/Makefile"
