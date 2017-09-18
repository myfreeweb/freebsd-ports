--- demos/cube.cpp.orig	2017-08-10 15:50:41 UTC
+++ demos/cube.cpp
@@ -2948,7 +2948,7 @@ int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPre
     return (int)msg.wParam;
 }
 
-#elif __linux__
+#elif defined(__unix__)
 
 int main(int argc, char **argv) {
     Demo demo;
