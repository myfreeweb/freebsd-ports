# $FreeBSD$

PORTNAME=		dose-response
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.0
CATEGORIES=		games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Open-world roguelike game where you play an addict

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS+=	libSDL2.so:devel/sdl20

USES=		cargo gnome
USE_GITHUB=	yes
GH_ACCOUNT=	tryjumping

CARGO_FEATURES+=prod sdl2/use-pkgconfig

CARGO_CRATES=	adler32-1.0.3 \
		andrew-0.1.4 \
		android_glue-0.2.3 \
		ansi_term-0.11.0 \
		approx-0.3.1 \
		arrayvec-0.4.9 \
		atty-0.2.11 \
		bincode-1.0.1 \
		bitflags-0.7.0 \
		bitflags-1.0.4 \
		block-0.1.6 \
		byteorder-1.2.7 \
		cc-1.0.28 \
		cfg-if-0.1.6 \
		cgl-0.2.3 \
		chrono-0.4.6 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		cocoa-0.18.4 \
		color_quant-1.0.1 \
		core-foundation-0.6.3 \
		core-foundation-sys-0.6.2 \
		core-graphics-0.17.3 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		deflate-0.7.19 \
		dlib-0.4.1 \
		downcast-rs-1.0.3 \
		either-1.5.0 \
		error-chain-0.10.0 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gif-0.10.1 \
		gl-0.10.0 \
		gl_generator-0.10.0 \
		gl_generator-0.9.0 \
		gleam-0.6.8 \
		glutin-0.19.0 \
		image-0.20.1 \
		inflate-0.4.4 \
		itoa-0.4.3 \
		jpeg-decoder-0.1.15 \
		khronos_api-2.2.0 \
		khronos_api-3.0.0 \
		lazy_static-0.2.11 \
		lazy_static-1.2.0 \
		libc-0.2.45 \
		libloading-0.5.0 \
		line_drawing-0.7.0 \
		lock_api-0.1.5 \
		log-0.3.9 \
		log-0.4.6 \
		lzw-0.10.0 \
		malloc_buf-0.0.6 \
		memmap-0.7.0 \
		memoffset-0.2.1 \
		metadeps-1.1.2 \
		nix-0.11.0 \
		nix-0.12.0 \
		nodrop-0.1.13 \
		num-0.1.42 \
		num-derive-0.2.3 \
		num-integer-0.1.39 \
		num-iter-0.1.37 \
		num-rational-0.2.1 \
		num-traits-0.2.6 \
		num_cpus-1.9.0 \
		objc-0.2.5 \
		ordered-float-1.0.1 \
		osmesa-sys-0.1.2 \
		owning_ref-0.4.0 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.1 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		png-0.12.0 \
		proc-macro2-0.4.24 \
		quote-0.6.10 \
		rand-0.3.22 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand-0.6.1 \
		rand_chacha-0.1.0 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.0 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		redox_syscall-0.1.44 \
		redox_termios-0.1.1 \
		rustc_version-0.2.3 \
		rusttype-0.7.3 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		sdl2-0.31.0 \
		sdl2-sys-0.31.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.82 \
		serde_derive-1.0.82 \
		serde_json-1.0.33 \
		shared_library-0.1.9 \
		simplelog-0.5.3 \
		smallvec-0.6.7 \
		smithay-client-toolkit-0.4.3 \
		stable_deref_trait-1.1.1 \
		stb_truetype-0.2.5 \
		strsim-0.7.0 \
		syn-0.15.23 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		tiff-0.2.1 \
		time-0.1.41 \
		toml-0.2.1 \
		toml-0.4.10 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		vec_map-0.8.1 \
		void-1.0.2 \
		walkdir-2.2.7 \
		wayland-client-0.21.7 \
		wayland-commons-0.21.7 \
		wayland-protocols-0.21.7 \
		wayland-scanner-0.21.7 \
		wayland-sys-0.21.7 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winit-0.18.0 \
		winres-0.1.8 \
		x11-dl-2.18.3 \
		xdg-2.2.0 \
		xml-rs-0.7.0 \
		xml-rs-0.8.0 \
		zmq-0.8.2 \
		zmq-sys-0.8.2

PLIST_FILES=	bin/${PORTNAME}
.for size in 16 32 48 64 256
PLIST_FILES+=	share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

PORTDOCS=	CHANGELOG.md README.md DEVELOPER-NOTES.md
INSTALLS_ICONS=		yes
DESKTOP_ENTRIES="Dose Response" "${COMMENT}" "${PORTNAME}" \
	"${PORTNAME}" "Games;" false

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for size in 16 32 48 64 256
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/assets/icon_${size}x${size}.png \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
