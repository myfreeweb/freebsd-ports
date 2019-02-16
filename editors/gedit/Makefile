# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gedit
PORTVERSION=	3.32.2
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GNOME 3 Desktop Environment

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		vala:lang/vala \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libpeas-gtk-1.0.so:devel/libpeas \
		libgspell-1.so:textproc/gspell \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome \
		localbase meson perl5 pkgconfig python:3.4+ shebangfix tar:xz
USE_PERL5=	build
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtksourceview4 introspection \
		libxml2 pygobject3
SHEBANG_FILES=	plugins/externaltools/data/send-to-fpaste.tool.in \
		plugins/externaltools/scripts/gedit-tool-merge.pl
USE_XORG=	sm x11
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="3.14"

BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

PLUGINDIRS=	${PREFIX}/lib/gedit/plugins ${PYTHON_SITELIBDIR}/gi/overrides

.include <bsd.port.pre.mk>

post-install:
# generates .py[co] files for installed modules
	@${FIND} ${STAGEDIR}${PREFIX} -name \*.pyc -delete
.for dir in ${PLUGINDIRS}
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${dir} -f ${dir:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${dir} -f ${dir:S;${PREFIX}/;;})
.endfor

.include <bsd.port.post.mk>
