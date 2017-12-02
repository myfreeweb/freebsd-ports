--- tools/mouse-dpi-tool.c.orig	2016-09-19 01:02:37 UTC
+++ tools/mouse-dpi-tool.c
@@ -26,7 +26,6 @@
 #endif
 
 #include <libevdev/libevdev.h>
-#include <sys/signalfd.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <limits.h>
@@ -50,6 +49,15 @@ struct measurements {
 	uint64_t us;
 };
 
+
+static volatile int sigint_catched = 0;
+static void
+sigint_handler(int signo)
+{
+	if (signo == SIGINT)
+		sigint_catched = 1;
+}
+
 static int
 usage(void) {
 	printf("Usage: %s /dev/input/event0\n", program_invocation_short_name);
@@ -147,24 +155,18 @@ handle_event(struct measurements *m, con
 
 static int
 mainloop(struct libevdev *dev, struct measurements *m) {
-	struct pollfd fds[2];
-	sigset_t mask;
+	struct pollfd fds[1];
 
 	fds[0].fd = libevdev_get_fd(dev);
 	fds[0].events = POLLIN;
 
-	sigemptyset(&mask);
-	sigaddset(&mask, SIGINT);
-	fds[1].fd = signalfd(-1, &mask, SFD_NONBLOCK);
-	fds[1].events = POLLIN;
-
-	sigprocmask(SIG_BLOCK, &mask, NULL);
+	signal(SIGINT, sigint_handler);
 
-	while (poll(fds, 2, -1)) {
+	while (poll(fds, 1, -1)) {
 		struct input_event ev;
 		int rc;
 
-		if (fds[1].revents)
+		if (sigint_catched)
 			break;
 
 		do {
