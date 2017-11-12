--- libweston/libinput-device.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/libinput-device.c
@@ -538,6 +538,7 @@ struct evdev_device *
 evdev_device_create(struct libinput_device *libinput_device,
 		    struct weston_seat *seat)
 {
+	printf("%s\n",__func__);
 	struct evdev_device *device;
 
 	device = zalloc(sizeof *device);
@@ -573,6 +574,7 @@ evdev_device_create(struct libinput_devi
 void
 evdev_device_destroy(struct evdev_device *device)
 {
+	printf("%s\n",__func__);
 	if (device->seat_caps & EVDEV_SEAT_POINTER)
 		weston_seat_release_pointer(device->seat);
 	if (device->seat_caps & EVDEV_SEAT_KEYBOARD)
