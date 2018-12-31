# $FreeBSD$

PORTNAME=		mesa-dev
DISTVERSION=		19.1.0-20190414
CATEGORIES?=		graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Development version of the Mesa graphics stack

LICENSE=       MIT

CONFLICTS_INSTALL=	mesa-dri mesa-libs libosmesa clover

USES=		compiler:c++11-lib bison gettext-tools meson \
		localbase pathfix pkgconfig python:3.6,build shebangfix
USE_LDCONFIG=	yes
USE_XORG=	xorgproto x11 xdamage xext \
		xfixes xshmfence xv xvmc xxf86vm xcb

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=myfreeweb
GL_PROJECT=	mesa
GL_COMMIT=	8bb1214d33cbc9551beadb75dcb76ce210181291

MESA_LLVM_VER?=	80

BUILD_DEPENDS=	llvm${MESA_LLVM_VER}>=5.0.0:devel/llvm${MESA_LLVM_VER} \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		wayland-protocols>=1.8:graphics/wayland-protocols \
		libclc>=0.3.0:devel/libclc \
		opencl>=0:devel/opencl \
		glslangValidator:devel/glslang \
		xrandr:x11/xrandr

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libdrm.so:graphics/libdrm \
		libOpenCL.so:devel/ocl-icd \
		libva.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libwayland-client.so:graphics/wayland \
		libwayland-server.so:graphics/wayland

.include <bsd.port.options.mk>

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

MESON_ARGS=	--native-file "${WRKSRC}/llvm.ini" \
		-Dglx-tls="false"\
		-Dvulkan-overlay-layer="true" \
		-Dgallium-drivers=r300,r600,radeonsi,nouveau,virgl,svga,swrast,swr,iris \
		-Dgallium-opencl="icd" \
		-Dgallium-omx="disabled" \
		-Dgallium-nine="true" \
		-Dgallium-va="true" \
		-Dosmesa="gallium"

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

pre-configure:
	${PRINTF} "[binaries]\nllvm-config = '${LOCALBASE}/bin/llvm-config${MESA_LLVM_VER}'" \
		> "${WRKSRC}/llvm.ini"

.include <bsd.port.mk>
