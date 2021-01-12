https://bugs.kde.org/show_bug.cgi?id=431505

--- src/monitor/glwidget.cpp.orig	2021-01-12 13:57:33 UTC
+++ src/monitor/glwidget.cpp
@@ -120,7 +120,10 @@ GLWidget::GLWidget(int id, QObject *parent)
     setPersistentSceneGraph(true);
     setClearBeforeRendering(false);
     setResizeMode(QQuickView::SizeRootObjectToView);
-    m_offscreenSurface.setFormat(QOpenGLContext::globalShareContext()->format());
+    auto fmt = QOpenGLContext::globalShareContext()->format();
+    fmt.setDepthBufferSize(format().depthBufferSize());
+    fmt.setStencilBufferSize(format().stencilBufferSize());
+    m_offscreenSurface.setFormat(fmt);
     m_offscreenSurface.create();
 
     m_refreshTimer.setSingleShot(true);
