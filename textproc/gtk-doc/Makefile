# Created by: fenner
# $FreeBSD$

PORTNAME=	gtk-doc
PORTVERSION=	1.26
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Code documentation system, originally for GTK+

BUILD_DEPENDS=	jade:textproc/jade \
		itstool:textproc/itstool \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		rarian-sk-config:textproc/rarian
RUN_DEPENDS=	jade:textproc/jade \
		docbook-xml>0:textproc/docbook-xml \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		rarian-sk-config:textproc/rarian

DOCBOOK_VERSION=	4.1.2

USES=		gmake gettext-tools pathfix perl5 pkgconfig python:2.7 tar:xz
USE_GNOME=	gnomeprefix libxslt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml-catalog=${LOCALBASE}/share/xml/catalog.ports

.include <bsd.port.mk>
