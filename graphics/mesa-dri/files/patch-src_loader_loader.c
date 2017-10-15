https://bugs.freedesktop.org/show_bug.cgi?id=103283

--- src/loader/loader.c.orig	2017-10-15 13:07:49 UTC
+++ src/loader/loader.c
@@ -312,18 +312,7 @@ loader_get_pci_id_for_fd(int fd, int *vendor_id, int *
 static char *
 drm_get_device_name_for_fd(int fd)
 {
-   unsigned int maj, min;
-   char buf[0x40];
-   int n;
-
-   if (dev_node_from_fd(fd, &maj, &min) < 0)
-      return NULL;
-
-   n = snprintf(buf, sizeof(buf), DRM_DEV_NAME, DRM_DIR_NAME, min);
-   if (n == -1 || n >= sizeof(buf))
-      return NULL;
-
-   return strdup(buf);
+   return drmGetDeviceNameFromFd2(fd);
 }
 #endif
 
