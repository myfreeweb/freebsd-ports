--- src/core/content_browser_client_qt.cpp.orig	2018-01-07 16:23:55.380472000 +0300
+++ src/core/content_browser_client_qt.cpp	2018-01-07 16:23:09.135025000 +0300
@@ -319,7 +319,7 @@
         else if (platform == QLatin1String("qnx"))
             m_handle = pni->nativeResourceForContext(QByteArrayLiteral("eglcontext"), qtContext);
         else if (platform == QLatin1String("eglfs") || platform == QLatin1String("wayland")
-                 || platform == QLatin1String("wayland-egl"))
+                 || platform == QLatin1String("wayland-egl") || platform == QLatin1String("gtk"))
             m_handle = pni->nativeResourceForContext(QByteArrayLiteral("eglcontext"), qtContext);
         else if (platform == QLatin1String("windows")) {
             if (gl::GetGLImplementation() == gl::kGLImplementationEGLGLES2)
