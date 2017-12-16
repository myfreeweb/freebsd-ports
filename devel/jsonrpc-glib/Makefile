# $FreeBSD$

PORTNAME=	jsonrpc-glib
PORTVERSION=	3.27.1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON-RPC interface for Glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
BUILD_DEPENDS=	vapigen:lang/vala

USES=		gettext localbase meson pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	GIR
OPTIONS_DEFAULT=GIR
OPTIONS_SUB=	yes

GIR_DESC=	Build introspection data
GIR_USE=	gnome=introspection
GIR_MESON_TRUE=	introspection

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/libexec/installed-tests
	@${RM} -r ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
