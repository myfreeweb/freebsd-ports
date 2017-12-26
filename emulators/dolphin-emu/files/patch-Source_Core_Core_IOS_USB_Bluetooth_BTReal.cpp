--- Source/Core/Core/IOS/USB/Bluetooth/BTReal.cpp.orig	2017-12-26 19:40:02.230432000 +0300
+++ Source/Core/Core/IOS/USB/Bluetooth/BTReal.cpp	2017-12-26 19:40:30.638769000 +0300
@@ -568,12 +568,14 @@
     return false;
   }
 
+#ifndef __FreeBSD__
   const int result = libusb_detach_kernel_driver(m_handle, INTERFACE);
   if (result < 0 && result != LIBUSB_ERROR_NOT_FOUND && result != LIBUSB_ERROR_NOT_SUPPORTED)
   {
     PanicAlertT("Failed to detach kernel driver for BT passthrough: %s", libusb_error_name(result));
     return false;
   }
+#endif
   if (libusb_claim_interface(m_handle, INTERFACE) < 0)
   {
     PanicAlertT("Failed to claim interface for BT passthrough");
