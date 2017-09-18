--- loader/loader.c.orig	2017-08-10 15:50:41 UTC
+++ loader/loader.c
@@ -204,7 +204,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__)
+#if defined(__unix__)
 
 static inline char *loader_getenv(const char *name, const struct loader_instance *inst) {
     // No allocation of memory necessary for Linux, but we should at least touch
