# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pangomm
PORTVERSION=	2.42.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Pango

LICENSE=	LGPL21

BUILD_DEPENDS=	gm4:devel/m4

USES+=		compiler:c++11-lang gmake gnome libtool localbase \
		pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	cairomm glibmm pango

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation \
		--enable-static=yes
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even
PLIST_SUB=	VERSION="2.4" API_VERSION="1.4"

post-patch:
.for d in tests
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/${d}//' \
		${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>
