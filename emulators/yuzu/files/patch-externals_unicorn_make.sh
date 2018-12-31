On FreeBSD 11, unicorn samples fail with:

../libunicorn.so: undefined reference to pthread_create

Rather than add -lthr, just disable them as they are completely unnecessary here.

--- externals/unicorn/make.sh.orig	2018-07-09 09:58:24 UTC
+++ externals/unicorn/make.sh
@@ -120,15 +120,15 @@ fi
 export CC INSTALL_BIN PREFIX PKGCFGDIR LIBDIRARCH LIBARCHS CFLAGS LDFLAGS

 case "$1" in
-  "" ) ${MAKE};;
+  "" ) ${MAKE} unicorn;;
   "asan" ) asan;;
   "install" ) install;;
   "uninstall" ) uninstall;;
-  "macos-universal" ) MACOS_UNIVERSAL=yes ${MAKE};;
-  "macos-universal-no" ) MACOS_UNIVERSAL=no ${MAKE};;
+  "macos-universal" ) MACOS_UNIVERSAL=yes ${MAKE} unicorn;;
+  "macos-universal-no" ) MACOS_UNIVERSAL=no ${MAKE} unicorn;;
   "cross-win32" ) build_cross i686-w64-mingw32;;
   "cross-win64" ) build_cross x86_64-w64-mingw32;;
-  "cross-android" ) CROSS=arm-linux-androideabi ${MAKE};;
+  "cross-android" ) CROSS=arm-linux-androideabi ${MAKE} unicorn;;
   "ios" ) build_iOS;;
   "ios_armv7" ) build_iOS armv7;;
   "ios_armv7s" ) build_iOS armv7s;;
