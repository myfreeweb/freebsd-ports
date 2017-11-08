# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.9.1
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libepoll-shim.so:devel/libepoll-shim \
		libwacom.so:x11/libwacom \
		libudev.so:devel/libudev-devd \
		libmtdev.so:devel/libmtdev

USES=		meson pkgconfig tar:xz
USE_LDCONFIG=	yes

MESON_ARGS+=	-Ddocumentation=false -Dtests=false

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEBUGGUI

DEBUGGUI_DESC=		GUI tool for input testing/debugging
DEBUGGUI_USE=		GNOME=gtk30,cairo,glib20
DEBUGGUI_MESON_OFF=	-Ddebug-gui=false

post-patch:
	${REINPLACE_CMD} -e 's|program_invocation_short_name|getprogname()|' \
	    ${WRKSRC}/tools/libinput-list-devices.c \
	    ${WRKSRC}/tools/ptraccel-debug.c ${WRKSRC}/tools/shared.c

.include <bsd.port.mk>
