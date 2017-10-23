Try harder to allocate userptr
https://github.com/FreeBSDDesktop/freebsd-base-graphics/issues/132

--- src/intel/vulkan/anv_gem.c.orig	2017-10-23 13:21:18 UTC
+++ src/intel/vulkan/anv_gem.c
@@ -31,6 +31,10 @@
 
 #include "anv_private.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 static int
 anv_ioctl(int fd, unsigned long request, void *arg)
 {
@@ -115,9 +119,16 @@ anv_gem_userptr(struct anv_device *device, void *mem, 
       .flags = 0,
    };
 
-   int ret = anv_ioctl(device->fd, DRM_IOCTL_I915_GEM_USERPTR, &userptr);
-   if (ret == -1)
+   int ret;
+retry:
+   ret = anv_ioctl(device->fd, DRM_IOCTL_I915_GEM_USERPTR, &userptr);
+   if (ret == -1) {
+      if (errno == ENODEV && userptr.flags == 0) {
+         userptr.flags = I915_USERPTR_UNSYNCHRONIZED;
+         goto retry;
+      }
       return 0;
+   }
 
    return userptr.handle;
 }
