--- app/paint/gimpmybrushcore.c.orig	2018-03-11 14:40:48 UTC
+++ app/paint/gimpmybrushcore.c
@@ -286,7 +286,9 @@ gimp_mybrush_core_motion (GimpPaintCore    *paint_core
                                    0.0f,
                                    coords->xtilt,
                                    coords->ytilt,
-                                   1.0f /* Pretend the cursor hasn't moved in a while */);
+                                   1.0f, /* Pretend the cursor hasn't moved in a while */
+                                   1.0,
+                                   0.0);
         }
 
       dt = 0.015;
@@ -322,7 +324,9 @@ gimp_mybrush_core_motion (GimpPaintCore    *paint_core
                                pressure,
                                coords->xtilt,
                                coords->ytilt,
-                               dt);
+                               dt,
+                               1.0,
+                               0.0);
     }
 
   mybrush->private->last_time = time;
