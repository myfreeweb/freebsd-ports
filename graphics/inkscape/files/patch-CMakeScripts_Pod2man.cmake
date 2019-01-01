--- CMakeScripts/Pod2man.cmake.orig	2019-01-01 17:36:05 UTC
+++ CMakeScripts/Pod2man.cmake
@@ -28,12 +28,12 @@ macro(pod2man PODFILE_FULL RELEASE SECTION CENTER)
             set(MANPAGE_TARGET "man-${NAME}-${LANG}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${LANG}.${SECTION}")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/${LANG}/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/man/${LANG}/man${SECTION}")
         else()
             set(MANPAGE_TARGET "man-${NAME}")
             set(MANFILE_TEMP "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.tmp")
             set(MANFILE_FULL "${CMAKE_CURRENT_BINARY_DIR}/${NAME}.${SECTION}")
-            set(MANFILE_DEST "${SHARE_INSTALL}/man/man${SECTION}")
+            set(MANFILE_DEST "${CMAKE_INSTALL_PREFIX}/man/man${SECTION}")
         endif()
         add_custom_command(
             OUTPUT ${MANFILE_TEMP}
