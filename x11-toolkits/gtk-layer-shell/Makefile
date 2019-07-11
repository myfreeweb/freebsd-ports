# $FreeBSD$

PORTNAME=	gtk-layer-shell
DISTVERSION=	g20190709
CATEGORIES=	x11-toolkits

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ library for the Wayland layer-shell protocol

LICENSE=	LGPL21

BUILD_DEPENDS=	wayland-scanner:graphics/wayland
LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		meson compiler:c11 gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wmww
GH_TAGNAME=	2f08ac3abca10edb5904c86f84a505d9aee9e049

USE_GNOME=	gtk30 cairo gdkpixbuf2 introspection:build

.include <bsd.port.mk>
