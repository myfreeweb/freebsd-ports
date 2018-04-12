--- imap/http_tzdist.c.orig	2018-04-10 20:07:15 UTC
+++ imap/http_tzdist.c
@@ -1376,7 +1376,7 @@ static void truncate_vtimezone(icalcomponent *vtz,
 
         /* Adjust DTSTART observance to UTC */
         icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-        obs.onset.is_utc = 1;
+        icaltime_set_utc(&obs.onset, 1);
 
         /* Check DTSTART vs window close */
         if (!icaltime_is_null_time(end) &&
@@ -1451,7 +1451,7 @@ static void truncate_vtimezone(icalcomponent *vtz,
                 if (!eternal) {
                     /* Adjust UNTIL to local time (for iterator) */
                     icaltime_adjust(&rrule.until, 0, 0, 0, obs.offset_from);
-                    rrule.until.is_utc = 0;
+                    icaltime_set_utc(&rrule.until, 0);
                 }
 
                 if (trunc_dtstart) {
@@ -1475,7 +1475,7 @@ static void truncate_vtimezone(icalcomponent *vtz,
 
                     /* Adjust observance to UTC */
                     icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-                    obs.onset.is_utc = 1;
+                    icaltime_set_utc(&obs.onset, 1);
 
                     if (trunc_until && icaltime_compare(obs.onset, end) >= 0) {
                         /* Observance is on/after window close */
@@ -1580,7 +1580,7 @@ static void truncate_vtimezone(icalcomponent *vtz,
 
             /* Adjust observance to UTC */
             icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-            obs.onset.is_utc = 1;
+            icaltime_set_utc(&obs.onset, 1);
 
             if (!icaltime_is_null_time(end) &&
                 icaltime_compare(obs.onset, end) >= 0) {
@@ -1691,7 +1691,7 @@ static void truncate_vtimezone(icalcomponent *vtz,
             case ICAL_DTSTART_PROPERTY:
                 /* Adjust window open to local time */
                 icaltime_adjust(&start, 0, 0, 0, tombstone.offset_from);
-                start.is_utc = 0;
+                icaltime_set_utc(&start, 0);
 
                 icalproperty_set_dtstart(prop, start);
                 break;
@@ -1775,14 +1775,14 @@ static int action_get(struct transaction_t *txn)
     /* Sanity check the parameters */
     if ((param = hash_lookup("start", &txn->req_qparams))) {
         start = icaltime_from_string(param->s);
-        if (param->next || !start.is_utc) {  /* once only, UTC */
+        if (param->next || !icaltime_is_utc(start)) {  /* once only, UTC */
             return json_error_response(txn, TZ_INVALID_START, param, &start);
         }
     }
 
     if ((param = hash_lookup("end", &txn->req_qparams))) {
         end = icaltime_from_string(param->s);
-        if (param->next || !end.is_utc  /* once only, UTC */
+        if (param->next || !icaltime_is_utc(end)  /* once only, UTC */
             || icaltime_compare(end, start) <= 0) {  /* end MUST be > start */
             return json_error_response(txn, TZ_INVALID_END, param, &end);
         }
@@ -1956,7 +1956,7 @@ static int action_expand(struct transaction_t *txn)
         return json_error_response(txn, TZ_INVALID_START, param, NULL);
 
     start = icaltime_from_string(param->s);
-    if (!start.is_utc)  /* MUST be UTC */
+    if (!icaltime_is_utc(start))  /* MUST be UTC */
         return json_error_response(txn, TZ_INVALID_START, param, &start);
 
     param = hash_lookup("end", &txn->req_qparams);
@@ -1964,7 +1964,7 @@ static int action_expand(struct transaction_t *txn)
         return json_error_response(txn, TZ_INVALID_END, param, NULL);
 
     end = icaltime_from_string(param->s);
-    if (!end.is_utc  /* MUST be UTC */
+    if (!icaltime_is_utc(end)  /* MUST be UTC */
         || icaltime_compare(end, start) <= 0) {  /* end MUST be > start */
         return json_error_response(txn, TZ_INVALID_END, param, &end);
     }
@@ -2235,7 +2235,7 @@ static int json_error_response(struct transaction_t *t
     else if (param->next) fmt = "Multiple %s parameters";
     else if (!param->s || !param->s[0]) fmt = "Missing %s value";
     else if (!time) fmt = "Invalid %s value";
-    else if (!time->is_utc) fmt = "Invalid %s UTC value";
+    else if (!icaltime_is_utc(*time)) fmt = "Invalid %s UTC value";
     else fmt = "End date-time <= start date-time";
 
     assert(!buf_len(&txn->buf));
