--- tests/pixbuf-readonly-to-mutable.c.orig	2018-01-14 18:46:52 UTC
+++ tests/pixbuf-readonly-to-mutable.c
@@ -22,17 +22,13 @@
 #include <string.h>
 
 #ifdef G_OS_UNIX
+#include <fcntl.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
 
 #ifdef G_OS_UNIX
 
-/* see https://bugzilla.gnome.org/show_bug.cgi?id=741933 */
-#ifndef MAP_ANONYMOUS
-#define MAP_ANONYMOUS MAP_ANON
-#endif
-
 typedef struct {
   void *buf;
   gsize len;
@@ -67,9 +63,10 @@ get_readonly_pixbuf (void)
     int pagesize;
     int pages;
     int r;
+    int zero_fd;
     gsize pixlen;
 
-    pagesize = sysconf (_SC_PAGE_SIZE);
+    pagesize = sysconf (_SC_PAGESIZE);
     g_assert_cmpint (pagesize, >, 0);
 
     pixlen = gdk_pixbuf_get_byte_length (reference);
@@ -77,8 +74,11 @@ get_readonly_pixbuf (void)
 
     buf = g_new0 (MappedBuf, 1);
     buf->len = pages * pagesize;
-    buf->buf = mmap (NULL, buf->len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
+    zero_fd = open("/dev/zero", O_RDWR);
+    g_assert(zero_fd != -1);
+    buf->buf = mmap (NULL, buf->len, PROT_READ | PROT_WRITE, MAP_PRIVATE, zero_fd, 0);
     g_assert (buf->buf != NULL);
+    close(zero_fd);
 
     memcpy (buf->buf, gdk_pixbuf_get_pixels (reference), pixlen);
 
