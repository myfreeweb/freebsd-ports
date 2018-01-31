# $FreeBSD$

PORTNAME=	libepubgen
PORTVERSION=	0.1.0
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for generating documents in ePub format

LICENSE=	MPL20

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

BUILD_DEPENDS=	${LOCALBASE}/include/boost/algorithm/string/classification.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/join.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/split.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/algorithm/string/trim.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/assign/list_of.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/functional/hash.hpp:devel/boost-libs \
		${LOCALBASE}/lib/libcppunit.so:devel/cppunit

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		compiler:features libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
