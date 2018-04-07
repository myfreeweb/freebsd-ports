--- input/input_keymaps.c.orig	2018-04-07 12:02:13 UTC
+++ input/input_keymaps.c
@@ -44,7 +44,7 @@
 #include "SDL.h"
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(HAVE_WAYLAND)
 #include <linux/input.h>
 #include <linux/kd.h>
 #endif
@@ -845,7 +845,7 @@ const struct rarch_key_map rarch_key_map_x11[] = {
 };
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(HAVE_WAYLAND)
 const struct rarch_key_map rarch_key_map_linux[] = {
    { KEY_BACKSPACE, RETROK_BACKSPACE },
    { KEY_TAB, RETROK_TAB },
