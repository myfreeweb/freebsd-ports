--- src/content_mapblock.cpp.orig	2018-03-11 21:42:16 UTC
+++ src/content_mapblock.cpp
@@ -43,7 +43,7 @@ with this program; if not, write to the Free Software
 // Corresponding offsets are listed in g_27dirs
 #define FRAMED_NEIGHBOR_COUNT 18

-static constexpr v3s16 light_dirs[8] = {
+static const v3s16 light_dirs[8] = {
	v3s16(-1, -1, -1),
	v3s16(-1, -1,  1),
	v3s16(-1,  1, -1),
