--- cargo-crates/tokio-0.1.3/src/reactor/poll_evented.rs.orig	2018-03-17 20:50:53 UTC
+++ cargo-crates/tokio-0.1.3/src/reactor/poll_evented.rs
@@ -433,16 +433,6 @@ mod platform {
     use mio::Ready;
     use mio::unix::UnixReady;
 
-    #[cfg(target_os = "dragonfly")]
-    pub fn all() -> Ready {
-        hup() | UnixReady::aio()
-    }
-
-    #[cfg(target_os = "freebsd")]
-    pub fn all() -> Ready {
-        hup() | UnixReady::aio() | UnixReady::lio()
-    }
-
     const HUP: usize = 1 << 2;
     const ERROR: usize = 1 << 3;
     const AIO: usize = 1 << 4;
