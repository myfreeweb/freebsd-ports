--- utils.c.orig	2018-10-28 14:58:13 UTC
+++ utils.c
@@ -29,6 +29,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <sys/un.h>
 #include <dirent.h>
 #include <errno.h>
@@ -42,8 +43,6 @@
 #include <sys/socket.h>
 #include <kvm.h>
 #include <libprocstat.h>
-#else
-#include <sys/stat.h>
 #endif
 
 #ifdef HAVE_DEVINFO_H
@@ -150,19 +149,14 @@ path_to_fd(const char *path)
 
 #ifdef HAVE_LIBPROCSTAT_H
 	struct procstat *procstat;
-	struct kinfo_proc *kip;
+	struct kinfo_proc *kip = NULL;
 	struct filestat_list *head = NULL;
 	struct filestat *fst;
 	unsigned int count;
-#else
-	struct stat st, fst;
-#define	MAX_FD	128
-#endif
 
-#ifdef HAVE_LIBPROCSTAT_H
 	procstat = procstat_open_sysctl();
 	if (procstat == NULL)
-		return (-1);
+		goto out;
 
 	count = 0;
 	kip = procstat_getprocs(procstat, KERN_PROC_PID, getpid(), &count);
@@ -189,13 +183,19 @@ out:
 	if (kip != NULL)
 		procstat_freeprocs(procstat, kip);
 	procstat_close(procstat);
-#else
+	if (fd != -1)
+		return (fd);
+#endif
+
+	struct stat st, stf;
+#define	MAX_FD	128
+
 	if (stat(path, &st) != 0)
 		return (-1);
 
 	for (fd = 0; fd < MAX_FD; ++fd) {
 
-		if (fstat(fd, &fst) != 0) {
+		if (fstat(fd, &stf) != 0) {
 			if (errno != EBADF) {
 				return -1;
 			} else {
@@ -203,13 +203,12 @@ out:
 			}
 		}
 
-		if (fst.st_rdev == st.st_rdev)
+		if (stf.st_rdev == st.st_rdev)
 			break;
 	}
 
 	if (fd == MAX_FD)
 		return (-1);
-#endif
 
 	return (fd);
 }
