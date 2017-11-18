--- Source/WebKit/PlatformGTK.cmake.orig        2017-10-16 13:49:22.000000000 +0300
+++ Source/WebKit/PlatformGTK.cmake     2017-11-18 14:56:55.286903000 +0300
@@ -1243,7 +1243,7 @@
 )
 install(FILES "${CMAKE_BINARY_DIR}/Source/WebKit/webkit2gtk-${WEBKITGTK_API_VERSION}.pc"
               "${CMAKE_BINARY_DIR}/Source/WebKit/webkit2gtk-web-extension-${WEBKITGTK_API_VERSION}.pc"
-        DESTINATION "${LIB_INSTALL_DIR}/pkgconfig"
+        DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"
 )
 install(FILES ${WebKit2GTK_INSTALLED_HEADERS}
               ${WebKit2WebExtension_INSTALLED_HEADERS}
