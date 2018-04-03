--- Source/JavaScriptCore/PlatformGTK.cmake.orig	2018-02-19 07:45:14 UTC
+++ Source/JavaScriptCore/PlatformGTK.cmake
@@ -25,7 +25,7 @@ add_custom_command(
 ADD_TYPELIB(${CMAKE_BINARY_DIR}/JavaScriptCore-${WEBKITGTK_API_VERSION}.typelib)
 
 install(FILES "${CMAKE_BINARY_DIR}/Source/JavaScriptCore/javascriptcoregtk-${WEBKITGTK_API_VERSION}.pc"
-        DESTINATION "${LIB_INSTALL_DIR}/pkgconfig"
+        DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"
 )
 
 install(FILES API/JavaScript.h
