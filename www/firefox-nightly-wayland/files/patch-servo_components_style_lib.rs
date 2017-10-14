--- servo/components/style/lib.rs.orig	2017-10-14 17:58:22 UTC
+++ servo/components/style/lib.rs
@@ -23,7 +23,6 @@
 //! [cssparser]: ../cssparser/index.html
 //! [selectors]: ../selectors/index.html
 
-#![deny(warnings)]
 #![deny(missing_docs)]
 
 // FIXME(bholley): We need to blanket-allow unsafe code in order to make the
