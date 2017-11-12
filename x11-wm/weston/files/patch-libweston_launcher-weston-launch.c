--- libweston/launcher-weston-launch.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/launcher-weston-launch.c
@@ -37,19 +37,29 @@
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <unistd.h>
-#include <linux/vt.h>
-#include <linux/kd.h>
-#include <linux/major.h>
+
+#include <termios.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#define TTY_BASENAME    "/dev/ttyv"
+#define TTY_0           "/dev/ttyv0"
+
+/* #include <linux/kd.h> */
+/* #include <linux/major.h> */
+/* #include <linux/vt.h> */
+/* #define TTY_BASENAME "/dev/tty" */
+/* #define TTY_0        "/dev/tty0" */
+
 
 #include "compositor.h"
 #include "weston-launch.h"
 #include "launcher-impl.h"
 
-#define DRM_MAJOR 226
+/* #define DRM_MAJOR 226 */
 
-#ifndef KDSKBMUTE
-#define KDSKBMUTE	0x4B51
-#endif
+/* #ifndef KDSKBMUTE */
+/* #define KDSKBMUTE	0x4B51 */
+/* #endif */
 
 #ifdef HAVE_LIBDRM
 
@@ -119,7 +129,7 @@ launcher_weston_launch_open(struct westo
 	msg.msg_iovlen = 1;
 	msg.msg_control = control;
 	msg.msg_controllen = sizeof control;
-	
+
 	do {
 		len = recvmsg(launcher->fd, &msg, MSG_CMSG_CLOEXEC);
 	} while (len < 0 && errno == EINTR);
@@ -141,6 +151,7 @@ launcher_weston_launch_open(struct westo
 		fprintf(stderr, "missing drm fd in socket request\n");
 		return -1;
 	}
+	weston_log("%s: Got fd %d from socket fd %d\n", __func__, data->fd, launcher->fd);
 
 	return data->fd;
 }
@@ -148,22 +159,35 @@ launcher_weston_launch_open(struct westo
 static void
 launcher_weston_launch_close(struct weston_launcher *launcher_base, int fd)
 {
+	weston_log("%s: fd %d\n",__func__,fd);
 	close(fd);
 }
 
 static void
 launcher_weston_launch_restore(struct weston_launcher *launcher_base)
 {
+	weston_log("%s\n",__func__);
 	struct launcher_weston_launch *launcher = wl_container_of(launcher_base, launcher, base);
 	struct vt_mode mode = { 0 };
 
-	if (ioctl(launcher->tty, KDSKBMUTE, 0) &&
+	if (/*ioctl(launcher->tty, KDSKBMUTE, 0) &&*/
 	    ioctl(launcher->tty, KDSKBMODE, launcher->kb_mode))
 		weston_log("failed to restore kb mode: %m\n");
 
 	if (ioctl(launcher->tty, KDSETMODE, KD_TEXT))
 		weston_log("failed to set KD_TEXT mode on tty: %m\n");
 
+	/* Restore sane mode */
+	struct termios tios;
+	if (tcgetattr(launcher->tty, &tios)) {
+		weston_log("Failed to get terminal attribute\n");
+	} else {
+		cfmakesane(&tios);
+		if (tcsetattr(launcher->tty, TCSAFLUSH, &tios)) {
+			weston_log("Failed to set terminal attribute\n");
+		}
+	}
+
 	/* We have to drop master before we switch the VT back in
 	 * VT_AUTO, so we don't risk switching to a VT with another
 	 * display server, that will then fail to set drm master. */
@@ -179,9 +203,10 @@ launcher_weston_launch_data(int fd, uint
 {
 	struct launcher_weston_launch *launcher = data;
 	int len, ret;
+	weston_log("%s\n",__func__);
 
 	if (mask & (WL_EVENT_HANGUP | WL_EVENT_ERROR)) {
-		weston_log("launcher socket closed, exiting\n");
+		weston_log("launcher socket (launcher->fd %d) closed, exiting\n",launcher->fd);
 		/* Normally the weston-launch will reset the tty, but
 		 * in this case it died or something, so do it here so
 		 * we don't end up with a stuck vt. */
@@ -195,11 +220,13 @@ launcher_weston_launch_data(int fd, uint
 
 	switch (ret) {
 	case WESTON_LAUNCHER_ACTIVATE:
+		weston_log("%s: Launcher activate event\n",__func__);
 		launcher->compositor->session_active = 1;
 		wl_signal_emit(&launcher->compositor->session_signal,
 			       launcher->compositor);
 		break;
 	case WESTON_LAUNCHER_DEACTIVATE:
+		weston_log("%s: Launcher deactivate event\n",__func__);
 		launcher->compositor->session_active = 0;
 		wl_signal_emit(&launcher->compositor->session_signal,
 			       launcher->compositor);
@@ -215,6 +242,7 @@ launcher_weston_launch_data(int fd, uint
 static int
 launcher_weston_launch_activate_vt(struct weston_launcher *launcher_base, int vt)
 {
+	weston_log("%s: vt %d\n",__func__,vt);
 	struct launcher_weston_launch *launcher = wl_container_of(launcher_base, launcher, base);
 	return ioctl(launcher->tty, VT_ACTIVATE, vt);
 }
@@ -223,6 +251,7 @@ static int
 launcher_weston_launch_connect(struct weston_launcher **out, struct weston_compositor *compositor,
 			       int tty, const char *seat_id, bool sync_drm)
 {
+	weston_log("%s\n",__func__);
 	struct launcher_weston_launch *launcher;
 	struct wl_event_loop *loop;
 
@@ -240,7 +269,9 @@ launcher_weston_launch_connect(struct we
 		/* We don't get a chance to read out the original kb
 		 * mode for the tty, so just hard code K_UNICODE here
 		 * in case we have to clean if weston-launch dies. */
-		launcher->kb_mode = K_UNICODE;
+
+		launcher->kb_mode = K_XLATE;
+		/* launcher->kb_mode = K_UNICODE; */
 
 		loop = wl_display_get_event_loop(compositor->wl_display);
 		launcher->source = wl_event_loop_add_fd(loop, launcher->fd,
@@ -261,6 +292,7 @@ launcher_weston_launch_connect(struct we
 static void
 launcher_weston_launch_destroy(struct weston_launcher *launcher_base)
 {
+	weston_log("%s\n",__func__);
 	struct launcher_weston_launch *launcher = wl_container_of(launcher_base, launcher, base);
 
 	if (launcher->fd != -1) {
