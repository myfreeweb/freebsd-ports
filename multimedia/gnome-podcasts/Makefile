# $FreeBSD$

PORTNAME=	gnome-podcasts
DISTVERSION=	0.4.8
CATEGORIES=	multimedia gnome
WRKSRC=		${WRKDIR}/podcasts-${GL_COMMIT}-${GL_COMMIT}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Podcast application for GNOME

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libhandy-0.0.so:x11-toolkits/libhandy0

USES=		cargo gettext gnome meson pkgconfig python:3.5+,build \
		shebangfix sqlite:3 ssl tar:xz
USE_GNOME=	cairo gtk30
USE_GSTREAMER1=	bad
USE_GITLAB=	yes
USE_GITHUB=	nodefault

GL_SITE=		https://gitlab.gnome.org
GL_ACCOUNT=		World
GL_PROJECT=		podcasts
GL_COMMIT=		9222cb80dae6b0d3e6a245d26b9e26c7f6ad3e61

GH_TUPLE=	danigm:gettext-rs:61938b9f5f1d3bdc31f9839f53fabe5ccf136a78:gettextrs
CARGO_CRATES=	addr2line-0.13.0 \
		adler-0.2.2 \
		aho-corasick-0.6.10 \
		aho-corasick-0.7.13 \
		ammonia-3.1.0 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		anyhow-1.0.31 \
		atk-0.8.0 \
		atk-sys-0.9.1 \
		atty-0.2.14 \
		autocfg-0.1.7 \
		autocfg-1.0.0 \
		backtrace-0.3.50 \
		base64-0.10.1 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		bytes-0.4.12 \
		bytes-0.5.5 \
		cairo-rs-0.8.1 \
		cairo-sys-rs-0.9.2 \
		cc-1.0.58 \
		cfg-if-0.1.10 \
		chrono-0.4.13 \
		cloudabi-0.0.3 \
		cloudabi-0.1.0 \
		cookie-0.12.0 \
		cookie_store-0.7.0 \
		core-foundation-0.7.0 \
		core-foundation-sys-0.7.0 \
		crc32fast-1.2.0 \
		crossbeam-channel-0.3.9 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.3 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.2 \
		ctor-0.1.15 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		dbus-0.6.5 \
		derive_builder-0.9.0 \
		derive_builder_core-0.9.0 \
		diesel-1.4.5 \
		diesel_derives-1.4.1 \
		diesel_migrations-1.4.0 \
		difference-2.0.0 \
		dtoa-0.4.6 \
		either-1.5.3 \
		encoding_rs-0.8.23 \
		error-chain-0.12.2 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		flate2-1.0.16 \
		fnv-1.0.7 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fragile-1.0.0 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futf-0.1.4 \
		futures-0.1.29 \
		futures-0.3.5 \
		futures-channel-0.3.5 \
		futures-core-0.3.5 \
		futures-cpupool-0.1.8 \
		futures-executor-0.3.5 \
		futures-io-0.3.5 \
		futures-macro-0.3.5 \
		futures-sink-0.3.5 \
		futures-task-0.3.5 \
		futures-util-0.3.5 \
		gdk-0.12.1 \
		gdk-pixbuf-0.8.0 \
		gdk-pixbuf-sys-0.9.1 \
		gdk-sys-0.9.1 \
		generator-0.6.21 \
		getrandom-0.1.14 \
		gimli-0.22.0 \
		gio-0.8.1 \
		gio-sys-0.9.1 \
		glib-0.9.3 \
		glib-sys-0.9.1 \
		glob-0.3.0 \
		gobject-sys-0.9.1 \
		gstreamer-0.15.7 \
		gstreamer-base-0.15.4 \
		gstreamer-base-sys-0.8.1 \
		gstreamer-player-0.15.5 \
		gstreamer-player-sys-0.8.1 \
		gstreamer-sys-0.8.1 \
		gstreamer-video-0.15.7 \
		gstreamer-video-sys-0.8.1 \
		gtk-0.8.1 \
		gtk-sys-0.9.2 \
		h2-0.1.26 \
		h2-0.2.5 \
		hermit-abi-0.1.15 \
		html2text-0.1.12 \
		html5ever-0.25.1 \
		http-0.1.21 \
		http-0.2.1 \
		http-body-0.1.0 \
		http-body-0.3.1 \
		httparse-1.3.4 \
		humansize-1.1.0 \
		hyper-0.12.35 \
		hyper-0.13.6 \
		hyper-tls-0.3.2 \
		hyper-tls-0.4.3 \
		ident_case-1.0.1 \
		idna-0.1.5 \
		idna-0.2.0 \
		indexmap-1.4.0 \
		instant-0.1.6 \
		iovec-0.1.4 \
		itoa-0.4.6 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		libc-0.2.72 \
		libdbus-sys-0.2.1 \
		libhandy-0.5.0 \
		libhandy-sys-0.5.0 \
		libsqlite3-sys-0.18.0 \
		locale_config-0.2.3 \
		lock_api-0.3.4 \
		lock_api-0.4.1 \
		log-0.4.8 \
		loggerv-0.7.2 \
		loom-0.3.4 \
		mac-0.1.1 \
		maplit-1.0.2 \
		markup5ever-0.10.0 \
		markup5ever_rcdom-0.1.0 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.3.3 \
		memoffset-0.5.5 \
		migrations_internals-1.4.1 \
		migrations_macros-1.4.2 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		miniz_oxide-0.4.0 \
		mio-0.6.22 \
		miow-0.2.1 \
		mpris-player-0.5.0 \
		muldiv-0.2.1 \
		native-tls-0.2.4 \
		net2-0.2.34 \
		new_debug_unreachable-1.0.4 \
		num-integer-0.1.43 \
		num-rational-0.2.4 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		object-0.20.0 \
		once_cell-1.4.0 \
		open-1.4.0 \
		openssl-0.10.30 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.58 \
		output_vt100-0.1.2 \
		pango-0.8.0 \
		pango-sys-0.9.1 \
		parking_lot-0.9.0 \
		parking_lot-0.11.0 \
		parking_lot_core-0.6.2 \
		parking_lot_core-0.8.0 \
		paste-0.1.18 \
		paste-impl-0.1.18 \
		percent-encoding-1.0.1 \
		percent-encoding-2.1.0 \
		phf-0.8.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_shared-0.8.0 \
		pin-project-0.4.22 \
		pin-project-internal-0.4.22 \
		pin-project-lite-0.1.7 \
		pin-utils-0.1.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.8 \
		precomputed-hash-0.1.1 \
		pretty_assertions-0.6.1 \
		proc-macro-hack-0.5.16 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.18 \
		publicsuffix-1.5.4 \
		quick-xml-0.17.2 \
		quote-1.0.7 \
		r2d2-0.8.9 \
		rand-0.4.6 \
		rand-0.6.5 \
		rand-0.7.3 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.2 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_pcg-0.1.2 \
		rand_pcg-0.2.1 \
		rand_xorshift-0.1.1 \
		rayon-1.3.1 \
		rayon-core-1.7.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		regex-0.2.11 \
		regex-1.3.9 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.3 \
		reqwest-0.9.24 \
		rfc822_sanitizer-0.3.3 \
		rss-1.9.0 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		schannel-0.1.19 \
		scheduled-thread-pool-0.2.5 \
		scoped-tls-0.1.2 \
		scopeguard-1.1.0 \
		security-framework-0.4.4 \
		security-framework-sys-0.4.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.114 \
		serde_derive-1.0.114 \
		serde_json-1.0.56 \
		serde_urlencoded-0.5.5 \
		siphasher-0.3.3 \
		slab-0.4.2 \
		smallvec-0.6.13 \
		smallvec-1.4.1 \
		socket2-0.3.12 \
		string-0.2.1 \
		string_cache-0.8.0 \
		string_cache_codegen-0.5.1 \
		strsim-0.9.3 \
		syn-1.0.33 \
		synstructure-0.12.4 \
		tempdir-0.3.7 \
		tempfile-3.1.0 \
		tendril-0.4.1 \
		thiserror-1.0.20 \
		thiserror-impl-1.0.20 \
		thread_local-0.3.6 \
		thread_local-1.0.1 \
		time-0.1.43 \
		tinyvec-0.3.3 \
		tokio-0.1.22 \
		tokio-0.2.21 \
		tokio-buf-0.1.1 \
		tokio-current-thread-0.1.7 \
		tokio-executor-0.1.10 \
		tokio-io-0.1.13 \
		tokio-macros-0.2.5 \
		tokio-reactor-0.1.12 \
		tokio-sync-0.1.8 \
		tokio-tcp-0.1.4 \
		tokio-threadpool-0.1.18 \
		tokio-timer-0.2.13 \
		tokio-tls-0.3.1 \
		tokio-util-0.3.1 \
		tower-service-0.3.0 \
		try-lock-0.2.2 \
		try_from-0.3.2 \
		ucd-util-0.1.8 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-1.7.2 \
		url-2.1.1 \
		utf-8-0.7.5 \
		utf8-ranges-1.0.4 \
		uuid-0.7.4 \
		vcpkg-0.2.10 \
		version_check-0.9.2 \
		want-0.2.0 \
		want-0.3.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.6.2 \
		ws2_32-sys-0.2.1 \
		xdg-2.2.0 \
		xml-rs-0.8.3 \
		xml5ever-0.16.1
CARGO_USE_GITHUB=	yes

CARGO_CONFIGURE=	no
CARGO_BUILD=		no
CARGO_INSTALL=		no
# cargo.mk doesn't auto add because of the github version
CARGO_ENV+=		GETTEXT_DIR=${LOCALBASE}
CONFIGURE_ENV+=		${CARGO_ENV}
MAKE_ENV+=		${CARGO_ENV}
SHEBANG_FILES=		scripts/*.sh
BINARY_ALIAS=		python3=${PYTHON_CMD}
GLIB_SCHEMAS=		org.gnome.Podcasts.gschema.xml
INSTALLS_ICONS=		yes

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gnome-podcasts

.include <bsd.port.mk>
