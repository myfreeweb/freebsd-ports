<<<<<<< HEAD
# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD: head/lang/spidermonkey52/Makefile 470485 2018-05-20 21:30:35Z kwm $

PORTNAME=	spidermonkey
DISTVERSION=	60.1.1pre3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://ftp.mozilla.org/pub/spidermonkey/prereleases/60/pre3/
DISTNAME=	mozjs-${DISTVERSION}
PKGNAMESUFFIX=	${SP_VER}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 60-esr

=======
# $FreeBSD$

PORTNAME=	spidermonkey
DISTVERSION=	60.9.0
CATEGORIES=	lang
MASTER_SITES=	MOZILLA/firefox/releases/${DISTVERSION}esr/source
PKGNAMESUFFIX=	${SP_VER}
DISTNAME=	firefox-${DISTVERSION}esr.source

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Standalone JavaScript based from Mozilla 60-esr

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3
BUILD_DEPENDS=	autoconf-2.13:devel/autoconf213
LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libffi.so:devel/libffi \
		libicudata.so:devel/icu

HAS_CONFIGURE=	yes
USES=		compiler:c++14-lang gmake localbase pathfix pkgconfig \
<<<<<<< HEAD
		python:2.7,build tar:bz2
#		python:2.7,build readline tar:xz
#USES+=	perl5
#USE_PERL5=	build
USE_LDCONFIG=	yes
SP_VER=		60

CONFIGURE_WRKSRC=	${WRKSRC}/_build
BUILD_WRKSRC=	${WRKSRC}/_build
INSTALL_WRKSRC=	${WRKSRC}/_build

#CONFIGURE_OUTSOURCE - If set, this port builds in an empty ${CONFIGURE_WRKSRC}
#                                 not being under ${WRKSRC}.
# CONFIGURE_WRKSRC
#                               - Directory to run configure in.
#                                 Default: ${WRKSRC}
# CONFIGURE_SCRIPT

CONFIGURE_SCRIPT=	../js/src/configure

CONFIGURE_ARGS=	--with-pthreads \
=======
		python:2.7,build tar:xz
USE_LDCONFIG=	yes
SP_VER=		60

WRKSRC=		${WRKDIR}/firefox-${DISTVERSION}
PATCH_WRKSRC=		${WRKDIR}/firefox-${DISTVERSION}/
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_SCRIPT=	../firefox-${DISTVERSION}/js/src/configure

CONFIGURE_ARGS=	--with-pthreads \
		--prefix=${PREFIX:Q} \
>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3
		--target=${CONFIGURE_TARGET} \
		--with-intl-api \
		--with-system-zlib \
		--disable-gold \
<<<<<<< HEAD
		--with-system-icu \
		--with-system-nspr
# There be dragons
CONFIGURE_ARGS+=--disable-jemalloc

OPTIONS_DEFINE=	DEBUG GCZEAL OPTIMIZE READLINE UTF8 DTRACE
OPTIONS_DEFAULT=METHODJIT OPTIMIZE READLINE
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug debug-symbols
DEBUG_CONFIGURE_DISABLE=debug

DTRACE_CONFIGURE_ENABLE=dtrace profiling
DTRACE_LIBS=	-lelf

GCZEAL_DESC=	Enable Zealous garbage collecting
GCZEAL_CONFIGURE_ENABLE=gczeal

OPTIMIZE_DESC=	Enable compiler optimizations
OPTIMIZE_CONFIGURE_ENABLE=	optimize

READLINE_DESC=	Link js shell to the readline library
READLINE_USES=	readline
READLINE_CONFIGURE_ENABLE=	readline

UTF8_DESC=	Treat strings as UTF8 instead of ISO-8859-1
UTF8_CFLAGS=	-DJS_C_STRINGS_ARE_UTF8
=======
		--disable-debug \
		--disable-debug-symbols \
		--disable-jemalloc \
		--with-system-icu \
		--with-system-nspr \
		--enable-shared-js \
		--enable-optimize \
		--enable-readline

CONFIGURE_ENV=	HOST_CC=${CC} HOST_CXX=${CXX}
>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.endif

<<<<<<< HEAD
post-patch:
# Skip some tests because bundled icu differs from system
	@${RM}  ${WRKSRC}/tests/test262/intl402/ch10/10.2/10.2.3_b.js \
		${WRKSRC}/tests/Intl/DateTimeFormat/format.js \
		${WRKSRC}/tests/ecma_6/String/normalize-generateddata-part1-not-listed.js

regression-test: build
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC_BUILD} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} ${WRKSRC}/js/src/tests/jstests.py \
	-d -s --no-progress js/src/shell/js

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
.if ! ${PORT_OPTIONS:MDTRACE}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js${SP_VER}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*
.endif
=======
post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libjs_static.ajs
	${LN} -fs libmozjs-${SP_VER}.so ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/js${SP_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs-${SP_VER}.*
>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3

.include <bsd.port.post.mk>
