--- libweston/timeline.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/timeline.c
@@ -1,3 +1,4 @@
+
 /*
  * Copyright © 2014 Pekka Paalanen <pq@iki.fi>
  * Copyright © 2014 Collabora, Ltd.
@@ -36,6 +37,8 @@
 #include "compositor.h"
 #include "file-util.h"
 
+#define ETIME ETIMEDOUT
+
 struct timeline_log {
 	clock_t clk_id;
 	FILE *file;
