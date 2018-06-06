# $FreeBSD$

PORTNAME=	skanlite
DISTVERSION=	2.0.1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/src/COPYING

LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libpng16.so:graphics/png

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n jobwidgets kio service widgetsaddons xmlgui
USE_QT5=	core dbus gui network widgets xml \
		buildtools_build qmake_build

CONFLICTS_INSTALL=	skanlite

.include <bsd.port.mk>
