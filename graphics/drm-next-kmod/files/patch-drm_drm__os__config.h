--- drm/drm_os_config.h.orig	2017-09-19 02:47:48 UTC
+++ drm/drm_os_config.h
@@ -2,6 +2,7 @@
 #define DRM_OS_CONFIG_H_ 
 
 #define CONFIG_DEBUG_FS 1
+#define COMPAT_FREEBSD32 1
 #ifdef COMPAT_FREEBSD32
 #define CONFIG_COMPAT 1
 #endif
@@ -27,10 +28,6 @@
 #define	CONFIG_ACPI_SLEEP 1 
 #define	CONFIG_DRM_I915_KMS 1
 #undef	CONFIG_INTEL_IOMMU
-#endif
-
-#ifdef COMPAT_FREEBSD32
-#define	CONFIG_COMPAT
 #endif
 
 #define	CONFIG_AGP	1
