--- src/gallium/drivers/swr/swr_fence.cpp.orig	2017-12-10 12:07:17 UTC
+++ src/gallium/drivers/swr/swr_fence.cpp
@@ -29,8 +29,11 @@
 #include "swr_screen.h"
 #include "swr_fence.h"
 
+
 #if defined(PIPE_CC_MSVC) // portable thread yield
    #define sched_yield SwitchToThread
+#elif defined(__FreeBSD__)
+   #include <sched.h>
 #endif
 
 /*
