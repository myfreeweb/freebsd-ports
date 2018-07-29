--- ffi.gemspec.orig	2018-07-29 13:02:08 UTC
+++ ffi.gemspec
@@ -21,6 +21,8 @@ Gem::Specification.new do |s|
   s.rubygems_version = "2.7.6".freeze
   s.summary = "Ruby FFI".freeze
 
+  s.files += ["lib/ffi/platform/aarch64-freebsd/types.conf".freeze, "lib/ffi/platform/arm-freebsd/types.conf".freeze]
+
   if s.respond_to? :specification_version then
     s.specification_version = 4
 
