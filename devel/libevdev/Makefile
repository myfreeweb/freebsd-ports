# $FreeBSD$

PORTNAME=	libevdev
PORTVERSION=	1.5.7
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Linux Event Device library

LICENSE?=	MIT # without linux/*.h

LIBEVDEV_SLAVE?=  no

USES=		tar:xz

.if ${LIBEVDEV_SLAVE} != headers
LICENSE_FILE=	${WRKSRC}/COPYING
USES+=		gmake libtool pathfix python:build compiler
GNU_CONFIGURE=	yes
BUILD_DEPENDS=	${PORTNAME}-headers>0:devel/${PORTNAME}-headers
CONFIGURE_ENV=	ac_cv_path_DOXYGEN="" ac_cv_path_VALGRIND=""
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

# Test requires /dev/uinput and should be run as root
.if exists(/dev/uinput)
TEST_USES+=		pkgconfig
TEST_LIB_DEPENDS=	libcheck.so:devel/check
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/test
.endif
.endif

.include <bsd.port.pre.mk>

# Do not allow clang optimize out calloc return value.
# Otherwise queue (over)allocation test fails
.if ${LIBEVDEV_SLAVE} != headers && ${COMPILER_TYPE} == clang
CFLAGS+=	-fno-builtin
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -E -e \
		's/__u([[:digit:]]+)/uint\1_t/g ; \
		s/__s([[:digit:]]+)/int\1_t/g ; \
		/# *include/ s|<sys/ioctl.h>|<sys/ioccom.h>| ; \
		/# *include[[:space:]]+<linux\/types.h>/d ; \
		/EVIOC(RMFF|GRAB|REVOKE)/ s/_IOW(.*), *int/_IOWINT\1/ ; \
		/EVIOCGKEYCODE/ s/_IOR/_IOWR/ ; \
		/EVIOCGMASK/ s/_IOR/_IOW/ ; \
		/EVIOCGMTSLOTS/ s/_IOC_READ/IOC_INOUT/ ; \
		/#define/ s/_IOC_READ/IOC_OUT/ ; \
		/#define/ s/_IOC_WRITE/IOC_IN/' \
		${WRKSRC}/include/linux/input.h
	@${REINPLACE_CMD} -i '' -E -e \
		's/__u([[:digit:]]+)/uint\1_t/g ; \
		s/__s([[:digit:]]+)/int\1_t/g ; \
		/# *include/s|<linux/types.h>|<sys/types.h>| ; \
		/#define/ s/_IOW(.*), *int/_IOWINT\1/ ; \
		/#define/ s/_IOW(.*), *char\*/_IO\1/ ; \
		/#define/ s/_IOC_READ/IOC_OUT/' \
		${WRKSRC}/include/linux/uinput.h
	@${REINPLACE_CMD} -e 's|program_invocation_short_name|getprogname()|' \
		${WRKSRC}/tools/mouse-dpi-tool.c \
		${WRKSRC}/tools/touchpad-edge-detector.c \
		${WRKSRC}/tools/libevdev-tweak-device.c

.include <bsd.port.post.mk>
