#ifndef __MATRIX_H_
#define __MATRIX_H_

GLAPI void APIENTRY glLoadTransposeMatrixf (const GLfloat * m);
GLAPI void APIENTRY glLoadTransposeMatrixd (const GLdouble * m);
GLAPI void APIENTRY glMultTransposeMatrixf (const GLfloat * m);
GLAPI void APIENTRY glMultTransposeMatrixd (const GLdouble * m);

void _fastcall transpose_float (const float* src, float* dst);
void _fastcall transpose_double (const double* src, double* dst);
void _fastcall transpose_int (const int* src, int* dst);
void _fastcall transpose_GLboolean (const GLboolean* src, GLboolean* dst);


#endif

