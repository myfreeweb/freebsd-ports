--- glfw/linux_joystick.c.orig	2018-03-17 12:15:57 UTC
+++ glfw/linux_joystick.c
@@ -25,6 +25,10 @@
 //
 //========================================================================
 
+#ifndef __linux__
+#include "null_joystick.c"
+#else
+
 #include "internal.h"
 
 #include <sys/types.h>
@@ -431,4 +435,6 @@ int _glfwPlatformPollJoystick(_GLFWjoystick* js, int m
 void _glfwPlatformUpdateGamepadGUID(char* guid)
 {
 }
+
+#endif
 
