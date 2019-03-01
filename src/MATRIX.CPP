//
// GL_ARB_transpose_matrix
//

#include "stdafx.h"

// транспонирование
void _fastcall transpose_float (const float* src, float* dst)
{
 dst[0] = src[0];
 dst[1] = src[4];
 dst[2] = src[8];
 dst[3] = src[12];
 dst[4] = src[1];
 dst[5] = src[5];
 dst[6] = src[9];
 dst[7] = src[13];
 dst[8] = src[2];
 dst[9] = src[6];
 dst[10] = src[10];
 dst[11] = src[14];
 dst[12] = src[3];
 dst[13] = src[7];
 dst[14] = src[11];
 dst[15] = src[15];
}

void _fastcall transpose_double (const double* src, double* dst)
{
 dst[0] = src[0];
 dst[1] = src[4];
 dst[2] = src[8];
 dst[3] = src[12];
 dst[4] = src[1];
 dst[5] = src[5];
 dst[6] = src[9];
 dst[7] = src[13];
 dst[8] = src[2];
 dst[9] = src[6];
 dst[10] = src[10];
 dst[11] = src[14];
 dst[12] = src[3];
 dst[13] = src[7];
 dst[14] = src[11];
 dst[15] = src[15];
}

void _fastcall transpose_int (const int* src, int* dst)
{
 dst[0] = src[0];
 dst[1] = src[4];
 dst[2] = src[8];
 dst[3] = src[12];
 dst[4] = src[1];
 dst[5] = src[5];
 dst[6] = src[9];
 dst[7] = src[13];
 dst[8] = src[2];
 dst[9] = src[6];
 dst[10] = src[10];
 dst[11] = src[14];
 dst[12] = src[3];
 dst[13] = src[7];
 dst[14] = src[11];
 dst[15] = src[15];
}

void _fastcall transpose_GLboolean (const GLboolean* src, GLboolean* dst)
{
 dst[0] = src[0];
 dst[1] = src[4];
 dst[2] = src[8];
 dst[3] = src[12];
 dst[4] = src[1];
 dst[5] = src[5];
 dst[6] = src[9];
 dst[7] = src[13];
 dst[8] = src[2];
 dst[9] = src[6];
 dst[10] = src[10];
 dst[11] = src[14];
 dst[12] = src[3];
 dst[13] = src[7];
 dst[14] = src[11];
 dst[15] = src[15];
}

GLAPI void APIENTRY glLoadTransposeMatrixf (const GLfloat * m)
{
 static float n[16];
 transpose_float(m,n);
 _glLoadMatrixf(n);
}

GLAPI void APIENTRY glLoadTransposeMatrixd (const GLdouble * m)
{
 static double n[16];
 transpose_double(m,n);
 _glLoadMatrixd(n);
}

GLAPI void APIENTRY glMultTransposeMatrixf (const GLfloat * m)
{
 static float n[16];
 transpose_float(m,n);
 _glMultMatrixf(n);
}

GLAPI void APIENTRY glMultTransposeMatrixd (const GLdouble * m)
{
 static double n[16];
 transpose_double(m,n);
 _glMultMatrixd(n);
}

GLAPI void APIENTRY new_glLoadIdentity (void)
{
 CHECKCONTEXT
 _glLoadIdentity();
}

GLAPI void APIENTRY new_glLoadMatrixd (const GLdouble *m)
{
 CHECKCONTEXT
 _glLoadMatrixd(m);
}

GLAPI void APIENTRY new_glLoadMatrixf (const GLfloat *m)
{
 CHECKCONTEXT
 _glLoadMatrixf(m);
}

GLAPI void APIENTRY new_glMatrixMode (GLenum mode)
{
 CHECKCONTEXT
 _glMatrixMode(mode);
}

GLAPI void APIENTRY new_glMultMatrixd (const GLdouble *m)
{
 CHECKCONTEXT
 _glMultMatrixd(m);
}

GLAPI void APIENTRY new_glMultMatrixf (const GLfloat *m)
{
 CHECKCONTEXT
 _glMultMatrixf(m);
}
