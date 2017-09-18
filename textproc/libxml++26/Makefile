# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxml++
PORTVERSION=	2.34.2
PORTREVISION?=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

USES+=		tar:xz compiler:c++11-lang
USE_CXXSTD=	c++11

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:devel/m4

USES+=		gettext-runtime gmake libtool pathfix pkgconfig
USE_GNOME=	glibmm libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^library_configdir =/s/libdir/includedir/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^Cflags:/s/libdir/includedir/' \
		${WRKSRC}/libxml++-2.6.pc.in

.include <bsd.port.mk>

.endif
