--- setup.py.orig	2025-02-15 18:20:54 UTC
+++ setup.py
@@ -62,7 +62,7 @@ setup(
     install_requires=['pandas>=1.3.0', 'numpy>=1.16.5',
                       'requests>=2.31', 'multitasking>=0.0.7',
                       'platformdirs>=2.0.0', 'pytz>=2022.5',
-                      'frozendict>=2.3.4', 'peewee>=3.16.2',
+                      'frozendict>=2.3.4', 'peewee>=3.15.0',
                       'beautifulsoup4>=4.11.1'],
     extras_require={
         'nospam': ['requests_cache>=1.0', 'requests_ratelimiter>=0.3.1'],
