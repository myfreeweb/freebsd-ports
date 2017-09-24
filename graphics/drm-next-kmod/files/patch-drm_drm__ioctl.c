--- drm/drm_ioctl.c.orig	2017-09-19 02:47:48 UTC
+++ drm/drm_ioctl.c
@@ -95,7 +95,7 @@
  * broken.
  */
 
-static int drm_version(struct drm_device *dev, void *data,
+int drm_version(struct drm_device *dev, void *data,
 		       struct drm_file *file_priv);
 
 /*
@@ -109,7 +109,7 @@ static int drm_version(struct drm_device *dev, void *d
  *
  * Copies the bus id from drm_device::unique into user space.
  */
-static int drm_getunique(struct drm_device *dev, void *data,
+int drm_getunique(struct drm_device *dev, void *data,
 		  struct drm_file *file_priv)
 {
 	struct drm_unique *u = data;
@@ -170,7 +170,7 @@ static int drm_set_busid(struct drm_device *dev, struc
  * Searches for the client with the specified index and copies its information
  * into userspace
  */
-static int drm_getclient(struct drm_device *dev, void *data,
+int drm_getclient(struct drm_device *dev, void *data,
 		  struct drm_file *file_priv)
 {
 	struct drm_client *client = data;
@@ -447,7 +447,7 @@ static int drm_copy_field(char __user *buf, size_t *bu
  *
  * Fills in the version information in \p arg.
  */
-static int drm_version(struct drm_device *dev, void *data,
+int drm_version(struct drm_device *dev, void *data,
 		       struct drm_file *file_priv)
 {
 	struct drm_version *version = data;
@@ -642,6 +642,33 @@ static const struct drm_ioctl_desc drm_ioctls[] = {
 
 #define DRM_CORE_IOCTL_COUNT	ARRAY_SIZE( drm_ioctls )
 
+
+long drm_ioctl_kernel(struct file *file, drm_ioctl_t *func, void *kdata,
+		      u32 flags)
+{
+	struct drm_file *file_priv = file->private_data;
+	struct drm_device *dev = file_priv->minor->dev;
+	int retcode;
+
+	if (drm_device_is_unplugged(dev))
+		return -ENODEV;
+
+	retcode = drm_ioctl_permit(flags, file_priv);
+	if (unlikely(retcode))
+		return retcode;
+
+	/* Enforce sane locking for modern driver ioctls. */
+	if (!drm_core_check_feature(dev, DRIVER_LEGACY) ||
+	    (flags & DRM_UNLOCKED))
+		retcode = func(dev, kdata, file_priv);
+	else {
+		mutex_lock(&drm_global_mutex);
+		retcode = func(dev, kdata, file_priv);
+		mutex_unlock(&drm_global_mutex);
+	}
+	return retcode;
+}
+
 /**
  * drm_ioctl - ioctl callback implementation for DRM drivers
  * @filp: file this ioctl is called on
@@ -709,10 +736,6 @@ long drm_ioctl(struct file *filp,
 		goto err_i1;
 	}
 
-	retcode = drm_ioctl_permit(ioctl->flags, file_priv);
-	if (unlikely(retcode))
-		goto err_i1;
-
 	if (ksize <= sizeof(stack_kdata)) {
 		kdata = stack_kdata;
 	} else {
@@ -731,17 +754,7 @@ long drm_ioctl(struct file *filp,
 	if (ksize > in_size)
 		memset(kdata + in_size, 0, ksize - in_size);
 
-	/* Enforce sane locking for modern driver ioctls. Core ioctls are
-	 * too messy still. */
-	if ((!drm_core_check_feature(dev, DRIVER_LEGACY) && is_driver_ioctl) ||
-	    (ioctl->flags & DRM_UNLOCKED))
-		retcode = func(dev, kdata, file_priv);
-	else {
-		mutex_lock(&drm_global_mutex);
-		retcode = func(dev, kdata, file_priv);
-		mutex_unlock(&drm_global_mutex);
-	}
-
+	retcode = drm_ioctl_kernel(filp, func, kdata, ioctl->flags);
 	if (copy_to_user((void __user *)arg, kdata, out_size) != 0)
 		retcode = -EFAULT;
 
