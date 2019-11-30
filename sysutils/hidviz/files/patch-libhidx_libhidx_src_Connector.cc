--- libhidx/libhidx/src/Connector.cc.orig	2017-05-16 06:02:19 UTC
+++ libhidx/libhidx/src/Connector.cc
@@ -26,6 +26,12 @@
 #include "subprocess.hh"
 #endif
 
+#ifdef __FreeBSD__
+#include <libgen.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 using generic = asio::generic::stream_protocol;
 
 #ifdef __linux__
@@ -119,8 +125,17 @@ namespace libhidx {
 
     std::string UnixSocketConnector::getExecutablePath() {
         char result[ PATH_MAX ];
+#ifdef __FreeBSD__
+        int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+        size_t count = sizeof(result);
+        sysctl(mib, 4, result, &count, NULL, 0);
+        char *dir = dirname(result);
+        count = strlen(dir);
+#else
         ssize_t count = readlink( "/proc/self/cwd", result, PATH_MAX );
-        return std::string( result, (count > 0) ? count : 0 );
+        char *dir = result;
+#endif
+        return std::string( dir, (count > 0) ? count : 0 );
     }
 #endif
 }
