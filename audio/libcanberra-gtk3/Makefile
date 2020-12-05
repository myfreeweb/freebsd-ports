# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
#   $MCom: ports/trunk/audio/libcanberra-gtk3/Makefile 19814 2014-08-15 20:17:00Z gusi $

CATEGORIES=	audio devel
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

MASTERDIR=	${.CURDIR}/../../audio/libcanberra
SLAVEPORT=	gtk3
PLIST=		${.CURDIR}/pkg-plist

do-build:
	cd ${BUILD_WRKSRC} && ${MAKE_ENV} ${GMAKE} libcanberra-gtk.pc
	cd ${BUILD_WRKSRC}/src \
		&& ${MAKE_ENV} ${GMAKE} \
			libcanberra-gtk.la \
			libcanberra-gtk-module.la  \
			canberra-gtk-play

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcanberra-gtk3.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
.for i in .so .so.0 .so.0.1.9
	${INSTALL_LIB} ${WRKSRC}/src/.libs/libcanberra-gtk3${i} \
		${STAGEDIR}${PREFIX}/lib/
.endfor
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/src/.libs/canberra-gtk-play \
		${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/src && env DESTDIR=${STAGEDIR} ${GMAKE} install-gtk3moduleLTLIBRARIES
	cd ${INSTALL_WRKSRC}/src && env DESTDIR=${STAGEDIR} ${GMAKE} install-dist_gsdgtkmodulesDATA
	${LN} -sf libcanberra-gtk3-module.so \
		${STAGEDIR}${PREFIX}/lib/gtk-3.0/modules/libcanberra-gtk-module.so

.include "${MASTERDIR}/Makefile"
