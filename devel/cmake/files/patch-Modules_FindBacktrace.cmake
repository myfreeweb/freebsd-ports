--- Modules/FindBacktrace.cmake.orig	2017-12-24 13:14:17 UTC
+++ Modules/FindBacktrace.cmake
@@ -72,7 +72,7 @@ else()
   # Check for external library, for non-glibc systems
   if(Backtrace_INCLUDE_DIR)
     # OpenBSD has libbacktrace renamed to libexecinfo
-    find_library(Backtrace_LIBRARY "execinfo")
+    set(Backtrace_LIBRARY "execinfo")
   elseif()     # respect user wishes
     set(_Backtrace_HEADER_TRY "backtrace.h")
     find_path(Backtrace_INCLUDE_DIR ${_Backtrace_HEADER_TRY})
