We build the main port without pulse/gstreamer deps,
but we do want them to be loaded if installed

--- src/driver-order.c.orig	2020-12-05 16:02:56 UTC
+++ src/driver-order.c
@@ -30,18 +30,14 @@
 #include "driver-order.h"
 
 const char* const ca_driver_order[] = {
-#ifdef HAVE_PULSE
         "pulse",
-#endif
 #ifdef HAVE_ALSA
         "alsa",
 #endif
 #ifdef HAVE_OSS
         "oss",
 #endif
-#ifdef HAVE_GSTREAMER
         "gstreamer",
-#endif
         /* ... */
         NULL
 };
