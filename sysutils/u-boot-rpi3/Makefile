# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2018.01
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/:uboot
PKGNAMESUFFIX=	-rpi3
DISTFILES=	u-boot-${PORTVERSION}.tar.bz2:uboot

MAINTAINER=	db@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for RPi3

LICENSE=	GPLv2

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

USE_GITHUB=	nodefault
GH_TUPLE=	gonzoua:rpi3-psci-monitor:2b8890a:psci \
	raspberrypi:firmware:9bcdc30:firmware

NO_ARCH=	yes

USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=aarch64-none-elf- \
		CONFIG_EFI=y

do-configure:
	(cd ${WRKSRC}; ${GMAKE} rpi_3_defconfig)

do-build:
	(cd ${WRKSRC}; ${GMAKE} ${MAKE_ARGS})
	(cd ${WRKSRC_psci}; ${MAKE})

# The output of the u-boot build process is u-boot.bin.  Older firmware
# versions require a standard header, but the recent versions (our case)
# are capable of booting u-boot.bin directly.  Also copy the entire
# contents of the bootfiles distribution (these are proprietary binary
# files required to boot).
# Also include the armstub8.bin needed to go SMP on RPI3
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/overlays
	${INSTALL_DATA} ${WRKSRC}/u-boot.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README
	${INSTALL_DATA} ${WRKSRC_firmware}/boot/*.bin \
		${WRKSRC_firmware}/boot/*.dat \
		${WRKSRC_firmware}/boot/*.elf \
		${WRKSRC_firmware}/boot/bcm2710-rpi-3-b.dtb \
		${WRKSRC_firmware}/boot/bcm2710-rpi-cm3.dtb \
		${WRKSRC_firmware}/boot/LICENCE.broadcom \
		${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	${INSTALL_DATA} ${WRKSRC_firmware}/boot/overlays/* ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/overlays
	${INSTALL_DATA} ${WRKSRC_psci}/armstub8.bin ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}

.include <bsd.port.mk>
