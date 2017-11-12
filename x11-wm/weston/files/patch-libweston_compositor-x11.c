--- libweston/compositor-x11.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/compositor-x11.c
@@ -37,6 +37,7 @@
 #include <errno.h>
 #include <sys/time.h>
 #include <sys/shm.h>
+#include <sys/stat.h>
 #include <linux/input.h>
 
 #include <xcb/xcb.h>
