#ifndef __MULTIDRAWARRAY_H_
#define __MULTIDRAWARRAY_H_

GLAPI void APIENTRY glMultiDrawArraysEXT(GLenum mode,GLint* first,GLsizei *count,GLsizei primcount);
GLAPI void APIENTRY glMultiDrawElementsEXT(GLenum mode,const GLsizei *count,GLenum type,const GLvoid **indices,GLsizei primcount);
GLAPI void APIENTRY glMultiModeDrawArraysIBM(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
GLAPI void APIENTRY glMultiModeDrawElementsIBM(const GLenum *mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount, GLint modestride);
GLAPI void APIENTRY glFlushVertexArrayRangeNV(void);
GLAPI void APIENTRY glVertexArrayRangeNV(GLsizei length, const GLvoid *pointer);
void* WINAPI wglAllocateMemoryNV (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
void WINAPI wglFreeMemoryNV (void *pointer);
GLAPI void APIENTRY glDeleteFencesNV (GLsizei n, const GLuint *fences);
GLAPI void APIENTRY glGenFencesNV(GLsizei n, GLuint *fences);
GLAPI GLboolean APIENTRY glIsFenceNV (GLuint fence);
GLAPI GLboolean APIENTRY glTestFenceNV (GLuint fence);
GLAPI void APIENTRY glGetFenceivNV (GLuint fence, GLenum pname, GLint *params);
GLAPI void APIENTRY glFinishFenceNV (GLuint fence);
GLAPI void APIENTRY glSetFenceNV (GLuint fence, GLenum condition);
GLAPI void APIENTRY glPixelDataRangeNV (GLenum target, GLsizei length, GLvoid *pointer);
GLAPI void APIENTRY glFlushPixelDataRangeNV (GLenum target);

#endif

