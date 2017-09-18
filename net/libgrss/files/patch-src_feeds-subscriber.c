--- src/feeds-subscriber.c.orig	2016-04-04 08:38:02.429437000 +0200
+++ src/feeds-subscriber.c	2016-04-04 08:38:23.903415000 +0200
@@ -18,6 +18,10 @@
  * Boston, MA  02110-1301, USA.
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include "feeds-subscriber.h"
 #include "feeds-subscriber-handler.h"
 #include "feeds-pubsubhubbub-subscriber.h"
