--- src/wayland-os.h.orig	2017-08-08 18:20:52 UTC
+++ src/wayland-os.h
@@ -30,11 +30,16 @@ int
 wl_os_socket_cloexec(int domain, int type, int protocol);
 
 int
+wl_os_socketpair_cloexec(int domain, int type, int protocol, int sv[2]);
+
+int
 wl_os_dupfd_cloexec(int fd, long minfd);
 
 ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags);
 
+/* FIXME? not sure if this will work in this header like this ...
+   though seems build only header perhaps? */
 int
 wl_os_epoll_create_cloexec(void);
 
