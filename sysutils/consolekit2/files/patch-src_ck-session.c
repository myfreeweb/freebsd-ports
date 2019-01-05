See https://github.com/ConsoleKit2/ConsoleKit2/pull/116

--- src/ck-session.c.orig	2017-07-24 14:47:48 UTC
+++ src/ck-session.c
@@ -54,6 +54,10 @@
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif

+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#include <termios.h>
+#endif
+
 #include <glib.h>
 #include <glib-unix.h>
 #include <glib/gi18n.h>
@@ -1482,6 +1486,16 @@ ck_session_setup_vt_signal (CkSession *session,
                 return;
         }

+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+        /* Put the tty into raw mode */
+        struct termios tios;
+        if (tcgetattr (session->priv->tty_fd, &tios))
+          g_warning ("Failed to get terminal attributes");
+        cfmakeraw (&tios);
+        if (tcsetattr (session->priv->tty_fd, TCSAFLUSH, &tios))
+          g_warning ("Failed to set terminal attributes");
+#endif
+
         session->priv->sig_watch_s1 = g_unix_signal_add_full (G_PRIORITY_HIGH,
                                                               SIGUSR1,
                                                               (GSourceFunc)vt_leave_handler,
@@ -1551,6 +1565,19 @@ ck_session_controller_cleanup (CkSession *session)
                 }
 #endif /* defined(KDSKBMODE) */

+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+                /* Restore sane mode */
+                struct termios tios;
+                if (tcgetattr (session->priv->tty_fd, &tios)) {
+                  g_warning ("Failed to get terminal attributes");
+                } else {
+                  cfmakesane (&tios);
+                  if (tcsetattr (session->priv->tty_fd, TCSAFLUSH, &tios)) {
+                    g_warning ("Failed to set terminal attributes");
+                  }
+                }
+#endif
+
                 if (ioctl (session->priv->tty_fd, VT_SETMODE, &mode) < 0) {
                         g_warning ("failed to return control of vt handling");
                 }
@@ -1701,6 +1728,15 @@ ck_session_get_device (CkSession *session,
         for (iter = session->priv->devices; iter != NULL; iter = g_list_next (iter)) {
                 if (ck_device_compare (iter->data, major, minor)) {
                         g_debug ("found device");
+                        CkDevice *device = CK_DEVICE (iter->data);
+                        if (ck_device_get_category(device) == DEVICE_EVDEV) {
+                                struct stat st;
+                                if (fstat(ck_device_get_fd(device), &st) == -1 && errno == EBADF) {
+                                        g_debug ("but it was a dead input device, removing");
+                                        session->priv->devices = g_list_remove (session->priv->devices, device);
+                                        return NULL;
+                                }
+                        }
                         return iter->data;
                 }
         }
