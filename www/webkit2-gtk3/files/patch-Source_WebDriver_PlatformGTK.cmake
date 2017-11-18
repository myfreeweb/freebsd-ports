--- Source/WebDriver/PlatformGTK.cmake.orig	2017-11-18 15:44:03.270855000 +0300
+++ Source/WebDriver/PlatformGTK.cmake	2017-11-18 15:44:08.480011000 +0300
@@ -5,6 +5,7 @@
 list(APPEND WebDriver_SYSTEM_INCLUDE_DIRECTORIES
     "${GLIB_INCLUDE_DIRS}"
     "${LIBSOUP_INCLUDE_DIRS}"
+    "${ICU_INCLUDE_DIRS}"
 )
 
 list(APPEND WebDriver_SOURCES
