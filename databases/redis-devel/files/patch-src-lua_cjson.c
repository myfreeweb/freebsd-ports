LuaJIT implements a function from 5.2: https://github.com/LuaJIT/LuaJIT/issues/325

lua_cjson does not include luajit.h, so we can't check for luajit without a custom define.
WITH_LUAJIT is defined in the Makefile.luajit extra patch.

--- deps/lua/src/lua_cjson.c.orig	2018-08-07 16:21:12 UTC
+++ deps/lua/src/lua_cjson.c
@@ -46,7 +46,9 @@
 #include "strbuf.h"
 #include "fpconv.h"
 
+#if defined(__sun)
 #include "../../../src/solarisfixes.h"
+#endif
 
 #ifndef CJSON_MODNAME
 #define CJSON_MODNAME   "cjson"
@@ -1292,7 +1294,7 @@ static int json_decode(lua_State *l)

 /* ===== INITIALISATION ===== */

-#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 502
+#if !defined(WITH_LUAJIT) && (!defined(LUA_VERSION_NUM) || LUA_VERSION_NUM < 502)
 /* Compatibility for Lua 5.1.
  *
  * luaL_setfuncs() is used to create a module table where the functions have
