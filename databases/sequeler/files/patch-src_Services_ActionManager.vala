--- src/Services/ActionManager.vala.orig	2018-03-18 14:04:05 UTC
+++ src/Services/ActionManager.vala
@@ -66,7 +66,7 @@ public class Sequeler.Services.ActionManager : Object 
 		window.insert_action_group ("win", actions);
 
 		foreach (var action in action_accelerators.get_keys ()) {
-			app.set_accels_for_action (ACTION_PREFIX + action, action_accelerators[action].to_array ());
+			//app.set_accels_for_action (ACTION_PREFIX + action, action_accelerators[action].to_array ());
 		}
 	}
 
