--- src/util/dzl-macros.h.orig	2017-12-12 03:19:46 UTC
+++ src/util/dzl-macros.h
@@ -25,6 +25,8 @@
 #ifdef __linux__
 # include <sys/types.h>
 # include <sys/syscall.h>
+#else
+# include <pthread_np.h>
 #endif
 
 G_BEGIN_DECLS
@@ -93,10 +95,10 @@ dzl_assert_is_main_thread (void)
   GThread *self = g_thread_self ();
 
   if G_LIKELY (main == self)
-    return TRUE;
+    return;
 
   /* Slow path, rely on task id == process id */
-  if ((pid_t)syscall (SYS_gettid) == getpid ())
+  if (pthread_main_np())
     {
       /* Allow for fast path next time */
       main = self;
