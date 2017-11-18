--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig       2017-08-09 12:13:51.000000000 +0300
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake    2017-11-18 15:17:56.116864000 +0300
@@ -6,6 +6,13 @@
     text/KillRingNone.cpp
 )

+list(APPEND PAL_INCLUDE_DIRECTORIES
+    ${LIBGCRYPT_INCLUDE_DIRS}
+)
+list(APPEND PAL_LIBRARIES
+    ${LIBGCRYPT_LIBRARIES}
+)
+
 if (ENABLE_SUBTLE_CRYPTO)
     list(APPEND PAL_SOURCES
         crypto/tasn1/Utilities.cpp
