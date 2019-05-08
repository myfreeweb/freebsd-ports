# $FreeBSD$

PORTNAME=	tilix
DISTVERSION=	1.9.3
CATEGORIES=	x11

MAINTAINER=	greg@unrelenting.technology
COMMENT=

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libunwind.so:devel/libunwind \
		libphobos2-ldc-shared.so:lang/ldc \
		libgtkd-3.so:x11-toolkits/gtkd-3 \
		libvted-3.so:x11-toolkits/gtkd-3

USES=	meson gnome shebangfix
USE_XORG=	x11
USE_GNOME=	gtk30 vte3
USE_GITHUB=	yes
GH_ACCOUNT=	gnunn1
SSP_UNSAFE=	yes # not understood by ldc2
SHEBANG_FILES=	data/scripts/tilix_int.sh
GLIB_SCHEMAS=	com.gexperts.Tilix.gschema.xml

post-patch:
	${CP} ${FILESDIR}/LINGUAS ${WRKSRC}/po

.include <bsd.port.mk>
