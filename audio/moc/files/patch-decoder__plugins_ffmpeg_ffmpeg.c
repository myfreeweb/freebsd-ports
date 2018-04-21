--- decoder_plugins/ffmpeg/ffmpeg.c.orig	2018-04-21 14:06:30 UTC
+++ decoder_plugins/ffmpeg/ffmpeg.c
@@ -993,8 +993,8 @@ static void *ffmpeg_open (const char *file)
 #endif
 
 	set_downmixing (data);
-	if (data->codec->capabilities & CODEC_CAP_TRUNCATED)
-		data->enc->flags |= CODEC_FLAG_TRUNCATED;
+	if (data->codec->capabilities & AV_CODEC_CAP_TRUNCATED)
+		data->enc->flags |= AV_CODEC_FLAG_TRUNCATED;
 
 #ifdef HAVE_AVCODEC_OPEN2
 	if (avcodec_open2 (data->enc, data->codec, NULL) < 0)
@@ -1025,7 +1025,7 @@ static void *ffmpeg_open (const char *file)
 
 	data->sample_width = sfmt_Bps (data->fmt);
 
-	if (data->codec->capabilities & CODEC_CAP_DELAY)
+	if (data->codec->capabilities & AV_CODEC_CAP_DELAY)
 		data->delay = true;
 	data->seek_broken = is_seek_broken (data);
 	data->timing_broken = is_timing_broken (data->ic);
