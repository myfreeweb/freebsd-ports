--- src/classlib/openjdk/class.c.orig	2014-07-12 21:27:51 UTC
+++ src/classlib/openjdk/class.c
@@ -23,6 +23,7 @@
 #include "jam.h"
 #include "hash.h"
 #include "class.h"
+#include "excep.h"
 #include "symbol.h"

 /* Cached offset of classes field in java.lang.ClassLoader objects */
@@ -179,3 +180,24 @@ char *classlibExternalClassName(Class *c

     return dot_name;
 }
+
+Class *findClassFromLoader(char *name, int init, Object *loader,
+                           int throw_error) {
+
+    Class *class = findClassFromClassLoader(name, loader);
+
+    if(class == NULL) {
+        if(!throw_error) {
+            Object *excep = exceptionOccurred();
+            char *dot_name = slash2DotsDup(name);
+
+            clearException();
+            signalChainedException(java_lang_ClassNotFoundException,
+                                   dot_name, excep);
+            sysFree(dot_name);
+        }
+    } else if(init)
+        initClass(class);
+
+    return class;
+}
