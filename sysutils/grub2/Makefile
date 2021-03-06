# Created by: sem@FreeBSD.org
# $FreeBSD$

PORTNAME=	grub2
PORTVERSION=	2.02
PORTREVISION=	15
CATEGORIES=	sysutils
MASTER_SITES=	GNU/grub
DISTNAME=	grub-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiboot boot loader

LICENSE=	GPLv3

BROKEN_i386=	uses amd64 assembly
DEPRECATED=	Unmaintained (more than five years), not updated (one-and-a-half years), does not build with modern compilers	# PR232961
EXPIRATION_DATE=2019-02-04

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex \
		gsed:textproc/gsed \
		help2man:misc/help2man
RUN_DEPENDS=	gsed:textproc/gsed

WRKSRC=		${WRKDIR}/grub-${PORTVERSION}

USES=		autoreconf:build bison cpe gettext gmake tar:xz
USE_GCC=	yes

GNU_CONFIGURE=	yes
INFO=		grub grub-dev
MAKE_JOBS_UNSAFE=	yes
SSP_UNSAFE=	yes

CPE_PRODUCT=	grub
CPE_VENDOR=	gnu

CONFIGURE_ARGS=	--disable-werror --localedir=${PREFIX}/share/locale --disable-efiemu
CONFIGURE_ENV=	CPP="${CC} -E" \
		LEX=${LOCALBASE}/bin/flex

OPTIONS_DEFINE=	MKFONT FUSE
OPTIONS_SUB=	yes
MKFONT_DESC=	Build grub-mkfont (require freetype2)
FUSE_DESC=	Build grub-mount (require FUSE)

MKFONT_CONFIGURE_ENABLE=	grub-mkfont
MKFONT_LIB_DEPENDS=		libfreetype.so:print/freetype2
MKFONT_BUILD_DEPENDS=		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu

FUSE_CONFIGURE_ENABLE=		grub-mount
FUSE_LIB_DEPENDS=		libfuse.so:sysutils/fusefs-libs

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
PLIST_SUB+=	EFIEMU="@comment "
.else
PLIST_SUB+=	EFIEMU=""
.endif

post-patch:
	@${LN} -s ${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf ${WRKSRC}
	@${TOUCH} -t 200001010000 ${WRKSRC}/Makefile.util.def
	@${REINPLACE_CMD} -e '/[^auU]sed/ s,sed,gsed,g' ${WRKSRC}/util/grub.d/*.in \
		${WRKSRC}/util/*.in ${WRKSRC}/util/i386/efi/grub-dumpdevtree \
		${WRKSRC}/util/bash-completion.d/grub-completion.bash.in

pre-configure:
	@${REINPLACE_CMD} -e 's|\\${PYTHON}|${PYTHON_CMD}|g' ${WRKSRC}/autogen.sh
	cd ${WRKSRC} && ./autogen.sh

post-configure:
	@${LN} -sfh /usr/include/machine /usr/include/sys /usr/include/x86 \
		${WRKSRC}/grub-core

.include <bsd.port.post.mk>
