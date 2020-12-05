# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
#   $MCom: ports/trunk/audio/libcanberra/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	libcanberra
DISTVERSION=	${CANBERRA_VERSION}
PORTREVISION?=	6
CATEGORIES=	audio devel
MASTER_SITES=	http://0pointer.de/lennart/projects/libcanberra/ \
		http://pkgs.fedoraproject.org/repo/pkgs/libcanberra/libcanberra-0.30.tar.xz/34cb7e4430afaf6f447c4ebdb9b42072/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libltdl.so:devel/libltdl

USES=		gmake gnome libtool localbase:ldflags pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lynx --disable-tdb --disable-alsa --disable-udev
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=${PORTVERSION}

.if defined(PKGNAMESUFFIX) # Backends and toolkit integrations
USES+=			canberra:lib
CONFIGURE_ARGS+=	--disable-null --disable-oss

.  if ${PKGNAMESUFFIX:M-gtk2}
USE_GNOME+=		cairo gdkpixbuf2 gtk20
USE_XORG+=		x11
CONFIGURE_ARGS+=	--enable-gtk \
			--disable-gtk3 --disable-pulse --disable-gstreamer --enable-null
.  endif

.  if ${PKGNAMESUFFIX:M-gtk3}
USE_GNOME+=		cairo gdkpixbuf2 gtk30
USE_XORG+=		x11
CONFIGURE_ARGS+=	--enable-gtk3 \
			--disable-gtk --disable-pulse --disable-gstreamer --enable-null
.  endif

.  if ${PKGNAMESUFFIX:M-pulse}
LIB_DEPENDS+=		libpulse.so:audio/pulseaudio
CONFIGURE_ARGS+=	--enable-pulse \
			--disable-gtk --disable-gtk3 --disable-gstreamer
.  endif

.  if ${PKGNAMESUFFIX:M-gstreamer}
USE_GSTREAMER1=	yes
CONFIGURE_ARGS+=	--enable-gstreamer \
			--disable-gtk --disable-gtk3 --disable-pulse
.  endif

.else # Main port
USES+=			canberra:selfbuild
USE_GNOME+=		cairo gdkpixbuf2 gtk30
USE_XORG+=		x11
CONFIGURE_ARGS+=	--enable-gtk3 \
			--disable-gtk --disable-pulse --disable-gstreamer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
