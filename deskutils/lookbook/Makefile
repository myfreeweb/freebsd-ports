# $FreeBSD$

PORTNAME=	lookbook
DISTVERSION=	1.0.0
CATEGORIES=	deskutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Browse and find system icons

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite

USE_GITHUB=	yes
GH_ACCOUNT=	danrabbit

USES=		meson pkgconfig
USE_GNOME=	glib20 gtk30 gtksourceview3
GLIB_SCHEMAS=	com.github.danrabbit.lookbook.gschema.xml

.include <bsd.port.mk>
