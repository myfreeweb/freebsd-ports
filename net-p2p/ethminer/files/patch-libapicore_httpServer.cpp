--- libapicore/httpServer.cpp.orig	2018-07-23 09:12:07 UTC
+++ libapicore/httpServer.cpp
@@ -1,6 +1,6 @@
 #include <chrono>
 #include <thread>
-#include <mongoose/mongoose.h>
+#include "mongoose/mongoose.h"
 #include <limits.h>
 #include "httpServer.h"
 #include "libdevcore/Log.h"
@@ -96,7 +96,7 @@ void httpServer::run(unsigned short port, dev::eth::Fa
     m_port = to_string(port);
     m_show_hwmonitors = show_hwmonitors;
 	m_show_power = show_power;
-    new thread(bind(&httpServer::run_thread, this));
+    new std::thread(bind(&httpServer::run_thread, this));
 }
 
 void httpServer::run_thread()
