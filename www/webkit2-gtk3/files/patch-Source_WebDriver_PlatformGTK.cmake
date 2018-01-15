--- Source/WebDriver/PlatformGTK.cmake.orig	2017-12-30 12:07:55.181958000 +0100
+++ Source/WebDriver/PlatformGTK.cmake	2017-12-30 12:11:20.519108000 +0100
@@ -5,6 +5,7 @@ add_definitions(-DLIBEXECDIR="${CMAKE_INSTALL_FULL_LIB
 list(APPEND WebDriver_SYSTEM_INCLUDE_DIRECTORIES
     "${GLIB_INCLUDE_DIRS}"
     "${LIBSOUP_INCLUDE_DIRS}"
+    "${ICU_INCLUDE_DIRS}"
 )
 
 list(APPEND WebDriver_SOURCES
@@ -18,4 +19,5 @@ list(APPEND WebDriver_SOURCES
 
 list(APPEND WebDriver_LIBRARIES
     ${LIBSOUP_LIBRARIES}
+    ${ICU_LIBRARIES}
 )
