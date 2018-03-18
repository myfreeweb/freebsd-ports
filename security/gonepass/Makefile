# $FreeBSD$

PORTNAME=	gonepass
DISTVERSION=	g20180318
CATEGORIES=	security

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ 1Password reader

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	jbreams
GH_TAGNAME=	6f0bc22

USES=		cmake ssl pkgconfig
USE_GNOME=	gtk30 gtkmm30

PLIST_FILES=	bin/gonepass \
		share/applications/gonepass.desktop \
		share/pixmaps/gonepass.png

.include <bsd.port.mk>
