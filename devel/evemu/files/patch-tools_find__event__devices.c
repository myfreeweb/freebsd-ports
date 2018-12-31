--- tools/find_event_devices.c.orig	2018-11-08 20:54:20 UTC
+++ tools/find_event_devices.c
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
