--- src/client/composer/composer-container.vala.orig	2018-04-03 19:08:38 UTC
+++ src/client/composer/composer-container.vala
@@ -87,8 +87,12 @@ public interface ComposerContainer {
         // Now add our actions to the window and their accelerators
         foreach (string action in ComposerWidget.action_accelerators.get_keys()) {
             this.top_window.add_action(composer.get_action(action));
+            string[] accels = new string[1];
+            foreach (string accelerator in ComposerWidget.action_accelerators[action]) {
+                accels[0] = accelerator;
+            }
             app.set_accels_for_action("win." + action,
-                                      ComposerWidget.action_accelerators[action].to_array());
+                                      accels);
         }
     }
 
