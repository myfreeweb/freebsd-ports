--- ethminer/main.cpp.orig	2018-09-25 12:04:14 UTC
+++ ethminer/main.cpp
@@ -36,7 +36,7 @@
 #include <libpoolprotocols/testing/SimulateClient.h>
 
 #if ETH_DBUS
-#include <DBusInt.h>
+#include "DBusInt.h"
 #endif
 
 #if API_CORE
@@ -406,11 +406,8 @@ class MinerCLI (public)
 		for (auto url : pools) {
 			if (url == "exit") // add fake scheme and port to 'exit' url
 				url = "stratum+tcp://-:x@exit:0";
-			URI uri;
-			try {
-				uri = url;
-			}
-			catch (...) {
+			URI uri(url);
+			if (!uri.Valid()) {
 				cerr << endl << "Bad endpoint address: " << url << "\n\n";
 				exit(-1);
 			}
