--- src/libinput-util.h.orig	2017-10-30 05:16:22 UTC
+++ src/libinput-util.h
@@ -39,6 +39,9 @@
 #include <string.h>
 #include <time.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <xlocale.h>
+#endif
 
 #include "libinput.h"
 
