--- libweston/libbacklight.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/libbacklight.c
@@ -36,11 +36,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <linux/types.h>
+/* #include <linux/types.h> */
 #include <dirent.h>
 #include <drm.h>
 #include <fcntl.h>
-#include <malloc.h>
+/* #include <malloc.h> */
 #include <string.h>
 #include <errno.h>
 
