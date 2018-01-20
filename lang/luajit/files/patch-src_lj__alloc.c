--- src/lj_alloc.c.orig	2019-05-20 18:39:52 UTC
+++ src/lj_alloc.c
@@ -343,20 +343,6 @@ static void *CALL_MMAP(size_t size)
 }
 #endif

-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !LJ_TARGET_PS4
-
-#include <sys/resource.h>
-
-static void init_mmap(void)
-{
-  struct rlimit rlim;
-  rlim.rlim_cur = rlim.rlim_max = 0x10000;
-  setrlimit(RLIMIT_DATA, &rlim);  /* Ignore result. May fail later. */
-}
-#define INIT_MMAP()	init_mmap()
-
-#endif
-
 static int CALL_MUNMAP(void *ptr, size_t size)
 {
   int olderr = errno;
