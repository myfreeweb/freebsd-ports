--- libretro-common/include/streams/interface_stream.h.orig	2018-02-19 12:43:32 UTC
+++ libretro-common/include/streams/interface_stream.h
@@ -32,6 +32,8 @@

 RETRO_BEGIN_DECLS
 
+#include <sys/types.h>
+
 enum intfstream_type
 {
    INTFSTREAM_FILE = 0,
