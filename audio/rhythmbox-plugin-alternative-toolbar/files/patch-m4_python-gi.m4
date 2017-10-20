The actual import needs a running X11 or Wayland server.

--- m4/python-gi.m4.orig	2017-10-20 20:19:10 UTC
+++ m4/python-gi.m4
@@ -3,7 +3,7 @@ dnl Original credit to https://lists.gnu.org/archive/h
 dnl macro that checks for specific modules in python
 AC_DEFUN([AC_PYTHON_GI_MODULE],
 [AC_MSG_CHECKING(for module $1 ($2) in gi.repository)
-echo "import gi; gi.require_version('$1', '$2'); from gi.repository import $1" | python3 -
+echo "import gi; gi.require_version('$1', '$2')" | python3 -
 if test $? -ne 0 ; then
 AC_MSG_RESULT(not found)
 AC_MSG_ERROR(You need the gobject-introspection binding $1)
