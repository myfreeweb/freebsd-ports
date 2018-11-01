# $FreeBSD$

COMMENT=	Development version of the Mesa libva driver
CATEGORIES=		multimedia

MASTERDIR=	${.CURDIR:H:H}/graphics/mesa-dev
PLIST=	${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"

PORTNAME=		libva-mesa-dev-driver

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libdrm.so:graphics/libdrm \
		libva-wayland.so:multimedia/libva

RUN_DEPENDS=

USE_XORG=
USE_LDCONFIG=	no

MESON_ARGS=	-Dglx-tls="false" \
		-Ddri-drivers="" \
		-Dvulkan-drivers="" \
		-Dgallium-opencl="disabled" \
		-Dgallium-omx="disabled" \
		-Dgallium-xvmc="false" \
		-Dgallium-nine="false" \
		-Dgallium-va="true" \
		-Dgles1="false" -Dgles2="false" \
		-Dosmesa="none"

