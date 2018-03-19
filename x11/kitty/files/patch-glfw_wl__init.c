--- glfw/wl_init.c.orig	2018-03-19 17:23:24 UTC
+++ glfw/wl_init.c
@@ -1046,8 +1046,10 @@ int _glfwPlatformInit(void)
     // Sync so we got all initial output events
     wl_display_roundtrip(_glfw.wl.display);
 
+#ifdef __linux__
     if (!_glfwInitJoysticksLinux())
         return GLFW_FALSE;
+#endif
 
     _glfwInitTimerPOSIX();
 
@@ -1073,7 +1075,9 @@ int _glfwPlatformInit(void)
 
 void _glfwPlatformTerminate(void)
 {
+#ifdef __linux__
     _glfwTerminateJoysticksLinux();
+#endif
     _glfwTerminateEGL();
     if (_glfw.wl.egl.handle)
     {
