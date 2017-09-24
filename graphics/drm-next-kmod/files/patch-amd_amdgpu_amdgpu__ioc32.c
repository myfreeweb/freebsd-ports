--- amd/amdgpu/amdgpu_ioc32.c.orig	2017-09-19 02:47:48 UTC
+++ amd/amdgpu/amdgpu_ioc32.c
@@ -31,8 +31,10 @@
 
 #include <drm/drmP.h>
 #include <drm/amdgpu_drm.h>
+#include "amdgpu.h"
 #include "amdgpu_drv.h"
 
+#ifdef CONFIG_COMPAT
 long amdgpu_kms_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
 {
 	unsigned int nr = DRM_IOCTL_NR(cmd);
@@ -45,3 +47,4 @@ long amdgpu_kms_compat_ioctl(struct file *filp, unsign
 
 	return ret;
 }
+#endif
