--- tools/touchpad-edge-detector.c.orig	2016-09-15 01:57:24 UTC
+++ tools/touchpad-edge-detector.c
@@ -26,7 +26,6 @@
 #endif
 
 #include <libevdev/libevdev.h>
-#include <sys/signalfd.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <limits.h>
@@ -60,6 +59,14 @@ struct size {
 	int w, h;
 };
 
+static volatile int sigint_catched = 0;
+static void
+sigint_handler(int signo)
+{
+	if (signo == SIGINT)
+		sigint_catched = 1;
+}
+
 static int
 print_current_values(const struct dimensions *d)
 {
@@ -105,24 +112,18 @@ handle_event(struct dimensions *d, const
 
 static int
 mainloop(struct libevdev *dev, struct dimensions *dim) {
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
