# $FreeBSD$

CATEGORIES=	audio devel
PKGNAMESUFFIX=	-gtk2
PORTREVISION=	0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec (GTK2 bindings)

MASTERDIR=	${.CURDIR}/../../audio/libcanberra
PLIST=		${.CURDIR}/pkg-plist

do-build:
	cd ${BUILD_WRKSRC} && ${MAKE_ENV} ${GMAKE} libcanberra-gtk.pc
	cd ${BUILD_WRKSRC}/src \
		&& ${MAKE_ENV} ${GMAKE} \
			libcanberra-gtk.la \
			libcanberra-gtk-module.la

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libcanberra-gtk.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.for i in .so .so.0 .so.0.1.9
	${INSTALL_LIB} ${INSTALL_WRKSRC}/src/.libs/libcanberra-gtk${i} \
		${STAGEDIR}${PREFIX}/lib/
.endfor
	cd ${INSTALL_WRKSRC}/src && env DESTDIR=${STAGEDIR} ${GMAKE} install-gtkmoduleLTLIBRARIES
	${LN} -sf libcanberra-gtk-module.so \
		${STAGEDIR}${PREFIX}/lib/gtk-2.0/modules/libcanberra-gtk-module.so

.include "${MASTERDIR}/Makefile"
