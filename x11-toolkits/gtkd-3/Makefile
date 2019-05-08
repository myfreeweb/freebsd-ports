# $FreeBSD$

PORTNAME=	gtkd
PORTVERSION=	3.9.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://gtkd.org/Downloads/sources/
DISTNAME=	GtkD-${PORTVERSION}
PKGNAMESUFFIX=	-3
WRKSRC=		${WRKDIR}

PATCH_SITES=	https://github.com/gtkd-developers/GtkD/commit/
PATCHFILES=	a9db09117ab27127ca4c3b8d2f308fae483a9199.patch:-p1 \
	68b055389b0c35cf7c5b16e198ffd7ac3c060e89.patch:-p1 \
	1282f0acbfbd4a4610a7e8d9482c0649027cc995.patch:-p1 \
	831a628dd73cd35bdb5cbb422b7d5decf091d2bc.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	D wrapper for Gtk+3

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2 \
		libpeas-1.0.so:devel/libpeas \
		libphobos2-ldc-shared.so:lang/ldc
BUILD_DEPENDS=	girtod:devel/gir-to-d

USES=		gettext-runtime gmake gnome zip
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 introspection \
		librsvg2 pango vte3
USE_GSTREAMER1=	bad
SSP_UNSAFE=	yes # not understood by ldc2
MAKEFILE=	GNUmakefile
MAKE_ARGS+=	datadir="${PREFIX}/libdata" \
		DC=ldc2 \
		prefix="${PREFIX}"
ALL_TARGET=	shared
INSTALL_TARGET=	install-headers install-shared

# NOTE:
# - we regenerate the bindings to get the compiletime (non-dlopen) version
# - dpkg can be installed on FreeBSD (!), it should not change where this installs
# - SOFLAGS_PEASD does not get localbase from pkgconfig because of --libs-only-l
#   (while not using that returns D-incompatible C flags)

post-patch:
	${REINPLACE_CMD} \
			-e 's/ldconfig -n/# ldconfig -n)/' \
			-e 's|shell which dpkg-architecture 2>/dev/null|false|' \
			-e 's|GIRTOD) -i src --|GIRTOD) -i src -g "${LOCALBASE}/share/gir-1.0" --|' \
			${WRKSRC}/GNUmakefile

# do not add generate-compiletime to ALL_TARGET, build does not *depend* on it
# (and so they would happen in parallel)
pre-build:
	${RM} -r ${WRKSRC}/generated
	@(cd ${BUILD_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} generate-compiletime)

.include <bsd.port.mk>
