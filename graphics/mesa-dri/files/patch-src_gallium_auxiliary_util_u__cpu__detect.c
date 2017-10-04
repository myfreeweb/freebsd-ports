FreeBSD armv6 cannot detect NEON at runtime

--- src/gallium/auxiliary/util/u_cpu_detect.c.orig	2017-07-31 10:50:59 UTC
+++ src/gallium/auxiliary/util/u_cpu_detect.c
@@ -311,7 +311,9 @@ check_os_arm_support(void)
     * used. Because of this we cannot use PIPE_OS_ANDROID here, but rather
     * have a separate macro that only gets enabled from respective Android.mk.
     */
-#if defined(HAS_ANDROID_CPUFEATURES)
+#if defined(__ARM_NEON)
+   util_cpu_caps.has_neon = 1;
+#elif defined(HAS_ANDROID_CPUFEATURES)
    AndroidCpuFamily cpu_family = android_getCpuFamily();
    uint64_t cpu_features = android_getCpuFeatures();
 
FreeBSD armv6 cannot detect NEON at runtime

--- src/gallium/auxiliary/util/u_cpu_detect.c.orig	2017-07-31 10:50:59 UTC
+++ src/gallium/auxiliary/util/u_cpu_detect.c
@@ -311,7 +311,9 @@ check_os_arm_support(void)
     * used. Because of this we cannot use PIPE_OS_ANDROID here, but rather
     * have a separate macro that only gets enabled from respective Android.mk.
     */
-#if defined(HAS_ANDROID_CPUFEATURES)
+#if defined(__ARM_NEON)
+   util_cpu_caps.has_neon = 1;
+#elif defined(HAS_ANDROID_CPUFEATURES)
    AndroidCpuFamily cpu_family = android_getCpuFamily();
    uint64_t cpu_features = android_getCpuFeatures();
 
