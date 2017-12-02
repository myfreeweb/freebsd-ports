# $FreeBSD$

PORTNAME=	libevdev
PORTREVISION=	0
PKGNAMESUFFIX=	-headers

COMMENT=	Input event device header files

LICENSE=	GPLv2

NO_BUILD=	yes
NO_ARCH=	yes

MASTERDIR=	${.CURDIR}/../../devel/libevdev
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
LIBEVDEV_SLAVE=	headers

HEADERS=	input.h input-event-codes.h uinput.h
PLIST_FILES=	${HEADERS:S|^|include/linux/|}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/linux/
.for i in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/linux/${i} \
		${STAGEDIR}${PREFIX}/include/linux/
.endfor

.include "${MASTERDIR}/Makefile"
