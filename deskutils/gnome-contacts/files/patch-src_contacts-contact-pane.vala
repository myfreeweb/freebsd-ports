--- src/contacts-contact-pane.vala.orig	2017-06-24 00:10:21.423378000 +0200
+++ src/contacts-contact-pane.vala	2017-06-24 00:10:41.841305000 +0200
@@ -482,7 +482,6 @@
 					DialogFlags.MODAL,
 					MessageType.ERROR,
 					ButtonsType.OK,
-					"%s",
 					_("Unable to create new contacts: %s"), e.message);
 	  }
 
