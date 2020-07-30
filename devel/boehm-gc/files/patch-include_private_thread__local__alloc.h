--- include/private/thread_local_alloc.h.orig	2020-07-30 21:08:59 UTC
+++ include/private/thread_local_alloc.h
@@ -55,8 +55,7 @@ EXTERN_C_BEGIN
 # elif (defined(LINUX) && !defined(ARM32) && !defined(AVR32) \
          && GC_GNUC_PREREQ(3, 3) \
          && !(defined(__clang__) && defined(HOST_ANDROID))) \
-       || (defined(FREEBSD) && defined(__GLIBC__) /* kFreeBSD */ \
-            && GC_GNUC_PREREQ(4, 4)) \
+       || (defined(FREEBSD)) \
        || (defined(HOST_ANDROID) && defined(ARM32) \
             && (GC_GNUC_PREREQ(4, 6) || GC_CLANG_PREREQ_FULL(3, 8, 256229)))
 #   define USE_COMPILER_TLS
