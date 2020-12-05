PORTNAME=	knotifyconfig
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 configuration system for KNotify

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	completion config coreaddons ecm i18n jobwidgets kio \
		service widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network widgets \
		buildtools_build qmake_build

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
