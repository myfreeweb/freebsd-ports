# $FreeBSD$

PORTNAME=	akira
PORTVERSION=	g20180319
CATEGORIES=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	UI and UX design tool based on GTK

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgranite.so:x11-toolkits/granite \
		libgee-0.8.so:devel/libgee \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3

USE_GITHUB=	yes
GH_ACCOUNT=	Alecaddd
GH_PROJECT=	Akira
GH_TAGNAME=	53895e9

USES=		meson pkgconfig
USE_GNOME=	glib20 gtk30 gdkpixbuf2 gtksourceview3 cairo libxml2
GLIB_SCHEMAS=	com.github.alecaddd.akira.gschema.xml

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
