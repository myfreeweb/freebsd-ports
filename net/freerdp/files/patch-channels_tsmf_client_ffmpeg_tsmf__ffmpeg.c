--- channels/tsmf/client/ffmpeg/tsmf_ffmpeg.c.orig	2017-11-28 14:26:30 UTC
+++ channels/tsmf/client/ffmpeg/tsmf_ffmpeg.c
@@ -346,7 +346,7 @@ static BOOL tsmf_ffmpeg_decode_video(ITSMFDecoder* dec
 		av_picture_copy((AVPicture*) frame, (AVPicture*) mdecoder->frame,
 						mdecoder->codec_context->pix_fmt,
 						mdecoder->codec_context->width, mdecoder->codec_context->height);
-		av_free(frame);
+		av_frame_free(&frame);
 	}
 
 	return ret;
@@ -432,7 +432,7 @@ static BOOL tsmf_ffmpeg_decode_audio(ITSMFDecoder* dec
 			{
 				frame_size = 0;
 			}
-			av_free(decoded_frame);
+			av_frame_free(&decoded_frame);
 		}
 #endif
 		if (len > 0)
@@ -529,7 +529,7 @@ static void tsmf_ffmpeg_free(ITSMFDecoder* decoder)
 {
 	TSMFFFmpegDecoder* mdecoder = (TSMFFFmpegDecoder*) decoder;
 	if (mdecoder->frame)
-		av_free(mdecoder->frame);
+		av_frame_free(&mdecoder->frame);
 
 	free(mdecoder->decoded_data);
 
@@ -539,7 +539,7 @@ static void tsmf_ffmpeg_free(ITSMFDecoder* decoder)
 			avcodec_close(mdecoder->codec_context);
 
 		free(mdecoder->codec_context->extradata);
-		av_free(mdecoder->codec_context);
+		av_frame_free(&mdecoder->codec_context);
 	}
 	free(decoder);
 }
