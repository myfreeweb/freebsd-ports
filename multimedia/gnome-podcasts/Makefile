# $FreeBSD$

PORTNAME=	gnome-podcasts
DISTVERSION=	0.4.6-158
CATEGORIES=	multimedia gnome
WRKSRC=		${WRKDIR}/podcasts-${GL_COMMIT}-${GL_COMMIT}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Podcast application for GNOME

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libhandy-0.0.so:x11-toolkits/libhandy

USES=		cargo gettext gnome meson pkgconfig python:3.5+,build \
		shebangfix sqlite:3 ssl tar:xz
USE_GNOME=	cairo gtk30
USE_GSTREAMER1=	bad
USE_GITLAB=	yes
USE_GITHUB=	nodefault

GL_SITE=		https://gitlab.gnome.org
GL_ACCOUNT=		World
GL_PROJECT=		podcasts
GL_COMMIT=		957b47680db08168ca5e79f6fc1c553a4e8c7a26
GH_TUPLE=		danigm:gettext-rs:c514bbe52ef892e3c0689eb474c564949d15e145:gettextrs \
			danigm:gettext-rs:c514bbe52ef892e3c0689eb474c564949d15e145:gettextsys \
			jugglerchris:rust-html2text:7e8ba71e1d1fa18bac8fb885b853b983d5069ec5:htmltext
CARGO_CRATES=		adler32-1.0.3 \
			aho-corasick-0.6.10 \
			aho-corasick-0.7.3 \
			ammonia-2.1.1 \
			ansi_term-0.11.0 \
			antidote-1.0.0 \
			arrayvec-0.4.10 \
			atk-0.6.0 \
			atk-sys-0.8.0 \
			atty-0.2.11 \
			autocfg-0.1.2 \
			backtrace-0.3.15 \
			backtrace-sys-0.1.28 \
			base64-0.10.1 \
			bitflags-1.0.4 \
			build_const-0.2.1 \
			byteorder-1.3.1 \
			bytes-0.4.12 \
			cairo-rs-0.6.0 \
			cairo-sys-rs-0.8.0 \
			cc-1.0.36 \
			cfg-if-0.1.7 \
			chrono-0.4.6 \
			cloudabi-0.0.3 \
			cookie-0.11.1 \
			cookie_store-0.5.1 \
			core-foundation-0.6.4 \
			core-foundation-sys-0.6.2 \
			crc-1.8.1 \
			crc32fast-1.2.0 \
			crossbeam-channel-0.3.8 \
			crossbeam-deque-0.2.0 \
			crossbeam-deque-0.7.1 \
			crossbeam-epoch-0.3.1 \
			crossbeam-epoch-0.7.1 \
			crossbeam-queue-0.1.2 \
			crossbeam-utils-0.2.2 \
			crossbeam-utils-0.6.5 \
			ctor-0.1.9 \
			darling-0.8.6 \
			darling_core-0.8.6 \
			darling_macro-0.8.6 \
			dbus-0.6.4 \
			debug_unreachable-0.1.1 \
			derive_builder-0.7.1 \
			derive_builder_core-0.4.1 \
			diesel-1.3.0 \
			diesel_derives-1.3.0 \
			diesel_migrations-1.3.0 \
			difference-2.0.0 \
			dtoa-0.4.4 \
			either-1.5.2 \
			encoding_rs-0.8.17 \
			error-chain-0.12.0 \
			failure-0.1.5 \
			failure_derive-0.1.5 \
			flate2-1.0.7 \
			fnv-1.0.6 \
			foreign-types-0.3.2 \
			foreign-types-shared-0.1.1 \
			fragile-0.3.0 \
			fuchsia-cprng-0.1.1 \
			fuchsia-zircon-0.3.3 \
			fuchsia-zircon-sys-0.3.3 \
			futf-0.1.4 \
			futures-0.1.26 \
			futures-cpupool-0.1.8 \
			gdk-0.10.0 \
			gdk-pixbuf-0.6.0 \
			gdk-pixbuf-sys-0.8.0 \
			gdk-sys-0.8.0 \
			gio-0.6.0 \
			gio-sys-0.8.0 \
			glib-0.7.1 \
			glib-sys-0.8.0 \
			glob-0.3.0 \
			gobject-sys-0.8.0 \
			gstreamer-0.13.0 \
			gstreamer-base-0.13.0 \
			gstreamer-base-sys-0.7.0 \
			gstreamer-player-0.13.0 \
			gstreamer-player-sys-0.7.0 \
			gstreamer-sys-0.7.0 \
			gstreamer-video-0.13.0 \
			gstreamer-video-sys-0.7.0 \
			gtk-0.6.0 \
			gtk-sys-0.8.0 \
			h2-0.1.18 \
			html5ever-0.22.5 \
			html5ever-0.23.0 \
			html5ever-atoms-0.3.0 \
			http-0.1.17 \
			httparse-1.3.3 \
			humansize-1.1.0 \
			hyper-0.12.28 \
			hyper-tls-0.3.2 \
			ident_case-1.0.1 \
			idna-0.1.5 \
			indexmap-1.0.2 \
			iovec-0.1.2 \
			itoa-0.4.4 \
			kernel32-sys-0.2.2 \
			lazy_static-0.2.11 \
			lazy_static-1.3.0 \
			lazycell-1.2.1 \
			libc-0.2.54 \
			libdbus-sys-0.1.5 \
			libhandy-0.3.0 \
			libhandy-sys-0.3.0 \
			libsqlite3-sys-0.9.3 \
			locale_config-0.2.2 \
			lock_api-0.1.5 \
			log-0.3.9 \
			log-0.4.6 \
			loggerv-0.7.1 \
			mac-0.1.1 \
			maplit-1.0.1 \
			markup5ever-0.7.5 \
			markup5ever-0.8.1 \
			matches-0.1.8 \
			memchr-2.2.0 \
			memoffset-0.2.1 \
			migrations_internals-1.3.0 \
			migrations_macros-1.3.0 \
			mime-0.2.6 \
			mime-0.3.13 \
			mime_guess-1.8.7 \
			mime_guess-2.0.0-alpha.6 \
			miniz_oxide-0.2.1 \
			miniz_oxide_c_api-0.2.1 \
			mio-0.6.16 \
			mio-uds-0.6.7 \
			miow-0.2.1 \
			mpris-player-0.3.0 \
			muldiv-0.2.0 \
			native-tls-0.2.3 \
			net2-0.2.33 \
			new_debug_unreachable-1.0.3 \
			nodrop-0.1.13 \
			num-integer-0.1.39 \
			num-rational-0.2.1 \
			num-traits-0.2.6 \
			num_cpus-1.10.0 \
			numtoa-0.1.0 \
			open-1.2.2 \
			openssl-0.10.22 \
			openssl-probe-0.1.2 \
			openssl-sys-0.9.46 \
			output_vt100-0.1.2 \
			owning_ref-0.4.0 \
			pango-0.6.0 \
			pango-sys-0.8.0 \
			parking_lot-0.7.1 \
			parking_lot_core-0.4.0 \
			percent-encoding-1.0.1 \
			phf-0.7.24 \
			phf_codegen-0.7.24 \
			phf_generator-0.7.24 \
			phf_shared-0.7.24 \
			pkg-config-0.3.14 \
			precomputed-hash-0.1.1 \
			pretty_assertions-0.6.1 \
			proc-macro2-0.3.8 \
			proc-macro2-0.4.30 \
			publicsuffix-1.5.2 \
			quick-xml-0.13.3 \
			quote-0.3.15 \
			quote-0.5.2 \
			quote-0.6.12 \
			r2d2-0.8.4 \
			rand-0.4.6 \
			rand-0.6.5 \
			rand_chacha-0.1.1 \
			rand_core-0.3.1 \
			rand_core-0.4.0 \
			rand_hc-0.1.0 \
			rand_isaac-0.1.1 \
			rand_jitter-0.1.4 \
			rand_os-0.1.3 \
			rand_pcg-0.1.2 \
			rand_xorshift-0.1.1 \
			rayon-1.0.3 \
			rayon-core-1.4.1 \
			rdrand-0.4.0 \
			redox_syscall-0.1.54 \
			redox_termios-0.1.1 \
			regex-0.2.11 \
			regex-1.1.6 \
			regex-syntax-0.5.6 \
			regex-syntax-0.6.6 \
			remove_dir_all-0.5.1 \
			reqwest-0.9.16 \
			rfc822_sanitizer-0.3.3 \
			rss-1.7.0 \
			rustc-demangle-0.1.14 \
			rustc_version-0.2.3 \
			ryu-0.2.8 \
			schannel-0.1.15 \
			scheduled-thread-pool-0.2.0 \
			scopeguard-0.3.3 \
			security-framework-0.3.1 \
			security-framework-sys-0.3.1 \
			semver-0.9.0 \
			semver-parser-0.7.0 \
			serde-0.9.15 \
			serde-1.0.91 \
			serde_derive-1.0.91 \
			serde_json-1.0.39 \
			serde_urlencoded-0.5.5 \
			siphasher-0.2.3 \
			slab-0.4.2 \
			smallvec-0.6.9 \
			stable_deref_trait-1.1.1 \
			string-0.1.3 \
			string_cache-0.5.2 \
			string_cache-0.7.3 \
			string_cache_codegen-0.4.2 \
			string_cache_shared-0.3.0 \
			syn-0.11.11 \
			syn-0.13.11 \
			syn-0.15.34 \
			synom-0.11.3 \
			synstructure-0.10.1 \
			tempdir-0.3.7 \
			tempfile-3.0.7 \
			tendril-0.4.1 \
			termion-1.5.2 \
			thread_local-0.3.6 \
			time-0.1.42 \
			tokio-0.1.19 \
			tokio-codec-0.1.1 \
			tokio-current-thread-0.1.6 \
			tokio-executor-0.1.7 \
			tokio-fs-0.1.6 \
			tokio-io-0.1.12 \
			tokio-reactor-0.1.9 \
			tokio-sync-0.1.5 \
			tokio-tcp-0.1.3 \
			tokio-threadpool-0.1.14 \
			tokio-timer-0.2.10 \
			tokio-trace-core-0.1.0 \
			tokio-udp-0.1.3 \
			tokio-uds-0.2.5 \
			try-lock-0.2.2 \
			try_from-0.3.2 \
			ucd-util-0.1.3 \
			unicase-1.4.2 \
			unicase-2.4.0 \
			unicode-bidi-0.3.4 \
			unicode-normalization-0.1.8 \
			unicode-width-0.1.5 \
			unicode-xid-0.0.4 \
			unicode-xid-0.1.0 \
			unreachable-0.1.1 \
			url-1.7.2 \
			utf-8-0.7.5 \
			utf8-ranges-1.0.2 \
			uuid-0.7.4 \
			vcpkg-0.2.6 \
			version_check-0.1.5 \
			void-1.0.2 \
			want-0.0.6 \
			winapi-0.2.8 \
			winapi-0.3.7 \
			winapi-build-0.1.1 \
			winapi-i686-pc-windows-gnu-0.4.0 \
			winapi-x86_64-pc-windows-gnu-0.4.0 \
			ws2_32-sys-0.2.1 \
			xdg-2.2.0 \
			xml-rs-0.8.0
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
