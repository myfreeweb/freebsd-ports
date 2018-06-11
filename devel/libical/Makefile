# Created by: Joe Kelsey
# $FreeBSD: head/devel/libical/Makefile 453790 2017-11-09 02:31:47Z jbeich $

PORTNAME=	libical
PORTVERSION=	3.0.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libical/libical/releases/download/v${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols

LICENSE=	LGPL21 MPL20
LICENSE_COMB=	dual

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lib pathfix perl5

USES=		cmake gnome pathfix perl5 pkgconfig
USE_PERL5=	build
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE= yes

BUILD_DEPENDS=	valac:lang/vala \
		gtkdoc-scan:textproc/gtk-doc
USE_GNOME=	introspection:build glib20 libxml2
CMAKE_ARGS+=	-DGOBJECT_INTROSPECTION=true \
		-DICAL_GLIB_VAPI=true \
		-DICAL_BUILD_DOCS=false

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
