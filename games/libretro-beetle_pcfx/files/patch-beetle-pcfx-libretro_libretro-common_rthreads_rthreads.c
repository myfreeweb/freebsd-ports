--- beetle-pcfx-libretro/libretro-common/rthreads/rthreads.c.orig	2019-10-28 21:40:46.846752000 -0300
+++ beetle-pcfx-libretro/libretro-common/rthreads/rthreads.c	2019-10-28 21:43:12.176283000 -0300
@@ -66,6 +66,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h> 
+
 struct thread_data
 {
    void (*func)(void*);
