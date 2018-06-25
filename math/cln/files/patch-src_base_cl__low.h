--- src/base/cl_low.h.orig	2014-10-05 21:21:40 UTC
+++ src/base/cl_low.h
@@ -207,7 +207,7 @@ inline uint32 mulu32_unchecked (uint32 arg1, uint32 ar
   // declared inside a namespace!
 } extern "C" uint32 mulu32_high; namespace cln {        // -> High-Teil
 #else
-  extern "C" uint32 mulu32_high;                        // -> High-Teil
+}  extern "C" uint32 mulu32_high; namespace cln {       // -> High-Teil
 #endif
 #if defined(__GNUC__) && defined(__m68k__) && !defined(NO_ASM)
   #define mulu32(x,y,hi_zuweisung,lo_zuweisung)  \
@@ -439,7 +439,7 @@ inline uint32 mulu32_unchecked (uint32 arg1, uint32 ar
   // Workaround MSVC compiler bug.
 } extern "C" uint16 divu_16_rest; namespace cln {         // -> Rest r
 #else
-  extern "C" uint16 divu_16_rest;                         // -> Rest r
+}  extern "C" uint16 divu_16_rest; namespace cln {        // -> Rest r
 #endif
 #endif
 #if defined(__GNUC__) && defined(__sparc64__) && !defined(NO_ASM)
@@ -589,7 +589,7 @@ inline uint32 mulu32_unchecked (uint32 arg1, uint32 ar
   // Workaround MSVC compiler bug.
 } extern "C" uint32 divu_32_rest; namespace cln {         // -> Rest r
 #else
-  extern "C" uint32 divu_32_rest;                         // -> Rest r
+}  extern "C" uint32 divu_32_rest; namespace cln {        // -> Rest r
 #endif
 #if defined(__GNUC__) && defined(__sparc64__) && !defined(NO_ASM)
   #define divu_3232_3232(x,y,q_zuweisung,r_zuweisung)  \
@@ -979,7 +979,7 @@ inline uint32 mulu32_unchecked (uint32 arg1, uint32 ar
   // Workaround MSVC compiler bug.
 } extern "C" uint64 divu_64_rest; namespace cln {         // -> Rest r
 #else
-  extern "C" uint64 divu_64_rest;                         // -> Rest r
+}  extern "C" uint64 divu_64_rest; namespace cln {        // -> Rest r
 #endif
   #define divu_6464_6464(x,y,q_zuweisung,r_zuweisung)  \
     { q_zuweisung divu_6464_6464_(x,y); r_zuweisung divu_64_rest; }
