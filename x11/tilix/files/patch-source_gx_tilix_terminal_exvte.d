--- source/gx/tilix/terminal/exvte.d.orig	2019-06-27 21:00:58 UTC
+++ source/gx/tilix/terminal/exvte.d
@@ -188,12 +188,6 @@ class ExtendedVTE : Terminal { (public)
 		vte_terminal_set_disable_bg_draw(vteTerminal, isDisabled);
     }
 
-static if (COMPILE_VTE_BACKGROUND_COLOR) {
-    public void getColorBackgroundForDraw(RGBA background) {
-		vte_terminal_get_color_background_for_draw(vteTerminal, background is null? null: background.getRGBAStruct());
-    }
-}
-
     /**
      * Returns the child pid running in the terminal or -1
      * if no child pid is running. May also return the VTE gpid
@@ -219,24 +213,12 @@ import vte.c.functions;
 __gshared extern(C) {
 	int function(VteTerminal* terminal) c_vte_terminal_get_disable_bg_draw;
 	void function(VteTerminal* terminal, int isAudible) c_vte_terminal_set_disable_bg_draw;
-
-	static if (COMPILE_VTE_BACKGROUND_COLOR) {
-		void function(VteTerminal* terminal, GdkRGBA* color) c_vte_terminal_get_color_background_for_draw;
-	}
 }
 
 alias vte_terminal_get_disable_bg_draw = c_vte_terminal_get_disable_bg_draw;
 alias vte_terminal_set_disable_bg_draw = c_vte_terminal_set_disable_bg_draw;
 
-static if (COMPILE_VTE_BACKGROUND_COLOR) {
-	alias vte_terminal_get_color_background_for_draw = c_vte_terminal_get_color_background_for_draw;
-}
-
 shared static this() {
 	Linker.link(vte_terminal_get_disable_bg_draw, "vte_terminal_get_disable_bg_draw", LIBRARY_VTE);
 	Linker.link(vte_terminal_set_disable_bg_draw, "vte_terminal_set_disable_bg_draw", LIBRARY_VTE);
-
-	static if (COMPILE_VTE_BACKGROUND_COLOR) {
-		Linker.link(vte_terminal_get_color_background_for_draw, "vte_terminal_get_color_background_for_draw", LIBRARY_VTE);
-	}
 }
