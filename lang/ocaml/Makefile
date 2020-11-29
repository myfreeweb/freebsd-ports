# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# for committer: bump PORTREVISION for math/facile whenever ocaml gets updated

PORTNAME=	ocaml
PORTVERSION=	4.11.1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/pub/distrib/${DISTNAME:R}/ GENTOO \
		http://caml.inria.fr/pub/distrib/${DISTNAME:R}/:docs
PKGNAMESUFFIX=	${SFX}

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES+=	8a46d76bf9359b5c.patch:-p1 # https://github.com/ocaml/ocaml/pull/9981

MAINTAINER=	michipili@gmail.com
COMMENT=	Objective Caml compiler and programming environment

LICENSE=		QPL10 LGPL20
LICENSE_COMB=		multi
LICENSE_NAME_QPL10=	Q Public License, Version 1.0
LICENSE_FILE_QPL10=	${WRKSRC}/LICENSE
LICENSE_PERMS_QPL10=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe compiler:c11 gmake tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	inria
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=
LDFLAGS_armv6=	-Wl,-znotext
LDFLAGS_armv7=	-Wl,-znotext
LDFLAGS_i386=	-Wl,-znotext

NOPRECIOUSMAKEVARS=yes	# ARCH
CONFIGURE_ARGS=	--verbose --prefix="${PREFIX}" \
		--disable-force-safe-string \
		CC="${CC}" \
		ASPP="${CC} -c" \
		PARTIALLD="${LD} -r"

OPTIONS_DEFINE=	THREADS DOCS EXAMPLES
OPTIONS_DEFAULT=THREADS

MODOPT=		camlp4o camlp4r ocamlc ocamldep ocamldoc ocamllex ocamlopt
PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]
DOCSDISTNAME=	${DISTNAME:C/([[:digit:]]+)\.([[:digit:]]+)\.([[:digit:]]+)/\1.\2/}

CONFLICTS=	metaocaml-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES:=	${DISTNAME}${EXTRACT_SUFX} \
		${DOCSDISTNAME}-refman-html.tar.gz:docs \
		${DOCSDISTNAME}-refman.pdf:docs
EXTRACT_ONLY:=	${DISTNAME}${EXTRACT_SUFX} \
		${DOCSDISTNAME}-refman-html.tar.gz
PLIST_SUB+=	DOC=""
PORTDOCS=	htmlman ${DOCSDISTNAME}-refman.pdf
.else
PLIST_SUB+=	DOC="@comment "
.endif

.if ${ARCH} == powerpc
LLD_UNSAFE=		yes
.endif

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=	THREADS=""
THR_LD=		-lpthread
.else
PLIST_SUB+=	THREADS="@comment "
THR_LD=		#empty
CONFIGURE_ARGS+=--disable-systhreads
.endif

.include <bsd.port.pre.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
USE_GCC=	yes
.endif

.if ${ARCH} == powerpc64le
USE_GCC=	yes
.endif

post-extract:
.if ${PORT_OPTIONS:MDOCS}
	@if ! (cd ${WRKDIR} && \
	  ${TAR} xf ${_DISTDIR}${DOCSDISTNAME}-refman-html.tar.gz \
	) \
	then \
	  exit 1; \
	fi;
.endif

# INSTALL* safeness (which preserves the correct permissions despite
# user's umask(1)
	@${FIND} ${WRKDIR} -type f -name Makefile -print0 | \
		${XARGS} -0 -n 5 -x ${REINPLACE_CMD} -E \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \4,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \4,' \
		-e 's,(${PATTERN}+.*(MANDIR|MANODIR|MANEXT)),\1\$${BSD_INSTALL_MAN} \4,'

check-test: do-install
	@cd ${WRKSRC}/testsuite; ${RM} _log; for d in tests/* ; do \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} one DIR=$${d} \
	2>&1 | tee -a _log || ${TRUE} ; done ; \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} report

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} htmlman ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${_DISTDIR}${DOCSDISTNAME}-refman.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
