The headers are bundled and the library is dynamically loaded,
so avoid requiring libvulkan at build time.

--- qb/config.libs.sh.orig	2018-12-31 20:08:25 UTC
+++ qb/config.libs.sh
@@ -554,13 +554,9 @@ check_lib '' MMAP "$CLIB" mmap

 check_enabled VULKAN vulkan

-if [ "$HAVE_VULKAN" != "no" ] && [ "$OS" = 'Win32' ]; then
-   HAVE_VULKAN=yes
-else
-   check_lib '' VULKAN -lvulkan vkCreateInstance
-fi
+HAVE_VULKAN=yes

-check_pkgconf PYTHON python3
+check_pkgconf PYTHON python-3.6

 if [ "$HAVE_MATERIALUI" != 'no' ] || [ "$HAVE_XMB" != 'no' ] || [ "$HAVE_ZARCH" != 'no' ] || [ "$HAVE_OZONE" != 'no' ]; then
    if [ "$HAVE_RGUI" = 'no' ]; then
