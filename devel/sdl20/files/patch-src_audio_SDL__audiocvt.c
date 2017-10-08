--- src/audio/SDL_audiocvt.c.orig	2017-10-07 23:59:17 UTC
+++ src/audio/SDL_audiocvt.c
@@ -725,7 +725,7 @@ SDL_ResampleCVT(SDL_AudioCVT *cvt, const int chans, co
 
     SDL_stack_free(padding);
 
-    SDL_memcpy(cvt->buf, dst, cvt->len_cvt);  /* !!! FIXME: remove this if we can get the resampler to work in-place again. */
+    SDL_memmove(cvt->buf, dst, cvt->len_cvt);  /* !!! FIXME: remove this if we can get the resampler to work in-place again. */
 
     if (cvt->filters[++cvt->filter_index]) {
         cvt->filters[cvt->filter_index](cvt, format);
