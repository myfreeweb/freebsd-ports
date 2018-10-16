# $FreeBSD$

PORTNAME=		mesa-dev
DISTVERSION=		18.3.0-20180916
CATEGORIES=		graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Development version of the Mesa graphics stack

LICENSE=       MIT

CONFLICTS_INSTALL=	mesa-dri mesa-libs libosmesa clover

USES=		compiler:c++11-lib bison gettext-tools meson \
		localbase pathfix pkgconfig python:3.6,build shebangfix
USE_LDCONFIG=	yes
USE_XORG=	xorgproto x11 xdamage xext \
		xfixes xshmfence xv xvmc xxf86vm xcb

USE_GITHUB=	yes
GH_ACCOUNT=	myfreeweb
GH_PROJECT=	mesa
GH_TAGNAME=	a46775fb6e

MESA_LLVM_VER?=	60

BUILD_DEPENDS=	llvm${MESA_LLVM_VER}>=5.0.0:devel/llvm${MESA_LLVM_VER} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		wayland-protocols>=1.8:graphics/wayland-protocols \
		libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl \
		xrandr:x11/xrandr

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm \
		libOpenCL.so:devel/ocl-icd \
		libva.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libwayland-client.so:graphics/wayland \
		libwayland-server.so:graphics/wayland

.if ${OPSYS} == DragonFly
LIB_DEPENDS+=  libelf.so:devel/libelf
.endif

BINARY_ALIAS=	python=${PYTHON_CMD}

RUN_DEPENDS=	llvm${MESA_LLVM_VER}>=5.0.0:devel/llvm${MESA_LLVM_VER} \
		libclc>=0.3.0:devel/libclc \
		xrandr:x11/xrandr \
		opencl>=0:devel/opencl

.if ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --build-id isn't supported by old GNU ld.bfd in base
USE_BINUTILS=		yes
LDFLAGS+=		-B${LOCALBASE}/bin
.endif

MESON_ARGS=	-Dglx-tls="false"\
		-Dgallium-opencl="icd" \
		-Dgallium-omx="disabled" \
		-Dgallium-nine="true" \
		-Dosmesa="gallium"

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.include <bsd.port.mk>
