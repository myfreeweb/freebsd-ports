Obtained from: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223019

--- external/boringssl/crypto/cpu-aarch64-linux.c.orig	2018-04-18 07:47:16 UTC
+++ external/boringssl/crypto/cpu-aarch64-linux.c
@@ -16,7 +16,40 @@

 #if defined(OPENSSL_AARCH64) && !defined(OPENSSL_STATIC_ARMCAP)

-#include <sys/auxv.h>
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <elf.h>
+#include <errno.h>
+#include <unistd.h>
+
+#ifndef AT_HWCAP
+#define AT_HWCAP                25
+#endif
+
+static unsigned long getauxval(unsigned long type) {
+  Elf_Auxinfo auxv[AT_COUNT];
+  size_t len = sizeof(auxv);
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_AUXV,
+    getpid(),
+  };
+
+  if (sysctl(mib, nitems(mib), auxv, &len, NULL, 0) != -1) {
+    for (size_t i = 0; i < nitems(auxv); i++)
+      if ((unsigned long)auxv[i].a_type == type)
+        return auxv[i].a_un.a_val;
+
+    errno = ENOENT;
+  }
+  return 0;
+}
+#else
+#define AT_HWCAP                16
+#define getauxval(x)            0
+#endif /* <sys/auxv.h> */

 #include <openssl/arm_arch.h>
