--- glfw/memfd.h.orig	2019-01-01 18:01:01 UTC
+++ glfw/memfd.h
@@ -6,7 +6,9 @@

 #pragma once

-#ifdef HAS_MEMFD_CREATE
+#ifdef __FreeBSD__
+// use SHM_ANON
+#elif HAS_MEMFD_CREATE

 #include <unistd.h>
 #include <sys/syscall.h>
