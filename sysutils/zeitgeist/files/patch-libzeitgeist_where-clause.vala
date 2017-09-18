From ebb1927aafb2fca016370b3d990f5a73afa598b2 Mon Sep 17 00:00:00 2001
From: Rico Tzschichholz <ricotz@ubuntu.com>
Date: Tue, 18 Oct 2016 09:59:16 +0200
Subject: Remove superfluous parentheses


--- libzeitgeist/where-clause.vala.orig	2014-07-03 07:46:46 UTC
+++ libzeitgeist/where-clause.vala
@@ -217,7 +217,7 @@ namespace Zeitgeist
             long[] pointers = new long[gptrarr.length + 1];
 #endif
             Memory.copy(pointers, ((PtrArray *) gptrarr)->pdata,
-                (gptrarr.length) * sizeof (void *));
+                gptrarr.length * sizeof (void *));
             return (T[]) pointers;
         }
 
