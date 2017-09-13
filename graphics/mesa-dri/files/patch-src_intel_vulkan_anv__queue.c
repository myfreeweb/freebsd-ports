Drop header that was never used

--- src/intel/vulkan/anv_queue.c.orig	2017-08-12 16:09:52 UTC
+++ src/intel/vulkan/anv_queue.c
@@ -27,7 +27,6 @@
 
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/eventfd.h>
 
 #include "anv_private.h"
 #include "vk_util.h"
