--- src/librustc_llvm/build.rs.orig	2017-12-07 10:38:33 UTC
+++ src/librustc_llvm/build.rs
@@ -231,8 +231,8 @@
 
     let llvm_static_stdcpp = env::var_os("LLVM_STATIC_STDCPP");
 
-    let stdcppname = if target.contains("openbsd") {
-        // llvm-config on OpenBSD doesn't mention stdlib=libc++
+    let stdcppname = if target.contains("openbsd") || target.contains("freebsd") {
+        // llvm-config on OpenBSD and FreeBSD doesn't mention stdlib=libc++
         "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
