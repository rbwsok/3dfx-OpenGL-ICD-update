//
// GL_EXT_multi_draw_arrays,
// GL_SUN_multi_draw_arrays,
// GL_IBM_multimode_draw_arrays,
// GL_NV_fence
// GL_NV_vertex_array_range
// GL_NV_vertex_array_range2
// GL_NV_pixel_data_range
//
#include "stdafx.h"

GLAPI void APIENTRY glMultiDrawArraysEXT(GLenum mode,GLint* first,GLsizei *count,GLsizei primcount)
{
 CHECKCONTEXT
 for(int i=0; i<primcount; i++) 
 {
  if (*(count+i)>0) _glDrawArrays(mode, *(first+i), *(count+i));
 }
}

GLAPI void APIENTRY glMultiDrawElementsEXT(GLenum mode,const GLsizei *count,GLenum type,const GLvoid **indices,GLsizei primcount)
{
 CHECKCONTEXT
 for(int i=0; i<primcount; i++) 
 {
  if (*(count+i)>0) _glDrawElements(mode, *(count+i), type,*(indices+i));
 }
}

PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArrays = glMultiDrawArraysEXT;
PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElements = glMultiDrawElementsEXT;

GLAPI void APIENTRY glMultiModeDrawArraysIBM(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride)
{
 CHECKCONTEXT
 for(int i=0; i<primcount; i++) 
 {
  if (*(count+i)>0) 
    _glDrawArrays(*((GLenum *)((char *)mode+i*modestride)),*(first+i),*(count+i));
 }
}

GLAPI void APIENTRY glMultiModeDrawElementsIBM(const GLenum *mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount, GLint modestride)
{
 CHECKCONTEXT
 for(int i=0; i<primcount; i++) 
 {
  if (*(count+i)>0) 
    _glDrawElements(*((GLenum *)((char *)mode+i*modestride)),*(count+i),type,*(indices+i));
 }
}

PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArrays = glMultiModeDrawArraysIBM;
PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElements = glMultiModeDrawElementsIBM;

GLAPI void APIENTRY glFlushVertexArrayRangeNV(void)
{

}

GLAPI void APIENTRY glVertexArrayRangeNV(GLsizei length, const GLvoid *pointer)
{

}

PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRange = glFlushVertexArrayRangeNV;
PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRange = glVertexArrayRangeNV;

void* WINAPI wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
 CHECKCONTEXTFALSE

 return (void*)GlobalAllocPtr(GPTR,size);
}

void WINAPI wglFreeMemoryNV (void *pointer)
{
 CHECKCONTEXT
 GlobalFree(pointer);
}

PFNWGLALLOCATEMEMORYNVPROC wglAllocateMemory = wglAllocateMemoryNV;
PFNWGLFREEMEMORYNVPROC wglFreeMemory = wglFreeMemoryNV;

GLAPI void APIENTRY glDeleteFencesNV (GLsizei n, const GLuint *fences)
{
 CHECKCONTEXT

}

GLAPI void APIENTRY glGenFencesNV(GLsizei n, GLuint *fences)
{
 CHECKCONTEXT

}

GLAPI GLboolean APIENTRY glIsFenceNV (GLuint fence)
{
 
 return GL_TRUE;
}

GLAPI GLboolean APIENTRY glTestFenceNV (GLuint fence)
{
 
 return GL_TRUE;
}

GLAPI void APIENTRY glGetFenceivNV (GLuint fence, GLenum pname, GLint *params)
{

}

GLAPI void APIENTRY glFinishFenceNV (GLuint fence)
{

}

GLAPI void APIENTRY glSetFenceNV (GLuint fence, GLenum condition)
{

}

PFNGLDELETEFENCESNVPROC glDeleteFences = glDeleteFencesNV;
PFNGLGENFENCESNVPROC glGenFences = glGenFencesNV;
PFNGLISFENCENVPROC glIsFence = glIsFenceNV;
PFNGLTESTFENCENVPROC glTestFence = glTestFenceNV;
PFNGLGETFENCEIVNVPROC glGetFenceiv = glGetFenceivNV;
PFNGLFINISHFENCENVPROC glFinishFence = glFinishFenceNV;
PFNGLSETFENCENVPROC glSetFence = glSetFenceNV;


GLAPI void APIENTRY glPixelDataRangeNV (GLenum target, GLsizei length, GLvoid *pointer)
{

}

GLAPI void APIENTRY glFlushPixelDataRangeNV (GLenum target)
{

}

PFNGLPIXELDATARANGENVPROC glPixelDataRange = glPixelDataRangeNV;
PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRange = glFlushPixelDataRangeNV;
