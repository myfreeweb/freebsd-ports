PORTNAME=	knotifications
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction for system notifications

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	codecs config coreaddons ecm windowsystem
USE_QT=		core dbus gui linguisttools widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	x11 xtst

OPTIONS_DEFINE=		CANBERRA SPEECH
OPTIONS_DEFAULT=	CANBERRA SPEECH

CANBERRA_DESC=			Use canberra instead of phonon4 for audio notifications
CANBERRA_USES=			canberra
CANBERRA_USE_OFF=		QT=phonon4
CANBERRA_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Canberra

SPEECH_DESC=		Text-to-speech support
SPEECH_USE=		QT=speech
SPEECH_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5TextToSpeech

.include <bsd.port.mk>
