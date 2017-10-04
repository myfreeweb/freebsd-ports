- Drop header that was never used
- Work around early timeouts with I915_USERPTR_UNSYNCHRONIZED

--- src/intel/vulkan/anv_queue.c.orig	2017-08-12 16:09:52 UTC
+++ src/intel/vulkan/anv_queue.c
@@ -27,7 +27,6 @@
 
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/eventfd.h>
 
 #include "anv_private.h"
 #include "vk_util.h"
@@ -102,7 +102,7 @@ anv_device_submit_simple_batch(struct anv_device *devi
    if (result != VK_SUCCESS)
       goto fail;
 
-   result = anv_device_wait(device, &bo, INT64_MAX);
+   result = anv_device_wait(device, &bo, INT32_MAX);
 
  fail:
    anv_bo_pool_free(&device->batch_bo_pool, &bo);
Drop header that was never used

--- src/intel/vulkan/anv_queue.c.orig	2017-08-12 16:09:52 UTC
+++ src/intel/vulkan/anv_queue.c
@@ -27,7 +27,6 @@
 
 #include <fcntl.h>
 #include <unistd.h>
-#include <sys/eventfd.h>
 
 #include "anv_private.h"
 #include "vk_util.h"
