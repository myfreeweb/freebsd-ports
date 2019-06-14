--- rtengine/previewimage.cc.orig	2019-06-13 11:51:46 UTC
+++ rtengine/previewimage.cc
@@ -124,7 +124,7 @@ PreviewImage::PreviewImage (const Glib::ustring &fname
             rtengine::Image8 output(fw, fh);
             rawImage.convertColorSpace(&image, params.icm, wb);
 #ifdef _OPENMP
-            #pragma omp parallel for schedule(dynamic, 10)
+            #pragma omp parallel for
 #endif
             for (int i = 0; i < fh; ++i)
                 for (int j = 0; j < fw; ++j) {
