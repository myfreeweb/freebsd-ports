# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-desktop
PORTVERSION=	3.24.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz

.if !defined(REFERENCE_PORT)
PORTSCOUT=	limitw:1,even

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		xkeyboard-config>=0:x11/xkeyboard-config \
		itstool:textproc/itstool
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		xkeyboard-config>=0:x11/xkeyboard-config

USES+=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig python:3.3+
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build \
		referencehack
USE_XORG=	x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project"
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/desktop-docs/fdl/Makefile.in \
		${WRKSRC}/desktop-docs/gpl/Makefile.in \
		${WRKSRC}/desktop-docs/lgpl/Makefile.in

.include <bsd.port.mk>

.endif
