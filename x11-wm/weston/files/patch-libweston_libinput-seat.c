--- libweston/libinput-seat.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/libinput-seat.c
@@ -114,6 +114,7 @@ device_removed(struct udev_input *input,
 {
 	struct evdev_device *device;
 
+	printf("%s\n",__func__);
 	device = libinput_device_get_user_data(libinput_device);
 	evdev_device_destroy(device);
 }
@@ -131,9 +132,11 @@ udev_seat_remove_devices(struct udev_sea
 void
 udev_input_disable(struct udev_input *input)
 {
+	printf("%s\n",__func__);
 	if (input->suspended)
 		return;
 
+	printf("%s\n",__func__);
 	libinput_suspend(input->libinput);
 	process_events(input);
 	input->suspended = 1;
@@ -142,6 +145,7 @@ udev_input_disable(struct udev_input *in
 static int
 udev_input_process_event(struct libinput_event *event)
 {
+	/* printf("%s\n",__func__); */
 	struct libinput *libinput = libinput_event_get_context(event);
 	struct libinput_device *libinput_device =
 		libinput_event_get_device(event);
@@ -150,9 +154,11 @@ udev_input_process_event(struct libinput
 
 	switch (libinput_event_get_type(event)) {
 	case LIBINPUT_EVENT_DEVICE_ADDED:
+		printf("%s: Device added\n",__func__);
 		device_added(input, libinput_device);
 		break;
 	case LIBINPUT_EVENT_DEVICE_REMOVED:
+		printf("%s: Device removed\n",__func__);
 		device_removed(input, libinput_device);
 		break;
 	default:
@@ -177,6 +183,7 @@ process_events(struct udev_input *input)
 	struct libinput_event *event;
 
 	while ((event = libinput_get_event(input->libinput))) {
+		/* printf("%s\n",__func__); */
 		process_event(event);
 		libinput_event_destroy(event);
 	}
@@ -227,6 +234,7 @@ const struct libinput_interface libinput
 int
 udev_input_enable(struct udev_input *input)
 {
+	printf("%s\n",__func__);
 	struct wl_event_loop *loop;
 	struct weston_compositor *c = input->compositor;
 	int fd;
