--- setup.py.orig	2019-01-01 18:02:32 UTC
+++ setup.py
@@ -608,8 +608,9 @@ def package(args, for_bundle=False, sh_launcher=False)
         for error in proc.stderr.decode('utf-8').splitlines():
             if not re.match(regex, error):
                 print(error, file=sys.stderr)
-        if not glob.glob(os.path.join(odir, '*/xterm-kitty')):
-            raise SystemExit('tic failed to output the compiled kitty terminfo file')
+        print(os.path.join(odir, '*/xterm-kitty'), glob.glob(os.path.join(odir, '*/xterm-kitty')))
+#        if not glob.glob(os.path.join(odir, '*/xterm-kitty')):
+#            raise SystemExit('tic failed to output the compiled kitty terminfo file')
     shutil.copy2('__main__.py', libdir)
     shutil.copy2('logo/kitty.rgba', os.path.join(libdir, 'logo'))
     shutil.copy2('logo/beam-cursor.png', os.path.join(libdir, 'logo'))
@@ -634,8 +635,8 @@ def package(args, for_bundle=False, sh_launcher=False)
     safe_makedirs(launcher_dir)
     build_linux_launcher(args, launcher_dir, for_bundle, sh_launcher, args.for_freeze)
     if not is_macos:  # {{{ linux desktop gunk
-        copy_man_pages(ddir)
-        copy_html_docs(ddir)
+#        copy_man_pages(ddir)
+#        copy_html_docs(ddir)
         icdir = os.path.join(ddir, 'share', 'icons', 'hicolor', '256x256', 'apps')
         safe_makedirs(icdir)
         shutil.copy2('logo/kitty.png', icdir)
@@ -822,8 +823,8 @@ def main():
         )
     elif args.action == 'linux-package':
         build(args, native_optimizations=False)
-        if not os.path.exists(os.path.join(base, 'docs/_build/html')):
-            run_tool(['make', 'docs'])
+#        if not os.path.exists(os.path.join(base, 'docs/_build/html')):
+#            run_tool(['make', 'docs'])
         package(args)
     elif args.action == 'osx-bundle':
         build(args, native_optimizations=False)
