--- glib/gutils.c.orig	2018-09-21 16:23:53.000000000 +0200
+++ glib/gutils.c	2018-12-18 08:03:53.168126000 +0100
@@ -2043,7 +2043,7 @@
 
 #ifndef G_OS_WIN32
       if (!data_dirs || !data_dirs[0])
-          data_dirs = "/usr/local/share/:/usr/share/";
+          data_dirs = "/usr/local/share/";
 
       data_dir_vector = g_strsplit (data_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #else
@@ -2119,7 +2119,7 @@
 	}
 #else
       if (!conf_dirs || !conf_dirs[0])
-          conf_dirs = "/etc/xdg";
+          conf_dirs = "/usr/local/etc/xdg:/etc/xdg";
 
       conf_dir_vector = g_strsplit (conf_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
@@ -2503,7 +2503,7 @@
 gboolean
 g_check_setuid (void)
 {
-#if defined(HAVE_SYS_AUXV_H)
+#if defined(HAVE_SYS_AUXV_H) && defined(HAVE_GETAUXVAL)
   unsigned long value;
   int errsv;
 
@@ -2513,6 +2513,8 @@
   if (errsv)
     g_error ("getauxval () failed: %s", g_strerror (errsv));
   return value;
+//#elif defined(HAVE_ELF_AUX_INFO)
+// doing this or falling back to the other UNIX thing?
 #elif defined(HAVE_ISSETUGID) && !defined(__BIONIC__)
   /* BSD: http://www.freebsd.org/cgi/man.cgi?query=issetugid&sektion=2 */
 
