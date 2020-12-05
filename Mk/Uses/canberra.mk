# $FreeBSD$
#
# Handle dependency on libcanberra.
#
# Feature:	canberra
# Usage:	USES=canberra[:arg,...]
# Valid ARGS:	build, run, lib, gtk2, gtk3, gstreamer, pulse
#
# MAINTAINER: desktop@FreeBSD.org

.if ! defined(_INCLUDE_USES_CANBERRA_MK)
_INCLUDE_USES_CANBERRA_MK=	yes

_valid_ARGS=	build run lib gtk2 gtk3 gstreamer pulse

.if empty(canberra_ARGS)
canberra_ARGS=	lib
.endif

CANBERRA_VERSION=	0.30

_CANBERRA_COMPONENTS=	lib gtk2 gtk3 gstreamer pulse alsa
_CANBERRA_SUPPORTED=	selfbuild ${_CANBERRA_COMPONENTS}

_CANBERRA_MODULE_DIR_REL=	lib/libcanberra-${CANBERRA_VERSION}
_CANBERRA_MODULE_DIR=	${PREFIX}/${_CANBERRA_MODULE_DIR_REL}

. if ${canberra_ARGS:Mselfbuild}
_CANBERRA_SELF_BUILD=	yes
. endif

canberra-lib_LIB=	libcanberra.so
canberra-lib_PORT=	audio/libcanberra

canberra-gtk2_LIB=	libcanberra-gtk.so
canberra-gtk2_PORT=	audio/libcanberra-gtk2

canberra-gtk3_LIB=	libcanberra-gtk3.so
canberra-gtk3_PORT=	audio/libcanberra-gtk3

canberra-gstreamer_PATH=	${_CANBERRA_MODULE_DIR}/libcanberra-gstreamer.so
canberra-gstreamer_PORT=	audio/libcanberra-gstreamer

canberra-pulse_PATH=	${_CANBERRA_MODULE_DIR}/libcanberra-pulse.so
canberra-pulse_PORT=	audio/libcanberra-pulse

PLIST_SUB+=		CANBERRA_VERSION=${CANBERRA_VERSION} \
			CANBERRA_MODULE_DIR=${_CANBERRA_MODULE_DIR_REL}

_USES_POST+=		canberra
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_CANBERRA_MK_POST) && !defined(_CANBERRA_SELF_BUILD)
_INCLUDE_USES_CANBERRA_MK_POST=	yes

_USE_CANBERRA=	${canberra_ARGS:Nselfbuild}
.  for component in ${_USE_CANBERRA:O:u:C/_(build|run)$//}
.    if ${_CANBERRA_COMPONENTS:M${component}} != ""
.      if defined(canberra-${component}_PORT) && (defined(canberra-${component}_LIB) || defined(canberra-${component}_PATH))
.        if ${canberra_ARGS:M${component}_*} != "" && ${_USE_CANBERRA:M${component}} == ""
canberra-${component}_TYPE=		# empty
.          if ${_USE_CANBERRA:M${component}_build} != ""
canberra--${component}_TYPE+=		build
.          endif
.          if ${_USE_CANBERRA:M${component}_run} != ""
canberra-${component}_TYPE+=		run
.          endif
.        endif
.        if !defined(canberra-${component}_TYPE)
canberra-${component}_TYPE=		build run
.        endif
.        if defined(canberra-${component}_LIB) && ${canberra-${component}_TYPE:Mbuild} && ${canberra-${component}_TYPE:Mrun}
LIB_DEPENDS+=		${canberra-${component}_LIB}:${canberra-${component}_PORT}
.        else
canberra-${component}_PATH?=	${LOCALBASE}/lib/${canberra-${component}_LIB}
canberra-${component}_DEPENDS=	${canberra-${component}_PATH}:${canberra-${component}_PORT}
.          if ${canberra-${component}_TYPE:Mbuild} != ""
BUILD_DEPENDS+=			${canberra-${component}_DEPENDS}
.          endif
.          if ${canberra-${component}_TYPE:Mrun} != ""
RUN_DEPENDS+=			${canberra-${component}_DEPENDS}
.          endif
.        endif
.      endif
.    else
IGNORE=		cannot be installed: unknown canberra component '${component}'
.    endif
.  endfor
.endif
