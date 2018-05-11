# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsigc++
PORTVERSION=	2.99.11
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^3\.

# this port wants c++17 from 12.99.11 and onwards but our framework doesn't support that yet.
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lang gmake libtool pathfix perl5 tar:xz
USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	API_VERSION="3.0"

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_OFF=	--enable-documentation=no

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||; \
		/^SUBDIRS =/s|examples||" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
