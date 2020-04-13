--- cogl/winsys/cogl-winsys-egl.c.orig	2020-04-13 18:42:11 UTC
+++ cogl/winsys/cogl-winsys-egl.c
@@ -57,6 +57,9 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#ifdef COGL_HAS_WAYLAND_EGL_SERVER_SUPPORT
+#include <EGL/eglmesaext.h>
+#endif
 
 #ifndef EGL_KHR_create_context
 #define EGL_CONTEXT_MAJOR_VERSION_KHR           0x3098
