--- include/drm/drmP.h.orig	2017-09-19 02:47:48 UTC
+++ include/drm/drmP.h
@@ -137,6 +137,7 @@
 #include <drm/drm_mem_util.h>
 #include <drm/drm_mm.h>
 #include <drm/drm_os_freebsd.h>
+#include <drm/drm_ioctl.h>
 #include <uapi/drm/drm_sarea.h>
 #include <drm/drm_vma_manager.h>
 #include <linux/atomic.h>
@@ -388,48 +389,6 @@ void drm_printk(const char *level, unsigned int catego
 
 #define DRM_IF_VERSION(maj, min) (maj << 16 | min)
 
-/**
- * Ioctl function type.
- *
- * \param inode device inode.
- * \param file_priv DRM file private pointer.
- * \param cmd command.
- * \param arg argument.
- */
-typedef int drm_ioctl_t(struct drm_device *dev, void *data,
-			struct drm_file *file_priv);
-
-typedef int drm_ioctl_compat_t(struct file *filp, unsigned int cmd,
-			       unsigned long arg);
-
-#define DRM_IOCTL_NR(n)                ((n) & 0xff)
-
-
-#define DRM_MAJOR       226
-
-#define DRM_AUTH	0x1
-#define	DRM_MASTER	0x2
-#define DRM_ROOT_ONLY	0x4
-#define DRM_CONTROL_ALLOW 0x8
-#define DRM_UNLOCKED	0x10
-#define DRM_RENDER_ALLOW 0x20
-
-struct drm_ioctl_desc {
-	unsigned long cmd;
-	int flags;
-	drm_ioctl_t *func;
-	unsigned int cmd_drv;
-	char *name;
-};
-
-/**
- * Creates a driver or general drm_ioctl_desc array entry for the given
- * ioctl, for use by drm_ioctl().
- */
-
-#define DRM_IOCTL_DEF_DRV(ioctl, _func, _flags)			\
-	[DRM_IOCTL_NR(DRM_##ioctl)] = {.cmd = DRM_IOCTL_##ioctl, .func = _func, .flags = _flags, .cmd_drv = DRM_IOCTL_##ioctl, .name = #ioctl }
-
 /* Event queued up for userspace to read */
 struct drm_pending_event {
 	struct completion *completion;
@@ -1047,12 +1006,6 @@ static inline bool drm_is_primary_client(const struct 
 /*@{*/
 
 				/* Driver support (drm_drv.h) */
-extern int drm_ioctl_permit(u32 flags, struct drm_file *file_priv);
-extern long drm_ioctl(struct file *filp,
-		      unsigned int cmd, unsigned long arg);
-extern long drm_compat_ioctl(struct file *filp,
-			     unsigned int cmd, unsigned long arg);
-extern bool drm_ioctl_flags(unsigned int nr, unsigned int *flags);
 
 /* File Operations (drm_fops.c) */
 int drm_open(struct inode *inode, struct file *filp);
@@ -1072,12 +1025,6 @@ void drm_event_cancel_free(struct drm_device *dev,
 			   struct drm_pending_event *p);
 void drm_send_event_locked(struct drm_device *dev, struct drm_pending_event *e);
 void drm_send_event(struct drm_device *dev, struct drm_pending_event *e);
-
-/* Misc. IOCTL support (drm_ioctl.c) */
-int drm_noop(struct drm_device *dev, void *data,
-	     struct drm_file *file_priv);
-int drm_invalid_op(struct drm_device *dev, void *data,
-		   struct drm_file *file_priv);
 
 /* Cache management (drm_cache.c) */
 void drm_clflush_pages(vm_page_t *pages, unsigned long num_pages);
