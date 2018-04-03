--- Source/WebKit/PlatformGTK.cmake.orig	2018-02-20 06:53:53 UTC
+++ Source/WebKit/PlatformGTK.cmake
@@ -847,7 +847,7 @@ install(TARGETS webkit2gtkinjectedbundle
 )
 install(FILES "${CMAKE_BINARY_DIR}/Source/WebKit/webkit2gtk-${WEBKITGTK_API_VERSION}.pc"
               "${CMAKE_BINARY_DIR}/Source/WebKit/webkit2gtk-web-extension-${WEBKITGTK_API_VERSION}.pc"
-        DESTINATION "${LIB_INSTALL_DIR}/pkgconfig"
+        DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"
 )
 install(FILES ${WebKit2GTK_INSTALLED_HEADERS}
               ${WebKit2WebExtension_INSTALLED_HEADERS}
