# Created by: Bjoern Koenig <bkoenig@alpha-tierchen.de>
# $FreeBSD$

PORTNAME=	jamvm
PORTVERSION=	2.0.0
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JamVM%20${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Compact Java virtual machine

LICENSE=	GPLv2


GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes
PLIST_SUB=	ARCH=${ARCH}
USES=		compiler gmake libtool pkgconfig

OPTIONS_DEFINE=	FFI ZIP
OPTIONS_SINGLE=	CLASSLIB
OPTIONS_SINGLE_CLASSLIB=	CLASSPATH OPENJDK6 OPENJDK7 OPENJDK8
OPTIONS_DEFAULT=FFI ZIP CLASSPATH
FFI_DESC=	use libffi to call native methods
ZIP_DESC=	turn-on zip support in the bootstrap loader
CLASSPATH_DESC=	build standalone JamVM with GNU Classpath as the class library
OPENJDK6_DESC=	build JamVM as a VM for OpenJDK 6 (using its class library)
OPENJDK7_DESC=	build JamVM as a VM for OpenJDK 7 (using its class library)
OPENJDK8_DESC=	build JamVM as a VM for OpenJDK 8 (using its class library)

FFI_CONFIGURE_ENABLE=	ffi
FFI_LIB_DEPENDS=	libffi.so:devel/libffi
ZIP_BUILD_DEPENDS=	zip:archivers/zip
ZIP_CONFIGURE_ENABLE=	zip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLASSPATH}

RUN_DEPENDS+=	${LOCALBASE}/share/classpath/glibj.zip:java/classpath
CONFIGURE_ARGS+=	--with-classpath-install-dir=${LOCALBASE}

.elif ${PORT_OPTIONS:MOPENJDK6}

RUN_DEPENDS+=	${LOCALBASE}/openjdk6/jre/lib/rt.jar:${PORTSDIR}/java/openjdk6
CONFIGURE_ARGS+=	--with-java-runtime-library=openjdk6
post-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/openjdk6/jre/lib/${ARCH}/jamvm
	@${MV} ${STAGEDIR}${PREFIX}/lib/libjvm.so ${STAGEDIR}${PREFIX}/openjdk6/jre/lib/${ARCH}/jamvm/libjvm.so
	@${RM} ${STAGEDIR}${PREFIX}/bin/jamvm

.elif ${PORT_OPTIONS:MOPENJDK7}

RUN_DEPENDS+=	${LOCALBASE}/openjdk7/jre/lib/rt.jar:${PORTSDIR}/java/openjdk7
CONFIGURE_ARGS+=	--with-java-runtime-library=openjdk7
post-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/openjdk7/jre/lib/${ARCH}/jamvm
	@${MV} ${STAGEDIR}${PREFIX}/lib/libjvm.so ${STAGEDIR}${PREFIX}/openjdk7/jre/lib/${ARCH}/jamvm/libjvm.so
	@${RM} ${STAGEDIR}${PREFIX}/bin/jamvm

.elif ${PORT_OPTIONS:MOPENJDK8}

RUN_DEPENDS+=	${LOCALBASE}/openjdk8/jre/lib/rt.jar:${PORTSDIR}/java/openjdk8
CONFIGURE_ARGS+=	--with-java-runtime-library=openjdk8
post-install:
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/openjdk8/jre/lib/${ARCH}/jamvm
	@${MV} ${STAGEDIR}${PREFIX}/lib/libjvm.so ${STAGEDIR}${PREFIX}/openjdk8/jre/lib/${ARCH}/jamvm/libjvm.so
	@${RM} ${STAGEDIR}${PREFIX}/bin/jamvm

.endif

.if empty(PORT_OPTIONS:MFFI) && ${ARCH} == "sparc64"
IGNORE=		for ${ARCH} requires libffi
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CONFIGURE_ARGS+=	--disable-int-inlining
.endif

LDFLAGS+=	-Wl,--version-script=${WRKSRC}/mapfile

post-extract:
	@${REINPLACE_CMD} -e "s,\(^include_HEADERS = .*\)jni.h\(.*\),\1\2," ${WRKSRC}/src/Makefile.in
	@${LN} -s bsd ${WRKSRC}/src/os/freebsd
	@${ECHO} "SUNWprivate_1.1 { *; };" > ${WRKSRC}/mapfile

.include <bsd.port.post.mk>
