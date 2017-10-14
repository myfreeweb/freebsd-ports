--- config/baseconfig.mk.orig	2017-08-10 10:39:31 UTC
+++ config/baseconfig.mk
@@ -2,10 +2,10 @@
 # directly in python/mozbuild/mozbuild/base.py for gmake validation.
 # We thus use INCLUDED_AUTOCONF_MK to enable/disable some parts depending
 # whether a normal build is happening or whether the check is running.
-includedir := $(includedir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-idldir = $(datadir)/idl/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-installdir = $(libdir)/$(MOZ_APP_NAME)-$(MOZ_APP_VERSION)
-sdkdir = $(libdir)/$(MOZ_APP_NAME)-devel-$(MOZ_APP_VERSION)
+includedir := $(includedir)/firefox
+idldir = $(datadir)/idl/firefox
+installdir = $(libdir)/firefox
+sdkdir = $(libdir)/firefox
 ifeq (.,$(DEPTH))
 DIST = dist
 else
