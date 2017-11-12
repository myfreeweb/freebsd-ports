--- clients/desktop-shell.c.orig	2016-09-17 07:06:45 UTC
+++ clients/desktop-shell.c
@@ -40,6 +40,7 @@
 #include <libgen.h>
 #include <ctype.h>
 #include <time.h>
+#include <signal.h>
 
 #include <wayland-client.h>
 #include "window.h"
@@ -49,6 +50,8 @@
 #include "shared/xalloc.h"
 #include "shared/zalloc.h"
 
+#define program_invocation_short_name getprogname()
+
 #include "weston-desktop-shell-client-protocol.h"
 
 #define DEFAULT_CLOCK_FORMAT CLOCK_FORMAT_MINUTES
