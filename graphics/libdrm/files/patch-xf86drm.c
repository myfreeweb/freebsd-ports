--- xf86drm.c.orig	2019-11-02 14:33:44.252388000 +0300
+++ xf86drm.c	2019-11-02 14:34:41.350209000 +0300
@@ -46,6 +46,9 @@
 #include <signal.h>
 #include <time.h>
 #include <sys/types.h>
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
 #include <sys/stat.h>
 #define stat_t struct stat
 #include <sys/ioctl.h>
@@ -61,6 +64,10 @@
 
 #define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#include <sys/pciio.h>
+#endif
+
 /* Not all systems have MAP_FAILED defined */
 #ifndef MAP_FAILED
 #define MAP_FAILED ((void *)-1)
@@ -72,7 +79,7 @@
 #include "util_math.h"
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#define DRM_MAJOR 145
+#define DRM_MAJOR 0	/* Major ID unused on systems with devfs */
 #endif
 
 #ifdef __NetBSD__
@@ -212,6 +219,58 @@
     return entry;
 }
 
+static int drmGetMinorBase(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type << 6;
+        default:
+            return -1;
+    };
+}
+
+static int drmGetMinorType(int minor)
+{
+    if (minor < 0)
+        return -1;
+
+    int type = minor >> 6;
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+        case DRM_NODE_CONTROL:
+        case DRM_NODE_RENDER:
+            return type;
+        default:
+            return -1;
+    }
+}
+
+#ifdef __linux__
+static const char *drmGetMinorName(int type)
+{
+    switch (type) {
+        case DRM_NODE_PRIMARY:
+            return DRM_PRIMARY_MINOR_NAME;
+        case DRM_NODE_CONTROL:
+            return DRM_CONTROL_MINOR_NAME;
+        case DRM_NODE_RENDER:
+            return DRM_RENDER_MINOR_NAME;
+        default:
+            return NULL;
+    }
+}
+#endif
+
+static int drmGetNodeNumber(const char *name)
+{
+    size_t name_len = strnlen(name, DRM_NODE_NAME_MAX);
+    while (name_len && isdigit(name[name_len - 1]))
+        --name_len;
+    return strtol(name + name_len, NULL, 10);
+}
+
 /**
  * Compare two busid strings
  *
@@ -343,7 +402,11 @@
     if (!dev_name)
         return -EINVAL;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     drmMsg("drmOpenDevice: node name is %s\n", buf);
 
     if (drm_server_info && drm_server_info->get_perms) {
@@ -456,7 +519,11 @@
     if (!dev_name)
         return -EINVAL;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    sprintf(buf, dev_name, DRM_DIR_NAME, minor + drmGetMinorBase(type));
+#else
     sprintf(buf, dev_name, DRM_DIR_NAME, minor);
+#endif
     if ((fd = open(buf, O_RDWR | O_CLOEXEC, 0)) >= 0)
         return fd;
     return -errno;
@@ -497,51 +564,6 @@
     return retval;
 }
 
-static int drmGetMinorBase(int type)
-{
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        return 0;
-    case DRM_NODE_CONTROL:
-        return 64;
-    case DRM_NODE_RENDER:
-        return 128;
-    default:
-        return -1;
-    };
-}
-
-static int drmGetMinorType(int minor)
-{
-    int type = minor >> 6;
-
-    if (minor < 0)
-        return -1;
-
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-    case DRM_NODE_CONTROL:
-    case DRM_NODE_RENDER:
-        return type;
-    default:
-        return -1;
-    }
-}
-
-static const char *drmGetMinorName(int type)
-{
-    switch (type) {
-    case DRM_NODE_PRIMARY:
-        return DRM_PRIMARY_MINOR_NAME;
-    case DRM_NODE_CONTROL:
-        return DRM_CONTROL_MINOR_NAME;
-    case DRM_NODE_RENDER:
-        return DRM_RENDER_MINOR_NAME;
-    default:
-        return NULL;
-    }
-}
-
 /**
  * Open the device by bus ID.
  *
@@ -2744,28 +2766,22 @@
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-    char name[128];
-    struct stat sbuf;
-    dev_t d;
-    int i;
-
     /* The whole drmOpen thing is a fiasco and we need to find a way
      * back to just using open(2).  For now, however, lets just make
      * things worse with even more ad hoc directory walking code to
      * discover the device file name. */
 
+    stat_t sbuf;
     fstat(fd, &sbuf);
-    d = sbuf.st_rdev;
+    dev_t d = sbuf.st_rdev;
 
-    for (i = 0; i < DRM_MAX_MINOR; i++) {
+    for (int i = 0; i < DRM_MAX_MINOR; i++) {
+        char name[DRM_NODE_NAME_MAX];
         snprintf(name, sizeof name, DRM_DEV_NAME, DRM_DIR_NAME, i);
         if (stat(name, &sbuf) == 0 && sbuf.st_rdev == d)
-            break;
+            return strdup(name);
     }
-    if (i == DRM_MAX_MINOR)
-        return NULL;
-
-    return strdup(name);
+    return NULL;
 }
 
 static bool drmNodeIsDRM(int maj, int min)
@@ -2778,13 +2794,43 @@
              maj, min);
     return stat(path, &sbuf) == 0;
 #else
-    return maj == DRM_MAJOR;
+    return !DRM_MAJOR || maj == DRM_MAJOR;
 #endif
 }
 
+static int drmGetNodeType(const char *name)
+{
+    if (strncmp(name, DRM_CONTROL_MINOR_NAME,
+        sizeof(DRM_CONTROL_MINOR_NAME ) - 1) == 0)
+        return DRM_NODE_CONTROL;
+
+    if (strncmp(name, DRM_RENDER_MINOR_NAME,
+        sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
+        return DRM_NODE_RENDER;
+
+    if (strncmp(name, DRM_PRIMARY_MINOR_NAME,
+        sizeof(DRM_PRIMARY_MINOR_NAME) - 1) == 0)
+        return DRM_NODE_PRIMARY;
+
+    return -EINVAL;
+}
+
 drm_public int drmGetNodeTypeFromFd(int fd)
 {
-    struct stat sbuf;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!name) {
+        errno = ENODEV;
+        return -1;
+    }
+
+    int type = drmGetNodeType(strrchr(name, '/') + 1);
+    free(name);
+    if (type < 0)
+        errno = ENODEV;
+    return type;
+#else
+    stat_t sbuf;
     int maj, min, type;
 
     if (fstat(fd, &sbuf))
@@ -2802,6 +2848,7 @@
     if (type == -1)
         errno = ENODEV;
     return type;
+#endif
 }
 
 drm_public int drmPrimeHandleToFD(int fd, uint32_t handle, uint32_t flags,
@@ -2842,7 +2889,7 @@
 #ifdef __linux__
     DIR *sysdir;
     struct dirent *ent;
-    struct stat sbuf;
+    stat_t sbuf;
     const char *name = drmGetMinorName(type);
     int len;
     char dev_name[64], buf[64];
@@ -2880,6 +2927,25 @@
 
     closedir(sysdir);
     return NULL;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    const char *dev_name = drmGetDeviceName(type);
+    if (!dev_name)
+        return NULL;
+
+    char *name = drmGetDeviceNameFromFd2(fd);
+    if (!name)
+        return NULL;
+
+    int oldnum = drmGetNodeNumber(name);
+    int oldtype = drmGetMinorType(oldnum);
+    if (oldtype < 0) {
+        free(name);
+        return NULL;
+    }
+
+    int newnum = oldnum - drmGetMinorBase(oldtype) + drmGetMinorBase(type);
+    snprintf(name, DRM_NODE_NAME_MAX, dev_name, DRM_DIR_NAME, newnum);
+    return name;
 #else
     struct stat sbuf;
     char buf[PATH_MAX + 1];
@@ -2998,7 +3064,7 @@
     }
 
     return -EINVAL;
-#elif defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
     return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
@@ -3022,7 +3088,8 @@
         *term = 0;
 }
 
-static int drmParsePciBusInfo(int maj, int min, drmPciBusInfoPtr info)
+static int drmParsePciBusInfo(const char *node, int node_type,
+                              int maj, int min, drmPciBusInfoPtr info)
 {
 #ifdef __linux__
     unsigned int domain, bus, dev, func;
@@ -3071,6 +3138,60 @@
     info->func = pinfo.func;
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    /*
+     * Only the primary nodes can be mapped to hw.dri.%i via major/minor
+     * Determine the primary node by offset and use its major/minor pair
+     */
+    if (node_type != DRM_NODE_PRIMARY) {
+        char name[DRM_NODE_NAME_MAX];
+        snprintf(name, sizeof(name), DRM_DEV_NAME, DRM_DIR_NAME,
+                 drmGetNodeNumber(node) - drmGetMinorBase(node_type));
+
+        stat_t sbuf;
+        if (stat(name, &sbuf))
+            return -errno;
+
+        maj = major(sbuf.st_rdev);
+        min = minor(sbuf.st_rdev);
+    }
+    /*
+     * Major/minor appear after the driver name in the hw.dri.%i.name node
+     * Find the node with matching major/minor pair and parse the bus ID,
+     * which may be after the name or may be alone in hw.dri.%i.busid
+     */
+    #define bus_fmt "pci:%04x:%02x:%02x.%u"
+    #define name_fmt "%*s %x " bus_fmt
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char name[16], value[256];
+        size_t length = sizeof(value);
+        snprintf(name, sizeof(name), "hw.dri.%i.name", i);
+        if (sysctlbyname(name, value, &length, NULL, 0))
+            continue;
+
+        value[length] = '\0';
+        unsigned int rdev = 0, domain = 0, bus = 0, slot = 0, func = 0;
+        int vals = sscanf(value, name_fmt, &rdev, &domain, &bus, &slot, &func);
+
+        if (vals >= 1 && rdev == makedev(maj,min)) {
+            if (vals < 5) {
+                /* busid not in the name, try busid */
+                length = sizeof(value);
+                snprintf(name, sizeof(name), "hw.dri.%i.busid", i);
+                if (sysctlbyname(name, value, &length, NULL, 0))
+                    break;
+                value[length] = '\0';
+                if (sscanf(value, bus_fmt, &domain, &bus, &slot, &func) != 4)
+                    break;
+            }
+            info->domain = domain;
+            info->bus = bus;
+            info->dev = slot;
+            info->func = func;
+            return 0;
+        }
+    }
+    return -ENODEV;
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
     return -EINVAL;
@@ -3105,32 +3226,7 @@
     return 0;
 }
 
-static int drmGetNodeType(const char *name)
-{
-    if (strncmp(name, DRM_CONTROL_MINOR_NAME,
-        sizeof(DRM_CONTROL_MINOR_NAME ) - 1) == 0)
-        return DRM_NODE_CONTROL;

-    if (strncmp(name, DRM_RENDER_MINOR_NAME,
-        sizeof(DRM_RENDER_MINOR_NAME) - 1) == 0)
-        return DRM_NODE_RENDER;
-
-    if (strncmp(name, DRM_PRIMARY_MINOR_NAME,
-        sizeof(DRM_PRIMARY_MINOR_NAME) - 1) == 0)
-        return DRM_NODE_PRIMARY;
-
-    return -EINVAL;
-}
-
-static int drmGetMaxNodeName(void)
-{
-    return sizeof(DRM_DIR_NAME) +
-           MAX3(sizeof(DRM_PRIMARY_MINOR_NAME),
-                sizeof(DRM_CONTROL_MINOR_NAME),
-                sizeof(DRM_RENDER_MINOR_NAME)) +
-           3 /* length of the node number */;
-}
-
 #ifdef __linux__
 static int parse_separate_sysfs_files(int maj, int min,
                                       drmPciDeviceInfoPtr device,
@@ -3202,6 +3298,7 @@
 #endif
 
 static int drmParsePciDeviceInfo(int maj, int min,
+                                 drmPciBusInfoPtr info,
                                  drmPciDeviceInfoPtr device,
                                  uint32_t flags)
 {
@@ -3238,6 +3335,43 @@
     device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    struct pci_conf_io pc;
+    struct pci_match_conf patterns[1];
+    struct pci_conf results[1];
+
+    int fd = open("/dev/pci", O_RDONLY, 0);
+    if (fd < 0)
+        return -errno;
+
+    bzero(&patterns, sizeof(patterns));
+    patterns[0].pc_sel.pc_domain = info->domain;
+    patterns[0].pc_sel.pc_bus = info->bus;
+    patterns[0].pc_sel.pc_dev = info->dev;
+    patterns[0].pc_sel.pc_func = info->func;
+    patterns[0].flags = PCI_GETCONF_MATCH_DOMAIN | PCI_GETCONF_MATCH_BUS
+                      | PCI_GETCONF_MATCH_DEV | PCI_GETCONF_MATCH_FUNC;
+    bzero(&pc, sizeof(struct pci_conf_io));
+    pc.num_patterns = 1;
+    pc.pat_buf_len = sizeof(patterns);
+    pc.patterns = patterns;
+    pc.match_buf_len = sizeof(results);
+    pc.matches = results;
+
+    if (ioctl(fd, PCIOCGETCONF, &pc) || pc.status == PCI_GETCONF_ERROR) {
+        int error = errno;
+        close(fd);
+        return -error;
+    }
+    close(fd);
+
+    device->vendor_id = results[0].pc_vendor;
+    device->device_id = results[0].pc_device;
+    device->subvendor_id = results[0].pc_subvendor;
+    device->subdevice_id = results[0].pc_subdevice;
+    device->revision_id = results[0].pc_revid;
+
+    return 0;
 #else
 #warning "Missing implementation of drmParsePciDeviceInfo"
     return -EINVAL;
@@ -3318,7 +3452,7 @@
     unsigned int i;
     char *ptr;
 
-    max_node_length = ALIGN(drmGetMaxNodeName(), sizeof(void *));
+    max_node_length = ALIGN(DRM_NODE_NAME_MAX, sizeof(void *));
     extra = DRM_NODE_MAX * (sizeof(void *) + max_node_length);
 
     size = sizeof(*device) + extra + bus_size + device_size;
@@ -3364,7 +3498,7 @@
 
     dev->businfo.pci = (drmPciBusInfoPtr)addr;
 
-    ret = drmParsePciBusInfo(maj, min, dev->businfo.pci);
+    ret = drmParsePciBusInfo(node, node_type, maj, min, dev->businfo.pci);
     if (ret)
         goto free_device;
 
@@ -3373,7 +3507,7 @@
         addr += sizeof(drmPciBusInfo);
         dev->deviceinfo.pci = (drmPciDeviceInfoPtr)addr;
 
-        ret = drmParsePciDeviceInfo(maj, min, dev->deviceinfo.pci, flags);
+        ret = drmParsePciDeviceInfo(maj, min, dev->businfo.pci, dev->deviceinfo.pci, flags);
         if (ret)
             goto free_device;
     }
@@ -3674,8 +3808,8 @@
                int req_subsystem_type,
                bool fetch_deviceinfo, uint32_t flags)
 {
-    struct stat sbuf;
-    char node[PATH_MAX + 1];
+    stat_t sbuf;
+    char node[DRM_NODE_NAME_MAX];
     int node_type, subsystem_type;
     unsigned int maj, min;
 
@@ -3683,7 +3817,7 @@
     if (node_type < 0)
         return -1;
 
-    snprintf(node, PATH_MAX, "%s/%s", DRM_DIR_NAME, d_name);
+    snprintf(node, sizeof(node), "%s/%s", DRM_DIR_NAME, d_name);
     if (stat(node, &sbuf))
         return -1;
 
@@ -3731,7 +3865,7 @@
                 local_devices[i]->available_nodes |= local_devices[j]->available_nodes;
                 node_type = log2(local_devices[j]->available_nodes);
                 memcpy(local_devices[i]->nodes[node_type],
-                       local_devices[j]->nodes[node_type], drmGetMaxNodeName());
+                       local_devices[j]->nodes[node_type], DRM_NODE_NAME_MAX);
                 drmFreeDevice(&local_devices[j]);
             }
         }
@@ -3771,7 +3905,7 @@
  * Get information about the opened drm device
  *
  * \param fd file descriptor of the drm device
- * \param flags feature/behaviour bitmask
+ * \param flags feature/behavior bitmask
  * \param device the address of a drmDevicePtr where the information
  *               will be allocated in stored
  *
@@ -3789,8 +3923,8 @@
      * Avoid stat'ing all of /dev needlessly by implementing this custom path.
      */
     drmDevicePtr     d;
-    struct stat      sbuf;
-    char             node[PATH_MAX + 1];
+    stat_t           sbuf;
+    char             node[DRM_NODE_NAME_MAX];
     const char      *dev_name;
     int              node_type, subsystem_type;
     int              maj, min, n, ret;
@@ -3922,7 +4056,7 @@
 /**
  * Get drm devices on the system
  *
- * \param flags feature/behaviour bitmask
+ * \param flags feature/behavior bitmask
  * \param devices the array of devices with drmDevicePtr elements
  *                can be NULL to get the device number first
  * \param max_devices the maximum number of devices for the array
@@ -4007,7 +4141,7 @@
 drm_public char *drmGetDeviceNameFromFd2(int fd)
 {
 #ifdef __linux__
-    struct stat sbuf;
+    stat_t sbuf;
     char path[PATH_MAX + 1], *value;
     unsigned int maj, min;
 
@@ -4030,9 +4164,26 @@
     free(value);
 
     return strdup(path);
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    stat_t sbuf;
+    if (fstat(fd, &sbuf))
+        return NULL;
+
+    dev_t rdev = sbuf.st_rdev;
+    /* minor numbers don't depend on node name suffix, search for a match */
+    for (int i = 0; i < DRM_MAX_MINOR; ++i) {
+        char node[DRM_NODE_NAME_MAX];
+        for (int j = 0; j < DRM_NODE_MAX; ++j) {
+            snprintf(node, sizeof(node), drmGetDeviceName(j),
+                     DRM_DIR_NAME, drmGetMinorBase(j) + i);
+            if (stat(node, &sbuf) == 0 && sbuf.st_rdev == rdev)
+                return strdup(node);
+        }
+    }
+    return NULL;
 #else
-    struct stat      sbuf;
-    char             node[PATH_MAX + 1];
+    stat_t           sbuf;
+    char             node[DRM_NODE_NAME_MAX];
     const char      *dev_name;
     int              node_type;
     int              maj, min, n;
