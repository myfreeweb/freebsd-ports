--- imap/ical_support.h.orig	2018-04-10 20:14:07 UTC
+++ imap/ical_support.h
@@ -100,6 +100,7 @@ extern struct icalperiodtype icalrecurrenceset_get_utc
                                                                                 void*),
                                                                 void *cb_rock);
 
+extern void icaltime_set_utc(struct icaltimetype *t, int set);
 
 /* Functions not declared in in libical < v2.0 */
 
