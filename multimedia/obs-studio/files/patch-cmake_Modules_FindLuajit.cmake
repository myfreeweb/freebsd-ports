--- cmake/Modules/FindLuajit.cmake.orig	2018-08-07 15:53:09 UTC
+++ cmake/Modules/FindLuajit.cmake
@@ -44,6 +44,7 @@ FIND_PATH(LUAJIT_INCLUDE_DIR
		include/luajit-2.0
		luajit2.0
		include/luajit2.0
+		include/luajit-2.1
		)

 find_library(LUAJIT_LIB
