--- libpoolprotocols/PoolManager.h.orig	2018-09-25 12:09:44 UTC
+++ libpoolprotocols/PoolManager.h
@@ -9,7 +9,7 @@
 #include "PoolClient.h"
 
 #if ETH_DBUS
-#include "DBusInt.h"
+#include "../ethminer/DBusInt.h"
 #endif
 
 using namespace std;
