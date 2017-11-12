--- libweston/weston-launch.c.orig	2016-09-17 07:06:45 UTC
+++ libweston/weston-launch.c
@@ -33,7 +33,6 @@
 #include <poll.h>
 #include <errno.h>
 
-#include <error.h>
 #include <getopt.h>
 
 #include <sys/types.h>
@@ -46,9 +45,34 @@
 #include <unistd.h>
 #include <fcntl.h>
 
-#include <linux/vt.h>
-#include <linux/major.h>
-#include <linux/kd.h>
+#include <termios.h>
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#define TTY_BASENAME    "/dev/ttyv"
+#define TTY_0           "/dev/ttyv0"
+#define error(s,e,...)									\
+	do {												\
+		if(e)											\
+			fprintf(stderr, "errno: %s\n",strerror(e));	\
+        fprintf(stderr, __VA_ARGS__);					\
+        fprintf(stderr, "\n");							\
+		if (s != 0) {									\
+			exit(-1);									\
+		}												\
+	} while(false)
+static inline int clearenv(void) {
+	extern char **environ;
+	environ[0] = NULL;
+	return 0;
+}
+
+/* #include <error.h> */
+/* #include <linux/kd.h> */
+/* #include <linux/major.h> */
+/* #include <linux/vt.h> */
+/* #define TTY_BASENAME "/dev/tty" */
+/* #define TTY_0        "/dev/tty0" */
+
 
 #include <pwd.h>
 #include <grp.h>
@@ -60,11 +84,12 @@
 
 #include "weston-launch.h"
 
-#define DRM_MAJOR 226
 
-#ifndef KDSKBMUTE
-#define KDSKBMUTE	0x4B51
-#endif
+/* #define DRM_MAJOR 226 */
+
+/* #ifndef KDSKBMUTE */
+/* #define KDSKBMUTE	0x4B51 */
+/* #endif */
 
 #ifndef EVIOCREVOKE
 #define EVIOCREVOKE _IOW('E', 0x91, int)
@@ -142,7 +167,7 @@ weston_launch_allowed(struct weston_laun
 {
 	struct group *gr;
 	gid_t *groups;
-	int i;
+	int i,n;
 #ifdef HAVE_SYSTEMD_LOGIN
 	char *session, *seat;
 	int err;
@@ -155,7 +180,8 @@ weston_launch_allowed(struct weston_laun
 	if (gr) {
 		groups = read_groups();
 		if (groups) {
-			for (i = 0; groups[i]; ++i) {
+			n = getgroups(0, NULL);
+			for (i = 0; i<n; ++i) {
 				if (groups[i] == gr->gr_gid) {
 					free(groups);
 					return true;
@@ -322,14 +348,14 @@ handle_open(struct weston_launch *wl, st
 		goto err0;
 	}
 
-	if (major(s.st_rdev) != INPUT_MAJOR &&
-	    major(s.st_rdev) != DRM_MAJOR) {
-		close(fd);
-		fd = -1;
-		fprintf(stderr, "Device %s is not an input or drm device\n",
-			message->path);
-		goto err0;
-	}
+	/* if (major(s.st_rdev) != INPUT_MAJOR && */
+	/*     major(s.st_rdev) != DRM_MAJOR) { */
+	/* 	close(fd); */
+	/* 	fd = -1; */
+	/* 	fprintf(stderr, "Device %s is not an input or drm device\n", */
+	/* 		message->path); */
+	/* 	goto err0; */
+	/* } */
 
 err0:
 	memset(&nmsg, 0, sizeof nmsg);
@@ -350,8 +376,8 @@ err0:
 	iov.iov_base = &ret;
 	iov.iov_len = sizeof ret;
 
-	if (wl->verbose)
-		fprintf(stderr, "weston-launch: opened %s: ret: %d, fd: %d\n",
+	/* if (wl->verbose) */
+		printf("weston-launch: opened %s: ret: %d, fd: %d\n",
 			message->path, ret, fd);
 	do {
 		len = sendmsg(wl->sock[0], &nmsg, 0);
@@ -360,10 +386,9 @@ err0:
 	if (len < 0)
 		return -1;
 
-	if (fd != -1 && major(s.st_rdev) == DRM_MAJOR)
+	if (fd != -1)
 		wl->drm_fd = fd;
-	if (fd != -1 && major(s.st_rdev) == INPUT_MAJOR &&
-	    wl->last_input_fd < fd)
+	if (fd != -1 && wl->last_input_fd < fd)
 		wl->last_input_fd = fd;
 
 	return 0;
@@ -422,9 +447,18 @@ quit(struct weston_launch *wl, int statu
 		pam_end(wl->ph, err);
 	}
 
-	if (ioctl(wl->tty, KDSKBMUTE, 0) &&
-	    ioctl(wl->tty, KDSKBMODE, wl->kb_mode))
-		fprintf(stderr, "failed to restore keyboard mode: %m\n");
+	/* if (ioctl(wl->tty, KDSKBMODE, wl->kb_mode)) */
+	if (ioctl(wl->tty, KDSKBMODE, K_XLATE))
+		fprintf(stderr, "Could not restore keyboard\n");
+
+	struct termios tios;
+	if (tcgetattr(wl->tty, &tios)) {
+		fprintf(stderr, "Failed to get terminal attribute\n");
+	} else {
+		cfmakesane(&tios);
+		if (tcsetattr(wl->tty , TCSAFLUSH, &tios))
+			fprintf(stderr, "Failed to set terminal attribute\n");
+	}
 
 	if (ioctl(wl->tty, KDSETMODE, KD_TEXT))
 		fprintf(stderr, "failed to set KD_TEXT mode on tty: %m\n");
@@ -435,6 +469,7 @@ quit(struct weston_launch *wl, int statu
 	drmDropMaster(wl->drm_fd);
 
 	mode.mode = VT_AUTO;
+	mode.frsig = SIGIO; /* not used, but has to be set anyway */
 	if (ioctl(wl->tty, VT_SETMODE, &mode) < 0)
 		fprintf(stderr, "could not reset vt handling\n");
 
@@ -444,15 +479,25 @@ quit(struct weston_launch *wl, int statu
 static void
 close_input_fds(struct weston_launch *wl)
 {
+	// Input device are being closed by: launcher_weston_launch_close()
+	// on exit or deactivate.
+	// This function will close the wayland socket fd as well
+	// and crash the program...
+
+	// Do we need this function?
+
 	struct stat s;
 	int fd;
 
 	for (fd = 3; fd <= wl->last_input_fd; fd++) {
-		if (fstat(fd, &s) == 0 && major(s.st_rdev) == INPUT_MAJOR) {
+		if (fstat(fd, &s) == 0) {
 			/* EVIOCREVOKE may fail if the kernel doesn't
 			 * support it, but all we can do is ignore it. */
+			printf("%s: Closing fd %d\n",__func__,fd);
 			ioctl(fd, EVIOCREVOKE, 0);
 			close(fd);
+		} else {
+			fprintf(stderr,"%s: stat failed on fd %d\n",__func__,fd);
 		}
 	}
 }
@@ -460,16 +505,22 @@ close_input_fds(struct weston_launch *wl
 static int
 handle_signal(struct weston_launch *wl)
 {
+	printf("%s\n",__func__);
+
 	struct signalfd_siginfo sig;
 	int pid, status, ret;
 
-	if (read(wl->signalfd, &sig, sizeof sig) != sizeof sig) {
-		error(0, errno, "reading signalfd failed");
+	ret = read(wl->signalfd, &sig, sizeof sig);
+	if (ret != sizeof sig) {
+		error(0, errno, "reading signalfd %d failed", wl->signalfd);
+		// Temporary add delay here so we don't get spammed with error messages
+		usleep(500000);
 		return -1;
 	}
 
 	switch (sig.ssi_signo) {
 	case SIGCHLD:
+		printf("%s: SIGCHLD\n",__func__);
 		pid = waitpid(-1, &status, 0);
 		if (pid == wl->child) {
 			wl->child = 0;
@@ -489,22 +540,32 @@ handle_signal(struct weston_launch *wl)
 		}
 		break;
 	case SIGTERM:
+		printf("%s: SIGTERM - killing\n",__func__);
 	case SIGINT:
+		printf("%s: SIGINT - killing\n",__func__);
 		if (wl->child)
 			kill(wl->child, sig.ssi_signo);
 		break;
 	case SIGUSR1:
+		printf("%s: SIGUSR1 - deactivating\n",__func__);
 		send_reply(wl, WESTON_LAUNCHER_DEACTIVATE);
-		close_input_fds(wl);
+
+		// This is done in launcher-weston-launcher.c,
+		// compositor-drm.c (session-notify)
+		// Double close = crash on vt switch (socket also get closed)
+		/* close_input_fds(wl); */
+
 		drmDropMaster(wl->drm_fd);
 		ioctl(wl->tty, VT_RELDISP, 1);
 		break;
 	case SIGUSR2:
+		printf("%s: SIGUSR2 - activating\n",__func__);
 		ioctl(wl->tty, VT_RELDISP, VT_ACKACQ);
 		drmSetMaster(wl->drm_fd);
 		send_reply(wl, WESTON_LAUNCHER_ACTIVATE);
 		break;
 	default:
+		printf("%s: Unknown signal\n",__func__);
 		return -1;
 	}
 
@@ -527,7 +588,7 @@ setup_tty(struct weston_launch *wl, cons
 		else
 			wl->tty = open(tty, O_RDWR | O_NOCTTY);
 	} else {
-		int tty0 = open("/dev/tty0", O_WRONLY | O_CLOEXEC);
+		int tty0 = open(TTY_0, O_WRONLY | O_CLOEXEC);
 		char filename[16];
 
 		if (tty0 < 0)
@@ -536,7 +597,7 @@ setup_tty(struct weston_launch *wl, cons
 		if (ioctl(tty0, VT_OPENQRY, &wl->ttynr) < 0 || wl->ttynr == -1)
 			error(1, errno, "failed to find non-opened console");
 
-		snprintf(filename, sizeof filename, "/dev/tty%d", wl->ttynr);
+		snprintf(filename, sizeof filename, "%s%d", TTY_BASENAME, wl->ttynr);
 		wl->tty = open(filename, O_RDWR | O_NOCTTY);
 		close(tty0);
 	}
@@ -544,26 +605,26 @@ setup_tty(struct weston_launch *wl, cons
 	if (wl->tty < 0)
 		error(1, errno, "failed to open tty");
 
-	if (fstat(wl->tty, &buf) == -1 ||
-	    major(buf.st_rdev) != TTY_MAJOR || minor(buf.st_rdev) == 0)
-		error(1, 0, "weston-launch must be run from a virtual terminal");
-
 	if (tty) {
 		if (fstat(wl->tty, &buf) < 0)
 			error(1, errno, "stat %s failed", tty);
 
-		if (major(buf.st_rdev) != TTY_MAJOR)
-			error(1, 0, "invalid tty device: %s", tty);
-
-		wl->ttynr = minor(buf.st_rdev);
+		if(ioctl(wl->tty, VT_GETINDEX, &wl->ttynr))
+			error(1, errno, "failed to get vt index for tty %s", tty);
 	}
 
 	if (ioctl(wl->tty, KDGKBMODE, &wl->kb_mode))
 		error(1, errno, "failed to get current keyboard mode: %m\n");
 
-	if (ioctl(wl->tty, KDSKBMUTE, 1) &&
-	    ioctl(wl->tty, KDSKBMODE, K_OFF))
-		error(1, errno, "failed to set K_OFF keyboard mode: %m\n");
+	if (ioctl(wl->tty, KDSKBMODE, K_RAW) == -1)
+		error(1, errno, "Could not set keyboard mode to K_RAW\n");
+
+	struct termios tios;
+	if (tcgetattr(wl->tty, &tios))
+		error(1, errno, "Failed to get terminal attribute %m\n");
+	cfmakeraw(&tios);
+	if (tcsetattr(wl->tty , TCSAFLUSH, &tios))
+		error(1, errno, "Failed to set terminal attribute %m\n");
 
 	if (ioctl(wl->tty, KDSETMODE, KD_GRAPHICS))
 		error(1, errno, "failed to set KD_GRAPHICS mode on tty: %m\n");
@@ -571,6 +632,7 @@ setup_tty(struct weston_launch *wl, cons
 	mode.mode = VT_PROCESS;
 	mode.relsig = SIGUSR1;
 	mode.acqsig = SIGUSR2;
+	mode.frsig = SIGIO; /* not used, but has to be set anyway */
 	if (ioctl(wl->tty, VT_SETMODE, &mode) < 0)
 		error(1, errno, "failed to take control of vt handling\n");
 
@@ -735,7 +797,7 @@ main(int argc, char *argv[])
 #else
 		      " - enable systemd session support for weston-launch.\n"
 #endif
-		      " - or add yourself to the 'weston-launch' group.");
+		      " - or add yourself to the 'weston-launch' group.\n");
 
 	if (setup_tty(&wl, tty) < 0)
 		exit(EXIT_FAILURE);
