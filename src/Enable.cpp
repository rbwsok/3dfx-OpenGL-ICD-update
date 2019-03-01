#include "stdafx.h"

void APIENTRY new_glEnable(GLenum cap)
{
#ifdef RB_DEBUG
 AddToLog("glEnable(");
 LogGLEnabled(cap);
 AddToLog(")\r\n");
#endif

 CHECKCONTEXT

 switch (cap)
 {
  case GL_MULTISAMPLE_ARB:
	   cap = GL_MULTISAMPLE_3DFX;
       break;
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB = GL_TRUE;
	   return;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB = GL_TRUE;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
       ctx.gl_SAMPLE_COVERAGE_ARB = GL_TRUE;
	   return;
	   break;
  case GL_RESCALE_NORMAL_EXT:
       ctx.gl_RESCALE_NORMAL_EXT = GL_TRUE;
       cap = GL_NORMALIZE;
	   break;
  case GL_NORMALIZE:
	   ctx.gl_NORMALIZE = GL_TRUE;
	   break;
  case GL_POINT_SPRITE_ARB:
	   ctx.gl_POINT_SPRITE_ARB = GL_TRUE;
	   break;
 }
 _glEnable(cap);
}

void APIENTRY new_glDisable(GLenum cap)
{
#ifdef RB_DEBUG
 AddToLog("glDisable(");
 LogGLEnabled(cap);
 AddToLog(")\r\n");
#endif

 CHECKCONTEXT

 switch (cap)
 {
  case GL_MULTISAMPLE_ARB:
	   cap = GL_MULTISAMPLE_3DFX;
       break;
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB = GL_FALSE;
	   return;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB = GL_FALSE;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
       ctx.gl_SAMPLE_COVERAGE_ARB = GL_FALSE;
	   return;
	   break;
  case GL_RESCALE_NORMAL_EXT:
       ctx.gl_RESCALE_NORMAL_EXT = GL_FALSE;
	   if (ctx.gl_NORMALIZE == GL_TRUE) return;
       cap = GL_NORMALIZE;
	   break;
  case GL_NORMALIZE:
	   ctx.gl_NORMALIZE = GL_FALSE;
	   if (ctx.gl_RESCALE_NORMAL_EXT == GL_TRUE) return;
	   break;
  case GL_POINT_SPRITE_ARB:
	   ctx.gl_POINT_SPRITE_ARB = GL_FALSE;
	   break;
 }
 _glDisable(cap);
}

GLboolean APIENTRY new_glIsEnabled(GLenum cap)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glIsEnabled (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXTFALSE

 switch (cap)
 {
  case GL_MULTISAMPLE_ARB:
	   cap = GL_MULTISAMPLE_3DFX;
       break;
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   return ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   return ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
       return ctx.gl_SAMPLE_COVERAGE_ARB;
	   break;
  case GL_VERTEX_ARRAY_RANGE_NV:
       return ctx.gl_VERTEX_ARRAY_RANGE_NV;
	   break;
  case GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV:
       return ctx.gl_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV;
	   break;
  case GL_WRITE_PIXEL_DATA_RANGE_NV:
	   return ctx.gl_WRITE_PIXEL_DATA_RANGE_NV;
       break;
  case GL_READ_PIXEL_DATA_RANGE_NV:
	   return ctx.gl_READ_PIXEL_DATA_RANGE_NV;
       break;
  case GL_RESCALE_NORMAL_EXT:
	   return ctx.gl_RESCALE_NORMAL_EXT;
	   break;
  case GL_NORMALIZE:
	   return ctx.gl_NORMALIZE;
	   break;
  case GL_POINT_SPRITE_ARB:
	   return ctx.gl_POINT_SPRITE_ARB;
	   break;
 }
 return _glIsEnabled(cap);
}

void APIENTRY new_glEnableClientState (GLenum array)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glEnableClientState (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 switch (array)
 {
  case GL_VERTEX_ARRAY_RANGE_NV:
	   ctx.gl_VERTEX_ARRAY_RANGE_NV = GL_TRUE;
	   return;
       break;
  case GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV:
	   ctx.gl_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV = GL_TRUE;
	   return;
       break;
  case GL_WRITE_PIXEL_DATA_RANGE_NV:
       ctx.gl_WRITE_PIXEL_DATA_RANGE_NV = GL_TRUE;
	   return;
       break;
  case GL_READ_PIXEL_DATA_RANGE_NV:
	   ctx.gl_READ_PIXEL_DATA_RANGE_NV = GL_TRUE;
	   return;
       break;
 }
 _glEnableClientState(array);
}

void APIENTRY new_glDisableClientState (GLenum array)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glDisableClientState (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 switch (array)
 {
  case GL_VERTEX_ARRAY_RANGE_NV:
       ctx.gl_VERTEX_ARRAY_RANGE_NV = GL_FALSE;
	   return;
       break;
  case GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV:
       ctx.gl_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV = GL_FALSE;
	   return;
       break;
  case GL_WRITE_PIXEL_DATA_RANGE_NV:
       ctx.gl_WRITE_PIXEL_DATA_RANGE_NV = GL_FALSE;
	   return;
       break;
  case GL_READ_PIXEL_DATA_RANGE_NV:
       ctx.gl_READ_PIXEL_DATA_RANGE_NV = GL_FALSE;
	   return;
       break;
 }
 _glDisableClientState(array);
}