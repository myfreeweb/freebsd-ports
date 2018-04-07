--- libretro-common/net/net_ifinfo.c.orig	2018-12-31 20:08:25 UTC
+++ libretro-common/net/net_ifinfo.c
@@ -50,6 +50,8 @@
 #include <netinet/in.h>
 #endif
 
+#include <netinet/in.h>
+
 void net_ifinfo_free(net_ifinfo_t *list)
 {
    unsigned k;
