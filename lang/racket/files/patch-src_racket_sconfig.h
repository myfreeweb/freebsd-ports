--- src/racket/sconfig.h.orig	2018-07-23 22:12:17 UTC
+++ src/racket/sconfig.h
@@ -344,6 +344,8 @@
 #  define FLUSH_SPARC_REGISTER_WINDOWS
 # elif defined(__arm__)
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "arm-freebsd"
+# elif defined(__aarch64__)
+#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "aarch64-freebsd"
 # elif defined(__powerpc__)
 #  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-freebsd"
 #  define MZ_USE_JIT_PPC
