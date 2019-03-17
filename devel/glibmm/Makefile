# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glibmm
PORTVERSION=	2.60.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib-2.0

LICENSE=	LGPL21

BUILD_DEPENDS=	gm4:devel/m4

USES=		compiler:c++11-lang gettext gmake gnome libtool pathfix \
		perl5 pkgconfig tar:xz
USE_GNOME=	glib20 libsigc++20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

PORTSCOUT?=	limitw:1,even
PLIST_SUB=	VERSION="2.4"

post-patch:
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s/${d}//' ${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>
