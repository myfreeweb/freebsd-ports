--- cogl/cogl-texture-2d.c.orig	2020-04-13 18:40:13 UTC
+++ cogl/cogl-texture-2d.c
@@ -56,6 +56,7 @@
 #include <math.h>
 
 #ifdef COGL_HAS_WAYLAND_EGL_SERVER_SUPPORT
+#include <EGL/eglmesaext.h>
 #include "cogl-wayland-server.h"
 #endif
 
