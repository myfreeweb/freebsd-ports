--- xwayland/launcher.c.orig	2016-09-17 07:06:45 UTC
+++ xwayland/launcher.c
@@ -42,6 +42,10 @@
 #include "shared/string-helpers.h"
 #include "compositor/weston.h"
 
+#define LOCK_FMT "/tmp/.X%d-lock"
+#define SOCKET_FMT "/tmp/.X11-unix/X%d"
+#define SOCKET2_FMT "/tmp/.X11-unix/X%d_"
+
 static int
 weston_xserver_handle_event(int listen_fd, uint32_t mask, void *data)
 {
@@ -68,9 +72,11 @@ weston_xserver_shutdown(struct weston_xs
 {
 	char path[256];
 
-	snprintf(path, sizeof path, "/tmp/.X%d-lock", wxs->display);
+	snprintf(path, sizeof path, LOCK_FMT, wxs->display);
 	unlink(path);
-	snprintf(path, sizeof path, "/tmp/.X11-unix/X%d", wxs->display);
+	snprintf(path, sizeof path, SOCKET_FMT, wxs->display);
+	unlink(path);
+	snprintf(path, sizeof path, SOCKET2_FMT, wxs->display);
 	unlink(path);
 	if (wxs->pid == 0) {
 		wl_event_source_remove(wxs->abstract_source);
@@ -98,10 +104,10 @@ bind_to_abstract_socket(int display)
 
 	addr.sun_family = AF_LOCAL;
 	name_size = snprintf(addr.sun_path, sizeof addr.sun_path,
-			     "%c/tmp/.X11-unix/X%d", 0, display);
+			     SOCKET2_FMT, display);
 	size = offsetof(struct sockaddr_un, sun_path) + name_size;
 	if (bind(fd, (struct sockaddr *) &addr, size) < 0) {
-		weston_log("failed to bind to @%s: %m\n", addr.sun_path + 1);
+		weston_log("failed to bind to '%s'\n", addr.sun_path);
 		close(fd);
 		return -1;
 	}
@@ -127,7 +133,7 @@ bind_to_unix_socket(int display)
 
 	addr.sun_family = AF_LOCAL;
 	name_size = snprintf(addr.sun_path, sizeof addr.sun_path,
-			     "/tmp/.X11-unix/X%d", display) + 1;
+			     SOCKET_FMT, display);
 	size = offsetof(struct sockaddr_un, sun_path) + name_size;
 	unlink(addr.sun_path);
 	if (bind(fd, (struct sockaddr *) &addr, size) < 0) {
@@ -152,7 +158,7 @@ create_lockfile(int display, char *lockf
 	int fd, size;
 	pid_t other;
 
-	snprintf(lockfile, lsize, "/tmp/.X%d-lock", display);
+	snprintf(lockfile, lsize, LOCK_FMT, display);
 	fd = open(lockfile, O_WRONLY | O_CLOEXEC | O_CREAT | O_EXCL, 0444);
 	if (fd < 0 && errno == EEXIST) {
 		fd = open(lockfile, O_CLOEXEC | O_RDONLY);
