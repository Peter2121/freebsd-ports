--- storage/innobase/xtrabackup/src/utils.cc.orig	2024-08-08 10:30:27 UTC
+++ storage/innobase/xtrabackup/src/utils.cc
@@ -21,6 +21,8 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Bos
 
 #ifdef __APPLE__
 #include <mach/mach_host.h>
+#endif
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/sysctl.h>
 #else
 #ifdef HAVE_PROCPS_V3
@@ -131,12 +133,14 @@ bool get_major_minor_version(const std::string &versio
   return true;
 }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 unsigned long host_total_memory() {
   unsigned long total_mem = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
   return total_mem;
 }
+#endif
 
+#ifdef __APPLE__
 unsigned long host_free_memory() {
   unsigned long total_mem = host_total_memory();
   int64_t used_mem;
@@ -157,6 +161,31 @@ unsigned long host_free_memory() {
     return total_mem - (unsigned long)used_mem;
   }
   return 0;
+}
+#elif defined(__FreeBSD__)
+unsigned long host_free_memory() {
+  static int mib_free[2] = { -1, 0 }; 
+  static int mib_inactive[2] = { -1, 0 };
+  size_t miblen = sizeof(mib_free) / sizeof(mib_free[0]);
+  uint32_t free_pages, inactive_pages;
+  size_t sz = sizeof(free_pages);
+  
+  free_pages = inactive_pages = 0;
+
+  if (mib_free[0] < 0 &&
+      sysctlnametomib("vm.stats.vm.v_free_count", mib_free, &miblen) < 0)
+          mib_free[0] = 0;
+  if (mib_inactive[0] < 0 &&
+      sysctlnametomib("vm.stats.vm.v_inactive_count", mib_inactive, &miblen) < 0)
+          mib_inactive[0] = 0;
+  
+  if (mib_free[0] &&
+      sysctl(mib_free, 2, &free_pages, &sz, NULL, 0) < 0)
+          free_pages = 0; /* should not happen */
+  if (mib_inactive[0] && sysctl(mib_inactive, 2, &inactive_pages, &sz, NULL, 0) < 0)
+          inactive_pages = 0; /* should not happen, too */
+
+  return (free_pages + inactive_pages) * sysconf(_SC_PAGESIZE);
 }
 #else
 unsigned long host_total_memory() {
