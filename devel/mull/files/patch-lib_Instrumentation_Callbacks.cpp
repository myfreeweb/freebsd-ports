--- lib/Instrumentation/Callbacks.cpp.orig	2018-10-01 09:02:27 UTC
+++ lib/Instrumentation/Callbacks.cpp
@@ -31,7 +31,7 @@ extern "C" void mull_leaveFunction(void **trampoline, 
 Value *Callbacks::injectInstrumentationInfoPointer(Module *module,
                                                    const char *variableName) {
   auto &context = module->getContext();
-  auto trampolineType = Type::getVoidTy(context)->getPointerTo()->getPointerTo();
+  auto trampolineType = Type::getInt8Ty(context)->getPointerTo();
   return module->getOrInsertGlobal(variableName, trampolineType);
 }
 
@@ -51,7 +51,7 @@ void Callbacks::injectCallbacks(llvm::Function *functi
                                 Value *offset) {
   auto &context = function->getParent()->getContext();
   auto intType = Type::getInt32Ty(context);
-  auto trampolineType = Type::getVoidTy(context)->getPointerTo()->getPointerTo();
+  auto trampolineType = Type::getInt8Ty(context)->getPointerTo()->getPointerTo();
   auto voidType = Type::getVoidTy(context);
   std::vector<Type *> parameterTypes({trampolineType, intType});
 
