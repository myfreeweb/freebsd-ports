--- shared/string-helpers.h.orig	2016-09-17 07:06:45 UTC
+++ shared/string-helpers.h
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <assert.h>
+#include <unistd.h>
 
 /* Convert string to integer
  *
