PORTNAME=	cld3
DISTVERSION=	3.3.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Compact Language Detection for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	rubygem-ffi110>=1.1.0<1.12.0:devel/rubygem-ffi110

USES=		gem pkgconfig
USE_RUBY=	yes

.include <bsd.port.mk>
