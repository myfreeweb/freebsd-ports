--- imap/xcal.c.orig	2018-04-10 20:11:52 UTC
+++ imap/xcal.c
@@ -114,8 +114,8 @@ const char *icaltime_as_iso_string(const struct icalti
     static char str[21];
     const char *fmt;
 
-    if (tt.is_date) fmt = "%04d-%02d-%02d";
-    else if (tt.is_utc) fmt = "%04d-%02d-%02dT%02d:%02d:%02dZ";
+    if (icaltime_is_date(tt)) fmt = "%04d-%02d-%02d";
+    else if (icaltime_is_utc(tt)) fmt = "%04d-%02d-%02dT%02d:%02d:%02dZ";
     else fmt = "%04d-%02d-%02dT%02d:%02d:%02d";
 
     snprintf(str, sizeof(str), fmt, tt.year, tt.month, tt.day,
