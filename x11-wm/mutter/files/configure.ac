--- configure.ac.orig	2018-04-13 19:11:54.000000000 +0200
+++ configure.ac	2018-05-03 20:53:08.499907000 +0200
@@ -270,12 +270,9 @@
 
 PKG_CHECK_MODULES(SYSTEMD, [libsystemd], [have_systemd=yes], [have_systemd=no])
 
-if test x$have_systemd = xyes; then
+if test x$have_systemd = xyes -o -z "$logind_provider"; then
      logind_provider="libsystemd"
 fi
-
-AS_IF([test -z "$logind_provider"],
-  AC_MSG_ERROR([Could not find either systemd or elogind as logind provider])])
 
 MUTTER_NATIVE_BACKEND_MODULES="libdrm $logind_provider libinput >= 1.4 gudev-1.0 gbm >= 10.3"
 
