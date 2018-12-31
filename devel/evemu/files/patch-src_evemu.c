--- src/evemu.c.orig	2017-06-02 08:02:09 UTC
+++ src/evemu.c
@@ -456,15 +456,12 @@ int evemu_write(const struct evemu_device *dev, FILE *
 static int parse_name(struct evemu_device *dev, const char *line)
 {
 	int matched;
-	char *devname = NULL;
+	char devname[UINPUT_MAX_NAME_SIZE];
 
-	if ((matched = sscanf(line, "N: %m[^\n\r]\n", &devname)) > 0) {
+	if ((matched = sscanf(line, "N: %[^\n\r]\n", devname)) > 0) {
 		if (strlen(evemu_get_name(dev)) == 0)
 			evemu_set_name(dev, devname);
 	}
-
-	if (devname != NULL)
-		free(devname);

 	if (matched <= 0)
 		error(FATAL, "Expected device name, but got: %s", line);
