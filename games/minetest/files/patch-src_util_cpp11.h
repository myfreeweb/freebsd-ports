--- src/util/cpp11.h.orig	2018-03-11 21:36:29 UTC
+++ src/util/cpp11.h
@@ -20,7 +20,7 @@ with this program; if not, write to the Free Software
 #ifndef MT_CPP11_HEADER
 #define MT_CPP11_HEADER

-#if __cplusplus < 201103L || _MSC_VER < 1600
+#if __cplusplus < 201103L
 #define USE_CPP11_FAKE_KEYWORD
 #endif
