--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2017-08-09 11:13:51.000000000 +0200
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake	2017-12-30 11:41:25.327123000 +0100
@@ -10,6 +10,13 @@ if (ENABLE_SUBTLE_CRYPTO)
     list(APPEND PAL_SOURCES
         crypto/tasn1/Utilities.cpp
     )
+
+    list(APPEND PAL_INCLUDE_DIRECTORIES
+        ${LIBGCRYPT_INCLUDE_DIRS}
+    )
+    list(APPEND PAL_LIBRARIES
+        ${LIBGCRYPT_LIBRARIES}
+    )
 endif ()
 
 list(APPEND PAL_SYSTEM_INCLUDE_DIRECTORIES
