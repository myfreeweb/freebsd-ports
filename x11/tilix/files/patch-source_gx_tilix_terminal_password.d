--- source/gx/tilix/terminal/password.d.orig	2019-06-27 21:00:58 UTC
+++ source/gx/tilix/terminal/password.d
@@ -172,7 +172,7 @@ class PasswordManagerDialog: Dialog { (private)
                 string uuid = randomUUID().toString();
                 pending[uuid] = c;
                 import gtkc.glib;
-                HashTable attributes = new HashTable(g_str_hash, g_str_equal);
+                HashTable attributes = new HashTable(&g_str_hash, &g_str_equal);
                 immutable(char*) uuidz = toStringz(uuid);
                 attributes.insert(cast(void*)attrID, cast(void*)uuidz);
                 attributes.insert(cast(void*)attrDescription, cast(void*)descriptionValue);
@@ -285,7 +285,7 @@ class PasswordManagerDialog: Dialog { (private)
 
     HashTable createHashTable() {
         import gtkc.glib;
-        return new HashTable(g_str_hash, g_str_equal);
+        return new HashTable(&g_str_hash, &g_str_equal);
     }
 
     void createSchema() {
