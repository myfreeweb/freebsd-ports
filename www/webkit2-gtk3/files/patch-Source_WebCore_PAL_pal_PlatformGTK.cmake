--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2018-02-19 07:45:31 UTC
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake
@@ -16,6 +16,13 @@ if (ENABLE_SUBTLE_CRYPTO)
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
