//
// GL_ARB_multisample
//

#include "stdafx.h"

GLAPI void APIENTRY glSampleCoverage(GLclampf value, GLboolean invert)
{
 CHECKCONTEXT
 ctx.ARB_multisample_invert = invert;
 ctx.ARB_multisample_value = value;
}
