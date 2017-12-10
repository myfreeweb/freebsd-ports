--- src/gallium/drivers/swr/rasterizer/memory/TilingFunctions.h.orig	2017-12-10 12:05:23 UTC
+++ src/gallium/drivers/swr/rasterizer/memory/TilingFunctions.h
@@ -624,7 +624,7 @@ uint32_t TileSwizzle2D(uint32_t xOffsetBytes, uint32_t
     case SWR_TILE_MODE_WMAJOR: return ComputeTileSwizzle2D<TilingTraits<SWR_TILE_MODE_WMAJOR, 8> >(xOffsetBytes, yOffsetRows, pState);
     default: SWR_INVALID("Unsupported tiling mode");
     }
-    return (uint32_t) NULL;
+    return 0;
 }
 
 //////////////////////////////////////////////////////////////////////////
@@ -644,7 +644,7 @@ uint32_t TileSwizzle3D(uint32_t xOffsetBytes, uint32_t
     case SWR_TILE_MODE_YMAJOR: return ComputeTileSwizzle3D<TilingTraits<SWR_TILE_MODE_YMAJOR, 32> >(xOffsetBytes, yOffsetRows, zOffsetSlices, pState);
     default: SWR_INVALID("Unsupported tiling mode");
     }
-    return (uint32_t) NULL;
+    return 0;
 }
 
 template<bool UseCachedOffsets>
@@ -677,7 +677,7 @@ uint32_t ComputeSurfaceOffset(uint32_t x, uint32_t y, 
     default: SWR_INVALID("Unsupported format");
     }
 
-    return (uint32_t) NULL;
+    return 0;
 }
 
 typedef void*(*PFN_COMPUTESURFADDR)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, const SWR_SURFACE_STATE*);
