--- glfw/wl_window.c.orig	2019-01-01 17:59:15 UTC
+++ glfw/wl_window.c
@@ -140,7 +140,9 @@ static int
 createAnonymousFile(off_t size)
 {
     int ret;
-#ifdef HAS_MEMFD_CREATE
+#ifdef __FreeBSD__
+    int fd = shm_open(SHM_ANON, O_RDWR | O_CLOEXEC, 0600);
+#elif HAS_MEMFD_CREATE
     int fd = memfd_create("glfw-shared", MFD_CLOEXEC | MFD_ALLOW_SEALING);
     if (fd < 0) return -1;
     // We can add this seal before calling posix_fallocate(), as the file
@@ -173,7 +175,11 @@ createAnonymousFile(off_t size)
     if (fd < 0)
         return -1;
 #endif
+#ifdef __FreeBSD__
+    ret = ftruncate(fd, size);
+#else
     ret = posix_fallocate(fd, 0, size);
+#endif
     if (ret != 0)
     {
         close(fd);
