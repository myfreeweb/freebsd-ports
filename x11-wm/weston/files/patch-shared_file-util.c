--- shared/file-util.c.orig	2015-10-24 00:02:43 UTC
+++ shared/file-util.c
@@ -34,6 +34,8 @@
 
 #include "file-util.h"
 
+#define ETIME ETIMEDOUT
+
 static int
 current_time_str(char *str, size_t len, const char *fmt)
 {
