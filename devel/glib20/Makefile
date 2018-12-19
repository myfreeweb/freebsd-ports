# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib
PORTVERSION=	2.58.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

LICENSE=	LGPL20

USES=		tar:xz
PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libffi.so:devel/libffi

# iconv:wchar_t - our iconv in base doesn't support utf-8 -> wchar_t (boooo)
# (wchar_t is used by glibmm, rawtherapee triggered this)
USES+=		compiler:c11 gettext gnome iconv:wchar_t \
		localbase:ldflags meson perl5 pkgconfig python:3.4+
USE_PYTHON=	py3kplist
USE_PERL5=	build
USE_LDCONFIG=	yes
MESON_ARGS=	-Db_lundef=false \
		-Dlibmount=false \
		-Dselinux=false \
		-Dxattr=false
BINARY_ALIAS=	python3=${PYTHON_VERSION}

LIBVERSION=	0.5800.2
PLIST_SUB+=	LIBVERSION=${LIBVERSION}

glib_MAN=	gtester.1 gtester-report.1 glib-gettextize.1
gio_MAN=	gdbus.1 gsettings.1 gio-querymodules.1 gio.1 \
		glib-compile-schemas.1 gapplication.1 \
		glib-compile-resources.1 gresource.1 gdbus-codegen.1
gobject_MAN=	glib-genmarshal.1 glib-mkenums.1 gobject-query.1

OPTIONS_DEFINE=	DEBUG MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=		docbook-xml>4.1.2:textproc/docbook-xml \
				docbook-xsl>0:textproc/docbook-xsl
MANPAGES_USE=			GNOME=libxslt:build
MANPAGES_MESON_TRUEE=	man

.include <bsd.port.pre.mk>

# doesn't build yet
MESON_ARGS+=	-Ddtrace=false

.if empty(ICONV_LIB)
MESON_ARGS+=	-Diconv=libc # native?
.else
MESON_ARGS+=	-Diconv=gnu
.endif

.if ${ARCH} == powerpc64
EXTRA_PATCHES=	${FILESDIR}/extra-arch-powerpc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|/usr/share/locale/locale|${LOCALBASE}/share/locale/locale|g' \
		${WRKSRC}/glib/gutils.c
	@${REINPLACE_CMD} -e 's|@PYTHON@|${PYTHON_VERSION}|g' \
		${WRKSRC}/gio/gdbus-2.0/codegen/gdbus-codegen.in \
		${WRKSRC}/glib/gtester-report.in \
		${WRKSRC}/gobject/glib-genmarshal.in \
		${WRKSRC}/gobject/glib-mkenums.in
	@${REINPLACE_CMD} -e '/inotify_init1/d' \
		-e '/inotify.h/d' \
		${WRKSRC}/meson.build

do-build-MANPAGES-on:
.for m in glib gio gobject
. for file in ${${m}_MAN}
	cd ${WRKSRC}/docs/reference/${m} && ${GMAKE} ${file}
. endfor
.endfor

CODEGENDIR=	${PREFIX}/share/glib-2.0/codegen

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/GConf/gsettings
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gio/modules
# generates .py[co] files for installed modules
# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
# with these files when module is imported from root user
	@${FIND} ${STAGEDIR}${PREFIX} -name \*.pyc -delete
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${CODEGENDIR} -f ${CODEGENDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${CODEGENDIR} -f ${CODEGENDIR:S;${PREFIX}/;;})

post-install-MANPAGES-on:
.for m in glib gio gobject
	${INSTALL_MAN} ${${m}_MAN:S|^|${WRKSRC}/docs/reference/${m}/|} \
		${STAGEDIR}${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>

.endif
