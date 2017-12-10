--- src/gallium/drivers/swr/rasterizer/common/os.h.orig	2017-12-10 12:01:20 UTC
+++ src/gallium/drivers/swr/rasterizer/common/os.h
@@ -89,7 +89,7 @@ static inline void AlignedFree(void* p)
 #define _mm_popcount_sizeT _mm_popcnt_u32
 #endif
 
-#elif defined(__APPLE__) || defined(FORCE_LINUX) || defined(__linux__) || defined(__gnu_linux__)
+#elif defined(__APPLE__) || defined(FORCE_LINUX) || defined(__linux__) || defined(__gnu_linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 
 #define SWR_API
 #define SWR_VISIBLE __attribute__((visibility("default")))
