--- src/Layouts/Partials/Layer.vala.orig	2018-03-19 20:56:51 UTC
+++ src/Layouts/Partials/Layer.vala
@@ -54,9 +54,9 @@ public class Akira.Layouts.Partials.Layer : Gtk.ListBo
 		get { return _locked; } set { _locked = value; }
 	}
 
-	private bool _hidden { get; set; default = false; }
+	private bool __hidden { get; set; default = false; }
 	public bool hidden {
-		get { return _hidden; } set { _hidden = value; }
+		get { return __hidden; } set { __hidden = value; }
 	}
 
 	// public Akira.Shape shape { get; construct; }
@@ -354,4 +354,4 @@ public class Akira.Layouts.Partials.Layer : Gtk.ListBo
 
 		return should_scroll;
 	}
-}
\ No newline at end of file
+}
