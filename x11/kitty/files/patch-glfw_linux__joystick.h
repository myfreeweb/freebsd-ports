--- glfw/linux_joystick.h.orig	2018-03-17 12:15:57 UTC
+++ glfw/linux_joystick.h
@@ -24,6 +24,10 @@
 //
 //========================================================================
 
+#ifndef __linux__
+#include "null_joystick.h"
+#else
+
 #include <linux/input.h>
 #include <linux/limits.h>
 #include <regex.h>
@@ -59,4 +63,6 @@ typedef struct _GLFWlibraryLinux
 GLFWbool _glfwInitJoysticksLinux(void);
 void _glfwTerminateJoysticksLinux(void);
 void _glfwDetectJoystickConnectionLinux(void);
+
+#endif
 
