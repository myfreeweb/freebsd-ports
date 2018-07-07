# $FreeBSD: branches/plasma5/KDE/x11-toolkits/kirigami2/Makefile 13982 2017-04-29 21:31:21Z tcberner $

PORTNAME=	kirigami2
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtQuick based components set

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm kdeclarative
USE_QT=		core dbus gui linguisttools network \
		qml quick quickcontrols2 svg testlib widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
