--- linux-launcher.c.orig	2018-03-19 17:44:22 UTC
+++ linux-launcher.c
@@ -79,6 +79,8 @@ int main(int argc, char *argv[]) {
     char apple[PATH_MAX+1] = {0};
     if (_NSGetExecutablePath(apple, &size) != 0) { fprintf(stderr, "Failed to get path to executable\n"); return 1; }
     if (realpath(apple, exe) == NULL) { fprintf(stderr, "realpath() failed on the executable's path\n"); return 1; }
+#elif __FreeBSD__
+    if (realpath("/proc/curproc/file", exe) == NULL) { fprintf(stderr, "Failed to read /proc/curproc/file, please run 'mount -t procfs procfs /proc' as root\n"); return 1; }
 #else
     if (realpath("/proc/self/exe", exe) == NULL) { fprintf(stderr, "Failed to read /proc/self/exe\n"); return 1; }
 #endif
