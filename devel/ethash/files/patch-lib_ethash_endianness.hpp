--- lib/ethash/endianness.hpp.orig	2018-09-25 09:46:42 UTC
+++ lib/ethash/endianness.hpp
@@ -31,6 +31,10 @@
 #define bswap32 __builtin_bswap32
 #define bswap64 __builtin_bswap64
 
+#elif __FreeBSD__
+
+#include <sys/endian.h>
+
 #else
 
 #include <endian.h>
