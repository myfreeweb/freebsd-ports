--- widget/xremoteclient/XRemoteClient.cpp.orig	2017-10-14 18:20:54 UTC
+++ widget/xremoteclient/XRemoteClient.cpp
@@ -29,6 +29,11 @@
 #include <gdk/gdk.h>
 #include <gdk/gdkx.h>
 
+#ifdef ENABLE_REMOTE_DBUS
+#include <dbus/dbus.h>
+#include <dbus/dbus-glib-lowlevel.h>
+#endif
+
 #define MOZILLA_VERSION_PROP   "_MOZILLA_VERSION"
 #define MOZILLA_LOCK_PROP      "_MOZILLA_LOCK"
 #define MOZILLA_COMMANDLINE_PROP "_MOZILLA_COMMANDLINE"
@@ -73,7 +78,9 @@ XRemoteClient::XRemoteClient()
   mMozProfileAtom = 0;
   mMozProgramAtom = 0;
   mLockData = 0;
+#ifdef ENABLE_REMOTE_DBUS
   mIsX11Display = true;
+#endif
   mConnection = nullptr;
 
   MOZ_LOG(sRemoteLm, LogLevel::Debug, ("XRemoteClient::XRemoteClient"));
@@ -107,9 +114,9 @@ XRemoteClient::Init()
   if (mInitialized)
     return NS_OK;
 
+#ifdef ENABLE_REMOTE_DBUS
   mIsX11Display = GDK_IS_X11_DISPLAY(gdk_display_get_default());
 
-#ifdef ENABLE_REMOTE_DBUS
   if (!mIsX11Display) {
     mConnection = already_AddRefed<DBusConnection>(
       dbus_bus_get(DBUS_BUS_SESSION, nullptr));
