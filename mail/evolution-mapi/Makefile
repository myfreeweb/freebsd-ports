# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-mapi
PORTVERSION=	3.22.0
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Microsoft Exchange plugin through OpenChange

BUILD_DEPENDS=	itstool:textproc/itstool \
		evolution>=3.0.0:mail/evolution
LIB_DEPENDS=	libmapi.so:mail/libmapi
RUN_DEPENDS=	evolution>=3.0.0:mail/evolution

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix pkgconfig \
		sqlite tar:xz
USE_GNOME=	atk cairo evolutiondataserver3 gdkpixbuf2 glib20 gtk30 \
		intltool pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-Wno-error=format-nonliteral
CFLAGS+=	-Wno-error=format-nonliteral
CONFIGURE_ARGS+=	--datarootdir=${PREFIX}/share/
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		-e 's|$$(prefix)/$$(DATADIRNAME)/|$$(prefix)/share/|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
