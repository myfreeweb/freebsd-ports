--- browser/app/nsBrowserApp.cpp.orig	2017-08-10 10:39:31 UTC
+++ browser/app/nsBrowserApp.cpp
@@ -291,6 +291,9 @@ int main(int argc, char* argv[], char* envp[])
   }
 #endif
 
+  setenv("MOZ_GMP_PATH", "/usr/local/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "/usr/local/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 #endif
