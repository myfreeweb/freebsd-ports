# $FreeBSD$

PORTNAME=		sequeler
DISTVERSIONPREFIX=	v
DISTVERSION=		0.5.4
CATEGORIES=		databases

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Friendly SQL client with a GTK interface

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala \
		${LOCALBASE}/lib/libgda-5.0/providers/libgda-postgres.so:databases/libgda5-postgresql \
		${LOCALBASE}/lib/libgda-5.0/providers/libgda-mysql.so:databases/libgda5-mysql
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite \
		libgee-0.8.so:devel/libgee

USE_GITHUB=	yes
GH_ACCOUNT=	Alecaddd

USES=		cmake pkgconfig
USE_GNOME=	glib20 gtk30 gdkpixbuf2 gtksourceview3 cairo libgda5 libxml2
GLIB_SCHEMAS=	com.github.alecaddd.sequeler.gschema.xml

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
