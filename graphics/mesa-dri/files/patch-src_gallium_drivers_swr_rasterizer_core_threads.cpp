--- src/gallium/drivers/swr/rasterizer/core/threads.cpp.orig	2017-12-21 20:31:21.000000000 +0300
+++ src/gallium/drivers/swr/rasterizer/core/threads.cpp	2017-12-24 02:25:05.561230000 +0300
@@ -30,12 +30,18 @@
 #include <fstream>
 #include <string>
 
-#if defined(__linux__) || defined(__gnu_linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__gnu_linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <pthread.h>
 #include <sched.h>
 #include <unistd.h>
 #endif
 
+#if defined(__FreeBSD__)
+#include <sstream>
+#include <tinyxml2.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "common/os.h"
 #include "context.h"
 #include "frontend.h"
@@ -216,6 +222,87 @@
             out_numThreadsPerProcGroup += core.threadIds.size();
         }
     }
+
+#elif defined(__FreeBSD__)
+
+    // XXX: the kernel does not return NUMA nodes
+    NumaNode numa_node;
+    numa_node.numaId = 0;
+    out_numThreadsPerProcGroup = 0;
+
+    size_t topology_len = 0;
+    if (sysctlbyname("kern.sched.topology_spec", NULL, &topology_len, NULL, 0))
+    {
+            SWR_INVALID("Sysctl shouldn't fail");
+    }
+    std::vector<char> topology(topology_len);
+    if (sysctlbyname("kern.sched.topology_spec", &topology[0], &topology_len, NULL, 0))
+    {
+            SWR_INVALID("Sysctl shouldn't fail");
+    }
+    tinyxml2::XMLDocument topology_doc;
+    topology_doc.Parse(&topology[0], topology_len);
+    std::function<void(tinyxml2::XMLElement*)> walk_topology =
+        [&walk_topology, &out_numThreadsPerProcGroup, &numa_node](tinyxml2::XMLElement* groups)
+    {
+            for (tinyxml2::XMLElement* child = groups->FirstChildElement();
+                            child != nullptr; child = child->NextSiblingElement())
+            {
+                    tinyxml2::XMLElement* cpu = child->FirstChildElement("cpu");
+                    tinyxml2::XMLElement* flags = child->FirstChildElement("flags");
+                    tinyxml2::XMLElement* children = child->FirstChildElement("children");
+                    bool in_smt = false;
+                    if (flags != nullptr)
+                    {
+                            for (tinyxml2::XMLElement* flag = flags->FirstChildElement();
+                                            flag != nullptr; flag = flag->NextSiblingElement())
+                            {
+                                    if (flag->Attribute("name", "THREAD"))
+                                    {
+                                            in_smt = true;
+                                            break;
+                                    }
+                            }
+                    }
+                    if (children != nullptr && !in_smt)
+                    {
+                            walk_topology(children);
+                            continue;
+                    }
+                    if (cpu == nullptr)
+                    {
+                            return;
+                    }
+                    uint32_t _id;
+                    std::vector<uint32_t> ids;
+                    std::stringstream ss(cpu->GetText());
+                    while (ss >> _id)
+                    {
+                            ids.push_back(_id);
+                            while (ss.peek() == ',' || ss.peek() == ' ') {
+                                    ss.ignore(1);
+                            }
+                    }
+                    out_numThreadsPerProcGroup += ids.size();
+                    if (in_smt)
+                    {
+                        Core core;
+                        core.threadIds = ids;
+                        numa_node.cores.push_back(core);
+                    }
+                    else
+                    {
+                        for (uint32_t id : ids)
+                        {
+                            Core core;
+                            core.threadIds.push_back(id);
+                            numa_node.cores.push_back(core);
+                        }
+                    }
+            }
+    };
+    walk_topology(topology_doc.RootElement());
+    out_nodes.push_back(numa_node);
 
 #elif defined(__APPLE__)
 
