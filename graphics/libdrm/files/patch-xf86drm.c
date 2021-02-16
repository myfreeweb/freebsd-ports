--- xf86drm.c.orig	2021-02-16 13:06:58 UTC
+++ xf86drm.c
@@ -99,7 +99,7 @@
 #define DRM_MAJOR 226 /* Linux */
 #endif
 
-#if defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
 struct drm_pciinfo {
 	uint16_t	domain;
 	uint8_t		bus;
@@ -3247,7 +3247,7 @@ static int drmParsePciBusInfo(int maj, int min, drmPci
     info->func = func;
 
     return 0;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
     struct drm_pciinfo pinfo;
     int fd, type;
 
@@ -3255,13 +3255,27 @@ static int drmParsePciBusInfo(int maj, int min, drmPci
     if (type == -1)
         return -ENODEV;
 
+#if defined(__FreeBSD__)
+    char name[SPECNAMELEN], path[PATH_MAX];
+    int id;
+
+    if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
+        return -1;
+    snprintf(path, PATH_MAX, "/dev/%s", name);
+    fd = open(path, O_RDWR | O_CLOEXEC);
+#else
     fd = drmOpenMinor(min, 0, type);
+#endif
     if (fd < 0)
         return -errno;
 
     if (drmIoctl(fd, DRM_IOCTL_GET_PCIINFO, &pinfo)) {
         close(fd);
+#if defined(__FreeBSD__)
+        return get_sysctl_pci_bus_info(maj, min, info);
+#else
         return -errno;
+#endif
     }
     close(fd);
 
@@ -3271,8 +3285,6 @@ static int drmParsePciBusInfo(int maj, int min, drmPci
     info->func = pinfo.func;
 
     return 0;
-#elif defined(__FreeBSD__)
-    return get_sysctl_pci_bus_info(maj, min, info);
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
     return -EINVAL;
@@ -3415,7 +3427,7 @@ static int drmParsePciDeviceInfo(int maj, int min,
         return parse_config_sysfs_file(maj, min, device);
 
     return 0;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
     struct drm_pciinfo pinfo;
     int fd, type;
 
@@ -3423,63 +3435,75 @@ static int drmParsePciDeviceInfo(int maj, int min,
     if (type == -1)
         return -ENODEV;
 
+#if defined(__FreeBSD__)
+    char name[SPECNAMELEN], path[PATH_MAX];
+    int id;
+
+    if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
+        return -1;
+    snprintf(path, PATH_MAX, "/dev/%s", name);
+    fd = open(path, O_RDWR | O_CLOEXEC);
+#else
     fd = drmOpenMinor(min, 0, type);
+#endif
     if (fd < 0)
         return -errno;
 
     if (drmIoctl(fd, DRM_IOCTL_GET_PCIINFO, &pinfo)) {
         close(fd);
-        return -errno;
-    }
-    close(fd);
+#if defined(__FreeBSD__)
+        drmPciBusInfo info;
+        struct pci_conf_io pc;
+        struct pci_match_conf patterns[1];
+        struct pci_conf results[1];
+        int error;
 
-    device->vendor_id = pinfo.vendor_id;
-    device->device_id = pinfo.device_id;
-    device->revision_id = pinfo.revision_id;
-    device->subvendor_id = pinfo.subvendor_id;
-    device->subdevice_id = pinfo.subdevice_id;
+        if (get_sysctl_pci_bus_info(maj, min, &info) != 0)
+            return -EINVAL;
 
-    return 0;
-#elif defined(__FreeBSD__)
-    drmPciBusInfo info;
-    struct pci_conf_io pc;
-    struct pci_match_conf patterns[1];
-    struct pci_conf results[1];
-    int fd, error;
+        fd = open("/dev/pci", O_RDONLY, 0);
+        if (fd < 0)
+            return -errno;
 
-    if (get_sysctl_pci_bus_info(maj, min, &info) != 0)
-        return -EINVAL;
+        bzero(&patterns, sizeof(patterns));
+        patterns[0].pc_sel.pc_domain = info.domain;
+        patterns[0].pc_sel.pc_bus = info.bus;
+        patterns[0].pc_sel.pc_dev = info.dev;
+        patterns[0].pc_sel.pc_func = info.func;
+        patterns[0].flags = PCI_GETCONF_MATCH_DOMAIN | PCI_GETCONF_MATCH_BUS
+                          | PCI_GETCONF_MATCH_DEV | PCI_GETCONF_MATCH_FUNC;
+        bzero(&pc, sizeof(struct pci_conf_io));
+        pc.num_patterns = 1;
+        pc.pat_buf_len = sizeof(patterns);
+        pc.patterns = patterns;
+        pc.match_buf_len = sizeof(results);
+        pc.matches = results;
 
-    fd = open("/dev/pci", O_RDONLY, 0);
-    if (fd < 0)
-        return -errno;
+        if (ioctl(fd, PCIOCGETCONF, &pc) || pc.status == PCI_GETCONF_ERROR) {
+            error = errno;
+            close(fd);
+            return -error;
+        }
+        close(fd);
 
-    bzero(&patterns, sizeof(patterns));
-    patterns[0].pc_sel.pc_domain = info.domain;
-    patterns[0].pc_sel.pc_bus = info.bus;
-    patterns[0].pc_sel.pc_dev = info.dev;
-    patterns[0].pc_sel.pc_func = info.func;
-    patterns[0].flags = PCI_GETCONF_MATCH_DOMAIN | PCI_GETCONF_MATCH_BUS
-                      | PCI_GETCONF_MATCH_DEV | PCI_GETCONF_MATCH_FUNC;
-    bzero(&pc, sizeof(struct pci_conf_io));
-    pc.num_patterns = 1;
-    pc.pat_buf_len = sizeof(patterns);
-    pc.patterns = patterns;
-    pc.match_buf_len = sizeof(results);
-    pc.matches = results;
+        device->vendor_id = results[0].pc_vendor;
+        device->device_id = results[0].pc_device;
+        device->subvendor_id = results[0].pc_subvendor;
+        device->subdevice_id = results[0].pc_subdevice;
+        device->revision_id = results[0].pc_revid;
 
-    if (ioctl(fd, PCIOCGETCONF, &pc) || pc.status == PCI_GETCONF_ERROR) {
-        error = errno;
-        close(fd);
-        return -error;
+        return 0;
+#else
+        return -errno;
+#endif
     }
     close(fd);
 
-    device->vendor_id = results[0].pc_vendor;
-    device->device_id = results[0].pc_device;
-    device->subvendor_id = results[0].pc_subvendor;
-    device->subdevice_id = results[0].pc_subdevice;
-    device->revision_id = results[0].pc_revid;
+    device->vendor_id = pinfo.vendor_id;
+    device->device_id = pinfo.device_id;
+    device->revision_id = pinfo.revision_id;
+    device->subvendor_id = pinfo.subvendor_id;
+    device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
 #else
