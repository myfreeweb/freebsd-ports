--- lib/ethash/keccak.c.orig	2018-09-26 10:15:09 UTC
+++ lib/ethash/keccak.c
@@ -33,6 +33,8 @@
 #define __BYTE_ORDER __LITTLE_ENDIAN
 #elif __APPLE__
 #include <machine/endian.h>
+#elif __FreeBSD__
+#include <sys/endian.h>
 #else
 #include <endian.h>
 #endif
