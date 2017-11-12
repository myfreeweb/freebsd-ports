--- compositor/main.c.orig	2016-09-17 07:06:45 UTC
+++ compositor/main.c
@@ -41,7 +41,9 @@
 #include <sys/socket.h>
 #include <libinput.h>
 #include <sys/time.h>
-#include <linux/limits.h>
+/* #include <linux/limits.h> */
+#include <limits.h>
+#define PATH_MAX _POSIX_PATH_MAX
 
 #ifdef HAVE_LIBUNWIND
 #define UNW_LOCAL_ONLY
@@ -61,6 +63,7 @@
 #include "compositor-headless.h"
 #include "compositor-rdp.h"
 #include "compositor-fbdev.h"
+#include "compositor-scfb.h"
 #include "compositor-x11.h"
 #include "compositor-wayland.h"
 
@@ -494,6 +497,9 @@ usage(int error_code)
 #if defined(BUILD_FBDEV_COMPOSITOR)
 			"\t\t\t\tfbdev-backend.so\n"
 #endif
+#if defined(BUILD_SCFB_COMPOSITOR)
+			"\t\t\t\tscfb-backend.so\n"
+#endif
 #if defined(BUILD_HEADLESS_COMPOSITOR)
 			"\t\t\t\theadless-backend.so\n"
 #endif
@@ -533,6 +539,14 @@ usage(int error_code)
 		"\n");
 #endif
 
+#if defined(BUILD_SCFB_COMPOSITOR)
+	fprintf(stderr,
+		"Options for scfb-backend.so:\n\n"
+		"  --tty=TTY\t\tThe tty to use\n"
+		"  --device=DEVICE\tThe framebuffer device to use\n"
+		"\n");
+#endif
+
 #if defined(BUILD_HEADLESS_COMPOSITOR)
 	fprintf(stderr,
 		"Options for headless-backend.so:\n\n"
@@ -636,9 +650,9 @@ clock_name(clockid_t clk_id)
 	static const char *names[] = {
 		[CLOCK_REALTIME] =		"CLOCK_REALTIME",
 		[CLOCK_MONOTONIC] =		"CLOCK_MONOTONIC",
-		[CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW",
-		[CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE",
-		[CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE",
+		/* [CLOCK_MONOTONIC_RAW] =		"CLOCK_MONOTONIC_RAW", */
+		/* [CLOCK_REALTIME_COARSE] =	"CLOCK_REALTIME_COARSE", */
+		/* [CLOCK_MONOTONIC_COARSE] =	"CLOCK_MONOTONIC_COARSE", */
 #ifdef CLOCK_BOOTTIME
 		[CLOCK_BOOTTIME] =		"CLOCK_BOOTTIME",
 #endif
@@ -1170,6 +1184,44 @@ load_fbdev_backend(struct weston_composi
 }
 
 static int
+load_scfb_backend(struct weston_compositor *c,
+				  int *argc, char **argv, struct weston_config *wc)
+{
+	struct weston_scfb_backend_config config = {{ 0, }};
+	struct weston_config_section *section;
+	char *s = NULL;
+	int ret = 0;
+
+	const struct weston_option scfb_options[] = {
+		{ WESTON_OPTION_INTEGER, "tty", 0, &config.tty },
+		{ WESTON_OPTION_STRING, "device", 0, &config.device },
+	};
+
+	parse_options(scfb_options, ARRAY_LENGTH(scfb_options), argc, argv);
+
+	if (!config.device)
+		config.device = strdup("/dev/ttyv1");
+
+	section = weston_config_get_section(wc, "output", "name", "scfb");
+	weston_config_section_get_string(section, "transform", &s, "normal");
+	if (weston_parse_transform(s, &config.output_transform) < 0)
+		weston_log("Invalid transform \"%s\" for output scfb\n", s);
+	free(s);
+
+	config.base.struct_version = WESTON_SCFB_BACKEND_CONFIG_VERSION;
+	config.base.struct_size = sizeof(struct weston_scfb_backend_config);
+	config.configure_device = configure_input_device;
+
+	/* load the actual wayland backend and configure it */
+	ret = weston_compositor_load_backend(c, WESTON_BACKEND_SCFB,
+					     &config.base);
+
+	free(config.device);
+
+	return ret;
+}
+
+static int
 weston_x11_backend_config_append_output_config(struct weston_x11_backend_config *config,
 					       struct weston_x11_backend_output_config *output_config) {
 	struct weston_x11_backend_output_config *new_outputs;
@@ -1536,6 +1588,8 @@ load_backend(struct weston_compositor *c
 		return load_rdp_backend(compositor, argc, argv, config);
 	else if (strstr(backend, "fbdev-backend.so"))
 		return load_fbdev_backend(compositor, argc, argv, config);
+	else if (strstr(backend, "scfb-backend.so"))
+		return load_scfb_backend(compositor, argc, argv, config);
 	else if (strstr(backend, "drm-backend.so"))
 		return load_drm_backend(compositor, argc, argv, config);
 	else if (strstr(backend, "x11-backend.so"))
