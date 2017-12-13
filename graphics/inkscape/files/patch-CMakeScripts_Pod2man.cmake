--- CMakeScripts/Pod2man.cmake.orig	2017-12-13 13:18:30.000000000 +0300
+++ CMakeScripts/Pod2man.cmake	2017-12-13 17:28:25.963923000 +0300
@@ -28,12 +28,12 @@
             set(MANPAGE_TARGET "man-${NAME}-${LANG}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}")
-            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/${SHARE_INSTALL}/man/${LANG}/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/man/${LANG}/man${SECTION}")
         else()
             set(MANPAGE_TARGET "man-${NAME}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}")
-            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/${SHARE_INSTALL}/man/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/man/man${SECTION}")
         endif()
         add_custom_command(
             OUTPUT ${MANFILE_TEMP}
