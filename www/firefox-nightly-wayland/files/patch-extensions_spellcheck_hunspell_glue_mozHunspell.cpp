--- extensions/spellcheck/hunspell/glue/mozHunspell.cpp.orig	2017-08-10 10:39:31 UTC
+++ extensions/spellcheck/hunspell/glue/mozHunspell.cpp
@@ -373,6 +373,14 @@ mozHunspell::LoadDictionaryList(bool aNotifyChildProce
     }
   }
 
+  // load system hunspell dictionaries
+  nsCOMPtr<nsIFile> hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("/usr/local/share/hunspell"),
+                        true, getter_AddRefs(hunDir));
+  if (hunDir) {
+      LoadDictionariesFromDir(hunDir);
+  }
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
