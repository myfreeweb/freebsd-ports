--- src/os/bsd/os.c.orig	2014-02-03 20:12:59 UTC
+++ src/os/bsd/os.c
@@ -97,3 +97,18 @@ char *nativeLibMapName(char *name) {
 long long nativePhysicalMemory() {
     return 0; /* TBD */
 }
+
+char *nativeJVMPath() {
+    Dl_info info;
+    char *path;
+
+    if(dladdr(nativeJVMPath, &info) == 0) {
+        printf("Error: dladdr failed.  Aborting VM\n");
+        exitVM(1);
+    }
+
+    path = sysMalloc(strlen(info.dli_fname) + 1);
+    strcpy(path, info.dli_fname);
+
+    return path;
+}
