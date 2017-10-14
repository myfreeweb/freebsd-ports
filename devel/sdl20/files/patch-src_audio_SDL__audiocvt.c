Obtained from: upstream

Fixes sound issues, see https://bugzilla.libsdl.org/show_bug.cgi?id=3858

--- src/audio/SDL_audiocvt.c.orig	2017-09-22 18:51:01 UTC
+++ src/audio/SDL_audiocvt.c
@@ -31,6 +31,8 @@
 #include "../SDL_dataqueue.h"
 #include "SDL_cpuinfo.h"
 
+#define DEBUG_AUDIOSTREAM 0
+
 #ifdef __SSE3__
 #define HAVE_SSE3_INTRINSICS 1
 #endif
@@ -467,37 +469,42 @@ SDL_FreeResampleFilter(void)
 static int
 ResamplerPadding(const int inrate, const int outrate)
 {
-    return (inrate > outrate) ? (int) SDL_ceil(((float) (RESAMPLER_SAMPLES_PER_ZERO_CROSSING * inrate) / ((float) outrate))) : RESAMPLER_SAMPLES_PER_ZERO_CROSSING;
+    if (inrate == outrate) {
+        return 0;
+    } else if (inrate > outrate) {
+        return (int) SDL_ceil(((float) (RESAMPLER_SAMPLES_PER_ZERO_CROSSING * inrate) / ((float) outrate)));
+    }
+    return RESAMPLER_SAMPLES_PER_ZERO_CROSSING;
 }
 
 /* lpadding and rpadding are expected to be buffers of (ResamplePadding(inrate, outrate) * chans * sizeof (float)) bytes. */
 static int
 SDL_ResampleAudio(const int chans, const int inrate, const int outrate,
-                        float *lpadding, float *rpadding, const float *inbuf,
-                        const int inbuflen, float *outbuf, const int outbuflen)
+                        const float *lpadding, const float *rpadding,
+                        const float *inbuf, const int inbuflen,
+                        float *outbuf, const int outbuflen)
 {
-    const float outtimeincr = 1.0f / ((float) outrate);
-    const float ratio = ((float) outrate) / ((float) inrate);
+    const double finrate = (double) inrate;
+    const double outtimeincr = 1.0 / ((float) outrate);
+    const double  ratio = ((float) outrate) / ((float) inrate);
     const int paddinglen = ResamplerPadding(inrate, outrate);
     const int framelen = chans * (int)sizeof (float);
     const int inframes = inbuflen / framelen;
     const int wantedoutframes = (int) ((inbuflen / framelen) * ratio);  /* outbuflen isn't total to write, it's total available. */
     const int maxoutframes = outbuflen / framelen;
-    const int outframes = (wantedoutframes < maxoutframes) ? wantedoutframes : maxoutframes;
+    const int outframes = SDL_min(wantedoutframes, maxoutframes);
     float *dst = outbuf;
-    float outtime = 0.0f;
+    double outtime = 0.0;
     int i, j, chan;
 
     for (i = 0; i < outframes; i++) {
         const int srcindex = (int) (outtime * inrate);
-        const float finrate = (float) inrate;
-        const float intime = ((float) srcindex) / finrate;
-        const float innexttime = ((float) (srcindex + 1)) / finrate;
-
-        const float interpolation1 = 1.0f - (innexttime - outtime) / (innexttime - intime);
+        const double intime = ((double) srcindex) / finrate;
+        const double innexttime = ((double) (srcindex + 1)) / finrate;
+        const double interpolation1 = 1.0 - ((innexttime - outtime) / (innexttime - intime));
         const int filterindex1 = (int) (interpolation1 * RESAMPLER_SAMPLES_PER_ZERO_CROSSING);
-        const float interpolation2 = 1.0f - interpolation1;
-        const int filterindex2 = interpolation2 * RESAMPLER_SAMPLES_PER_ZERO_CROSSING;
+        const double interpolation2 = 1.0 - interpolation1;
+        const int filterindex2 = (int) (interpolation2 * RESAMPLER_SAMPLES_PER_ZERO_CROSSING);
 
         for (chan = 0; chan < chans; chan++) {
             float outsample = 0.0f;
@@ -714,18 +721,17 @@ SDL_ResampleCVT(SDL_AudioCVT *cvt, const int chans, co
     SDL_assert(format == AUDIO_F32SYS);
 
     /* we keep no streaming state here, so pad with silence on both ends. */
-    padding = SDL_stack_alloc(float, paddingsamples);
+    padding = (float *) SDL_calloc(paddingsamples, sizeof (float));
     if (!padding) {
         SDL_OutOfMemory();
         return;
     }
-    SDL_memset(padding, '\0', paddingsamples * sizeof (float));
 
     cvt->len_cvt = SDL_ResampleAudio(chans, inrate, outrate, padding, padding, src, srclen, dst, dstlen);
 
-    SDL_stack_free(padding);
+    SDL_free(padding);
 
-    SDL_memcpy(cvt->buf, dst, cvt->len_cvt);  /* !!! FIXME: remove this if we can get the resampler to work in-place again. */
+    SDL_memmove(cvt->buf, dst, cvt->len_cvt);  /* !!! FIXME: remove this if we can get the resampler to work in-place again. */
 
     if (cvt->filters[++cvt->filter_index]) {
         cvt->filters[cvt->filter_index](cvt, format);
@@ -1076,6 +1082,7 @@ struct SDL_AudioStream
     SDL_AudioCVT cvt_before_resampling;
     SDL_AudioCVT cvt_after_resampling;
     SDL_DataQueue *queue;
+    SDL_bool first_run;
     Uint8 *work_buffer_base;  /* maybe unaligned pointer from SDL_realloc(). */
     int work_buffer_len;
     int src_sample_frame_size;
@@ -1089,6 +1096,8 @@ struct SDL_AudioStream
     double rate_incr;
     Uint8 pre_resample_channels;
     int packetlen;
+    int resampler_padding_samples;
+    float *resampler_padding;
     void *resampler_state;
     SDL_ResampleAudioStreamFunc resampler_func;
     SDL_ResetAudioStreamResamplerFunc reset_resampler_func;
@@ -1129,16 +1138,7 @@ SDL_ResampleAudioStream_SRC(SDL_AudioStream *stream, c
     SRC_DATA data;
     int result;
 
-    if (inbuf == ((const float *) outbuf)) {  /* libsamplerate can't work in-place. */
-        Uint8 *ptr = EnsureStreamBufferSize(stream, inbuflen + outbuflen);
-        if (ptr == NULL) {
-            SDL_OutOfMemory();
-            return 0;
-        }
-        SDL_memcpy(ptr + outbuflen, ptr, inbuflen);
-        inbuf = (const float *) (ptr + outbuflen);
-        outbuf = (float *) ptr;
-    }
+    SDL_assert(inbuf != ((const float *) outbuf));  /* SDL_AudioStreamPut() shouldn't allow in-place resamples. */
 
     data.data_in = (float *)inbuf; /* Older versions of libsamplerate had a non-const pointer, but didn't write to it */
     data.input_frames = inbuflen / framelen;
@@ -1213,54 +1213,33 @@ SetupLibSampleRateResampling(SDL_AudioStream *stream)
 static int
 SDL_ResampleAudioStream(SDL_AudioStream *stream, const void *_inbuf, const int inbuflen, void *_outbuf, const int outbuflen)
 {
+    const Uint8 *inbufend = ((const Uint8 *) _inbuf) + inbuflen;
     const float *inbuf = (const float *) _inbuf;
     float *outbuf = (float *) _outbuf;
     const int chans = (int) stream->pre_resample_channels;
     const int inrate = stream->src_rate;
     const int outrate = stream->dst_rate;
-    const int paddingsamples = ResamplerPadding(inrate, outrate) * chans;
+    const int paddingsamples = stream->resampler_padding_samples;
     const int paddingbytes = paddingsamples * sizeof (float);
     float *lpadding = (float *) stream->resampler_state;
-    float *rpadding;
+    const float *rpadding = (const float *) inbufend; /* we set this up so there are valid padding samples at the end of the input buffer. */
+    const int cpy = SDL_min(inbuflen, paddingbytes);
     int retval;
 
-    if (inbuf == ((const float *) outbuf)) {  /* !!! FIXME can't work in-place (for now!). */
-        Uint8 *ptr = EnsureStreamBufferSize(stream, inbuflen + outbuflen);
-        if (ptr == NULL) {
-            SDL_OutOfMemory();
-            return 0;
-        }
-        SDL_memcpy(ptr + outbuflen, ptr, inbuflen);
-        inbuf = (const float *) (ptr + outbuflen);
-        outbuf = (float *) ptr;
-    }
+    SDL_assert(inbuf != ((const float *) outbuf));  /* SDL_AudioStreamPut() shouldn't allow in-place resamples. */
 
-    /* !!! FIXME: streaming current resamples on Put, because of probably good reasons I can't remember right now, but if we resample on Get, we'd be able to access legit right padding values. */
-    rpadding = SDL_stack_alloc(float, paddingsamples);
-    if (!rpadding) {
-        SDL_OutOfMemory();
-        return 0;
-    }
-    SDL_memset(rpadding, '\0', paddingbytes);
-
     retval = SDL_ResampleAudio(chans, inrate, outrate, lpadding, rpadding, inbuf, inbuflen, outbuf, outbuflen);
 
-    SDL_stack_free(rpadding);
-
     /* update our left padding with end of current input, for next run. */
-    SDL_memcpy(lpadding, ((const Uint8 *) inbuf) + (inbuflen - paddingbytes), paddingbytes);
-
+    SDL_memcpy((lpadding + paddingsamples) - (cpy / sizeof (float)), inbufend - cpy, cpy);
     return retval;
 }
 
 static void
 SDL_ResetAudioStreamResampler(SDL_AudioStream *stream)
 {
-    /* set all the left padding to silence. */
-    const int inrate = stream->src_rate;
-    const int outrate = stream->dst_rate;
-    const int chans = (int) stream->pre_resample_channels;
-    const int len = ResamplerPadding(inrate, outrate) * chans;
+    /* set all the padding to silence. */
+    const int len = stream->resampler_padding_samples;
     SDL_memset(stream->resampler_state, '\0', len * sizeof (float));
 }
 
@@ -1293,6 +1272,7 @@ SDL_NewAudioStream(const SDL_AudioFormat src_format,
        the resampled data (!!! FIXME: decide if that works in practice, though!). */
     pre_resample_channels = SDL_min(src_channels, dst_channels);
 
+    retval->first_run = SDL_TRUE;
     retval->src_sample_frame_size = (SDL_AUDIO_BITSIZE(src_format) / 8) * src_channels;
     retval->src_format = src_format;
     retval->src_channels = src_channels;
@@ -1304,7 +1284,15 @@ SDL_NewAudioStream(const SDL_AudioFormat src_format,
     retval->pre_resample_channels = pre_resample_channels;
     retval->packetlen = packetlen;
     retval->rate_incr = ((double) dst_rate) / ((double) src_rate);
+    retval->resampler_padding_samples = ResamplerPadding(retval->src_rate, retval->dst_rate) * pre_resample_channels;
+    retval->resampler_padding = (float *) SDL_calloc(retval->resampler_padding_samples, sizeof (float));
 
+    if (retval->resampler_padding == NULL) {
+        SDL_FreeAudioStream(retval);
+        SDL_OutOfMemory();
+        return NULL;
+    }
+
     /* Not resampling? It's an easy conversion (and maybe not even that!). */
     if (src_rate == dst_rate) {
         retval->cvt_before_resampling.needed = SDL_FALSE;
@@ -1325,9 +1313,7 @@ SDL_NewAudioStream(const SDL_AudioFormat src_format,
 #endif
 
         if (!retval->resampler_func) {
-            const int chans = (int) pre_resample_channels;
-            const int len = ResamplerPadding(src_rate, dst_rate) * chans;
-            retval->resampler_state = SDL_calloc(len, sizeof (float));
+            retval->resampler_state = SDL_calloc(retval->resampler_padding_samples, sizeof (float));
             if (!retval->resampler_state) {
                 SDL_FreeAudioStream(retval);
                 SDL_OutOfMemory();
@@ -1366,7 +1352,12 @@ int
 SDL_AudioStreamPut(SDL_AudioStream *stream, const void *buf, const Uint32 _buflen)
 {
     int buflen = (int) _buflen;
-    const void *origbuf = buf;
+    int workbuflen;
+    Uint8 *workbuf;
+    Uint8 *resamplebuf = NULL;
+    int resamplebuflen = 0;
+    int neededpaddingbytes;
+    int paddingbytes;
 
     /* !!! FIXME: several converters can take advantage of SIMD, but only
        !!! FIXME:  if the data is aligned to 16 bytes. EnsureStreamBufferSize()
@@ -1376,6 +1367,10 @@ SDL_AudioStreamPut(SDL_AudioStream *stream, const void
        !!! FIXME:  isn't a multiple of 16. In these cases, we should chop off
        !!! FIXME:  a few samples at the end and convert them separately. */
 
+    #if DEBUG_AUDIOSTREAM
+    printf("AUDIOSTREAM: wants to put %d preconverted bytes\n", buflen);
+    #endif
+
     if (!stream) {
         return SDL_InvalidParamError("stream");
     } else if (!buf) {
@@ -1384,60 +1379,120 @@ SDL_AudioStreamPut(SDL_AudioStream *stream, const void
         return 0;  /* nothing to do. */
     } else if ((buflen % stream->src_sample_frame_size) != 0) {
         return SDL_SetError("Can't add partial sample frames");
+    } else if (buflen < ((stream->resampler_padding_samples / stream->pre_resample_channels) * stream->src_sample_frame_size)) {
+        return SDL_SetError("Need to put a larger buffer");
     }
 
+    /* no padding prepended on first run. */
+    neededpaddingbytes = stream->resampler_padding_samples * sizeof (float);
+    paddingbytes = stream->first_run ? 0 : neededpaddingbytes;
+    stream->first_run = SDL_FALSE;
+
+    if (!stream->cvt_before_resampling.needed &&
+        (stream->dst_rate == stream->src_rate) &&
+        !stream->cvt_after_resampling.needed) {
+        #if DEBUG_AUDIOSTREAM
+        printf("AUDIOSTREAM: no conversion needed at all, queueing %d bytes.\n", buflen);
+        #endif
+        return SDL_WriteToDataQueue(stream->queue, buf, buflen);
+    }
+
+    /* Make sure the work buffer can hold all the data we need at once... */
+    workbuflen = buflen;
     if (stream->cvt_before_resampling.needed) {
-        const int workbuflen = buflen * stream->cvt_before_resampling.len_mult;  /* will be "* 1" if not needed */
-        Uint8 *workbuf = EnsureStreamBufferSize(stream, workbuflen);
-        if (workbuf == NULL) {
-            return -1;  /* probably out of memory. */
-        }
-        SDL_assert(buf == origbuf);
-        SDL_memcpy(workbuf, buf, buflen);
-        stream->cvt_before_resampling.buf = workbuf;
+        workbuflen *= stream->cvt_before_resampling.len_mult;
+    }
+
+    if (stream->dst_rate != stream->src_rate) {
+        /* resamples can't happen in place, so make space for second buf. */
+        const int framesize = stream->pre_resample_channels * sizeof (float);
+        const int frames = workbuflen / framesize;
+        resamplebuflen = ((int) SDL_ceil(frames * stream->rate_incr)) * framesize;
+        #if DEBUG_AUDIOSTREAM
+        printf("AUDIOSTREAM: will resample %d bytes to %d (ratio=%.6f)\n", workbuflen, resamplebuflen, stream->rate_incr);
+        #endif
+        workbuflen += resamplebuflen;
+    }
+
+    if (stream->cvt_after_resampling.needed) {
+        /* !!! FIXME: buffer might be big enough already? */
+        workbuflen *= stream->cvt_after_resampling.len_mult;
+    }
+
+    workbuflen += neededpaddingbytes;
+
+    #if DEBUG_AUDIOSTREAM
+    printf("AUDIOSTREAM: Putting %d bytes of preconverted audio, need %d byte work buffer\n", buflen, workbuflen);
+    #endif
+
+    workbuf = EnsureStreamBufferSize(stream, workbuflen);
+    if (!workbuf) {
+        return -1;  /* probably out of memory. */
+    }
+
+    resamplebuf = workbuf;  /* default if not resampling. */
+
+    SDL_memcpy(workbuf + paddingbytes, buf, buflen);
+
+    if (stream->cvt_before_resampling.needed) {
+        stream->cvt_before_resampling.buf = workbuf + paddingbytes;
         stream->cvt_before_resampling.len = buflen;
         if (SDL_ConvertAudio(&stream->cvt_before_resampling) == -1) {
             return -1;   /* uhoh! */
         }
-        buf = workbuf;
         buflen = stream->cvt_before_resampling.len_cvt;
+
+        #if DEBUG_AUDIOSTREAM
+        printf("AUDIOSTREAM: After initial conversion we have %d bytes\n", buflen);
+        #endif
     }
 
     if (stream->dst_rate != stream->src_rate) {
-        const int workbuflen = buflen * ((int) SDL_ceil(stream->rate_incr));
-        Uint8 *workbuf = EnsureStreamBufferSize(stream, workbuflen);
-        if (workbuf == NULL) {
-            return -1;  /* probably out of memory. */
+        /* save off some samples at the end; they are used for padding now so
+           the resampler is coherent and then used at the start of the next
+           put operation. Prepend last put operation's padding, too. */
+
+        /* prepend prior put's padding. :P */
+        if (paddingbytes) {
+            SDL_memcpy(workbuf, stream->resampler_padding, paddingbytes);
+            buflen += paddingbytes;
         }
-        /* don't SDL_memcpy(workbuf, buf, buflen) here; our resampler can work inplace or not,
-           libsamplerate needs buffers to be separate; either way, avoid a copy here if possible. */
-        if (buf != origbuf) {
-            buf = workbuf;  /* in case we realloc()'d the pointer. */
+
+        /* save off the data at the end for the next run. */
+        SDL_memcpy(stream->resampler_padding, workbuf + (buflen - neededpaddingbytes), neededpaddingbytes);
+
+        resamplebuf = workbuf + buflen;  /* skip to second piece of workbuf. */
+        SDL_assert(buflen >= neededpaddingbytes);
+        if (buflen > neededpaddingbytes) {
+            buflen = stream->resampler_func(stream, workbuf, buflen - neededpaddingbytes, resamplebuf, resamplebuflen);
+        } else {
+            buflen = 0;
         }
-        buflen = stream->resampler_func(stream, buf, buflen, workbuf, workbuflen);
-        buf = EnsureStreamBufferSize(stream, workbuflen);
-        SDL_assert(buf != NULL);  /* shouldn't be growing, just aligning. */
+
+        #if DEBUG_AUDIOSTREAM
+        printf("AUDIOSTREAM: After resampling we have %d bytes\n", buflen);
+        #endif
     }
 
-    if (stream->cvt_after_resampling.needed) {
-        const int workbuflen = buflen * stream->cvt_after_resampling.len_mult;  /* will be "* 1" if not needed */
-        Uint8 *workbuf = EnsureStreamBufferSize(stream, workbuflen);
-        if (workbuf == NULL) {
-            return -1;  /* probably out of memory. */
-        }
-        if (buf == origbuf) {  /* copy if we haven't before. */
-            SDL_memcpy(workbuf, origbuf, buflen);
-        }
-        stream->cvt_after_resampling.buf = workbuf;
+    if (stream->cvt_after_resampling.needed && (buflen > 0)) {
+        stream->cvt_after_resampling.buf = resamplebuf;
         stream->cvt_after_resampling.len = buflen;
         if (SDL_ConvertAudio(&stream->cvt_after_resampling) == -1) {
             return -1;   /* uhoh! */
         }
-        buf = workbuf;
         buflen = stream->cvt_after_resampling.len_cvt;
+
+        #if DEBUG_AUDIOSTREAM
+        printf("AUDIOSTREAM: After final conversion we have %d bytes\n", buflen);
+        #endif
     }
 
-    return SDL_WriteToDataQueue(stream->queue, buf, buflen);
+    #if DEBUG_AUDIOSTREAM
+    printf("AUDIOSTREAM: Final output is %d bytes\n", buflen);
+    #endif
+
+    /* resamplebuf holds the final output, even if we didn't resample. */
+    return buflen ? SDL_WriteToDataQueue(stream->queue, resamplebuf, buflen) : 0;
 }
 
 void
@@ -1450,6 +1505,7 @@ SDL_AudioStreamClear(SDL_AudioStream *stream)
         if (stream->reset_resampler_func) {
             stream->reset_resampler_func(stream);
         }
+        stream->first_run = SDL_TRUE;
     }
 }
 
@@ -1458,6 +1514,10 @@ SDL_AudioStreamClear(SDL_AudioStream *stream)
 int
 SDL_AudioStreamGet(SDL_AudioStream *stream, void *buf, const Uint32 len)
 {
+    #if DEBUG_AUDIOSTREAM
+    printf("AUDIOSTREAM: want to get %u converted bytes\n", (unsigned int) len);
+    #endif
+
     if (!stream) {
         return SDL_InvalidParamError("stream");
     } else if (!buf) {
@@ -1488,6 +1548,7 @@ SDL_FreeAudioStream(SDL_AudioStream *stream)
         }
         SDL_FreeDataQueue(stream->queue);
         SDL_free(stream->work_buffer_base);
+        SDL_free(stream->resampler_padding);
         SDL_free(stream);
     }
 }
