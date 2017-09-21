--- src/classlib/openjdk/jvm.c.orig	2014-07-24 00:23:42 UTC
+++ src/classlib/openjdk/jvm.c
@@ -522,27 +522,22 @@ jclass JVM_FindClassFromBootLoader(JNIEn
 jclass JVM_FindClassFromClassLoader(JNIEnv *env, const char *name,
                                     jboolean init, jobject loader,
                                     jboolean throw_error) {
-    Class *class;

     TRACE("JVM_FindClassFromClassLoader(env=%p, name=%s, init=%d, loader=%p,"
           " throw_error=%d)", env, name, init, loader, throw_error);

-    class = findClassFromClassLoader((char *)name, loader);
+    return findClassFromLoader((char *)name, init, loader, throw_error);
+}

-    if(class == NULL) {
-        if(!throw_error) {
-            Object *excep = exceptionOccurred();
-            char *dot_name = slash2DotsDup((char*)name);
+/* JVM_FindClassFromCaller */

-            clearException();
-            signalChainedException(java_lang_ClassNotFoundException,
-                                   dot_name, excep);
-            sysFree(dot_name);
-        }
-    } else if(init)
-        initClass(class);
+jclass JVM_FindClassFromCaller(JNIEnv *env, const char *name, jboolean init,
+                               jobject loader, jclass caller) {

-    return class;
+    TRACE("JVM_FindClassFromCaller(env=%p, name=%s, init=%d, loader=%p,"
+          " caller=%p)", env, name, init, loader, caller);
+
+    return findClassFromLoader((char *)name, init, loader, FALSE);
 }
