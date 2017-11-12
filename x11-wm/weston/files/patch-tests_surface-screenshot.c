--- tests/surface-screenshot.c.orig	2016-09-17 07:06:45 UTC
+++ tests/surface-screenshot.c
@@ -36,6 +36,8 @@
 #include "compositor.h"
 #include "file-util.h"
 
+#define ETIME ETIMEDOUT
+
 static char *
 encode_PAM_comment_line(const char *comment)
 {
