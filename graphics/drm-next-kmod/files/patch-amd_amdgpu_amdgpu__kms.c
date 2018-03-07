--- amd/amdgpu/amdgpu_kms.c.orig	2018-03-06 19:36:21 UTC
+++ amd/amdgpu/amdgpu_kms.c
@@ -882,20 +882,20 @@ int amdgpu_get_vblank_timestamp_kms(struct drm_device 
 }
 
 const struct drm_ioctl_desc amdgpu_ioctls_kms[] = {
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_CREATE, amdgpu_gem_create_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_CTX, amdgpu_ctx_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_BO_LIST, amdgpu_bo_list_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_CREATE, amdgpu_gem_create_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_CTX, amdgpu_ctx_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_BO_LIST, amdgpu_bo_list_ioctl, DRM_RENDER_ALLOW),
 	/* KMS */
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_MMAP, amdgpu_gem_mmap_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_WAIT_IDLE, amdgpu_gem_wait_idle_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_CS, amdgpu_cs_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_INFO, amdgpu_info_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_WAIT_CS, amdgpu_cs_wait_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_WAIT_FENCES, amdgpu_cs_wait_fences_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_METADATA, amdgpu_gem_metadata_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_VA, amdgpu_gem_va_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_OP, amdgpu_gem_op_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
-	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_USERPTR, amdgpu_gem_userptr_ioctl, DRM_AUTH|DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_MMAP, amdgpu_gem_mmap_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_WAIT_IDLE, amdgpu_gem_wait_idle_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_CS, amdgpu_cs_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_INFO, amdgpu_info_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_WAIT_CS, amdgpu_cs_wait_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_WAIT_FENCES, amdgpu_cs_wait_fences_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_METADATA, amdgpu_gem_metadata_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_VA, amdgpu_gem_va_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_OP, amdgpu_gem_op_ioctl, DRM_RENDER_ALLOW),
+	DRM_IOCTL_DEF_DRV(AMDGPU_GEM_USERPTR, amdgpu_gem_userptr_ioctl, DRM_RENDER_ALLOW),
 };
 const int amdgpu_max_kms_ioctl = ARRAY_SIZE(amdgpu_ioctls_kms);
 
