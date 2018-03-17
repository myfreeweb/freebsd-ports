# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lollypop
DISTVERSION=	0.9.401
CATEGORIES=	audio
MASTER_SITES=	https://gitlab.gnome.org/gnumdk/lollypop/repository/archive${EXTRACT_SUFX}?ref=${DISTVERSION}&num;/ \
	https://gitlab.gnome.org/gnumdk/lollypop-po/repository/archive${EXTRACT_SUFX}?ref=${PO_COMMIT}&num;/:po \
DISTNAME=	${MAIN_DISTNAME}
DISTFILES=	${MAIN_DISTFILE} \
	${PO_DISTFILE}:po
EXTRACT_ONLY=	${MAIN_DISTFILE}
WRKSRC=	${WRKDIR}/${MAIN_DISTNAME}

MAIN_COMMIT=	e53c9a4e1b4c57512dbde78e765e826e8fb7e33e
MAIN_DISTNAME=	lollypop-${DISTVERSION}-${MAIN_COMMIT}
MAIN_DISTFILE=	${MAIN_DISTNAME}${EXTRACT_SUFX}
PO_COMMIT=	755933dac59ba8f4f643c67b6eff177de00ddb11
PO_DISTFILE=	lollypop-po-${PO_COMMIT}-${PO_COMMIT}${EXTRACT_SUFX}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Play and organize your music collection

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.8:databases/py-sqlite3@${PY_FLAVOR} \
		itstool:textproc/itstool \
	${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1:devel/py-dbus@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pylast>=1.4.0:audio/py-pylast@${PY_FLAVOR}
LIB_DEPENDS=	libnotify.so:devel/libnotify \
	libappstream-glib.so:devel/appstream-glib \
	libtotem-plparser.so:multimedia/totem-pl-parser

USES=	shebangfix python:3.4+ pkgconfig gettext meson sqlite
USE_GNOME=	glib20 gtk30 pygobject3 introspection:build intltool intlhack
USE_GSTREAMER1=	yes mpg123 ogg flac opus libav faad good speex
USE_PYTHON=	py3kplist
INSTALLS_ICONS=	yes

SHEBANG_FILES=	lollypop/*.py

GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer1=pulse

SUB_FILES=	pkg-message

post-extract:
	@${MKDIR} ${WRKSRC}/subprojects/po
	@${TAR} -C ${WRKSRC}/subprojects/po -xzf ${DISTDIR}/${PO_DISTFILE} --strip-components 1

.include <bsd.port.mk>
