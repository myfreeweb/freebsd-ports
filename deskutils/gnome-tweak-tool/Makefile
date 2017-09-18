# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.24.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

LICENSE=	GPLv3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

NO_ARCH=	yes
USES=		gettext gmake gnome localbase pathfix pkgconfig \
		python:2.7 tar:xz
#		python:2.7 shebangfix tar:xz
USE_GNOME=	gtk30 pygobject3 intltool
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
#SHEBANG_FILES=	gnome-tweak-tool

.include <bsd.port.mk>
