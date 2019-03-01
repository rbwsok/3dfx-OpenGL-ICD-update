#ifndef __VBO_H_
#define __VBO_H_

GLAPI void APIENTRY glBindBuffer(GLenum target, GLuint buffer);
GLAPI void APIENTRY glDeleteBuffers(GLsizei n, const GLuint *buffers);
GLAPI void APIENTRY glGenBuffers(GLsizei n, GLuint *buffers);
GLAPI GLboolean APIENTRY glIsBuffer(GLuint buffer);
GLAPI void APIENTRY glBufferData(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
GLAPI void APIENTRY glBufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
GLAPI void APIENTRY glGetBufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
GLAPI GLvoid* APIENTRY glMapBuffer(GLenum target, GLenum access);
GLAPI GLboolean APIENTRY glUnmapBuffer(GLenum target);
GLAPI void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params);

GLAPI void APIENTRY glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const GLvoid *indices);

#endif

