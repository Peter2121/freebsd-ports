--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2025-01-27 17:37:37 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -641,7 +641,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
@@ -1049,7 +1049,7 @@ scoped_refptr<VideoFrame> GpuMemoryBufferVideoFramePoo
       media::IOSurfaceIsWebGPUCompatible(handle.io_surface.get());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_webgpu_compatible =
       handle.native_pixmap_handle.supports_zero_copy_webgpu_import;
 #endif
@@ -1229,7 +1229,7 @@ GpuMemoryBufferVideoFramePool::PoolImpl::GetOrCreateFr
       si_usage |= gpu::SHARED_IMAGE_USAGE_SCANOUT;
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40194712): Always add the flag once the
     // OzoneImageBacking is by default turned on.
     if (base::CommandLine::ForCurrentProcess()->HasSwitch(
