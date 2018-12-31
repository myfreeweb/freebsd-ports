# $FreeBSD$

PORTNAME=	mesa-dev
DISTVERSION=	19.3.0-20190903
CATEGORIES?=	graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Development version of the Mesa graphics stack

LICENSE=	MIT

#CONFLICTS_INSTALL=	mesa-dri mesa-libs libosmesa clover

USES=		bison compiler:c++11-lib gettext-tools localbase meson pathfix \
		pkgconfig python:3.6,build shebangfix xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb xdamage xext xfixes xorgproto xshmfence xv xvmc xxf86vm

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	myfreeweb
GL_PROJECT=	mesa
GL_COMMIT=	6eaaf1f08be16e687565fb8a6aee7c1d010830e6

MESA_LLVM_VER?=	90

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR} \
		glslangValidator:devel/glslang \
		libclc>=0.3.0:devel/libclc \
		llvm${MESA_LLVM_VER}>=5.0.0:devel/llvm${MESA_LLVM_VER} \
		opencl>=0:devel/opencl \
		wayland-protocols>=1.8:graphics/wayland-protocols \
		xrandr:x11/xrandr

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2 \
		libOpenCL.so:devel/ocl-icd \
		libva.so:multimedia/libva \
		libvdpau.so:multimedia/libvdpau \
		libwayland-server.so:graphics/wayland \
		libunwind.so:devel/libunwind # note: on aarch64, need a modern 2019* version

.include <bsd.port.options.mk>

# Does DFly really not have libelf in base?
# On FBSD, ports libelf *breaks* stuff (data->d_size != shdr->sh_size)
.if ${OPSYS} == DragonFly
LIB_DEPENDS+=	libelf.so:devel/libelf
.endif

BINARY_ALIAS=	python=${PYTHON_CMD}

RUN_DEPENDS=	libclc>=0.3.0:devel/libclc \
		llvm${MESA_LLVM_VER}>=5.0.0:devel/llvm${MESA_LLVM_VER} \
		opencl>=0:devel/opencl \
		xrandr:x11/xrandr

.if ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
# --build-id isn't supported by old GNU ld.bfd in base
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif

MESON_ARGS=	--native-file="${WRKSRC}/llvm.ini" \
		-Dgallium-nine="true" \
		-Dgallium-omx="disabled" \
		-Dgallium-opencl="icd" \
		-Dgallium-va="true" \
		-Dosmesa="gallium" \
		-Dvulkan-overlay-layer="true"

.include <bsd.port.options.mk>

PLIST_SUB+=	VK_ARCH="${ARCH:S/amd64/x86_64/:S/aarch64/arm64/}"

.if ${ARCH} == amd64 || ${ARCH} == i386
MESON_ARGS+=	-Dgallium-drivers=r300,r600,radeonsi,nouveau,virgl,svga,swrast,swr,iris \
		-Dvulkan-drivers=amd,intel
PLIST_SUB+=	IRIS="" SWR="" INTEL="" LEGACY=""
.else
MESON_ARGS+=	-Delf-tls="false" \
		-Dgallium-drivers=r300,r600,radeonsi,nouveau,virgl,svga,swrast \
		-Dvulkan-drivers=amd
PLIST_SUB+=	IRIS="@comment " SWR="@comment " INTEL="@comment " LEGACY="@comment "
.endif

pre-configure:
	${PRINTF} "[binaries]\nllvm-config = '${LOCALBASE}/bin/llvm-config${MESA_LLVM_VER}'" \
		> "${WRKSRC}/llvm.ini"

.include <bsd.port.mk>
