--- i915/i915_ioc32.c.orig	2017-09-19 02:47:48 UTC
+++ i915/i915_ioc32.c
@@ -46,24 +46,24 @@ struct drm_i915_getparam32 {
 	u32 value;
 };
 
+extern int i915_getparam(struct drm_device *dev, void *data,
+			 struct drm_file *file_priv);
+
 static int compat_i915_getparam(struct file *file, unsigned int cmd,
 				unsigned long arg)
 {
+	drm_i915_getparam_t __user *request = (void __user *)arg;
 	struct drm_i915_getparam32 req32;
-	drm_i915_getparam_t __user *request;
 
-	if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
+	if (copy_from_user(&req32, request, sizeof(req32)))
 		return -EFAULT;
 
-	request = compat_alloc_user_space(sizeof(*request));
-	if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
-	    || __put_user(req32.param, &request->param)
-	    || __put_user((void __user *)(unsigned long)req32.value,
-			  &request->value))
+	if (put_user(req32.param, &request->param)
+	    || put_user(req32.value, &request->value))
 		return -EFAULT;
 
-	return drm_ioctl(file, DRM_IOCTL_I915_GETPARAM,
-			 (unsigned long)request);
+	return drm_ioctl_kernel(file, i915_getparam,
+			 request, DRM_AUTH|DRM_RENDER_ALLOW);
 }
 
 static drm_ioctl_compat_t *i915_compat_ioctls[] = {
