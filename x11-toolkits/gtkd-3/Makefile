# $FreeBSD$

PORTNAME=	gtkd
PORTVERSION=	3.8.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://gtkd.org/Downloads/sources/
DISTNAME=	GtkD-${PORTVERSION}
PKGNAMESUFFIX=	-3
WRKSRC=	${WRKDIR}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	D wrapper for Gtk+3

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libphobos2-ldc-shared.so:lang/ldc

USES=	gmake zip
SSP_UNSAFE=	yes # not understood by ldc2
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	DC=ldc2 prefix="${PREFIX}" datadir="${PREFIX}/libdata"
INSTALL_TARGET=	install-headers install-shared

post-patch:
	${REINPLACE_CMD} \
			-e 's/tar xv)/tar xvf -)/' \
			-e 's/ldconfig -n/# ldconfig -n)/' \
			-e 's/install-headers-gtkdsv install-shared-gstreamer install-shared-vte install-shared-peas/install-headers-gtkdsv install-headers-gstreamer install-headers-vte install-headers-peas/' \
			${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
