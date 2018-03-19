--- kitty/threading.h.orig	2018-03-17 12:15:57 UTC
+++ kitty/threading.h
@@ -11,6 +11,8 @@
 #ifdef __APPLE__
 // I cant figure out how to get pthread.h to include this definition on macOS. MACOSX_DEPLOYMENT_TARGET does not work.
 extern int pthread_setname_np(const char *name);
+#elif __FreeBSD__
+#include <pthread_np.h>
 #else
 // Need _GNU_SOURCE for pthread_setname_np on linux and that causes other issues on systems with old glibc
 extern int pthread_setname_np(pthread_t, const char *name);
@@ -21,6 +23,8 @@ set_thread_name(const char *name) {
     int ret = 0;
 #ifdef __APPLE__
     ret = pthread_setname_np(name);
+#elif __FreeBSD__
+    pthread_set_name_np(pthread_self(), name);
 #else
     ret = pthread_setname_np(pthread_self(), name);
 #endif
