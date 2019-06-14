# $FreeBSD$

PORTNAME=	bookworm
DISTVERSION=	1.1.1-108
DISTVERSIONSUFFIX=	-g8881b96
CATEGORIES=	deskutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	A simple, focused eBook reader

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgranite.so:x11-toolkits/granite \
		libpoppler-glib.so:graphics/poppler-glib \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	curl:ftp/curl \
		html2text:textproc/html2text \
		unar:archivers/unarchiver \
		unzip:archivers/unzip

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig \
		python:3.5+,build,run shebangfix sqlite:3
USE_GITHUB=	yes
GH_ACCOUNT=	babluboy
USE_GNOME=	glib20 gtk30 libxml2
GLIB_SCHEMAS=	com.github.babluboy.bookworm.gschema.xml
INSTALLS_ICONS=	yes
SHEBANG_FILES=	data/scripts/*.sh data/scripts/mobi_lib/*.py
bash_CMD=	/bin/sh

# for meson/post_install.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
