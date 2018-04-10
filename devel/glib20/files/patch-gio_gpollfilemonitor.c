--- gio/gpollfilemonitor.c.orig	2018-04-09 23:28:09.875927000 +0200
+++ gio/gpollfilemonitor.c	2018-04-09 23:28:24.729117000 +0200
@@ -50,7 +50,9 @@ g_poll_file_monitor_finalize (GObject* object)
   
   poll_monitor = G_POLL_FILE_MONITOR (object);
 
+  g_poll_file_monitor_cancel (G_FILE_MONITOR (poll_monitor));
   g_object_unref (poll_monitor->file);
+  g_clear_object (&poll_monitor->last_info);
 
   G_OBJECT_CLASS (g_poll_file_monitor_parent_class)->finalize (object);
 }
