--- setup.py.orig	2018-03-19 17:22:21 UTC
+++ setup.py
@@ -168,7 +168,7 @@ def init_env(
     sanitize_args = get_sanitize_args(cc, ccver) if sanitize else set()
     cflags = os.environ.get(
         'OVERRIDE_CFLAGS', (
-            '-Wextra -Wno-missing-field-initializers -Wall -std=c99 -D_XOPEN_SOURCE=700'
+            '-Wextra -Wno-missing-field-initializers -Wall -std=c99'
             ' -pedantic-errors -Werror {} {} -D{}DEBUG -fwrapv {} {} -pipe {} -fvisibility=hidden'
         ).format(
             optimize,
