--- src/Services/ActionManager.vala.orig	2018-03-19 20:59:31 UTC
+++ src/Services/ActionManager.vala
@@ -71,7 +71,7 @@ public class Akira.Services.ActionManager : Object {
 		window.insert_action_group ("win", actions);
 
 		foreach (var action in action_accelerators.get_keys ()) {
-			app.set_accels_for_action (ACTION_PREFIX + action, action_accelerators[action].to_array ());
+			//app.set_accels_for_action (ACTION_PREFIX + action, action_accelerators[action].to_array ());
 		}
 	}
 
@@ -149,4 +149,4 @@ public class Akira.Services.ActionManager : Object {
 		warning("action from group");
 		action_group.activate_action (action_name, null);
 	}
-}
\ No newline at end of file
+}
