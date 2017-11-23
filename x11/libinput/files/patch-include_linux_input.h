--- include/linux/input.h.orig	2017-10-30 05:16:22 UTC
+++ include/linux/input.h
@@ -11,7 +11,18 @@
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#define __u8 uint8_t
+#define __u16 uint16_t
+#define __u32 uint32_t
+#define __u64 uint64_t
+#define __s16 int16_t
+#define __s32 int32_t
+#define _IOC_READ IOC_OUT
+#define _IOC_WRITE IOC_IN
+#else
 #include <linux/types.h>
+#endif
 
 #include "input-event-codes.h"
 
