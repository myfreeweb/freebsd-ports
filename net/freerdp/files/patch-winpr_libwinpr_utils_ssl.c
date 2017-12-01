--- winpr/libwinpr/utils/ssl.c.orig	2017-12-01 18:59:18.376989000 +0300
+++ winpr/libwinpr/utils/ssl.c	2017-12-01 18:59:35.393053000 +0300
@@ -279,7 +279,7 @@
 
 	if (flags & WINPR_SSL_INIT_ENABLE_FIPS)
 	{
-#if (OPENSSL_VERSION_NUMBER < 0x10001000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10001000L) || defined(LIBRESSL_VERSION_NUMBER)
 		WLog_ERR(TAG, "Openssl fips mode ENable not available on openssl versions less than 1.0.1!");
 #else
 		WLog_DBG(TAG, "Ensuring openssl fips mode is ENabled");
@@ -348,7 +348,7 @@
 
 BOOL winpr_FIPSMode(void)
 {
-#if (OPENSSL_VERSION_NUMBER < 0x10001000L)
+#if (OPENSSL_VERSION_NUMBER < 0x10001000L) || defined(LIBRESSL_VERSION_NUMBER)
 	return FALSE;
 #else
 	return (FIPS_mode() == 1);
