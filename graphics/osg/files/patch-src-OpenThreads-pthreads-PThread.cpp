--- src/OpenThreads/pthreads/PThread.cpp.orig	2018-06-29 12:56:35.000000000 +0300
+++ src/OpenThreads/pthreads/PThread.cpp	2018-07-12 22:10:15.672946000 +0300
@@ -21,6 +21,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <pthread.h>
+#include <pthread_np.h>
 #include <limits.h>
 
 #if defined __linux__ || defined __sun || defined __APPLE__ || ANDROID
@@ -113,7 +114,7 @@
 static void setAffinity(const Affinity& affinity)
 {
     //std::cout<<"setProcessAffinity : "<< affinity.activeCPUs.size() <<std::endl;
-    cpu_set_t cpumask;
+    cpuset_t cpumask;
     CPU_ZERO( &cpumask );
     unsigned int numprocessors = OpenThreads::GetNumberOfProcessors();
     if (affinity)
