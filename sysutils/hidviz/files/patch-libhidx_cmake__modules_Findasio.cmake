--- libhidx/cmake_modules/Findasio.cmake.orig	2019-11-30 12:59:48 UTC
+++ libhidx/cmake_modules/Findasio.cmake
@@ -1,4 +1,4 @@
-if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/asio/asio/include/asio.hpp")
+if(0)
     find_package(Git)
 
     if(NOT GIT_FOUND)
@@ -16,7 +16,7 @@ if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/asio/asio/i
 endif()
 
 add_library(asio INTERFACE)
-target_include_directories(asio INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/asio/asio/include/")
+target_include_directories(asio INTERFACE "${CMAKE_SOURCE_DIR}/asio/asio/include/")
 target_compile_definitions(asio INTERFACE ASIO_STANDALONE)
 
 if(WIN32)
