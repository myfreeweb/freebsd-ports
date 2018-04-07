--- input/drivers_joypad/udev_joypad.c.orig	2018-04-07 12:29:47 UTC
+++ input/drivers_joypad/udev_joypad.c
@@ -25,7 +25,9 @@
 #include <sys/stat.h>
 #include <sys/poll.h>
 #include <libudev.h>
+#ifdef __linux__
 #include <linux/types.h>
+#endif
 #include <linux/input.h>

 #include <retro_inline.h>
