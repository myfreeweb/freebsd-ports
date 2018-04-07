--- libretro-common/rthreads/rthreads.c.orig	2018-12-31 20:08:25 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -69,6 +69,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
