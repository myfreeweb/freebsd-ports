--- numpy/distutils/system_info.py.orig	2019-08-27 21:01:36 UTC
+++ numpy/distutils/system_info.py
@@ -172,6 +172,8 @@ def _c_string_literal(s):
     Convert a python string into a literal suitable for inclusion into C code
     """
     # only these three characters are forbidden in C strings
+    if s is None:
+        return '"None"'
     s = s.replace('\\', r'\\')
     s = s.replace('"',  r'\"')
     s = s.replace('\n', r'\n')
@@ -1112,8 +1114,8 @@ class atlas_info(system_info):
     dir_env_var = 'ATLAS'
     _lib_names = ['f77blas', 'cblas']
     if sys.platform[:7] == 'freebsd':
-        _lib_atlas = ['atlas_r']
-        _lib_lapack = ['alapack_r']
+        _lib_atlas = ['atlas']
+        _lib_lapack = ['alapack']
     else:
         _lib_atlas = ['atlas']
         _lib_lapack = ['lapack']
