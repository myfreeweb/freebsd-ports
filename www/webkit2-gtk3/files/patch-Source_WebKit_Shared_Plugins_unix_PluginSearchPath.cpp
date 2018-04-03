--- Source/WebKit/Shared/Plugins/unix/PluginSearchPath.cpp.orig	2018-02-20 06:53:53 UTC
+++ Source/WebKit/Shared/Plugins/unix/PluginSearchPath.cpp
@@ -49,6 +49,7 @@ Vector<String> pluginsDirectories()
 
     result.append(FileSystem::homeDirectoryPath() + "/.mozilla/plugins");
     result.append(FileSystem::homeDirectoryPath() + "/.netscape/plugins");
+    result.append("/usr/local/lib/browser_plugins/symlinks/webkit-gtk3");
     result.append("/usr/lib/browser/plugins");
     result.append("/usr/local/lib/mozilla/plugins");
     result.append("/usr/lib/firefox/plugins");
