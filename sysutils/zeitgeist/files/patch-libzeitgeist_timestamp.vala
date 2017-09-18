From ebb1927aafb2fca016370b3d990f5a73afa598b2 Mon Sep 17 00:00:00 2001
From: Rico Tzschichholz <ricotz@ubuntu.com>
Date: Tue, 18 Oct 2016 09:59:16 +0200
Subject: Remove superfluous parentheses


--- libzeitgeist/timestamp.vala.orig	2014-07-03 07:46:47 UTC
+++ libzeitgeist/timestamp.vala
@@ -76,7 +76,7 @@ namespace Zeitgeist.Timestamp
      */
     public int64 from_timeval (TimeVal timeval)
     {
-        var m_seconds = (int64) (timeval.tv_sec) * 1000;
+        var m_seconds = (int64) timeval.tv_sec * 1000;
         return m_seconds + ((int64) timeval.tv_usec / 1000);
     }
 
