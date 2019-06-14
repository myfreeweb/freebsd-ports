--- scanner/inputaudio/input.c.orig	2018-07-01 10:28:47 UTC
+++ scanner/inputaudio/input.c
@@ -21,6 +21,7 @@ static const char* plugin_search_dirs[] = {
   "r128",
   "",
   NULL, /* = g_path_get_dirname(av0); */
+  INPUT_PREFIX "/lib/loudness",
   NULL
 };
