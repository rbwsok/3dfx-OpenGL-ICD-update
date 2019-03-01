//
// GL_ARB_vertex_buffer_object
// GL_EXT_draw_range_elements
//

#include "stdafx.h"

//#define MAX_BUFFERS 512


int arraybuf = 0;
int elarraybuf = 0;
int packbuf = 0;
int unpackbuf = 0;

struct ARB_BUFFER
{
 bool init;
 bool mapped;
 void *buf;
 int size;
 int usage;
 int access;
};

DYNARRAY bufs(32,sizeof(ARB_BUFFER));

//ARB_BUFFER bufs[MAX_BUFFERS];

GLAPI void APIENTRY glBindBuffer(GLenum target, GLuint buffer)
{
#ifdef RB_DEBUG
 AddToLog("glBindBuffer()\r\n");
#endif

 ARB_BUFFER *arb = (ARB_BUFFER *)bufs.GetElement(buffer);
 if (arb == NULL ||	arb->init == false) return;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
	   arraybuf = buffer;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
	   elarraybuf = buffer;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
	   packbuf = buffer;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
	   unpackbuf = buffer;
	   break;

  default: return;
 }
}

GLAPI void APIENTRY glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
#ifdef RB_DEBUG
 AddToLog("glDeleteBuffers()\r\n");
#endif

 if (n <= 0) return;
 ARB_BUFFER *arb = NULL;

 for (int i = 0; i < n; i++)
 {
  if (buffers[i] > 0)
  {
   arb = (ARB_BUFFER *)bufs.GetElement(buffers[i]);
   if (arb != NULL && arb->init == true)
   {
    if (arb->buf != 0) GlobalFree(arb->buf);
	arb->buf = 0;
	arb->size = 0;
	arb->init = false;
    bufs.DelElement(buffers[i]);
   }
  }
 }
}

GLAPI void APIENTRY glGenBuffers(GLsizei n, GLuint *buffers)
{
#ifdef RB_DEBUG
 AddToLog("glGenBuffers()\r\n");
#endif

 if (n <= 0) return;
 if (bufs.currentfree == 0) bufs.AddElement(0);

 // поиск свободного буфера в списке
 for (int i = 0; i < n; i++)
 {
  buffers[i] = bufs.AddElement(0);
  ((ARB_BUFFER*)(bufs.GetElement(buffers[i])))->init = true;
 }
}

GLAPI GLboolean APIENTRY glIsBuffer(GLuint buffer)
{
#ifdef RB_DEBUG
 AddToLog("glIsBuffer()\r\n");
#endif

 if (buffer <= 0) return GL_FALSE;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(buffer));
 if (arb == NULL || arb->init == false) return GL_FALSE;

 return GL_TRUE;
}

GLAPI void APIENTRY glBufferData(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage)
{
#ifdef RB_DEBUG
 AddToLog("glBufferData()\r\n");
#endif

 switch (usage)
 {
  case GL_STREAM_DRAW_ARB:
  case GL_STREAM_READ_ARB:
  case GL_STREAM_COPY_ARB:
  case GL_STATIC_DRAW_ARB:
  case GL_STATIC_READ_ARB:
  case GL_STATIC_COPY_ARB:
  case GL_DYNAMIC_DRAW_ARB:
  case GL_DYNAMIC_READ_ARB:
  case GL_DYNAMIC_COPY_ARB:
	   break;
  default: return;
 }

 if (size <= 0) return;

 ///////////////
 
 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return;
 }

 if (cur <= 0) return;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return;

 if (arb->buf != 0)
 {
  GlobalFree(arb->buf);
  arb->buf = 0;
  arb->size = 0;
 }
 if (data != 0)
 {
  arb->buf = GlobalAllocPtr(GPTR,size);
  memcpy(arb->buf,data,size);
  arb->size = size;
 }
 arb->usage = usage;
}

GLAPI void APIENTRY glBufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data)
{
#ifdef RB_DEBUG
 AddToLog("glBufferSubData()\r\n");
#endif

 if (size <= 0 || offset < 0) return;

 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return;
 }

 if (cur <= 0) return;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return;

 if ((size + offset) > arb->size) return;
 memcpy((char*)arb->buf + offset,data,size);
}

GLAPI void APIENTRY glGetBufferSubData(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data)
{
#ifdef RB_DEBUG
 AddToLog("glGetBufferSubData()\r\n");
#endif

 if (size <= 0 || offset < 0) return;

 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return;
 }

 if (cur <= 0) return;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return;

 if ((size + offset) > arb->size) return;
 memcpy(data,(char*)arb->buf + offset,size);
}

GLAPI GLvoid* APIENTRY glMapBuffer(GLenum target, GLenum access)
{
#ifdef RB_DEBUG
 AddToLog("glMapBuffer()\r\n");
#endif

 void* adr;

 switch (access)
 {
  case GL_READ_ONLY_ARB:
  case GL_WRITE_ONLY_ARB:
  case GL_READ_WRITE_ARB:
	   break;
  default: return 0;
 }

 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return 0;
 }

 if (cur <= 0) return 0;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return 0;

 if (arb->mapped == true) return 0;
 adr = arb->buf;
 arb->mapped = true;
 arb->access = access;

 return adr;
}

GLAPI GLboolean APIENTRY glUnmapBuffer(GLenum target)
{
#ifdef RB_DEBUG
 AddToLog("glUnmapBuffer()\r\n");
#endif

 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return GL_FALSE;
 }

 if (cur <= 0) return GL_FALSE;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return GL_FALSE;

 if (arb->mapped == false) return GL_FALSE;
 arb->mapped = false;

 return GL_TRUE;
}

GLAPI void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
#ifdef RB_DEBUG
 AddToLog("glGetBufferParameteriv()\r\n");
#endif

 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return;
 }

 if (cur <= 0) return;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return;
 
 switch (pname)
 {
  case GL_BUFFER_SIZE_ARB:
       params[0] = arb->size;
	   break;
  case GL_BUFFER_USAGE_ARB:
       params[0] = arb->usage;
	   break;
  case GL_BUFFER_ACCESS_ARB:
       params[0] = arb->access;
	   break;
  case GL_BUFFER_MAPPED_ARB:
       params[0] = arb->mapped;
       break;
  default: return;
 }

}
	
GLAPI void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params)
{
#ifdef RB_DEBUG
 AddToLog("glGetBufferPointerv()\r\n");
#endif

 int cur;

 switch (target)
 {
  case GL_ARRAY_BUFFER_ARB:
       cur = arraybuf;
	   break;
  case GL_ELEMENT_ARRAY_BUFFER_ARB:
       cur = elarraybuf;
	   break;
  case GL_PIXEL_PACK_BUFFER_EXT:
       cur = packbuf;
	   break;
  case GL_PIXEL_UNPACK_BUFFER_EXT:
       cur = unpackbuf;
	   break;

  default: return;
 }

 if (cur <= 0) return;
 ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(cur));
 if (arb == NULL ||	arb->init == false) return;

 switch (pname)
 {
  case GL_BUFFER_MAP_POINTER_ARB:
  	   params[0] = arb->buf;
	   break;
  default: return;
 }
}

void APIENTRY new_glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
#ifdef RB_DEBUG
 AddToLog("glVertexPointer()\r\n");
#endif

 char* ptr = (char*)pointer;

 if (arraybuf > 0)
 {
  ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(arraybuf));
//  if (arb == NULL || arb->init == false) return;
  ptr = (char*)arb->buf + (int)pointer;
 }
 _glVertexPointer(size,type,stride,ptr);
}

void APIENTRY new_glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
#ifdef RB_DEBUG
 AddToLog("glTexCoordPointer()\r\n");
#endif

 char* ptr = (char*)pointer;
 if (arraybuf > 0)
 {
  ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(arraybuf));
//  if (arb == NULL || arb->init == false) return;
  ptr = (char*)arb->buf + (int)pointer;
 }

 _glTexCoordPointer(size,type,stride,ptr);
}

void APIENTRY new_glNormalPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
{
 char* ptr = (char*)pointer;
 if (arraybuf > 0)
 {
  ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(arraybuf));
//  if (arb == NULL || arb->init == false) return;
  ptr = (char*)arb->buf + (int)pointer;
 }

 _glNormalPointer(type,stride,ptr);
}

void APIENTRY new_glColorPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
 char* ptr = (char*)pointer;
 if (arraybuf > 0)
 {
  ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(arraybuf));
//  if (arb == NULL || arb->init == false) return;
  ptr = (char*)arb->buf + (int)pointer;
 }

 _glColorPointer(size,type,stride,ptr);
}

void APIENTRY new_glEdgeFlagPointer (GLsizei stride, const GLvoid *pointer)
{
 char* ptr = (char*)pointer;
 if (arraybuf > 0)
 {
  ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(arraybuf));
//  if (arb == NULL || arb->init == false) return;
  ptr = (char*)arb->buf + (int)pointer;
 }

 _glEdgeFlagPointer(stride,ptr);
}

void APIENTRY new_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
 char* ptr = (char*)indices;
 if (elarraybuf > 0)
 {
  ARB_BUFFER *arb = (ARB_BUFFER*)(bufs.GetElement(elarraybuf));
//  if (arb == NULL || arb->init == false) return;
  ptr = (char*)arb->buf + (int)indices;
 }

 _glDrawElements(mode,count,type,ptr);
}
/*
void APIENTRY new_glInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer)
{
#if _DEBUG
 wsprintf(logbuf,"glInterleavedArrays(0x%X,%d,0x%X)\r\n",format,stride,pointer);
 AddToLog(logbuf);
#endif

 _glInterleavedArrays (format,stride,pointer);
}*/



void APIENTRY glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const GLvoid *indices)
{
 new_glDrawElements(mode,count,type,indices);
}

