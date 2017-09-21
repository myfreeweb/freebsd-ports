--- src/classlib/openjdk/openjdk.h.orig	2013-08-28 00:53:35 UTC
+++ src/classlib/openjdk/openjdk.h
@@ -1,5 +1,5 @@
 /*
- * Copyright (C) 2010, 2011, 2013 Robert Lougher <rob@jamvm.org.uk>.
+ * Copyright (C) 2010, 2011, 2013, 2014 Robert Lougher <rob@jamvm.org.uk>.
  *
  * This file is part of JamVM.
  *
@@ -53,3 +53,6 @@ extern int getMembers(Class *clazz, Obje
 extern Object *resolveMemberName(Class *mh_class, Object *mname);

 extern Object *getMethodParameters(Object *method);
+
+extern Class *findClassFromLoader(char *name, int init, Object *loader,
+                                  int throw_error);
