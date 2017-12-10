--- src/gallium/drivers/swr/rasterizer/core/threads.cpp.orig	2017-12-10 12:05:31 UTC
+++ src/gallium/drivers/swr/rasterizer/core/threads.cpp
@@ -30,7 +30,7 @@
 #include <fstream>
 #include <string>
 
-#if defined(__linux__) || defined(__gnu_linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__gnu_linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <pthread.h>
 #include <sched.h>
 #include <unistd.h>
@@ -218,7 +218,7 @@ void CalculateProcessorTopology(CPUNumaNodes& out_node
         }
     }
 
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 
 #else
 
