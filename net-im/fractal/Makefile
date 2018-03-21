# $FreeBSD$

PORTNAME=	fractal
DISTVERSION=	0.1.19
CATEGORIES=	net-im

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Matrix IM client

LICENSE=	GPLv3+

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgmp.so:math/gmp

USES=		ssl cargo meson shebangfix
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	danigm
GL_COMMIT=	1fe7b79b1c29da1c24dc913b4d7983eadb820b2d
USE_GNOME=	gtk30 cairo
INSTALLS_ICONS=	yes
SHEBANG_FILES=	${WRKSRC}/scripts/*.sh
SHEBANG_LANG=	bash
MAKE_ENV+=	${CARGO_ENV}

CARGO_TARGET_DIR=	${WRKSRC}/target
CARGO_BUILD=		no
CARGO_CONFIGURE=	no
CARGO_INSTALL=		no
CARGO_TEST=		no

CARGO_CRATES=	adler32-1.0.2 \
		aho-corasick-0.6.4 \
		arrayvec-0.4.7 \
		atk-sys-0.5.0  \
		backtrace-0.3.5  \
		backtrace-sys-0.1.16  \
		base64-0.9.0  \
		bitflags-0.9.1  \
		bitflags-1.0.1  \
		block-0.1.6 \
		build_const-0.2.0 \
		byteorder-1.2.1 \
		bytes-0.4.6 \
		c_vec-1.2.1 \
		cairo-rs-0.3.0 \
		cairo-sys-rs-0.5.0 \
		cc-1.0.8 \
		cfg-if-0.1.2 \
		chrono-0.4.0 \
		core-foundation-0.2.3 \
		core-foundation-sys-0.2.3 \
		crc-1.7.0 \
		crossbeam-deque-0.3.0 \
		crossbeam-epoch-0.4.0 \
		crossbeam-utils-0.2.2 \
		dbus-0.2.3 \
		dbus-0.4.1 \
		dtoa-0.4.2 \
		encoding_rs-0.7.2 \
		error-chain-0.10.0 \
		failure-0.1.1 \
		failure_derive-0.1.1 \
		fixedbitset-0.1.8 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.18 \
		futures-cpupool-0.1.8 \
		gcc-0.3.54 \
		gdk-0.7.0 \
		gdk-pixbuf-0.3.0 \
		gdk-pixbuf-sys-0.5.0 \
		gdk-sys-0.5.0 \
		gio-0.3.0 \
		gio-sys-0.5.0 \
		glib-0.4.1 \
		glib-sys-0.5.0 \
		gobject-sys-0.5.0 \
		gtk-0.3.0 \
		gtk-sys-0.5.0 \
		httparse-1.2.4 \
		hyper-0.11.22 \
		hyper-tls-0.1.2 \
		idna-0.1.4 \
		iovec-0.1.2 \
		itoa-0.3.4 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.0.0 \
		lazycell-0.6.0 \
		libc-0.2.39 \
		libflate-0.1.14 \
		log-0.3.9 \
		log-0.4.1 \
		mac-notification-sys-0.1.3 \
		malloc_buf-0.0.6 \
		matches-0.1.6 \
		memchr-2.0.1 \
		memoffset-0.2.1 \
		mime-0.3.5 \
		mime_guess-2.0.0-alpha.4 \
		mio-0.6.14 \
		miow-0.2.1 \
		native-tls-0.1.5 \
		net2-0.2.32 \
		nodrop-0.1.12 \
		nom-2.2.1 \
		notify-rust-3.4.2 \
		num-0.1.42 \
		num-bigint-0.1.43 \
		num-complex-0.1.43 \
		num-integer-0.1.36 \
		num-iter-0.1.35 \
		num-rational-0.1.42 \
		num-traits-0.2.1 \
		num_cpus-1.8.0 \
		objc-0.2.2 \
		objc-foundation-0.1.1 \
		objc_id-0.1.0 \
		openssl-0.9.24 \
		openssl-sys-0.9.27 \
		ordermap-0.3.5 \
		pango-0.3.0 \
		pango-sys-0.5.0 \
		percent-encoding-1.0.1 \
		petgraph-0.4.11 \
		phf-0.7.21 \
		phf_codegen-0.7.21 \
		phf_generator-0.7.21 \
		phf_shared-0.7.21 \
		pkg-config-0.3.9 \
		proc-macro2-0.2.3 \
		quote-0.3.15 \
		quote-0.4.2 \
		rand-0.3.22 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		regex-0.2.10 \
		regex-syntax-0.5.3 \
		relay-0.1.1 \
		remove_dir_all-0.3.0 \
		reqwest-0.8.5 \
		rust-crypto-0.2.36 \
		rust-gmp-0.3.2 \
		rustc-demangle-0.1.7 \
		rustc-serialize-0.3.24 \
		safemem-0.2.0 \
		schannel-0.1.11 \
		scoped-tls-0.1.1 \
		scopeguard-0.3.3 \
		secret-service-0.4.0 \
		security-framework-0.1.16 \
		security-framework-sys-0.1.16 \
		serde-1.0.33 \
		serde_derive-1.0.33 \
		serde_derive_internals-0.21.0 \
		serde_json-1.0.11 \
		serde_urlencoded-0.5.1 \
		siphasher-0.2.2 \
		slab-0.3.0 \
		slab-0.4.0 \
		smallvec-0.2.1 \
		syn-0.11.11 \
		syn-0.12.14 \
		synom-0.11.3 \
		synstructure-0.6.1 \
		take-0.1.0 \
		tempdir-0.3.6 \
		thread_local-0.3.5 \
		time-0.1.39 \
		tokio-0.1.3 \
		tokio-core-0.1.15 \
		tokio-executor-0.1.0 \
		tokio-io-0.1.6 \
		tokio-proto-0.1.1 \
		tokio-reactor-0.1.0 \
		tokio-service-0.1.0 \
		tokio-threadpool-0.1.0 \
		tokio-tls-0.1.4 \
		tree_magic-0.2.0 \
		ucd-util-0.1.1 \
		unicase-1.4.2 \
		unicase-2.1.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.5 \
		unicode-segmentation-1.2.0 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		url-1.7.0 \
		utf8-ranges-1.0.0 \
		uuid-0.5.1 \
		vcpkg-0.2.2 \
		version_check-0.1.3 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

# XXX: copy pasted from cargo.mk to avoid override
pre-configure:
	@${MKDIR} ${WRKDIR}/.cargo
	@${ECHO_CMD} "[source.cargo]" > ${WRKDIR}/.cargo/config
	@${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> ${WRKDIR}/.cargo/config
	@${ECHO_CMD} "[source.crates-io]" >> ${WRKDIR}/.cargo/config
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${WRKDIR}/.cargo/config
	@if ! ${GREP} -qF '[profile.release]' ${CARGO_CARGOTOML}; then \
		${ECHO_CMD} "" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "[profile.release]" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "opt-level = 2" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "debug = false" >> ${CARGO_CARGOTOML}; \
	fi
	@${CARGO_CARGO_RUN} update \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_UPDATE_ARGS}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fractal

.include <bsd.port.mk>
