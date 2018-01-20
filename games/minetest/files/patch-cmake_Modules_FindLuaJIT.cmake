--- cmake/Modules/FindLuaJIT.cmake.orig	2018-03-11 18:37:44 UTC
+++ cmake/Modules/FindLuaJIT.cmake
@@ -9,7 +9,7 @@
 FIND_PATH(LUA_INCLUDE_DIR luajit.h
	HINTS
	$ENV{LUA_DIR}
-	PATH_SUFFIXES include/luajit-2.0 include/luajit-5_1-2.0 include
+	PATH_SUFFIXES include/luajit-2.1 include/luajit-2.0 include/luajit-5_1-2.0 include
	PATHS
	~/Library/Frameworks
	/Library/Frameworks
