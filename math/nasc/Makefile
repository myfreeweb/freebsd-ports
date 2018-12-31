# $FreeBSD$

PORTNAME=	nasc
DISTVERSION=	0.4.6
CATEGORIES=	math

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Smart dual-pane plain-text calculator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite \
		libgee-0.8.so:devel/libgee \
		libqalculate.so:math/libqalculate \
		libsoup-2.4.so:devel/libsoup

USE_GITHUB=	yes
GH_ACCOUNT=	parnold-x

USES=		cmake:noninja pkgconfig
USE_GNOME=	glib20 gtk30 gtksourceview3
GLIB_SCHEMAS=	com.github.parnold-x.nasc.gschema.xml

.include <bsd.port.mk>
