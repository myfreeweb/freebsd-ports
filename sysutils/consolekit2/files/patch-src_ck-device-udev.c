How CK sees our drm devices:
major 1 minor 104 subsystem # sysname 0 devnode /dev/drm/0 active ? TRUE

(seems like symlinks get resolved)

--- src/ck-device-udev.c.orig	2017-06-02 01:31:44 UTC
+++ src/ck-device-udev.c
@@ -391,13 +391,16 @@ ck_device_new (guint    major,
         /* Start with other device as a default, we have special things
          * we do with DRM and EVDEV devices so find and tag them */
         device->category = DEVICE_OTHER;
-        if (g_strcmp0 (subsystem, "drm") == 0)
+        if ((g_strcmp0 (subsystem, "drm") == 0 && g_str_has_prefix (sysname, "card"))
+#ifndef __linux__
+                        /* on BSD, the dri/card0 -> drm/0 symlink gets resolved,
+                         * and subsystem is not emulated by libudev-devd */
+                        || strstr (device->devnode, "drm") != NULL
+#endif
+           )
         {
-                if (g_str_has_prefix (sysname, "card"))
-                {
-                        g_debug ("DEVICE_DRM");
-                        device->category = DEVICE_DRM;
-                }
+                g_debug ("DEVICE_DRM");
+                device->category = DEVICE_DRM;
         }
         else if (g_strcmp0 (subsystem, "input") == 0)
         {
