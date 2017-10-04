Try harder to allocate userptr
https://github.com/FreeBSDDesktop/freebsd-base-graphics/issues/132

--- src/intel/vulkan/anv_gem.c.orig	2017-09-17 23:03:22 UTC
+++ src/intel/vulkan/anv_gem.c
@@ -114,9 +114,16 @@ anv_gem_userptr(struct anv_device *device, void *mem, 
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
