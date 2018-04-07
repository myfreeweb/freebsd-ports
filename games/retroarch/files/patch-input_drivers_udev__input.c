--- input/drivers/udev_input.c.orig	2018-02-19 12:43:32 UTC
+++ input/drivers/udev_input.c
@@ -46,7 +46,9 @@
 #include <sys/poll.h>

 #include <libudev.h>
+#ifdef __linux__
 #include <linux/types.h>
+#endif
 #include <linux/input.h>
 #include <linux/kd.h>

@@ -1204,7 +1206,9 @@ static void *udev_input_init(const char *joypad_driver
    udev->joypad = input_joypad_init_driver(joypad_driver, udev);
    input_keymaps_init_keyboard_lut(rarch_key_map_linux);

+#ifdef __linux__
    linux_terminal_disable_input();
+#endif

 #ifndef HAVE_X11
    RARCH_WARN("[udev]: Full-screen pointer won't be available.\n");
@@ -1299,7 +1303,11 @@ input_driver_t input_udev = {
    udev_input_get_capabilities,
    "udev",
    udev_input_grab_mouse,
+#ifdef __linux__
    linux_terminal_grab_stdin,
+#else
+   NULL,
+#endif
    udev_input_set_rumble,
    udev_input_get_joypad_driver,
    NULL,
