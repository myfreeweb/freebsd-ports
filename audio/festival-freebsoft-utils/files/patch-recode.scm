--- recode.scm.orig	2008-10-16 10:10:04 UTC
+++ recode.scm
@@ -29,7 +29,7 @@
       string
       (with-temp-file-data (tmpfile string)
         (with-temp-file out-tmpfile
-          (system (format nil "iconv -c -f %s -t %s//TRANSLIT -o %s %s" from to out-tmpfile tmpfile))
+          (system (format nil "iconv -c -f %s -t %s//TRANSLIT %s > %s" from to tmpfile out-tmpfile))
           (read-file out-tmpfile)))))
 
 (defvar recode-special-utf8-translations
