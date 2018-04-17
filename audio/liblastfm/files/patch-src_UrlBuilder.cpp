- Use https to avoid 301 redirect
- Override default TolerantMode to prevent overprocessing the input URL

--- src/UrlBuilder.cpp.orig        2015-02-06 16:49:40 UTC
+++ src/UrlBuilder.cpp
@@ -60,10 +60,10 @@ QUrl
 lastfm::UrlBuilder::url() const
 {
     QUrl url;
-    url.setScheme( "http" );
+    url.setScheme( "https" );
     url.setHost( host() );
 #if QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 )
-    url.setPath( d->path );
+    url.setPath( d->path , QUrl::StrictMode );
 #else
     url.setEncodedPath( d->path );
 #endif
