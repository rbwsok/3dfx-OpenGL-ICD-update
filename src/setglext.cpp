#include "stdafx.h"

struct GetProcAddressOverride
{
 const char *name;
 PROC proc;
};


GetProcAddressOverride extfunc[] = 
{
// GL_EXT_multi_draw_arrays
{"glMultiDrawArraysEXT",(PROC)glMultiDrawArraysEXT},
{"glMultiDrawElementsEXT",(PROC)glMultiDrawElementsEXT},
// GL_SUN_multi_draw_arrays
{"glMultiDrawArraysSUN",(PROC)glMultiDrawArraysEXT},
{"glMultiDrawElementsSUN",(PROC)glMultiDrawElementsEXT},
// GL_IBM_multimode_draw_arrays
{"glMultiModeDrawArraysIBM",(PROC)glMultiModeDrawArraysIBM},
{"glMultiModeDrawElementsIBM",(PROC)glMultiModeDrawElementsIBM},
// GL_ARB_transpose_matrix
{"glLoadTransposeMatrixfARB",(PROC)glLoadTransposeMatrixf},
{"glLoadTransposeMatrixdARB",(PROC)glLoadTransposeMatrixd},
{"glMultTransposeMatrixfARB",(PROC)glMultTransposeMatrixf},
{"glMultTransposeMatrixdARB",(PROC)glMultTransposeMatrixd},
// WGL_ARB_extensions_string
{"wglGetExtensionsStringARB",(PROC)wglGetExtensionsStringARB},
// WGL_EXT_extensions_string
{"wglGetExtensionsStringEXT",(PROC)wglGetExtensionsStringEXT},
// WGL_ARB_pixel_format
{"wglGetPixelFormatAttribivARB",(PROC)wglGetPixelFormatAttribivARB},
{"wglGetPixelFormatAttribfvARB",(PROC)wglGetPixelFormatAttribfvARB},
{"wglChoosePixelFormatARB",(PROC)wglChoosePixelFormatARB},
// WGL/GL_ARB_multisample
{"glSampleCoverageARB",(PROC)glSampleCoverage},
// GL_NV_vertex_array_range
{"glVertexArrayRangeNV",(PROC)glVertexArrayRangeNV},
{"glFlushVertexArrayRangeNV",(PROC)glFlushVertexArrayRangeNV},
{"wglAllocateMemoryNV",(PROC)wglAllocateMemoryNV},
{"wglFreeMemoryNV",(PROC)wglFreeMemoryNV},
// GL_NV_fence
{"glDeleteFencesNV",(PROC)glDeleteFencesNV},
{"glGenFencesNV",(PROC)glGenFencesNV},
{"glIsFenceNV",(PROC)glIsFenceNV},
{"glTestFenceNV",(PROC)glTestFenceNV},
{"glGetFenceivNV",(PROC)glGetFenceivNV},
{"glFinishFenceNV",(PROC)glFinishFenceNV},
{"glSetFenceNV",(PROC)glSetFenceNV},
// GL_NV_pixel_data_range
{"glPixelDataRangeNV",(PROC)glPixelDataRangeNV},
{"glFlushPixelDataRangeNV",(PROC)glFlushPixelDataRangeNV},
// GL_MESA_window_pos
{"glWindowPos2dMESA" ,(PROC)glWindowPos2d},
{"glWindowPos2dvMESA",(PROC)glWindowPos2dv},
{"glWindowPos2fMESA" ,(PROC)glWindowPos2f},
{"glWindowPos2fvMESA",(PROC)glWindowPos2fv},
{"glWindowPos2iMESA" ,(PROC)glWindowPos2i},
{"glWindowPos2ivMESA",(PROC)glWindowPos2iv},
{"glWindowPos2sMESA" ,(PROC)glWindowPos2s},
{"glWindowPos2svMESA",(PROC)glWindowPos2sv},
{"glWindowPos3dMESA" ,(PROC)glWindowPos3d},
{"glWindowPos3dvMESA",(PROC)glWindowPos3dv},
{"glWindowPos3fMESA" ,(PROC)glWindowPos3f},
{"glWindowPos3fvMESA",(PROC)glWindowPos3fv},
{"glWindowPos3iMESA" ,(PROC)glWindowPos3i},
{"glWindowPos3ivMESA",(PROC)glWindowPos3iv},
{"glWindowPos3sMESA" ,(PROC)glWindowPos3s},
{"glWindowPos3svMESA",(PROC)glWindowPos3sv},
{"glWindowPos4dMESA" ,(PROC)glWindowPos4d},
{"glWindowPos4dvMESA",(PROC)glWindowPos4dv},
{"glWindowPos4fMESA" ,(PROC)glWindowPos4f},
{"glWindowPos4fvMESA",(PROC)glWindowPos4fv},
{"glWindowPos4iMESA" ,(PROC)glWindowPos4i},
{"glWindowPos4ivMESA",(PROC)glWindowPos4iv},
{"glWindowPos4sMESA" ,(PROC)glWindowPos4s},
{"glWindowPos4svMESA",(PROC)glWindowPos4sv},
// GL_ARB_window_pos
{"glWindowPos2dARB" ,(PROC)glWindowPos2d},
{"glWindowPos2dvARB",(PROC)glWindowPos2dv},
{"glWindowPos2fARB" ,(PROC)glWindowPos2f},
{"glWindowPos2fvARB",(PROC)glWindowPos2fv},
{"glWindowPos2iARB" ,(PROC)glWindowPos2i},
{"glWindowPos2ivARB",(PROC)glWindowPos2iv},
{"glWindowPos2sARB" ,(PROC)glWindowPos2s},
{"glWindowPos2svARB",(PROC)glWindowPos2sv},
{"glWindowPos3dARB" ,(PROC)glWindowPos3d},
{"glWindowPos3dvARB",(PROC)glWindowPos3dv},
{"glWindowPos3fARB" ,(PROC)glWindowPos3f},
{"glWindowPos3fvARB",(PROC)glWindowPos3fv},
{"glWindowPos3iARB" ,(PROC)glWindowPos3i},
{"glWindowPos3ivARB",(PROC)glWindowPos3iv},
{"glWindowPos3sARB" ,(PROC)glWindowPos3s},
{"glWindowPos3svARB",(PROC)glWindowPos3sv},
// GL_ARB_vertex_buffer_object
{"glBindBufferARB",          (PROC)glBindBuffer},
{"glDeleteBuffersARB",       (PROC)glDeleteBuffers},
{"glGenBuffersARB",          (PROC)glGenBuffers},
{"glIsBufferARB",            (PROC)glIsBuffer},
{"glBufferDataARB",          (PROC)glBufferData},
{"glBufferSubDataARB",       (PROC)glBufferSubData},
{"glGetBufferSubDataARB",    (PROC)glGetBufferSubData},
{"glMapBufferARB",           (PROC)glMapBuffer},
{"glUnmapBufferARB",         (PROC)glUnmapBuffer},
{"glGetBufferParameterivARB",(PROC)glGetBufferParameteriv},
{"glGetBufferPointervARB",   (PROC)glGetBufferPointerv},
// GL_NV_point_sprite
{"glPointParameteriNV",      (PROC)glPointParameteriNV},
{"glPointParameterivNV",     (PROC)glPointParameterivNV},
// GL_EXT_draw_range_elements
{"glDrawRangeElementsEXT",   (PROC)glDrawRangeElements},
{0,0}};

PROC WINAPI new_wglGetProcAddress (LPCSTR lpszProc)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"wglGetProcAddress (%s)\r\n",lpszProc);
 AddToLog(logbuf);
#endif

 // GL_3DFX_tbuffer
 if (strcmp(lpszProc,"glTbufferMask3DFX") == 0)
  return _wglGetProcAddress("glTBufferMask3DFX");
 
 // GL_ARB_point_parameters
 if (strcmp(lpszProc,"glPointParameterfARB") == 0)
  return _wglGetProcAddress("glPointParameterfEXT");
 if (strcmp(lpszProc,"glPointParameterfvARB") == 0)
  return _wglGetProcAddress("glPointParameterfvEXT");

 for (int i=0;;i++)
 {
  if (extfunc[i].name == 0) break;
  if (strcmp(lpszProc,extfunc[i].name) == 0)
   return extfunc[i].proc;
 }

 return _wglGetProcAddress(lpszProc);
}
