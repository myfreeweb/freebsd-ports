--- loader/vk_loader_platform.h.orig	2017-08-10 15:50:41 UTC
+++ loader/vk_loader_platform.h
@@ -30,7 +30,7 @@
 #include "vulkan/vk_platform.h"
 #include "vulkan/vk_sdk_platform.h"
 
-#if defined(__linux__)
+#if defined(__unix__)
 /* Linux-specific common code: */
 
 // Headers:
