--- libweston/compositor-drm.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/compositor-drm.c
@@ -34,7 +34,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <linux/input.h>
-#include <linux/vt.h>
+//#include <linux/vt.h>
 #include <assert.h>
 #include <sys/mman.h>
 #include <dlfcn.h>
@@ -2801,18 +2801,21 @@ session_notify(struct wl_listener *liste
 	struct drm_output *output;
 
 	if (compositor->session_active) {
-		weston_log("activating session\n");
+		weston_log("%s: activating session\n",__func__);
 		compositor->state = b->prev_state;
 		drm_backend_set_modes(b);
 		weston_compositor_damage_all(compositor);
 		udev_input_enable(&b->input);
 	} else {
-		weston_log("deactivating session\n");
+		weston_log("%s: deactivating session\n",__func__);
+		weston_log("%s: pid %d, uid %d, euid %d.\n",__func__,getpid(),getuid(),geteuid());
 		udev_input_disable(&b->input);
 
 		b->prev_state = compositor->state;
 		weston_compositor_offscreen(compositor);
 
+		weston_log("%s: did set offscreen\n",__func__);
+
 		/* If we have a repaint scheduled (either from a
 		 * pending pageflip or the idle handler), make sure we
 		 * cancel that so we don't try to pageflip when we're
@@ -2835,6 +2838,7 @@ session_notify(struct wl_listener *liste
 					output->crtc_id, 0, 0,
 					0, 0, 0, 0, 0, 0, 0, 0);
 	};
+	weston_log("%s: did session_notify\n",__func__);
 }
 
 /*
@@ -2853,44 +2857,50 @@ find_primary_gpu(struct drm_backend *b, 
 	struct udev_device *device, *drm_device, *pci;
 
 	e = udev_enumerate_new(b->udev);
-	udev_enumerate_add_match_subsystem(e, "drm");
-	udev_enumerate_add_match_sysname(e, "card[0-9]*");
 
-	udev_enumerate_scan_devices(e);
-	drm_device = NULL;
-	udev_list_entry_foreach(entry, udev_enumerate_get_list_entry(e)) {
-		path = udev_list_entry_get_name(entry);
-		device = udev_device_new_from_syspath(b->udev, path);
-		if (!device)
-			continue;
-		device_seat = udev_device_get_property_value(device, "ID_SEAT");
-		if (!device_seat)
-			device_seat = default_seat;
-		if (strcmp(device_seat, seat)) {
-			udev_device_unref(device);
-			continue;
-		}
+	// libudev-devd don't support matching properly yet
+	device = udev_device_new_from_syspath(e, "/dev/dri/card0");
+	return device;
 
-		pci = udev_device_get_parent_with_subsystem_devtype(device,
-								"pci", NULL);
-		if (pci) {
-			id = udev_device_get_sysattr_value(pci, "boot_vga");
-			if (id && !strcmp(id, "1")) {
-				if (drm_device)
-					udev_device_unref(drm_device);
-				drm_device = device;
-				break;
-			}
-		}
+	/* udev_enumerate_add_match_subsystem(e, "drm"); */
+	/* udev_enumerate_add_match_sysname(e, "card0"); */
 
-		if (!drm_device)
-			drm_device = device;
-		else
-			udev_device_unref(device);
-	}
+	/* udev_enumerate_scan_devices(e); */
+	/* drm_device = NULL; */
+	/* udev_list_entry_foreach(entry, udev_enumerate_get_list_entry(e)) { */
+	/* 	path = udev_list_entry_get_name(entry); */
+	/* 	printf("udev iterate got path %s\n",path); */
+	/* 	device = udev_device_new_from_syspath(b->udev, path); */
+	/* 	if (!device) */
+	/* 		continue; */
+	/* 	device_seat = udev_device_get_property_value(device, "ID_SEAT"); */
+	/* 	if (!device_seat) */
+	/* 		device_seat = default_seat; */
+	/* 	if (strcmp(device_seat, seat)) { */
+	/* 		udev_device_unref(device); */
+	/* 		continue; */
+	/* 	} */
 
-	udev_enumerate_unref(e);
-	return drm_device;
+	/* 	pci = udev_device_get_parent_with_subsystem_devtype(device, */
+	/* 							"pci", NULL); */
+	/* 	if (pci) { */
+	/* 		id = udev_device_get_sysattr_value(pci, "boot_vga"); */
+	/* 		if (id && !strcmp(id, "1")) { */
+	/* 			if (drm_device) */
+	/* 				udev_device_unref(drm_device); */
+	/* 			drm_device = device; */
+	/* 			break; */
+	/* 		} */
+	/* 	} */
+
+	/* 	if (!drm_device) */
+	/* 		drm_device = device; */
+	/* 	else */
+	/* 		udev_device_unref(device); */
+	/* } */
+
+	/* udev_enumerate_unref(e); */
+	/* return drm_device; */
 }
 
 static void
