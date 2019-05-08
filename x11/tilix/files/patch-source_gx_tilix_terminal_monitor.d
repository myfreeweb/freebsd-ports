--- source/gx/tilix/terminal/monitor.d.orig	2019-11-25 19:51:34 UTC
+++ source/gx/tilix/terminal/monitor.d
@@ -128,7 +128,7 @@ enum SLEEP_CONSTANT_MS = 300;
 /**
  * List of processes being monitored.
  */
-shared ProcessStatus[GPid] processes;
+shared(ProcessStatus)[GPid] processes;
 
 void monitorProcesses(int sleep, Tid tid) {
     bool abort = false;
