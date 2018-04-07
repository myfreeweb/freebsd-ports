--- libretro-common/rthreads/rthreads.c.orig	2018-02-19 12:43:32 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -66,6 +66,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
