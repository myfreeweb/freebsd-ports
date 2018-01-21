--- include/configs/rpi.h.orig	2018-01-20 14:35:07 UTC
+++ include/configs/rpi.h
@@ -76,11 +76,11 @@
 #endif
 
 /* Console UART */
-#if defined (CONFIG_BCM2837) || defined(CONFIG_TARGET_RPI_0_W)
-#define CONFIG_BCM283X_MU_SERIAL
-#else
+/* #if defined (CONFIG_BCM2837) || defined(CONFIG_TARGET_RPI_0_W) */
+/* #define CONFIG_BCM283X_MU_SERIAL */
+/* #else */
 #define CONFIG_PL01X_SERIAL
-#endif
+/* #endif */
 
 /* Console configuration */
 #define CONFIG_SYS_CBSIZE		1024
@@ -141,7 +141,7 @@
 #define ENV_MEM_LAYOUT_SETTINGS \
 	"fdt_high=ffffffff\0" \
 	"initrd_high=ffffffff\0" \
-	"fdt_addr_r=0x00000100\0" \
+	"fdt_addr_r=0x00004000\0" \
 	"pxefile_addr_r=0x00100000\0" \
 	"kernel_addr_r=0x01000000\0" \
 	"scriptaddr=0x02000000\0" \
