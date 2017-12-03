--- test/test-libevdev-init.c.orig	2016-08-17 00:37:01 UTC
+++ test/test-libevdev-init.c
@@ -490,7 +490,7 @@ START_TEST(test_set_clock_id)
 	rc = libevdev_set_clock_id(dev, CLOCK_MONOTONIC);
 	ck_assert_int_eq(rc, 0);
 
-	rc = libevdev_set_clock_id(dev, CLOCK_MONOTONIC_RAW);
+	rc = libevdev_set_clock_id(dev, CLOCK_MONOTONIC_FAST);
 	ck_assert_int_eq(rc, -EINVAL);
 
 	uinput_device_free(uidev);
