--- hwaccess.h.orig	2018-07-25 12:39:14 UTC
+++ hwaccess.h
@@ -79,7 +79,7 @@
 /* ARM can be either endian. */
 #if defined (__ARMEB__)
 #define __FLASHROM_BIG_ENDIAN__ 1
-#elif defined (__ARMEL__)
+#elif defined (__ARMEL__) || defined (__aarch64__)
 #define __FLASHROM_LITTLE_ENDIAN__ 1
 #endif
 
