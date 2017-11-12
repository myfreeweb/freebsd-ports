--- clients/screenshot.c.orig	2016-08-10 22:56:50 UTC
+++ clients/screenshot.c
@@ -40,6 +40,8 @@
 #include "shared/os-compatibility.h"
 #include "shared/xalloc.h"
 
+#define program_invocation_short_name getprogname()
+
 /* The screenshooter is a good example of a custom object exposed by
  * the compositor and serves as a test bed for implementing client
  * side marshalling outside libwayland.so */
