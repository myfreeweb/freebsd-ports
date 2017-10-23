--- src/intel/vulkan/anv_queue.c.orig	2017-10-23 13:21:18 UTC
+++ src/intel/vulkan/anv_queue.c
@@ -27,13 +27,16 @@
 
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/eventfd.h>
 
 #include "anv_private.h"
 #include "vk_util.h"
 
 #include "genxml/gen7_pack.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 VkResult
 anv_device_execbuf(struct anv_device *device,
                    struct drm_i915_gem_execbuffer2 *execbuf,
@@ -103,7 +106,7 @@ anv_device_submit_simple_batch(struct anv_device *devi
    if (result != VK_SUCCESS)
       goto fail;
 
-   result = anv_device_wait(device, &bo, INT64_MAX);
+   result = anv_device_wait(device, &bo, INT32_MAX);
 
  fail:
    anv_bo_pool_free(&device->batch_bo_pool, &bo);
