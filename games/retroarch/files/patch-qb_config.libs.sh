The headers are bundled and the library is dynamically loaded,
so avoid requiring libvulkan at build time.

--- qb/config.libs.sh.orig	2018-02-19 12:43:32 UTC
+++ qb/config.libs.sh
@@ -465,13 +465,9 @@ fi
 check_lib '' STRCASESTR "$CLIB" strcasestr
 check_lib '' MMAP "$CLIB" mmap
 
-if [ "$HAVE_VULKAN" != "no" ] && [ "$OS" = 'Win32' ]; then
-   HAVE_VULKAN=yes
-else
-   check_lib '' VULKAN -lvulkan vkCreateInstance
-fi
+HAVE_VULKAN=yes
 
-check_pkgconf PYTHON python3
+check_pkgconf PYTHON python-3.6
 
 if [ "$HAVE_MATERIALUI" != 'no' ] || [ "$HAVE_XMB" != 'no' ] || [ "$HAVE_ZARCH" != 'no' ]; then
    if [ "$HAVE_RGUI" = 'no' ]; then
