# $FreeBSD$

PORTNAME=	libqxp
PORTVERSION=	0.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://dev-www.libreoffice.org/src/${PORTNAME}/
PKGNAMESUFFIX=	00

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for parsing QuarkXPress documents

LICENSE=	MPL20

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge

BUILD_DEPENDS=	${LOCALBASE}/include/boost/math/constants/constants.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/optional.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/variant.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/range/adaptor/reversed.hpp:devel/boost-libs \
		${LOCALBASE}/include/boost/cstdint.hpp:devel/boost-libs \
		${LOCALBASE}/lib/libcppunit.so:devel/cppunit

CONFIGURE_ARGS=	--disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes
USES=		compiler:features libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
