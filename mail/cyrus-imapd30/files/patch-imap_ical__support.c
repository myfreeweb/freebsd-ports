--- imap/ical_support.c.orig	2018-04-10 20:13:17 UTC
+++ imap/ical_support.c
@@ -830,6 +830,14 @@ struct icalperiodtype icalrecurrenceset_get_utc_timesp
     return span;
 }
 
+EXPORTED void icaltime_set_utc(struct icaltimetype *t, int set)
+{
+#ifdef ICALTIME_HAS_IS_UTC
+    t->is_utc = set;
+#else
+    icaltime_set_timezone(t, set ? icaltimezone_get_utc_timezone() : NULL);
+#endif
+}
 
 #ifndef HAVE_TZDIST_PROPS
 
