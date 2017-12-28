# $FreeBSD$

PORTNAME=		maxcso
DISTVERSIONPREFIX=	v
DISTVERSION=		1.9.0
CATEGORIES=		archivers

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Fast ISO to CSO compressor for PSP and PS2 emulators

LICENSE=	ISCL

LIB_DEPENDS=	libuv.so:devel/libuv \
		liblz4.so:archivers/liblz4 \
		libzopfli.so:archivers/zopfli
BUILD_DEPENDS=	pkg-config:devel/pkgconf

USE_GITHUB=	yes
GH_ACCOUNT=	unknownbrackets

USES=		gmake compiler:c++11-lang

CFLAGS+=	-fPIC -DNDEBUG=1 -flto
CXXFLAGS+=	-std=c++11
LDFLAGS+=	-pie -pthread -fuse-ld=lld
# bfd fails to link (not lto related)

PLIST_FILES=	bin/${PORTNAME}

# The included makefile uses bundled zopfli and does not use pkg-config
do-build:
	(cd ${WRKSRC}/7zip && ${GMAKE} ${MAKE_ENV} CXXFLAGS="${CXXFLAGS} -ICPP" 7zip.a)
	(cd ${WRKSRC} && ${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${PORTNAME} \
			$$(pkg-config --libs --cflags libuv) $$(pkg-config --libs --cflags liblz4) \
			-lzopfli -lz -I7zip 7zip/7zip.a src/*.cpp cli/*.cpp)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
