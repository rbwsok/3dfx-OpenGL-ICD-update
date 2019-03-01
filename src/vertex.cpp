#include "stdafx.h"
#include "hml/hm.h"

GLenum beginmode;

GLAPI void APIENTRY glPointParameteriNV (GLenum, GLint)
{

}

GLAPI void APIENTRY glPointParameterivNV (GLenum, const GLint *)
{

}

// проверка на состо€ние
// выход:
//  true - продолжать работу вызывающей функции
//  false - завершить работу вызывающей функции
bool CheckVertexState(GLfloat x,GLfloat y,GLfloat z, GLfloat w)
{
 CHECKCONTEXTFALSE

 if (ctx.gl_POINT_SPRITE_ARB == GL_TRUE)
 {
  // вывод point sprite
  _glEnd();
  static mat4 m;

  // расчет перпендикул€ра к взгл€ду
  _glGetFloatv(GL_MODELVIEW_MATRIX,(float*)&m);

  vec3 right = vec3(m.m[0][0], m.m[1][0], m.m[2][0]);
  vec3 up =	   vec3(m.m[0][1], m.m[1][1], m.m[2][1]);

  right = normalize(right);
  up = normalize(up);

  // расчет размера спрайта
  _glGetFloatv(GL_PROJECTION_MATRIX,(float*)&m);
    
#ifdef RB_DEBUG
 sprintf(logbuf,"%g %g\r\n",m[0][0],m[1][1]);
 AddToLog(logbuf);
 sprintf(logbuf,"r %g %g %g\r\n",right.x,right.y,right.z);
 AddToLog(logbuf);
 sprintf(logbuf,"u %g %g %g\r\n",up.x,up.y,up.z);
 AddToLog(logbuf);
#endif

  right *= m[1][1];
  up *= m[0][0];

  _glBegin(GL_QUADS);
   _glTexCoord2d(0,0);
   _glVertex3f(x + up.x, y + up.y, z + up.z);
   _glTexCoord2d(0,1);
   _glVertex3f(x - right.x, y - right.y, z - right.z);
   _glTexCoord2d(1,1);
   _glVertex3f(x - up.x, y - up.y, z - up.z);
   _glTexCoord2d(1,0);
   _glVertex3f(x + right.x, y + right.y, z + right.z);
  _glEnd();
  _glBegin(beginmode);
  return false;
 }
 return true;
}

void APIENTRY new_glBegin(GLenum mode)
{
#ifdef RB_DEBUG
 AddToLog("glBegin(");
 LogGLBegin(mode);
 AddToLog(")\r\n");
#endif
 CHECKCONTEXT

 beginmode = mode;
	
 _glBegin(mode);
}

void APIENTRY new_glEnd(void)
{
#ifdef RB_DEBUG
 AddToLog("glEnd()\r\n");
#endif
 CHECKCONTEXT

 beginmode = 0;
 _glEnd();
}

void APIENTRY new_glVertex2d (GLdouble x, GLdouble y)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex2d(%g,%g)\r\n",x,y);
 AddToLog(logbuf);
#endif
 
 if (CheckVertexState((GLfloat)x,(GLfloat)y,0,1) == false) return;

 _glVertex2d (x,y);
}

void APIENTRY new_glVertex2dv (const GLdouble *v)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex2dv(%g,%g)\r\n",v[0],v[1]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],0,1) == false) return;

 _glVertex2dv(v);
}

void APIENTRY new_glVertex2f (GLfloat x, GLfloat y)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex2f(%g,%g)\r\n",x,y);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,0,1) == false) return;

 _glVertex2f (x,y);
}

void APIENTRY new_glVertex2fv (const GLfloat *v)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex2fv(%g,%g)\r\n",v[0],v[1]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],0,1) == false) return;

 _glVertex2fv(v);
}

void APIENTRY new_glVertex2i (GLint x, GLint y)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex2i(%d,%d)\r\n",x,y);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,0,1) == false) return;

 _glVertex2i (x,y);
}

void APIENTRY new_glVertex2iv (const GLint *v)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex2iv(%d,%d)\r\n",v[0],v[1]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],0,1) == false) return;

 _glVertex2iv(v);
}

void APIENTRY new_glVertex2s (GLshort x, GLshort y)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex2s(%hd,%hd)\r\n",x,y);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,0,1) == false) return;

 _glVertex2s (x,y);
}

void APIENTRY new_glVertex2sv (const GLshort *v)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex2sv(%hd,%hd)\r\n",v[0],v[1]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],0,1) == false) return;

 _glVertex2sv(v);
}

void APIENTRY new_glVertex3d (GLdouble x, GLdouble y, GLdouble z)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex3d(%g,%g,%g)\r\n",x,y,z);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,1) == false) return;

 _glVertex3d (x,y,z);
}

void APIENTRY new_glVertex3dv (const GLdouble *v)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex3dv(%g,%g,%g)\r\n",v[0],v[1],v[2]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],1) == false) return;

 _glVertex3dv(v);
}

void APIENTRY new_glVertex3f (GLfloat x, GLfloat y, GLfloat z)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex3f(%g,%g,%g)\r\n",x,y,z);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,1) == false) return;

 _glVertex3f (x,y,z);
}

void APIENTRY new_glVertex3fv (const GLfloat *v)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex3fv(%g,%g,%g)\r\n",v[0],v[1],v[2]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],1) == false) return;

 _glVertex3fv(v);
}

void APIENTRY new_glVertex3i (GLint x, GLint y, GLint z)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex3i(%d,%d,%d)\r\n",x,y,z);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,1) == false) return;

 _glVertex3i (x,y,z);
}

void APIENTRY new_glVertex3iv (const GLint *v)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex3iv(%d,%d,%d)\r\n",v[0],v[1],v[2]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],1) == false) return;

 _glVertex3iv(v);
}

void APIENTRY new_glVertex3s (GLshort x, GLshort y, GLshort z)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex3s(%hd,%hd,%hd)\r\n",x,y,z);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,1) == false) return;

 _glVertex3s (x,y,z);
}

void APIENTRY new_glVertex3sv (const GLshort *v)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex3sv(%hd,%hd,%hd)\r\n",v[0],v[1],v[2]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],1) == false) return;

 _glVertex3sv(v);
}

void APIENTRY new_glVertex4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex4d(%g,%g,%g,%g)\r\n",x,y,z,w);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w) == false) return;

 _glVertex4d (x,y,z,w);
}

void APIENTRY new_glVertex4dv (const GLdouble *v)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex4dv(%g,%g,%g,%g)\r\n",v[0],v[1],v[2],v[3]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]) == false) return;

 _glVertex4dv (v);
}

void APIENTRY new_glVertex4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex4f(%g,%g,%g,%g)\r\n",x,y,z,w);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w) == false) return;

 _glVertex4f (x,y,z,w);
}

void APIENTRY new_glVertex4fv (const GLfloat *v)
{
#ifdef RB_DEBUG
 sprintf(logbuf,"glVertex4fv(%g,%g,%g,%g)\r\n",v[0],v[1],v[2],v[3]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]) == false) return;

 _glVertex4fv(v);
}

void APIENTRY new_glVertex4i (GLint x, GLint y, GLint z, GLint w)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex4i(%d,%d,%d,%d)\r\n",x,y,z,w);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w) == false) return;

 _glVertex4i (x,y,z,w);
}

void APIENTRY new_glVertex4iv (const GLint *v)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex4iv(%d,%d,%d,%d)\r\n",v[0],v[1],v[2],v[3]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]) == false) return;

 _glVertex4iv(v);
}

void APIENTRY new_glVertex4s (GLshort x, GLshort y, GLshort z, GLshort w)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex4s(%hd,%hd,%hd,%hd)\r\n",x,y,z,w);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w) == false) return;

 _glVertex4s (x,y,z,w);
}

void APIENTRY new_glVertex4sv (const GLshort *v)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glVertex4sv(%hd,%hd,%hd,%hd)\r\n",v[0],v[1],v[2],v[3]);
 AddToLog(logbuf);
#endif

 if (CheckVertexState((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]) == false) return;

 _glVertex4sv(v);
}
