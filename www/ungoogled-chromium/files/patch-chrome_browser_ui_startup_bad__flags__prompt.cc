--- chrome/browser/ui/startup/bad_flags_prompt.cc.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/ui/startup/bad_flags_prompt.cc
@@ -100,7 +100,7 @@ const char* const kBadFlags[] = {
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // Speech dispatcher is buggy, it can crash and it can make Chrome freeze.
     // http://crbug.com/327295
     switches::kEnableSpeechDispatcher,
