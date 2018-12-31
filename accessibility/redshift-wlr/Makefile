# $FreeBSD$

PKGNAMESUFFIX=	-wlr

COMMENT=	Adjusts the color temperature of your Wayland screen (using wlr protocol)

MASTERDIR=	${.CURDIR}/../redshift
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

LIB_DEPENDS+=	libwayland-client.so:graphics/wayland

GH_ACCOUNT=	minus7
GH_TAGNAME=	a2177ed9942

.include "${MASTERDIR}/Makefile"

PORTVERSION=	1.12.20180901
