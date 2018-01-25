- Implement futex_wake() and futex_wait() via _umtx_op()

--- src/util/futex.h.orig	2018-01-23 18:08:50 UTC
+++ src/util/futex.h
@@ -29,10 +29,38 @@
 #include <limits.h>
 #include <stdint.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+# if __FreeBSD__ < 11
+#  include <machine/atomic.h>
+# endif
+#include <errno.h>
+#include <sys/umtx.h>
+#else
 #include <linux/futex.h>
 #include <sys/syscall.h>
+#endif
 #include <sys/time.h>
 
+#if defined(__FreeBSD__) /* Based on libxshmfence */
+static inline int sys_futex(void *addr, int op, int32_t val)
+{
+   return _umtx_op(addr, op, (uint32_t)val, NULL, NULL) == -1 ? errno : 0;
+}
+
+static inline int futex_wake(uint32_t *addr, int count)
+{
+   return sys_futex(addr, UMTX_OP_WAKE, count);
+}
+
+static inline int futex_wait(uint32_t *addr, int32_t value, struct timespec *timeout)
+{
+   if (!timeout)
+      return sys_futex(addr, UMTX_OP_WAIT_UINT, value);
+
+   struct _umtx_time tm = { ._clockid = CLOCK_REALTIME, ._flags = UMTX_ABSTIME, ._timeout = *timeout };
+   return _umtx_op(addr, UMTX_OP_WAIT_UINT, (uint32_t)value, (void *)sizeof(tm), &tm) == -1 ? errno : 0;
+}
+#else
 static inline long sys_futex(void *addr1, int op, int val1, const struct timespec *timeout, void *addr2, int val3)
 {
    return syscall(SYS_futex, addr1, op, val1, timeout, addr2, val3);
@@ -50,6 +71,7 @@ static inline int futex_wait(uint32_t *addr, int32_t v
    return sys_futex(addr, FUTEX_WAIT_BITSET, value, timeout, NULL,
                     FUTEX_BITSET_MATCH_ANY);
 }
+#endif
 
 #endif
 
