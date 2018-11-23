# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jackit
PORTVERSION=	1.9.12
DISTVERSIONPREFIX=v
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Low latency audio server

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libcelt0.so:audio/celt

USES=		waf compiler:c11 pkgconfig shebangfix python:3.4+,build
USE_GITHUB=	yes
GH_ACCOUNT=	myfreeweb
GH_PROJECT=	jack2
GH_TAGNAME=	ed5436d
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

SHEBANG_FILES=	example-clients/jack_control
SHEBANG_LANG=	python3

CONFIGURE_ARGS+=	--celt=yes --sndfile=yes --samplerate=yes

OPTIONS_DEFINE=		ALSA READLINE OPUS DBUS
OPTIONS_DEFAULT=	READLINE OPUS DBUS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--alsa=no
ALSA_CONFIGURE_ON=	--alsa=yes

DBUS_CONFIGURE_ON=	--dbus
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libsysinfo.so:devel/libsysinfo \
			libexpat.so:textproc/expat2
DBUS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR}

READLINE_USES=		readline
READLINE_CONFIGURE_ON=	--readline=yes
READLINE_CONFIGURE_OFF=	--readline=no

OPUS_LIB_DEPENDS=	 libopus.so:audio/opus
OPUS_CONFIGURE_ON=	--opus=yes
OPUS_CONFIGURE_OFF=	--opus=no

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDBUS}
PLIST_SUB+=	CLASSIC="@comment "
.else
PLIST_SUB+=	CLASSIC=""
.endif

post-extract:
	echo '#define SVN_VERSION "${GH_TAGNAME}"' > ${WRKSRC}/svnversion.h

.include <bsd.port.post.mk>
