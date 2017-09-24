--- i915/i915_drv.c.orig	2017-09-19 02:47:48 UTC
+++ i915/i915_drv.c
@@ -230,7 +230,7 @@ static void intel_detect_pch(struct drm_device *dev)
 	pci_dev_put(pch);
 }
 
-static int i915_getparam(struct drm_device *dev, void *data,
+int i915_getparam(struct drm_device *dev, void *data,
 			 struct drm_file *file_priv)
 {
 	struct drm_i915_private *dev_priv = to_i915(dev);
