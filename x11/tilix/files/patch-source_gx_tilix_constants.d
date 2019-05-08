--- source/gx/tilix/constants.d.orig	2019-06-27 21:00:58 UTC
+++ source/gx/tilix/constants.d
@@ -42,7 +42,7 @@ immutable bool USE_COMMIT_SYNCHRONIZATION = false;
  * Compile tilix with support for VTE method vte_terminal_get_color_background_for_draw,
  * only needed until VTE 0.54 is released and GtkD is updated.
  */
-immutable bool COMPILE_VTE_BACKGROUND_COLOR = false;
+immutable bool COMPILE_VTE_BACKGROUND_COLOR = true;
 
 /**************************************
  * Application Constants
