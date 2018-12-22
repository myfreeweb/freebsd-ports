# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vala
PORTVERSION=	0.44.5
PORTEPOCH=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21

BUILD_DEPENDS=	graphviz>=0:graphics/graphviz
RUN_DEPENDS=	graphviz>=0:graphics/graphviz

USES=		bison gettext-runtime gmake gnome libtool \
		localbase pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix libxslt:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even
VALA_VER=	${PORTVERSION:R}
PLIST_SUB=	VERSION=0.44

.include <bsd.port.mk>
