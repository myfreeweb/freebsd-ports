--- servo/ports/geckolib/lib.rs.orig	2017-10-14 18:05:08 UTC
+++ servo/ports/geckolib/lib.rs
@@ -2,8 +2,6 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
-#![deny(warnings)]
-
 extern crate cssparser;
 extern crate env_logger;
 extern crate libc;
