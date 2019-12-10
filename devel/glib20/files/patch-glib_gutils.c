--- glib/gutils.c.orig	2018-12-23 14:10:41.000000000 +0100
+++ glib/gutils.c	2018-12-27 00:18:23.471950000 +0100
@@ -2219,7 +2219,7 @@
     }
 #else
   if (!conf_dirs || !conf_dirs[0])
-    conf_dirs = "/etc/xdg";
+    conf_dirs = "/usr/local/etc/xdg:/etc/xdg";
<<<<<<< HEAD
 
=======

>>>>>>> 92de14d576e349bacfb7270f86f8a308b0983ad3
   conf_dir_vector = g_strsplit (conf_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
