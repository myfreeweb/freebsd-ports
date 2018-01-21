--- scripts/check-config.sh.orig	2018-01-20 14:37:21 UTC
+++ scripts/check-config.sh
@@ -38,14 +38,14 @@ cat `find ${srctree} -name "Kconfig*"` |sed -n \
 	|sort |uniq > ${ok}
 comm -23 ${suspects} ${ok} >${new_adhoc}
 if [ -s ${new_adhoc} ]; then
-	echo >&2 "Error: You must add new CONFIG options using Kconfig"
+	echo >&2 "Warning: You must add new CONFIG options using Kconfig"
 	echo >&2 "The following new ad-hoc CONFIG options were detected:"
 	cat >&2 ${new_adhoc}
 	echo >&2
 	echo >&2 "Please add these via Kconfig instead. Find a suitable Kconfig"
 	echo >&2 "file and add a 'config' or 'menuconfig' option."
 	# Don't delete the temporary files in case they are useful
-	exit 1
+	#exit 1
 else
 	rm ${suspects} ${ok} ${new_adhoc}
 fi
