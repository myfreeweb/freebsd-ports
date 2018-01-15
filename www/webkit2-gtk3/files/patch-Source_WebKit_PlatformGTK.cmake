--- Source/WebKit/PlatformGTK.cmake.orig	2017-10-16 12:49:22.000000000 +0200
+++ Source/WebKit/PlatformGTK.cmake	2017-12-30 11:37:01.845567000 +0100
@@ -1243,7 +1243,7 @@ install(TARGETS webkit2gtkinjectedbundle
 )
 install(FILES "${CMAKE_BINARY_DIR}/Source/WebKit/webkit2gtk-${WEBKITGTK_API_VERSION}.pc"
               "${CMAKE_BINARY_DIR}/Source/WebKit/webkit2gtk-web-extension-${WEBKITGTK_API_VERSION}.pc"
-        DESTINATION "${LIB_INSTALL_DIR}/pkgconfig"
+        DESTINATION "${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig"
 )
 install(FILES ${WebKit2GTK_INSTALLED_HEADERS}
               ${WebKit2WebExtension_INSTALLED_HEADERS}
