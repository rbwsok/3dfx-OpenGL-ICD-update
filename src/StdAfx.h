//#pragma comment(linker,"/FILEALIGN:512")


#define CHECKCONTEXT if (ctx.makecontext == GL_FALSE) return;
#define CHECKCONTEXTFALSE if (ctx.makecontext == GL_FALSE) return false;

#include <windows.h>
#include <windowsx.h>
#include <d3d8.h>
#include <d3dx8.h>
#include <gl/gl.h>
#include <gl/GLU.h>
#include <stdio.h>
#include "dynarray.h"
#include "d3dobject.h"
#include "d3ddevice.h"
#include "d3dsurf.h"
#include "glext.h"
#include "wglext.h"
#include "main.h"
#include "glget.h"
#include "log.h"
#include "multidrawarray.h"
#include "matrix.h"
#include "pixelformat.h"
#include "enable.h"
#include "multisample.h"
#include "winpos.h"
#include "vbo.h"
#include "gltex.h"
#include "vertex.h"


