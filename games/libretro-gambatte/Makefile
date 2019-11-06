# Created by: Yuri Victorovich <yuri@rawbw.com>
# Updated by: Daniel Menelkir <menelkir@itroll.org>

PORTNAME=	libretro-gambatte
PORTVERSION=	0.20191028
PORTREVISION=	1
CATEGORIES=	games
LICENSE=	GPLv2

MAINTAINER=	menelkir@itroll.org
COMMENT=	Libretro Implementation of libgambatte, a Game Boy Color emulator.

BUILD_DEPENDS=	cmake:devel/cmake

ONLY_FOR_ARCHS=	i386 amd64

ALL_CORES=     	libretro:gambatte-libretro:gambatte:b979970:x

USE_GITHUB=	nodefault

# variables that depend on ALL_CORES
GH_TUPLE=	${ALL_CORES:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\1:\2:\4:\3/\2,}
CORE_DIRS=	${ALL_CORES:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\2,}

#PLIST_FILES+=	${ALL_CORES:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),libexec/libretro/\3_libretro.so,}
.for CORE in ${ALL_CORES}
.for A in ${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\5,:S/,/ /g}
PLIST_FILES+=	libexec/libretro/${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}_${A}_libretro.so
.endfor
GIT_REV+=	GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}=$$(git ls-remote https://github.com/${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\1,}/${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\2,}.git | ${GREP} HEAD | ${SED} -E "s/^(.......).*/\\1/g") &&
GIT_REV_ECHO+=	echo "GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}=$${GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}}" &&
GIT_REV_CHANGE+=	if [ "${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\4,}" != "$${GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}}" ]; then echo "upstream revision changed: core=${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,} old=${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\4,}  new=$${GIT_REV_${CORE:C,^([^:]*):([^:]*):([^:]*):([^:]*):([^:]*),\3,}}"; fi &&
.endfor

PLIST_FILES:=	${PLIST_FILES:S/_x_libretro/_libretro/}

WRKSRC=		${WRKDIR}/all-cores

USES=		compiler:c++11-lib dos2unix gmake lua:53 python ssl
USE_LDCONFIG=	yes
USE_GL=		gl

.include <bsd.port.pre.mk>

# Avoid a lot of patching for 9.
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_CXXSTD=	gnu++11
.endif


do-build:
	@for dir in ${CORE_DIRS}; do \
	  ${ECHO_MSG} "===>  Building for ${PKGNAME}: core $${dir} ($$(date))"; \
	  cd ${WRKSRC}/$${dir}; \
	  if [ -f Makefile.freebsd ]; then \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.freebsd ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  elif [ -f Makefile.libretro ]; then \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile.libretro ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  elif [ -f CMakeLists.txt ]; then \
	    ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake . && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  else \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} Makefile ${_MAKE_JOBS} ${MAKE_ARGS}; \
	  fi; \
	done;

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/libretro;
	@for dir in ${CORE_DIRS}; do \
	  ${INSTALL_LIB} $$(find ${WRKSRC}/$${dir}/ -name "*.so") ${STAGEDIR}/${PREFIX}/libexec/libretro; \
	done;

post-install:
	@${RM} ${STAGEDIR}/${PREFIX}/libexec/libretro/libcurl.so

print-upstream-revisions:
	@${ECHO} "--begin print upstream revisions--" && \
		${GIT_REV} \
		${GIT_REV_ECHO} \
	${ECHO} "--end print upstream revisions--"

print-updated-revisions:
	@${ECHO} "--begin print updated revisions--" && \
		${GIT_REV} \
		${GIT_REV_CHANGE} \
	${ECHO} "--end print updated revisions--"

.include <bsd.port.post.mk>
