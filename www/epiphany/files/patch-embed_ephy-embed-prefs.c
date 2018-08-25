--- embed/ephy-embed-prefs.c.orig	2018-08-25 19:58:04 UTC
+++ embed/ephy-embed-prefs.c
@@ -432,6 +432,7 @@ ephy_embed_prefs_init (gpointer user_data)
                                                        "enable-javascript", TRUE,
                                                        "enable-dns-prefetching", TRUE,
                                                        "javascript-can-open-windows-automatically", TRUE,
+                                                       "enable-mediasource", TRUE,
                                                        NULL);
 
   for (i = 0; i < G_N_ELEMENTS (webkit_pref_entries); i++) {
