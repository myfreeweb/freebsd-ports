--- src/utils.c.orig	2016-04-04 08:58:07.943087000 +0200
+++ src/utils.c	2016-04-04 08:58:18.125288000 +0200
@@ -28,6 +28,10 @@
 
 #include "utils.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 typedef struct {
 	gchar	*data;
 	gint	length;
