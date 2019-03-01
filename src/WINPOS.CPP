#include "stdafx.h"

GLAPI void APIENTRY glWindowPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
#ifdef RB_DEBUG
 AddToLog("glWindowPos4f()\r\n");
#endif

 CHECKCONTEXT
 GLfloat fx, fy;

 /* Push current matrix mode and viewport attributes */
 _glPushAttrib( GL_TRANSFORM_BIT | GL_VIEWPORT_BIT );

 /* Setup projection parameters */
 _glMatrixMode( GL_PROJECTION );
 _glPushMatrix();
 _glLoadIdentity();
 _glMatrixMode( GL_MODELVIEW );
 _glPushMatrix();
 _glLoadIdentity();

 _glDepthRange( z, z );
 _glViewport( (int) x - 1, (int) y - 1, 2, 2 );

 /* set the raster (window) position */
 fx = x - (int) x;
 fy = y - (int) y;
 _glRasterPos4f( fx, fy, 0.0, w );

 /* restore matrices, viewport and matrix mode */
 _glPopMatrix();
 _glMatrixMode( GL_PROJECTION );
 _glPopMatrix();

 _glPopAttrib();
}

GLAPI void APIENTRY glWindowPos2d(GLdouble x, GLdouble y)
{
 glWindowPos4f((float)x,(float)y,0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2dv(const GLdouble *v)
{
 glWindowPos4f((float)v[0],(float)v[1],0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2f(GLfloat x, GLfloat y)
{
 glWindowPos4f((float)x,(float)y,0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2fv(const GLfloat *v)
{
 glWindowPos4f((float)v[0],(float)v[1],0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2i(GLint x, GLint y)
{
 glWindowPos4f((float)x,(float)y,0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2iv(const GLint *v)
{
 glWindowPos4f((float)v[0],(float)v[1],0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2s(GLshort x, GLshort y)
{
 glWindowPos4f((float)x,(float)y,0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos2sv(const GLshort *v)
{
 glWindowPos4f((float)v[0],(float)v[1],0.0f,1.0f);
}

GLAPI void APIENTRY glWindowPos3d(GLdouble x, GLdouble y, GLdouble z)
{
 glWindowPos4f((float)x,(float)y,(float)z,1.0f);
}

GLAPI void APIENTRY glWindowPos3dv(const GLdouble *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],1.0f);
}

GLAPI void APIENTRY glWindowPos3f(GLfloat x, GLfloat y, GLfloat z)
{
 glWindowPos4f((float)x,(float)y,(float)z,1.0f);
}

GLAPI void APIENTRY glWindowPos3fv(const GLfloat *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],1.0f);
}

GLAPI void APIENTRY glWindowPos3i(GLint x, GLint y, GLint z)
{
 glWindowPos4f((float)x,(float)y,(float)z,1.0f);
}

GLAPI void APIENTRY glWindowPos3iv(const GLint *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],1.0f);
}

GLAPI void APIENTRY glWindowPos3s(GLshort x, GLshort y, GLshort z)
{
 glWindowPos4f((float)x,(float)y,(float)z,1.0f);
}

GLAPI void APIENTRY glWindowPos3sv(const GLshort *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],1.0f);
}

GLAPI void APIENTRY glWindowPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
 glWindowPos4f((float)x,(float)y,(float)z,(float)w);
}

GLAPI void APIENTRY glWindowPos4dv(const GLdouble *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],(float)v[3]);
}

GLAPI void APIENTRY glWindowPos4fv(const GLfloat *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],(float)v[3]);
}

GLAPI void APIENTRY glWindowPos4i(GLint x, GLint y, GLint z, GLint w)
{
 glWindowPos4f((float)x,(float)y,(float)z,(float)w);
}

GLAPI void APIENTRY glWindowPos4iv(const GLint *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],(float)v[3]);
}

GLAPI void APIENTRY glWindowPos4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
 glWindowPos4f((float)x,(float)y,(float)z,(float)w);
}

GLAPI void APIENTRY glWindowPos4sv(const GLshort *v)
{
 glWindowPos4f((float)v[0],(float)v[1],(float)v[2],(float)v[3]);
}
