--- libweston/compositor.h.orig	2016-09-17 07:06:45 UTC
+++ libweston/compositor.h
@@ -1558,6 +1558,7 @@ weston_compositor_create(struct wl_displ
 enum weston_compositor_backend {
 	WESTON_BACKEND_DRM,
 	WESTON_BACKEND_FBDEV,
+	WESTON_BACKEND_SCFB,
 	WESTON_BACKEND_HEADLESS,
 	WESTON_BACKEND_RDP,
 	WESTON_BACKEND_WAYLAND,
