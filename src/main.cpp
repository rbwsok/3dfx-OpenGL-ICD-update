#include "stdafx.h"

GLRBCONTEXT ctx;

#define EXTPATH1 "SOFTWARE\\Rainbow\\OpenGL_Control\\GLExtensions"
#define EXTPATH2 "SOFTWARE\\Rainbow\\OpenGL_Control\\WGLExtensions"
#define OPTPATH "SOFTWARE\\Rainbow\\OpenGL_Control\\Options"

bool GetPtrProcs(void);
void QueryRegOpt(void);

void InitContext(void)
{
 // признак создания GL контекста
 ctx.makecontext = GL_FALSE;

 // GL_ARB_multisample
 ctx.ARB_multisample_invert = GL_FALSE;
 ctx.ARB_multisample_value = 1;

 // GL_ARB_multisample
 ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB = GL_FALSE;
 ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB = GL_FALSE;
 ctx.gl_SAMPLE_COVERAGE_ARB = GL_FALSE;

 // GL_EXT_rescale_normal 
 ctx.gl_RESCALE_NORMAL_EXT = GL_FALSE;
 ctx.gl_NORMALIZE = GL_FALSE;

 // GL_ARB_point_sprite
 ctx.gl_POINT_SPRITE_ARB = GL_FALSE;

 // GL_NV_vertex_array_range
 ctx.gl_VERTEX_ARRAY_RANGE_NV = GL_FALSE;
 // GL_NV_vertex_array_range2
 ctx.gl_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV = GL_FALSE;
 // GL_NV_pixel_data_range
 ctx.gl_WRITE_PIXEL_DATA_RANGE_NV = GL_FALSE;
 ctx.gl_READ_PIXEL_DATA_RANGE_NV = GL_FALSE;

 // создание списка текстур
 ctx.textures = new DYNARRAY(32,sizeof(GLTEXTURE));
 // текущая текстура
 ctx.current_texture = 0;

 // GL_SGIS_generate_mipmap
 ctx.SGIS_generate_mipmaps_hint = GL_DONT_CARE;

 // GL_NV_multisample_filter_hint
 ctx.NV_multisample_filter_hint = GL_DONT_CARE;

}

HMODULE hglLib = 0;
BOOL APIENTRY DllMain( HANDLE hModule,DWORD ul_reason_for_call, LPVOID lpReserved)
{
 switch( ul_reason_for_call ) 
 {
  case DLL_PROCESS_DETACH:
       if (hglLib != 0) FreeLibrary(hglLib);
       break;
  case DLL_PROCESS_ATTACH:
	   if (GetPtrProcs() == false) return FALSE;
	   QueryRegOpt();
	   InitContext();	   
	   break;
  case DLL_THREAD_ATTACH:
       break;
  case DLL_THREAD_DETACH:
       break;
  default:
       break;
 }
 return TRUE;
}

PFNGLACCUMGLPROC _glAccum = NULL;
PFNGLALPHAFUNCGLPROC _glAlphaFunc = NULL;
PFNGLARETEXTURESRESIDENTGLPROC _glAreTexturesResident = NULL;
PFNGLARRAYELEMENTGLPROC _glArrayElement = NULL;
PFNGLBEGINGLPROC _glBegin = NULL;
PFNGLBINDTEXTUREGLPROC _glBindTexture = NULL;
PFNGLBITMAPGLPROC _glBitmap = NULL;
PFNGLBLENDFUNCGLPROC _glBlendFunc = NULL;
PFNGLCALLLISTGLPROC _glCallList = NULL;
PFNGLCALLLISTSGLPROC _glCallLists = NULL;
PFNGLCLEARGLPROC _glClear = NULL;
PFNGLCLEARACCUMGLPROC _glClearAccum = NULL;
PFNGLCLEARCOLORGLPROC _glClearColor = NULL;
PFNGLCLEARDEPTHGLPROC _glClearDepth = NULL;
PFNGLCLEARINDEXGLPROC _glClearIndex = NULL;
PFNGLCLEARSTENCILGLPROC _glClearStencil = NULL;
PFNGLCLIPPLANEGLPROC _glClipPlane = NULL;
PFNGLCOLOR3BGLPROC _glColor3b = NULL;
PFNGLCOLOR3BVGLPROC _glColor3bv = NULL;
PFNGLCOLOR3DGLPROC _glColor3d = NULL;
PFNGLCOLOR3DVGLPROC _glColor3dv = NULL;
PFNGLCOLOR3FGLPROC _glColor3f = NULL;
PFNGLCOLOR3FVGLPROC _glColor3fv = NULL;
PFNGLCOLOR3IGLPROC _glColor3i = NULL;
PFNGLCOLOR3IVGLPROC _glColor3iv = NULL;
PFNGLCOLOR3SGLPROC _glColor3s = NULL;
PFNGLCOLOR3SVGLPROC _glColor3sv = NULL;
PFNGLCOLOR3UBGLPROC _glColor3ub = NULL;
PFNGLCOLOR3UBVGLPROC _glColor3ubv = NULL;
PFNGLCOLOR3UIGLPROC _glColor3ui = NULL;
PFNGLCOLOR3UIVGLPROC _glColor3uiv = NULL;
PFNGLCOLOR3USGLPROC _glColor3us = NULL;
PFNGLCOLOR3USVGLPROC _glColor3usv = NULL;
PFNGLCOLOR4BGLPROC _glColor4b = NULL;
PFNGLCOLOR4BVGLPROC _glColor4bv = NULL;
PFNGLCOLOR4DGLPROC _glColor4d = NULL;
PFNGLCOLOR4DVGLPROC _glColor4dv = NULL;
PFNGLCOLOR4FGLPROC _glColor4f = NULL;
PFNGLCOLOR4FVGLPROC _glColor4fv = NULL;
PFNGLCOLOR4IGLPROC _glColor4i = NULL;
PFNGLCOLOR4IVGLPROC _glColor4iv = NULL;
PFNGLCOLOR4SGLPROC _glColor4s = NULL;
PFNGLCOLOR4SVGLPROC _glColor4sv = NULL;
PFNGLCOLOR4UBGLPROC _glColor4ub = NULL;
PFNGLCOLOR4UBVGLPROC _glColor4ubv = NULL;
PFNGLCOLOR4UIGLPROC _glColor4ui = NULL;
PFNGLCOLOR4UIVGLPROC _glColor4uiv = NULL;
PFNGLCOLOR4USGLPROC _glColor4us = NULL;
PFNGLCOLOR4USVGLPROC _glColor4usv = NULL;
PFNGLCOLORMASKGLPROC _glColorMask = NULL;
PFNGLCOLORMATERIALGLPROC _glColorMaterial = NULL;
PFNGLCOLORPOINTERGLPROC _glColorPointer = NULL;
PFNGLCOPYPIXELSGLPROC _glCopyPixels = NULL;
PFNGLCOPYTEXIMAGE1DGLPROC _glCopyTexImage1D = NULL;
PFNGLCOPYTEXIMAGE2DGLPROC _glCopyTexImage2D = NULL;
PFNGLCOPYTEXSUBIMAGE1DGLPROC _glCopyTexSubImage1D = NULL;
PFNGLCOPYTEXSUBIMAGE2DGLPROC _glCopyTexSubImage2D = NULL;
PFNGLCULLFACEGLPROC _glCullFace = NULL;
PFNGLDELETELISTSGLPROC _glDeleteLists = NULL;
PFNGLDELETETEXTURESGLPROC _glDeleteTextures = NULL;
PFNGLDEPTHFUNCGLPROC _glDepthFunc = NULL;
PFNGLDEPTHMASKGLPROC _glDepthMask = NULL;
PFNGLDEPTHRANGEGLPROC _glDepthRange = NULL;
PFNGLDISABLEGLPROC _glDisable = NULL;
PFNGLDISABLECLIENTSTATEGLPROC _glDisableClientState = NULL;
PFNGLDRAWARRAYSGLPROC _glDrawArrays = NULL;
PFNGLDRAWBUFFERGLPROC _glDrawBuffer = NULL;
PFNGLDRAWELEMENTSGLPROC _glDrawElements = NULL;
PFNGLDRAWPIXELSGLPROC _glDrawPixels = NULL;
PFNGLEDGEFLAGGLPROC _glEdgeFlag = NULL;
PFNGLEDGEFLAGPOINTERGLPROC _glEdgeFlagPointer = NULL;
PFNGLEDGEFLAGVGLPROC _glEdgeFlagv = NULL;
PFNGLENABLEGLPROC _glEnable = NULL;
PFNGLENABLECLIENTSTATEGLPROC _glEnableClientState = NULL;
PFNGLENDGLPROC _glEnd = NULL;
PFNGLENDLISTGLPROC _glEndList = NULL;
PFNGLEVALCOORD1DGLPROC _glEvalCoord1d = NULL;
PFNGLEVALCOORD1DVGLPROC _glEvalCoord1dv = NULL;
PFNGLEVALCOORD1FGLPROC _glEvalCoord1f = NULL;
PFNGLEVALCOORD1FVGLPROC _glEvalCoord1fv = NULL;
PFNGLEVALCOORD2DGLPROC _glEvalCoord2d = NULL;
PFNGLEVALCOORD2DVGLPROC _glEvalCoord2dv = NULL;
PFNGLEVALCOORD2FGLPROC _glEvalCoord2f = NULL;
PFNGLEVALCOORD2FVGLPROC _glEvalCoord2fv = NULL;
PFNGLEVALMESH1GLPROC _glEvalMesh1 = NULL;
PFNGLEVALMESH2GLPROC _glEvalMesh2 = NULL;
PFNGLEVALPOINT1GLPROC _glEvalPoint1 = NULL;
PFNGLEVALPOINT2GLPROC _glEvalPoint2 = NULL;
PFNGLFEEDBACKBUFFERGLPROC _glFeedbackBuffer = NULL;
PFNGLFINISHGLPROC _glFinish = NULL;
PFNGLFLUSHGLPROC _glFlush = NULL;
PFNGLFOGFGLPROC _glFogf = NULL;
PFNGLFOGFVGLPROC _glFogfv = NULL;
PFNGLFOGIGLPROC _glFogi = NULL;
PFNGLFOGIVGLPROC _glFogiv = NULL;
PFNGLFRONTFACEGLPROC _glFrontFace = NULL;
PFNGLFRUSTUMGLPROC _glFrustum = NULL;
PFNGLGENLISTSGLPROC _glGenLists = NULL;
PFNGLGENTEXTURESGLPROC _glGenTextures = NULL;
PFNGLGETBOOLEANVGLPROC _glGetBooleanv = NULL;
PFNGLGETCLIPPLANEGLPROC _glGetClipPlane = NULL;
PFNGLGETDOUBLEVGLPROC _glGetDoublev = NULL;
PFNGLGETERRORGLPROC _glGetError = NULL;
PFNGLGETFLOATVGLPROC _glGetFloatv = NULL;
PFNGLGETINTEGERVGLPROC _glGetIntegerv = NULL;
PFNGLGETLIGHTFVGLPROC _glGetLightfv = NULL;
PFNGLGETLIGHTIVGLPROC _glGetLightiv = NULL;
PFNGLGETMAPDVGLPROC _glGetMapdv = NULL;
PFNGLGETMAPFVGLPROC _glGetMapfv = NULL;
PFNGLGETMAPIVGLPROC _glGetMapiv = NULL;
PFNGLGETMATERIALFVGLPROC _glGetMaterialfv = NULL;
PFNGLGETMATERIALIVGLPROC _glGetMaterialiv = NULL;
PFNGLGETPIXELMAPFVGLPROC _glGetPixelMapfv = NULL;
PFNGLGETPIXELMAPUIVGLPROC _glGetPixelMapuiv = NULL;
PFNGLGETPIXELMAPUSVGLPROC _glGetPixelMapusv = NULL;
PFNGLGETPOINTERVGLPROC _glGetPointerv = NULL;
PFNGLGETPOLYGONSTIPPLEGLPROC _glGetPolygonStipple = NULL;
PFNGLGETSTRINGGLPROC _glGetString = NULL;
PFNGLGETTEXENVFVGLPROC _glGetTexEnvfv = NULL;
PFNGLGETTEXENVIVGLPROC _glGetTexEnviv = NULL;
PFNGLGETTEXGENDVGLPROC _glGetTexGendv = NULL;
PFNGLGETTEXGENFVGLPROC _glGetTexGenfv = NULL;
PFNGLGETTEXGENIVGLPROC _glGetTexGeniv = NULL;
PFNGLGETTEXIMAGEGLPROC _glGetTexImage = NULL;
PFNGLGETTEXLEVELPARAMETERFVGLPROC _glGetTexLevelParameterfv = NULL;
PFNGLGETTEXLEVELPARAMETERIVGLPROC _glGetTexLevelParameteriv = NULL;
PFNGLGETTEXPARAMETERFVGLPROC _glGetTexParameterfv = NULL;
PFNGLGETTEXPARAMETERIVGLPROC _glGetTexParameteriv = NULL;
PFNGLHINTGLPROC _glHint = NULL;
PFNGLINDEXMASKGLPROC _glIndexMask = NULL;
PFNGLINDEXPOINTERGLPROC _glIndexPointer = NULL;
PFNGLINDEXDGLPROC _glIndexd = NULL;
PFNGLINDEXDVGLPROC _glIndexdv = NULL;
PFNGLINDEXFGLPROC _glIndexf = NULL;
PFNGLINDEXFVGLPROC _glIndexfv = NULL;
PFNGLINDEXIGLPROC _glIndexi = NULL;
PFNGLINDEXIVGLPROC _glIndexiv = NULL;
PFNGLINDEXSGLPROC _glIndexs = NULL;
PFNGLINDEXSVGLPROC _glIndexsv = NULL;
PFNGLINDEXUBGLPROC _glIndexub = NULL;
PFNGLINDEXUBVGLPROC _glIndexubv = NULL;
PFNGLINITNAMESGLPROC _glInitNames = NULL;
PFNGLINTERLEAVEDARRAYSGLPROC _glInterleavedArrays = NULL;
PFNGLISENABLEDGLPROC _glIsEnabled = NULL;
PFNGLISLISTGLPROC _glIsList = NULL;
PFNGLISTEXTUREGLPROC _glIsTexture = NULL;
PFNGLLIGHTMODELFGLPROC _glLightModelf = NULL;
PFNGLLIGHTMODELFVGLPROC _glLightModelfv = NULL;
PFNGLLIGHTMODELIGLPROC _glLightModeli = NULL;
PFNGLLIGHTMODELIVGLPROC _glLightModeliv = NULL;
PFNGLLIGHTFGLPROC _glLightf = NULL;
PFNGLLIGHTFVGLPROC _glLightfv = NULL;
PFNGLLIGHTIGLPROC _glLighti = NULL;
PFNGLLIGHTIVGLPROC _glLightiv = NULL;
PFNGLLINESTIPPLEGLPROC _glLineStipple = NULL;
PFNGLLINEWIDTHGLPROC _glLineWidth = NULL;
PFNGLLISTBASEGLPROC _glListBase = NULL;
PFNGLLOADIDENTITYGLPROC _glLoadIdentity = NULL;
PFNGLLOADMATRIXDGLPROC _glLoadMatrixd = NULL;
PFNGLLOADMATRIXFGLPROC _glLoadMatrixf = NULL;
PFNGLLOADNAMEGLPROC _glLoadName = NULL;
PFNGLLOGICOPGLPROC _glLogicOp = NULL;
PFNGLMAP1DGLPROC _glMap1d = NULL;
PFNGLMAP1FGLPROC _glMap1f = NULL;
PFNGLMAP2DGLPROC _glMap2d = NULL;
PFNGLMAP2FGLPROC _glMap2f = NULL;
PFNGLMAPGRID1DGLPROC _glMapGrid1d = NULL;
PFNGLMAPGRID1FGLPROC _glMapGrid1f = NULL;
PFNGLMAPGRID2DGLPROC _glMapGrid2d = NULL;
PFNGLMAPGRID2FGLPROC _glMapGrid2f = NULL;
PFNGLMATERIALFGLPROC _glMaterialf = NULL;
PFNGLMATERIALFVGLPROC _glMaterialfv = NULL;
PFNGLMATERIALIGLPROC _glMateriali = NULL;
PFNGLMATERIALIVGLPROC _glMaterialiv = NULL;
PFNGLMATRIXMODEGLPROC _glMatrixMode = NULL;
PFNGLMULTMATRIXDGLPROC _glMultMatrixd = NULL;
PFNGLMULTMATRIXFGLPROC _glMultMatrixf = NULL;
PFNGLNEWLISTGLPROC _glNewList = NULL;
PFNGLNORMAL3BGLPROC _glNormal3b = NULL;
PFNGLNORMAL3BVGLPROC _glNormal3bv = NULL;
PFNGLNORMAL3DGLPROC _glNormal3d = NULL;
PFNGLNORMAL3DVGLPROC _glNormal3dv = NULL;
PFNGLNORMAL3FGLPROC _glNormal3f = NULL;
PFNGLNORMAL3FVGLPROC _glNormal3fv = NULL;
PFNGLNORMAL3IGLPROC _glNormal3i = NULL;
PFNGLNORMAL3IVGLPROC _glNormal3iv = NULL;
PFNGLNORMAL3SGLPROC _glNormal3s = NULL;
PFNGLNORMAL3SVGLPROC _glNormal3sv = NULL;
PFNGLNORMALPOINTERGLPROC _glNormalPointer = NULL;
PFNGLORTHOGLPROC _glOrtho = NULL;
PFNGLPASSTHROUGHGLPROC _glPassThrough = NULL;
PFNGLPIXELMAPFVGLPROC _glPixelMapfv = NULL;
PFNGLPIXELMAPUIVGLPROC _glPixelMapuiv = NULL;
PFNGLPIXELMAPUSVGLPROC _glPixelMapusv = NULL;
PFNGLPIXELSTOREFGLPROC _glPixelStoref = NULL;
PFNGLPIXELSTOREIGLPROC _glPixelStorei = NULL;
PFNGLPIXELTRANSFERFGLPROC _glPixelTransferf = NULL;
PFNGLPIXELTRANSFERIGLPROC _glPixelTransferi = NULL;
PFNGLPIXELZOOMGLPROC _glPixelZoom = NULL;
PFNGLPOINTSIZEGLPROC _glPointSize = NULL;
PFNGLPOLYGONMODEGLPROC _glPolygonMode = NULL;
PFNGLPOLYGONOFFSETGLPROC _glPolygonOffset = NULL;
PFNGLPOLYGONSTIPPLEGLPROC _glPolygonStipple = NULL;
PFNGLPOPATTRIBGLPROC _glPopAttrib = NULL;
PFNGLPOPCLIENTATTRIBGLPROC _glPopClientAttrib = NULL;
PFNGLPOPMATRIXGLPROC _glPopMatrix = NULL;
PFNGLPOPNAMEGLPROC _glPopName = NULL;
PFNGLPRIORITIZETEXTURESGLPROC _glPrioritizeTextures = NULL;
PFNGLPUSHATTRIBGLPROC _glPushAttrib = NULL;
PFNGLPUSHCLIENTATTRIBGLPROC _glPushClientAttrib = NULL;
PFNGLPUSHMATRIXGLPROC _glPushMatrix = NULL;
PFNGLPUSHNAMEGLPROC _glPushName = NULL;
PFNGLRASTERPOS2DGLPROC _glRasterPos2d = NULL;
PFNGLRASTERPOS2DVGLPROC _glRasterPos2dv = NULL;
PFNGLRASTERPOS2FGLPROC _glRasterPos2f = NULL;
PFNGLRASTERPOS2FVGLPROC _glRasterPos2fv = NULL;
PFNGLRASTERPOS2IGLPROC _glRasterPos2i = NULL;
PFNGLRASTERPOS2IVGLPROC _glRasterPos2iv = NULL;
PFNGLRASTERPOS2SGLPROC _glRasterPos2s = NULL;
PFNGLRASTERPOS2SVGLPROC _glRasterPos2sv = NULL;
PFNGLRASTERPOS3DGLPROC _glRasterPos3d = NULL;
PFNGLRASTERPOS3DVGLPROC _glRasterPos3dv = NULL;
PFNGLRASTERPOS3FGLPROC _glRasterPos3f = NULL;
PFNGLRASTERPOS3FVGLPROC _glRasterPos3fv = NULL;
PFNGLRASTERPOS3IGLPROC _glRasterPos3i = NULL;
PFNGLRASTERPOS3IVGLPROC _glRasterPos3iv = NULL;
PFNGLRASTERPOS3SGLPROC _glRasterPos3s = NULL;
PFNGLRASTERPOS3SVGLPROC _glRasterPos3sv = NULL;
PFNGLRASTERPOS4DGLPROC _glRasterPos4d = NULL;
PFNGLRASTERPOS4DVGLPROC _glRasterPos4dv = NULL;
PFNGLRASTERPOS4FGLPROC _glRasterPos4f = NULL;
PFNGLRASTERPOS4FVGLPROC _glRasterPos4fv = NULL;
PFNGLRASTERPOS4IGLPROC _glRasterPos4i = NULL;
PFNGLRASTERPOS4IVGLPROC _glRasterPos4iv = NULL;
PFNGLRASTERPOS4SGLPROC _glRasterPos4s = NULL;
PFNGLRASTERPOS4SVGLPROC _glRasterPos4sv = NULL;
PFNGLREADBUFFERGLPROC _glReadBuffer = NULL;
PFNGLREADPIXELSGLPROC _glReadPixels = NULL;
PFNGLRECTDGLPROC _glRectd = NULL;
PFNGLRECTDVGLPROC _glRectdv = NULL;
PFNGLRECTFGLPROC _glRectf = NULL;
PFNGLRECTFVGLPROC _glRectfv = NULL;
PFNGLRECTIGLPROC _glRecti = NULL;
PFNGLRECTIVGLPROC _glRectiv = NULL;
PFNGLRECTSGLPROC _glRects = NULL;
PFNGLRECTSVGLPROC _glRectsv = NULL;
PFNGLRENDERMODEGLPROC _glRenderMode = NULL;
PFNGLROTATEDGLPROC _glRotated = NULL;
PFNGLROTATEFGLPROC _glRotatef = NULL;
PFNGLSCALEDGLPROC _glScaled = NULL;
PFNGLSCALEFGLPROC _glScalef = NULL;
PFNGLSCISSORGLPROC _glScissor = NULL;
PFNGLSELECTBUFFERGLPROC _glSelectBuffer = NULL;
PFNGLSHADEMODELGLPROC _glShadeModel = NULL;
PFNGLSTENCILFUNCGLPROC _glStencilFunc = NULL;
PFNGLSTENCILMASKGLPROC _glStencilMask = NULL;
PFNGLSTENCILOPGLPROC _glStencilOp = NULL;
PFNGLTEXCOORD1DGLPROC _glTexCoord1d = NULL;
PFNGLTEXCOORD1DVGLPROC _glTexCoord1dv = NULL;
PFNGLTEXCOORD1FGLPROC _glTexCoord1f = NULL;
PFNGLTEXCOORD1FVGLPROC _glTexCoord1fv = NULL;
PFNGLTEXCOORD1IGLPROC _glTexCoord1i = NULL;
PFNGLTEXCOORD1IVGLPROC _glTexCoord1iv = NULL;
PFNGLTEXCOORD1SGLPROC _glTexCoord1s = NULL;
PFNGLTEXCOORD1SVGLPROC _glTexCoord1sv = NULL;
PFNGLTEXCOORD2DGLPROC _glTexCoord2d = NULL;
PFNGLTEXCOORD2DVGLPROC _glTexCoord2dv = NULL;
PFNGLTEXCOORD2FGLPROC _glTexCoord2f = NULL;
PFNGLTEXCOORD2FVGLPROC _glTexCoord2fv = NULL;
PFNGLTEXCOORD2IGLPROC _glTexCoord2i = NULL;
PFNGLTEXCOORD2IVGLPROC _glTexCoord2iv = NULL;
PFNGLTEXCOORD2SGLPROC _glTexCoord2s = NULL;
PFNGLTEXCOORD2SVGLPROC _glTexCoord2sv = NULL;
PFNGLTEXCOORD3DGLPROC _glTexCoord3d = NULL;
PFNGLTEXCOORD3DVGLPROC _glTexCoord3dv = NULL;
PFNGLTEXCOORD3FGLPROC _glTexCoord3f = NULL;
PFNGLTEXCOORD3FVGLPROC _glTexCoord3fv = NULL;
PFNGLTEXCOORD3IGLPROC _glTexCoord3i = NULL;
PFNGLTEXCOORD3IVGLPROC _glTexCoord3iv = NULL;
PFNGLTEXCOORD3SGLPROC _glTexCoord3s = NULL;
PFNGLTEXCOORD3SVGLPROC _glTexCoord3sv = NULL;
PFNGLTEXCOORD4DGLPROC _glTexCoord4d = NULL;
PFNGLTEXCOORD4DVGLPROC _glTexCoord4dv = NULL;
PFNGLTEXCOORD4FGLPROC _glTexCoord4f = NULL;
PFNGLTEXCOORD4FVGLPROC _glTexCoord4fv = NULL;
PFNGLTEXCOORD4IGLPROC _glTexCoord4i = NULL;
PFNGLTEXCOORD4IVGLPROC _glTexCoord4iv = NULL;
PFNGLTEXCOORD4SGLPROC _glTexCoord4s = NULL;
PFNGLTEXCOORD4SVGLPROC _glTexCoord4sv = NULL;
PFNGLTEXCOORDPOINTERGLPROC _glTexCoordPointer = NULL;
PFNGLTEXENVFGLPROC _glTexEnvf = NULL;
PFNGLTEXENVFVGLPROC _glTexEnvfv = NULL;
PFNGLTEXENVIGLPROC _glTexEnvi = NULL;
PFNGLTEXENVIVGLPROC _glTexEnviv = NULL;
PFNGLTEXGENDGLPROC _glTexGend = NULL;
PFNGLTEXGENDVGLPROC _glTexGendv = NULL;
PFNGLTEXGENFGLPROC _glTexGenf = NULL;
PFNGLTEXGENFVGLPROC _glTexGenfv = NULL;
PFNGLTEXGENIGLPROC _glTexGeni = NULL;
PFNGLTEXGENIVGLPROC _glTexGeniv = NULL;
PFNGLTEXIMAGE1DGLPROC _glTexImage1D = NULL;
PFNGLTEXIMAGE2DGLPROC _glTexImage2D = NULL;
PFNGLTEXPARAMETERFGLPROC _glTexParameterf = NULL;
PFNGLTEXPARAMETERFVGLPROC _glTexParameterfv = NULL;
PFNGLTEXPARAMETERIGLPROC _glTexParameteri = NULL;
PFNGLTEXPARAMETERIVGLPROC _glTexParameteriv = NULL;
PFNGLTEXSUBIMAGE1DGLPROC _glTexSubImage1D = NULL;
PFNGLTEXSUBIMAGE2DGLPROC _glTexSubImage2D = NULL;
PFNGLTRANSLATEDGLPROC _glTranslated = NULL;
PFNGLTRANSLATEFGLPROC _glTranslatef = NULL;
PFNGLVERTEX2DGLPROC _glVertex2d = NULL;
PFNGLVERTEX2DVGLPROC _glVertex2dv = NULL;
PFNGLVERTEX2FGLPROC _glVertex2f = NULL;
PFNGLVERTEX2FVGLPROC _glVertex2fv = NULL;
PFNGLVERTEX2IGLPROC _glVertex2i = NULL;
PFNGLVERTEX2IVGLPROC _glVertex2iv = NULL;
PFNGLVERTEX2SGLPROC _glVertex2s = NULL;
PFNGLVERTEX2SVGLPROC _glVertex2sv = NULL;
PFNGLVERTEX3DGLPROC _glVertex3d = NULL;
PFNGLVERTEX3DVGLPROC _glVertex3dv = NULL;
PFNGLVERTEX3FGLPROC _glVertex3f = NULL;
PFNGLVERTEX3FVGLPROC _glVertex3fv = NULL;
PFNGLVERTEX3IGLPROC _glVertex3i = NULL;
PFNGLVERTEX3IVGLPROC _glVertex3iv = NULL;
PFNGLVERTEX3SGLPROC _glVertex3s = NULL;
PFNGLVERTEX3SVGLPROC _glVertex3sv = NULL;
PFNGLVERTEX4DGLPROC _glVertex4d = NULL;
PFNGLVERTEX4DVGLPROC _glVertex4dv = NULL;
PFNGLVERTEX4FGLPROC _glVertex4f = NULL;
PFNGLVERTEX4FVGLPROC _glVertex4fv = NULL;
PFNGLVERTEX4IGLPROC _glVertex4i = NULL;
PFNGLVERTEX4IVGLPROC _glVertex4iv = NULL;
PFNGLVERTEX4SGLPROC _glVertex4s = NULL;
PFNGLVERTEX4SVGLPROC _glVertex4sv = NULL;
PFNGLVERTEXPOINTERGLPROC _glVertexPointer = NULL;
PFNGLVIEWPORTGLPROC _glViewport = NULL;
PFNWGLUSEFONTOUTLINESAGLPROC _wglUseFontOutlinesA = NULL;
PFNWGLUSEFONTOUTLINESWGLPROC _wglUseFontOutlinesW = NULL;
PFNWGLUSEFONTBITMAPSAGLPROC _wglUseFontBitmapsA = NULL;
PFNWGLUSEFONTBITMAPSWGLPROC _wglUseFontBitmapsW = NULL;
PFNWGLCOPYCONTEXTGLPROC _wglCopyContext = NULL;
PFNWGLCREATECONTEXTGLPROC _wglCreateContext = NULL;
PFNWGLCREATELAYERCONTEXTGLPROC _wglCreateLayerContext = NULL;
PFNWGLDELETECONTEXTGLPROC _wglDeleteContext = NULL;
PFNWGLGETCURRENTCONTEXTGLPROC _wglGetCurrentContext = NULL;
PFNWGLGETCURRENTDCGLPROC _wglGetCurrentDC = NULL;
PFNWGLGETPROCADDRESSGLPROC _wglGetProcAddress = NULL;
PFNWGLMAKECURRENTGLPROC _wglMakeCurrent = NULL;
PFNWGLSHARELISTSGLPROC _wglShareLists = NULL;
PFNWGLDESCRIBELAYERPLANEGLPROC _wglDescribeLayerPlane = NULL;
PFNWGLSETLAYERPALETTEENTRIESGLPROC _wglSetLayerPaletteEntries = NULL;
PFNWGLGETLAYERPALETTEENTRIESGLPROC _wglGetLayerPaletteEntries = NULL;
PFNWGLREALIZELAYERPALETTEGLPROC _wglRealizeLayerPalette = NULL;
PFNWGLSWAPLAYERBUFFERSGLPROC _wglSwapLayerBuffers = NULL;
PFNWGLCHOOSEPIXELFORMATGLPROC _wglChoosePixelFormat = NULL;
PFNWGLDESCRIBEPIXELFORMATGLPROC _wglDescribePixelFormat = NULL;
PFNWGLGETPIXELFORMATGLPROC _wglGetPixelFormat = NULL;
PFNWGLSETPIXELFORMATGLPROC _wglSetPixelFormat = NULL;
PFNWGLSWAPBUFFERSGLPROC _wglSwapBuffers = NULL;
PFNWGLGETDEFAULTPROCADDRESSGLPROC _wglGetDefaultProcAddress = NULL;
PFNDRVCOPYCONTEXTGLPROC _DrvCopyContext = NULL;
PFNDRVCREATECONTEXTGLPROC _DrvCreateContext = NULL;
PFNDRVCREATELAYERCONTEXTGLPROC _DrvCreateLayerContext = NULL;
PFNDRVDELETECONTEXTGLPROC _DrvDeleteContext = NULL;
PFNDRVDESCRIBELAYERPLANEGLPROC _DrvDescribeLayerPlane = NULL;
PFNDRVDESCRIBEPIXELFORMATGLPROC _DrvDescribePixelFormat = NULL;
PFNDRVSETLAYERPALETTEENTRIESGLPROC _DrvSetLayerPaletteEntries = NULL;
PFNDRVGETLAYERPALETTEENTRIESGLPROC _DrvGetLayerPaletteEntries = NULL;
PFNDRVREALIZELAYERPALETTEGLPROC _DrvRealizeLayerPalette = NULL;
PFNDRVSWAPLAYERBUFFERSGLPROC _DrvSwapLayerBuffers = NULL;
PFNDRVSHARELISTSGLPROC _DrvShareLists = NULL;
PFNDRVSETPIXELFORMATGLPROC _DrvSetPixelFormat = NULL;
PFNDRVSWAPBUFFERSGLPROC _DrvSwapBuffers = NULL;
PFNDRVGETPROCADDRESSGLPROC _DrvGetProcAddress = NULL;
PFNDRVSETCONTEXTGLPROC _DrvSetContext = NULL;
PFNDRVRELEASECONTEXTGLPROC _DrvReleaseContext = NULL;
PFNDRVVALIDATEVERSIONGLPROC _DrvValidateVersion = NULL;

bool GetPtrProcs(void)
{
 hglLib = LoadLibrary("3dfxicd.dll");
 if (hglLib == 0)
 {
  hglLib = LoadLibrary("3dfxogl.dll");
  if (hglLib == 0)
  {
   hglLib = LoadLibrary("3dfxvgl.dll");
   if (hglLib == 0) return false;  
  }
 }

 (FARPROC &)_glAccum = GetProcAddress(hglLib,"glAccum");
 if (_glAccum == NULL) return false;
 (FARPROC &)_glAlphaFunc = GetProcAddress(hglLib,"glAlphaFunc");
 if (_glAlphaFunc == NULL) return false;
 (FARPROC &)_glAreTexturesResident = GetProcAddress(hglLib,"glAreTexturesResident");
 if (_glAreTexturesResident == NULL) return false;
 (FARPROC &)_glArrayElement = GetProcAddress(hglLib,"glArrayElement");
 if (_glArrayElement == NULL) return false;
 (FARPROC &)_glBegin = GetProcAddress(hglLib,"glBegin");
 if (_glBegin == NULL) return false;
 (FARPROC &)_glBindTexture = GetProcAddress(hglLib,"glBindTexture");
 if (_glBindTexture == NULL) return false;
 (FARPROC &)_glBitmap = GetProcAddress(hglLib,"glBitmap");
 if (_glBitmap == NULL) return false;
 (FARPROC &)_glBlendFunc = GetProcAddress(hglLib,"glBlendFunc");
 if (_glBlendFunc == NULL) return false;
 (FARPROC &)_glCallList = GetProcAddress(hglLib,"glCallList");
 if (_glCallList == NULL) return false;
 (FARPROC &)_glCallLists = GetProcAddress(hglLib,"glCallLists");
 if (_glCallLists == NULL) return false;
 (FARPROC &)_glClear = GetProcAddress(hglLib,"glClear");
 if (_glClear == NULL) return false;
 (FARPROC &)_glClearAccum = GetProcAddress(hglLib,"glClearAccum");
 if (_glClearAccum == NULL) return false;
 (FARPROC &)_glClearColor = GetProcAddress(hglLib,"glClearColor");
 if (_glClearColor == NULL) return false;
 (FARPROC &)_glClearDepth = GetProcAddress(hglLib,"glClearDepth");
 if (_glClearDepth == NULL) return false;
 (FARPROC &)_glClearIndex = GetProcAddress(hglLib,"glClearIndex");
 if (_glClearIndex == NULL) return false;
 (FARPROC &)_glClearStencil = GetProcAddress(hglLib,"glClearStencil");
 if (_glClearStencil == NULL) return false;
 (FARPROC &)_glClipPlane = GetProcAddress(hglLib,"glClipPlane");
 if (_glClipPlane == NULL) return false;
 (FARPROC &)_glColor3b = GetProcAddress(hglLib,"glColor3b");
 if (_glColor3b == NULL) return false;
 (FARPROC &)_glColor3bv = GetProcAddress(hglLib,"glColor3bv");
 if (_glColor3bv == NULL) return false;
 (FARPROC &)_glColor3d = GetProcAddress(hglLib,"glColor3d");
 if (_glColor3d == NULL) return false;
 (FARPROC &)_glColor3dv = GetProcAddress(hglLib,"glColor3dv");
 if (_glColor3dv == NULL) return false;
 (FARPROC &)_glColor3f = GetProcAddress(hglLib,"glColor3f");
 if (_glColor3f == NULL) return false;
 (FARPROC &)_glColor3fv = GetProcAddress(hglLib,"glColor3fv");
 if (_glColor3fv == NULL) return false;
 (FARPROC &)_glColor3i = GetProcAddress(hglLib,"glColor3i");
 if (_glColor3i == NULL) return false;
 (FARPROC &)_glColor3iv = GetProcAddress(hglLib,"glColor3iv");
 if (_glColor3iv == NULL) return false;
 (FARPROC &)_glColor3s = GetProcAddress(hglLib,"glColor3s");
 if (_glColor3s == NULL) return false;
 (FARPROC &)_glColor3sv = GetProcAddress(hglLib,"glColor3sv");
 if (_glColor3sv == NULL) return false;
 (FARPROC &)_glColor3ub = GetProcAddress(hglLib,"glColor3ub");
 if (_glColor3ub == NULL) return false;
 (FARPROC &)_glColor3ubv = GetProcAddress(hglLib,"glColor3ubv");
 if (_glColor3ubv == NULL) return false;
 (FARPROC &)_glColor3ui = GetProcAddress(hglLib,"glColor3ui");
 if (_glColor3ui == NULL) return false;
 (FARPROC &)_glColor3uiv = GetProcAddress(hglLib,"glColor3uiv");
 if (_glColor3uiv == NULL) return false;
 (FARPROC &)_glColor3us = GetProcAddress(hglLib,"glColor3us");
 if (_glColor3us == NULL) return false;
 (FARPROC &)_glColor3usv = GetProcAddress(hglLib,"glColor3usv");
 if (_glColor3usv == NULL) return false;
 (FARPROC &)_glColor4b = GetProcAddress(hglLib,"glColor4b");
 if (_glColor4b == NULL) return false;
 (FARPROC &)_glColor4bv = GetProcAddress(hglLib,"glColor4bv");
 if (_glColor4bv == NULL) return false;
 (FARPROC &)_glColor4d = GetProcAddress(hglLib,"glColor4d");
 if (_glColor4d == NULL) return false;
 (FARPROC &)_glColor4dv = GetProcAddress(hglLib,"glColor4dv");
 if (_glColor4dv == NULL) return false;
 (FARPROC &)_glColor4f = GetProcAddress(hglLib,"glColor4f");
 if (_glColor4f == NULL) return false;
 (FARPROC &)_glColor4fv = GetProcAddress(hglLib,"glColor4fv");
 if (_glColor4fv == NULL) return false;
 (FARPROC &)_glColor4i = GetProcAddress(hglLib,"glColor4i");
 if (_glColor4i == NULL) return false;
 (FARPROC &)_glColor4iv = GetProcAddress(hglLib,"glColor4iv");
 if (_glColor4iv == NULL) return false;
 (FARPROC &)_glColor4s = GetProcAddress(hglLib,"glColor4s");
 if (_glColor4s == NULL) return false;
 (FARPROC &)_glColor4sv = GetProcAddress(hglLib,"glColor4sv");
 if (_glColor4sv == NULL) return false;
 (FARPROC &)_glColor4ub = GetProcAddress(hglLib,"glColor4ub");
 if (_glColor4ub == NULL) return false;
 (FARPROC &)_glColor4ubv = GetProcAddress(hglLib,"glColor4ubv");
 if (_glColor4ubv == NULL) return false;
 (FARPROC &)_glColor4ui = GetProcAddress(hglLib,"glColor4ui");
 if (_glColor4ui == NULL) return false;
 (FARPROC &)_glColor4uiv = GetProcAddress(hglLib,"glColor4uiv");
 if (_glColor4uiv == NULL) return false;
 (FARPROC &)_glColor4us = GetProcAddress(hglLib,"glColor4us");
 if (_glColor4us == NULL) return false;
 (FARPROC &)_glColor4usv = GetProcAddress(hglLib,"glColor4usv");
 if (_glColor4usv == NULL) return false;
 (FARPROC &)_glColorMask = GetProcAddress(hglLib,"glColorMask");
 if (_glColorMask == NULL) return false;
 (FARPROC &)_glColorMaterial = GetProcAddress(hglLib,"glColorMaterial");
 if (_glColorMaterial == NULL) return false;
 (FARPROC &)_glColorPointer = GetProcAddress(hglLib,"glColorPointer");
 if (_glColorPointer == NULL) return false;
 (FARPROC &)_glCopyPixels = GetProcAddress(hglLib,"glCopyPixels");
 if (_glCopyPixels == NULL) return false;
 (FARPROC &)_glCopyTexImage1D = GetProcAddress(hglLib,"glCopyTexImage1D");
 if (_glCopyTexImage1D == NULL) return false;
 (FARPROC &)_glCopyTexImage2D = GetProcAddress(hglLib,"glCopyTexImage2D");
 if (_glCopyTexImage2D == NULL) return false;
 (FARPROC &)_glCopyTexSubImage1D = GetProcAddress(hglLib,"glCopyTexSubImage1D");
 if (_glCopyTexSubImage1D == NULL) return false;
 (FARPROC &)_glCopyTexSubImage2D = GetProcAddress(hglLib,"glCopyTexSubImage2D");
 if (_glCopyTexSubImage2D == NULL) return false;
 (FARPROC &)_glCullFace = GetProcAddress(hglLib,"glCullFace");
 if (_glCullFace == NULL) return false;
 (FARPROC &)_glDeleteLists = GetProcAddress(hglLib,"glDeleteLists");
 if (_glDeleteLists == NULL) return false;
 (FARPROC &)_glDeleteTextures = GetProcAddress(hglLib,"glDeleteTextures");
 if (_glDeleteTextures == NULL) return false;
 (FARPROC &)_glDepthFunc = GetProcAddress(hglLib,"glDepthFunc");
 if (_glDepthFunc == NULL) return false;
 (FARPROC &)_glDepthMask = GetProcAddress(hglLib,"glDepthMask");
 if (_glDepthMask == NULL) return false;
 (FARPROC &)_glDepthRange = GetProcAddress(hglLib,"glDepthRange");
 if (_glDepthRange == NULL) return false;
 (FARPROC &)_glDisable = GetProcAddress(hglLib,"glDisable");
 if (_glDisable == NULL) return false;
 (FARPROC &)_glDisableClientState = GetProcAddress(hglLib,"glDisableClientState");
 if (_glDisableClientState == NULL) return false;
 (FARPROC &)_glDrawArrays = GetProcAddress(hglLib,"glDrawArrays");
 if (_glDrawArrays == NULL) return false;
 (FARPROC &)_glDrawBuffer = GetProcAddress(hglLib,"glDrawBuffer");
 if (_glDrawBuffer == NULL) return false;
 (FARPROC &)_glDrawElements = GetProcAddress(hglLib,"glDrawElements");
 if (_glDrawElements == NULL) return false;
 (FARPROC &)_glDrawPixels = GetProcAddress(hglLib,"glDrawPixels");
 if (_glDrawPixels == NULL) return false;
 (FARPROC &)_glEdgeFlag = GetProcAddress(hglLib,"glEdgeFlag");
 if (_glEdgeFlag == NULL) return false;
 (FARPROC &)_glEdgeFlagPointer = GetProcAddress(hglLib,"glEdgeFlagPointer");
 if (_glEdgeFlagPointer == NULL) return false;
 (FARPROC &)_glEdgeFlagv = GetProcAddress(hglLib,"glEdgeFlagv");
 if (_glEdgeFlagv == NULL) return false;
 (FARPROC &)_glEnable = GetProcAddress(hglLib,"glEnable");
 if (_glEnable == NULL) return false;
 (FARPROC &)_glEnableClientState = GetProcAddress(hglLib,"glEnableClientState");
 if (_glEnableClientState == NULL) return false;
 (FARPROC &)_glEnd = GetProcAddress(hglLib,"glEnd");
 if (_glEnd == NULL) return false;
 (FARPROC &)_glEndList = GetProcAddress(hglLib,"glEndList");
 if (_glEndList == NULL) return false;
 (FARPROC &)_glEvalCoord1d = GetProcAddress(hglLib,"glEvalCoord1d");
 if (_glEvalCoord1d == NULL) return false;
 (FARPROC &)_glEvalCoord1dv = GetProcAddress(hglLib,"glEvalCoord1dv");
 if (_glEvalCoord1dv == NULL) return false;
 (FARPROC &)_glEvalCoord1f = GetProcAddress(hglLib,"glEvalCoord1f");
 if (_glEvalCoord1f == NULL) return false;
 (FARPROC &)_glEvalCoord1fv = GetProcAddress(hglLib,"glEvalCoord1fv");
 if (_glEvalCoord1fv == NULL) return false;
 (FARPROC &)_glEvalCoord2d = GetProcAddress(hglLib,"glEvalCoord2d");
 if (_glEvalCoord2d == NULL) return false;
 (FARPROC &)_glEvalCoord2dv = GetProcAddress(hglLib,"glEvalCoord2dv");
 if (_glEvalCoord2dv == NULL) return false;
 (FARPROC &)_glEvalCoord2f = GetProcAddress(hglLib,"glEvalCoord2f");
 if (_glEvalCoord2f == NULL) return false;
 (FARPROC &)_glEvalCoord2fv = GetProcAddress(hglLib,"glEvalCoord2fv");
 if (_glEvalCoord2fv == NULL) return false;
 (FARPROC &)_glEvalMesh1 = GetProcAddress(hglLib,"glEvalMesh1");
 if (_glEvalMesh1 == NULL) return false;
 (FARPROC &)_glEvalMesh2 = GetProcAddress(hglLib,"glEvalMesh2");
 if (_glEvalMesh2 == NULL) return false;
 (FARPROC &)_glEvalPoint1 = GetProcAddress(hglLib,"glEvalPoint1");
 if (_glEvalPoint1 == NULL) return false;
 (FARPROC &)_glEvalPoint2 = GetProcAddress(hglLib,"glEvalPoint2");
 if (_glEvalPoint2 == NULL) return false;
 (FARPROC &)_glFeedbackBuffer = GetProcAddress(hglLib,"glFeedbackBuffer");
 if (_glFeedbackBuffer == NULL) return false;
 (FARPROC &)_glFinish = GetProcAddress(hglLib,"glFinish");
 if (_glFinish == NULL) return false;
 (FARPROC &)_glFlush = GetProcAddress(hglLib,"glFlush");
 if (_glFlush == NULL) return false;
 (FARPROC &)_glFogf = GetProcAddress(hglLib,"glFogf");
 if (_glFogf == NULL) return false;
 (FARPROC &)_glFogfv = GetProcAddress(hglLib,"glFogfv");
 if (_glFogfv == NULL) return false;
 (FARPROC &)_glFogi = GetProcAddress(hglLib,"glFogi");
 if (_glFogi == NULL) return false;
 (FARPROC &)_glFogiv = GetProcAddress(hglLib,"glFogiv");
 if (_glFogiv == NULL) return false;
 (FARPROC &)_glFrontFace = GetProcAddress(hglLib,"glFrontFace");
 if (_glFrontFace == NULL) return false;
 (FARPROC &)_glFrustum = GetProcAddress(hglLib,"glFrustum");
 if (_glFrustum == NULL) return false;
 (FARPROC &)_glGenLists = GetProcAddress(hglLib,"glGenLists");
 if (_glGenLists == NULL) return false;
 (FARPROC &)_glGenTextures = GetProcAddress(hglLib,"glGenTextures");
 if (_glGenTextures == NULL) return false;
 (FARPROC &)_glGetBooleanv = GetProcAddress(hglLib,"glGetBooleanv");
 if (_glGetBooleanv == NULL) return false;
 (FARPROC &)_glGetClipPlane = GetProcAddress(hglLib,"glGetClipPlane");
 if (_glGetClipPlane == NULL) return false;
 (FARPROC &)_glGetDoublev = GetProcAddress(hglLib,"glGetDoublev");
 if (_glGetDoublev == NULL) return false;
 (FARPROC &)_glGetError = GetProcAddress(hglLib,"glGetError");
 if (_glGetError == NULL) return false;
 (FARPROC &)_glGetFloatv = GetProcAddress(hglLib,"glGetFloatv");
 if (_glGetFloatv == NULL) return false;
 (FARPROC &)_glGetIntegerv = GetProcAddress(hglLib,"glGetIntegerv");
 if (_glGetIntegerv == NULL) return false;
 (FARPROC &)_glGetLightfv = GetProcAddress(hglLib,"glGetLightfv");
 if (_glGetLightfv == NULL) return false;
 (FARPROC &)_glGetLightiv = GetProcAddress(hglLib,"glGetLightiv");
 if (_glGetLightiv == NULL) return false;
 (FARPROC &)_glGetMapdv = GetProcAddress(hglLib,"glGetMapdv");
 if (_glGetMapdv == NULL) return false;
 (FARPROC &)_glGetMapfv = GetProcAddress(hglLib,"glGetMapfv");
 if (_glGetMapfv == NULL) return false;
 (FARPROC &)_glGetMapiv = GetProcAddress(hglLib,"glGetMapiv");
 if (_glGetMapiv == NULL) return false;
 (FARPROC &)_glGetMaterialfv = GetProcAddress(hglLib,"glGetMaterialfv");
 if (_glGetMaterialfv == NULL) return false;
 (FARPROC &)_glGetMaterialiv = GetProcAddress(hglLib,"glGetMaterialiv");
 if (_glGetMaterialiv == NULL) return false;
 (FARPROC &)_glGetPixelMapfv = GetProcAddress(hglLib,"glGetPixelMapfv");
 if (_glGetPixelMapfv == NULL) return false;
 (FARPROC &)_glGetPixelMapuiv = GetProcAddress(hglLib,"glGetPixelMapuiv");
 if (_glGetPixelMapuiv == NULL) return false;
 (FARPROC &)_glGetPixelMapusv = GetProcAddress(hglLib,"glGetPixelMapusv");
 if (_glGetPixelMapusv == NULL) return false;
 (FARPROC &)_glGetPointerv = GetProcAddress(hglLib,"glGetPointerv");
 if (_glGetPointerv == NULL) return false;
 (FARPROC &)_glGetPolygonStipple = GetProcAddress(hglLib,"glGetPolygonStipple");
 if (_glGetPolygonStipple == NULL) return false;
 (FARPROC &)_glGetString = GetProcAddress(hglLib,"glGetString");
 if (_glGetString == NULL) return false;
 (FARPROC &)_glGetTexEnvfv = GetProcAddress(hglLib,"glGetTexEnvfv");
 if (_glGetTexEnvfv == NULL) return false;
 (FARPROC &)_glGetTexEnviv = GetProcAddress(hglLib,"glGetTexEnviv");
 if (_glGetTexEnviv == NULL) return false;
 (FARPROC &)_glGetTexGendv = GetProcAddress(hglLib,"glGetTexGendv");
 if (_glGetTexGendv == NULL) return false;
 (FARPROC &)_glGetTexGenfv = GetProcAddress(hglLib,"glGetTexGenfv");
 if (_glGetTexGenfv == NULL) return false;
 (FARPROC &)_glGetTexGeniv = GetProcAddress(hglLib,"glGetTexGeniv");
 if (_glGetTexGeniv == NULL) return false;
 (FARPROC &)_glGetTexImage = GetProcAddress(hglLib,"glGetTexImage");
 if (_glGetTexImage == NULL) return false;
 (FARPROC &)_glGetTexLevelParameterfv = GetProcAddress(hglLib,"glGetTexLevelParameterfv");
 if (_glGetTexLevelParameterfv == NULL) return false;
 (FARPROC &)_glGetTexLevelParameteriv = GetProcAddress(hglLib,"glGetTexLevelParameteriv");
 if (_glGetTexLevelParameteriv == NULL) return false;
 (FARPROC &)_glGetTexParameterfv = GetProcAddress(hglLib,"glGetTexParameterfv");
 if (_glGetTexParameterfv == NULL) return false;
 (FARPROC &)_glGetTexParameteriv = GetProcAddress(hglLib,"glGetTexParameteriv");
 if (_glGetTexParameteriv == NULL) return false;
 (FARPROC &)_glHint = GetProcAddress(hglLib,"glHint");
 if (_glHint == NULL) return false;
 (FARPROC &)_glIndexMask = GetProcAddress(hglLib,"glIndexMask");
 if (_glIndexMask == NULL) return false;
 (FARPROC &)_glIndexPointer = GetProcAddress(hglLib,"glIndexPointer");
 if (_glIndexPointer == NULL) return false;
 (FARPROC &)_glIndexd = GetProcAddress(hglLib,"glIndexd");
 if (_glIndexd == NULL) return false;
 (FARPROC &)_glIndexdv = GetProcAddress(hglLib,"glIndexdv");
 if (_glIndexdv == NULL) return false;
 (FARPROC &)_glIndexf = GetProcAddress(hglLib,"glIndexf");
 if (_glIndexf == NULL) return false;
 (FARPROC &)_glIndexfv = GetProcAddress(hglLib,"glIndexfv");
 if (_glIndexfv == NULL) return false;
 (FARPROC &)_glIndexi = GetProcAddress(hglLib,"glIndexi");
 if (_glIndexi == NULL) return false;
 (FARPROC &)_glIndexiv = GetProcAddress(hglLib,"glIndexiv");
 if (_glIndexiv == NULL) return false;
 (FARPROC &)_glIndexs = GetProcAddress(hglLib,"glIndexs");
 if (_glIndexs == NULL) return false;
 (FARPROC &)_glIndexsv = GetProcAddress(hglLib,"glIndexsv");
 if (_glIndexsv == NULL) return false;
 (FARPROC &)_glIndexub = GetProcAddress(hglLib,"glIndexub");
 if (_glIndexub == NULL) return false;
 (FARPROC &)_glIndexubv = GetProcAddress(hglLib,"glIndexubv");
 if (_glIndexubv == NULL) return false;
 (FARPROC &)_glInitNames = GetProcAddress(hglLib,"glInitNames");
 if (_glInitNames == NULL) return false;
 (FARPROC &)_glInterleavedArrays = GetProcAddress(hglLib,"glInterleavedArrays");
 if (_glInterleavedArrays == NULL) return false;
 (FARPROC &)_glIsEnabled = GetProcAddress(hglLib,"glIsEnabled");
 if (_glIsEnabled == NULL) return false;
 (FARPROC &)_glIsList = GetProcAddress(hglLib,"glIsList");
 if (_glIsList == NULL) return false;
 (FARPROC &)_glIsTexture = GetProcAddress(hglLib,"glIsTexture");
 if (_glIsTexture == NULL) return false;
 (FARPROC &)_glLightModelf = GetProcAddress(hglLib,"glLightModelf");
 if (_glLightModelf == NULL) return false;
 (FARPROC &)_glLightModelfv = GetProcAddress(hglLib,"glLightModelfv");
 if (_glLightModelfv == NULL) return false;
 (FARPROC &)_glLightModeli = GetProcAddress(hglLib,"glLightModeli");
 if (_glLightModeli == NULL) return false;
 (FARPROC &)_glLightModeliv = GetProcAddress(hglLib,"glLightModeliv");
 if (_glLightModeliv == NULL) return false;
 (FARPROC &)_glLightf = GetProcAddress(hglLib,"glLightf");
 if (_glLightf == NULL) return false;
 (FARPROC &)_glLightfv = GetProcAddress(hglLib,"glLightfv");
 if (_glLightfv == NULL) return false;
 (FARPROC &)_glLighti = GetProcAddress(hglLib,"glLighti");
 if (_glLighti == NULL) return false;
 (FARPROC &)_glLightiv = GetProcAddress(hglLib,"glLightiv");
 if (_glLightiv == NULL) return false;
 (FARPROC &)_glLineStipple = GetProcAddress(hglLib,"glLineStipple");
 if (_glLineStipple == NULL) return false;
 (FARPROC &)_glLineWidth = GetProcAddress(hglLib,"glLineWidth");
 if (_glLineWidth == NULL) return false;
 (FARPROC &)_glListBase = GetProcAddress(hglLib,"glListBase");
 if (_glListBase == NULL) return false;
 (FARPROC &)_glLoadIdentity = GetProcAddress(hglLib,"glLoadIdentity");
 if (_glLoadIdentity == NULL) return false;
 (FARPROC &)_glLoadMatrixd = GetProcAddress(hglLib,"glLoadMatrixd");
 if (_glLoadMatrixd == NULL) return false;
 (FARPROC &)_glLoadMatrixf = GetProcAddress(hglLib,"glLoadMatrixf");
 if (_glLoadMatrixf == NULL) return false;
 (FARPROC &)_glLoadName = GetProcAddress(hglLib,"glLoadName");
 if (_glLoadName == NULL) return false;
 (FARPROC &)_glLogicOp = GetProcAddress(hglLib,"glLogicOp");
 if (_glLogicOp == NULL) return false;
 (FARPROC &)_glMap1d = GetProcAddress(hglLib,"glMap1d");
 if (_glMap1d == NULL) return false;
 (FARPROC &)_glMap1f = GetProcAddress(hglLib,"glMap1f");
 if (_glMap1f == NULL) return false;
 (FARPROC &)_glMap2d = GetProcAddress(hglLib,"glMap2d");
 if (_glMap2d == NULL) return false;
 (FARPROC &)_glMap2f = GetProcAddress(hglLib,"glMap2f");
 if (_glMap2f == NULL) return false;
 (FARPROC &)_glMapGrid1d = GetProcAddress(hglLib,"glMapGrid1d");
 if (_glMapGrid1d == NULL) return false;
 (FARPROC &)_glMapGrid1f = GetProcAddress(hglLib,"glMapGrid1f");
 if (_glMapGrid1f == NULL) return false;
 (FARPROC &)_glMapGrid2d = GetProcAddress(hglLib,"glMapGrid2d");
 if (_glMapGrid2d == NULL) return false;
 (FARPROC &)_glMapGrid2f = GetProcAddress(hglLib,"glMapGrid2f");
 if (_glMapGrid2f == NULL) return false;
 (FARPROC &)_glMaterialf = GetProcAddress(hglLib,"glMaterialf");
 if (_glMaterialf == NULL) return false;
 (FARPROC &)_glMaterialfv = GetProcAddress(hglLib,"glMaterialfv");
 if (_glMaterialfv == NULL) return false;
 (FARPROC &)_glMateriali = GetProcAddress(hglLib,"glMateriali");
 if (_glMateriali == NULL) return false;
 (FARPROC &)_glMaterialiv = GetProcAddress(hglLib,"glMaterialiv");
 if (_glMaterialiv == NULL) return false;
 (FARPROC &)_glMatrixMode = GetProcAddress(hglLib,"glMatrixMode");
 if (_glMatrixMode == NULL) return false;
 (FARPROC &)_glMultMatrixd = GetProcAddress(hglLib,"glMultMatrixd");
 if (_glMultMatrixd == NULL) return false;
 (FARPROC &)_glMultMatrixf = GetProcAddress(hglLib,"glMultMatrixf");
 if (_glMultMatrixf == NULL) return false;
 (FARPROC &)_glNewList = GetProcAddress(hglLib,"glNewList");
 if (_glNewList == NULL) return false;
 (FARPROC &)_glNormal3b = GetProcAddress(hglLib,"glNormal3b");
 if (_glNormal3b == NULL) return false;
 (FARPROC &)_glNormal3bv = GetProcAddress(hglLib,"glNormal3bv");
 if (_glNormal3bv == NULL) return false;
 (FARPROC &)_glNormal3d = GetProcAddress(hglLib,"glNormal3d");
 if (_glNormal3d == NULL) return false;
 (FARPROC &)_glNormal3dv = GetProcAddress(hglLib,"glNormal3dv");
 if (_glNormal3dv == NULL) return false;
 (FARPROC &)_glNormal3f = GetProcAddress(hglLib,"glNormal3f");
 if (_glNormal3f == NULL) return false;
 (FARPROC &)_glNormal3fv = GetProcAddress(hglLib,"glNormal3fv");
 if (_glNormal3fv == NULL) return false;
 (FARPROC &)_glNormal3i = GetProcAddress(hglLib,"glNormal3i");
 if (_glNormal3i == NULL) return false;
 (FARPROC &)_glNormal3iv = GetProcAddress(hglLib,"glNormal3iv");
 if (_glNormal3iv == NULL) return false;
 (FARPROC &)_glNormal3s = GetProcAddress(hglLib,"glNormal3s");
 if (_glNormal3s == NULL) return false;
 (FARPROC &)_glNormal3sv = GetProcAddress(hglLib,"glNormal3sv");
 if (_glNormal3sv == NULL) return false;
 (FARPROC &)_glNormalPointer = GetProcAddress(hglLib,"glNormalPointer");
 if (_glNormalPointer == NULL) return false;
 (FARPROC &)_glOrtho = GetProcAddress(hglLib,"glOrtho");
 if (_glOrtho == NULL) return false;
 (FARPROC &)_glPassThrough = GetProcAddress(hglLib,"glPassThrough");
 if (_glPassThrough == NULL) return false;
 (FARPROC &)_glPixelMapfv = GetProcAddress(hglLib,"glPixelMapfv");
 if (_glPixelMapfv == NULL) return false;
 (FARPROC &)_glPixelMapuiv = GetProcAddress(hglLib,"glPixelMapuiv");
 if (_glPixelMapuiv == NULL) return false;
 (FARPROC &)_glPixelMapusv = GetProcAddress(hglLib,"glPixelMapusv");
 if (_glPixelMapusv == NULL) return false;
 (FARPROC &)_glPixelStoref = GetProcAddress(hglLib,"glPixelStoref");
 if (_glPixelStoref == NULL) return false;
 (FARPROC &)_glPixelStorei = GetProcAddress(hglLib,"glPixelStorei");
 if (_glPixelStorei == NULL) return false;
 (FARPROC &)_glPixelTransferf = GetProcAddress(hglLib,"glPixelTransferf");
 if (_glPixelTransferf == NULL) return false;
 (FARPROC &)_glPixelTransferi = GetProcAddress(hglLib,"glPixelTransferi");
 if (_glPixelTransferi == NULL) return false;
 (FARPROC &)_glPixelZoom = GetProcAddress(hglLib,"glPixelZoom");
 if (_glPixelZoom == NULL) return false;
 (FARPROC &)_glPointSize = GetProcAddress(hglLib,"glPointSize");
 if (_glPointSize == NULL) return false;
 (FARPROC &)_glPolygonMode = GetProcAddress(hglLib,"glPolygonMode");
 if (_glPolygonMode == NULL) return false;
 (FARPROC &)_glPolygonOffset = GetProcAddress(hglLib,"glPolygonOffset");
 if (_glPolygonOffset == NULL) return false;
 (FARPROC &)_glPolygonStipple = GetProcAddress(hglLib,"glPolygonStipple");
 if (_glPolygonStipple == NULL) return false;
 (FARPROC &)_glPopAttrib = GetProcAddress(hglLib,"glPopAttrib");
 if (_glPopAttrib == NULL) return false;
 (FARPROC &)_glPopClientAttrib = GetProcAddress(hglLib,"glPopClientAttrib");
 if (_glPopClientAttrib == NULL) return false;
 (FARPROC &)_glPopMatrix = GetProcAddress(hglLib,"glPopMatrix");
 if (_glPopMatrix == NULL) return false;
 (FARPROC &)_glPopName = GetProcAddress(hglLib,"glPopName");
 if (_glPopName == NULL) return false;
 (FARPROC &)_glPrioritizeTextures = GetProcAddress(hglLib,"glPrioritizeTextures");
 if (_glPrioritizeTextures == NULL) return false;
 (FARPROC &)_glPushAttrib = GetProcAddress(hglLib,"glPushAttrib");
 if (_glPushAttrib == NULL) return false;
 (FARPROC &)_glPushClientAttrib = GetProcAddress(hglLib,"glPushClientAttrib");
 if (_glPushClientAttrib == NULL) return false;
 (FARPROC &)_glPushMatrix = GetProcAddress(hglLib,"glPushMatrix");
 if (_glPushMatrix == NULL) return false;
 (FARPROC &)_glPushName = GetProcAddress(hglLib,"glPushName");
 if (_glPushName == NULL) return false;
 (FARPROC &)_glRasterPos2d = GetProcAddress(hglLib,"glRasterPos2d");
 if (_glRasterPos2d == NULL) return false;
 (FARPROC &)_glRasterPos2dv = GetProcAddress(hglLib,"glRasterPos2dv");
 if (_glRasterPos2dv == NULL) return false;
 (FARPROC &)_glRasterPos2f = GetProcAddress(hglLib,"glRasterPos2f");
 if (_glRasterPos2f == NULL) return false;
 (FARPROC &)_glRasterPos2fv = GetProcAddress(hglLib,"glRasterPos2fv");
 if (_glRasterPos2fv == NULL) return false;
 (FARPROC &)_glRasterPos2i = GetProcAddress(hglLib,"glRasterPos2i");
 if (_glRasterPos2i == NULL) return false;
 (FARPROC &)_glRasterPos2iv = GetProcAddress(hglLib,"glRasterPos2iv");
 if (_glRasterPos2iv == NULL) return false;
 (FARPROC &)_glRasterPos2s = GetProcAddress(hglLib,"glRasterPos2s");
 if (_glRasterPos2s == NULL) return false;
 (FARPROC &)_glRasterPos2sv = GetProcAddress(hglLib,"glRasterPos2sv");
 if (_glRasterPos2sv == NULL) return false;
 (FARPROC &)_glRasterPos3d = GetProcAddress(hglLib,"glRasterPos3d");
 if (_glRasterPos3d == NULL) return false;
 (FARPROC &)_glRasterPos3dv = GetProcAddress(hglLib,"glRasterPos3dv");
 if (_glRasterPos3dv == NULL) return false;
 (FARPROC &)_glRasterPos3f = GetProcAddress(hglLib,"glRasterPos3f");
 if (_glRasterPos3f == NULL) return false;
 (FARPROC &)_glRasterPos3fv = GetProcAddress(hglLib,"glRasterPos3fv");
 if (_glRasterPos3fv == NULL) return false;
 (FARPROC &)_glRasterPos3i = GetProcAddress(hglLib,"glRasterPos3i");
 if (_glRasterPos3i == NULL) return false;
 (FARPROC &)_glRasterPos3iv = GetProcAddress(hglLib,"glRasterPos3iv");
 if (_glRasterPos3iv == NULL) return false;
 (FARPROC &)_glRasterPos3s = GetProcAddress(hglLib,"glRasterPos3s");
 if (_glRasterPos3s == NULL) return false;
 (FARPROC &)_glRasterPos3sv = GetProcAddress(hglLib,"glRasterPos3sv");
 if (_glRasterPos3sv == NULL) return false;
 (FARPROC &)_glRasterPos4d = GetProcAddress(hglLib,"glRasterPos4d");
 if (_glRasterPos4d == NULL) return false;
 (FARPROC &)_glRasterPos4dv = GetProcAddress(hglLib,"glRasterPos4dv");
 if (_glRasterPos4dv == NULL) return false;
 (FARPROC &)_glRasterPos4f = GetProcAddress(hglLib,"glRasterPos4f");
 if (_glRasterPos4f == NULL) return false;
 (FARPROC &)_glRasterPos4fv = GetProcAddress(hglLib,"glRasterPos4fv");
 if (_glRasterPos4fv == NULL) return false;
 (FARPROC &)_glRasterPos4i = GetProcAddress(hglLib,"glRasterPos4i");
 if (_glRasterPos4i == NULL) return false;
 (FARPROC &)_glRasterPos4iv = GetProcAddress(hglLib,"glRasterPos4iv");
 if (_glRasterPos4iv == NULL) return false;
 (FARPROC &)_glRasterPos4s = GetProcAddress(hglLib,"glRasterPos4s");
 if (_glRasterPos4s == NULL) return false;
 (FARPROC &)_glRasterPos4sv = GetProcAddress(hglLib,"glRasterPos4sv");
 if (_glRasterPos4sv == NULL) return false;
 (FARPROC &)_glReadBuffer = GetProcAddress(hglLib,"glReadBuffer");
 if (_glReadBuffer == NULL) return false;
 (FARPROC &)_glReadPixels = GetProcAddress(hglLib,"glReadPixels");
 if (_glReadPixels == NULL) return false;
 (FARPROC &)_glRectd = GetProcAddress(hglLib,"glRectd");
 if (_glRectd == NULL) return false;
 (FARPROC &)_glRectdv = GetProcAddress(hglLib,"glRectdv");
 if (_glRectdv == NULL) return false;
 (FARPROC &)_glRectf = GetProcAddress(hglLib,"glRectf");
 if (_glRectf == NULL) return false;
 (FARPROC &)_glRectfv = GetProcAddress(hglLib,"glRectfv");
 if (_glRectfv == NULL) return false;
 (FARPROC &)_glRecti = GetProcAddress(hglLib,"glRecti");
 if (_glRecti == NULL) return false;
 (FARPROC &)_glRectiv = GetProcAddress(hglLib,"glRectiv");
 if (_glRectiv == NULL) return false;
 (FARPROC &)_glRects = GetProcAddress(hglLib,"glRects");
 if (_glRects == NULL) return false;
 (FARPROC &)_glRectsv = GetProcAddress(hglLib,"glRectsv");
 if (_glRectsv == NULL) return false;
 (FARPROC &)_glRenderMode = GetProcAddress(hglLib,"glRenderMode");
 if (_glRenderMode == NULL) return false;
 (FARPROC &)_glRotated = GetProcAddress(hglLib,"glRotated");
 if (_glRotated == NULL) return false;
 (FARPROC &)_glRotatef = GetProcAddress(hglLib,"glRotatef");
 if (_glRotatef == NULL) return false;
 (FARPROC &)_glScaled = GetProcAddress(hglLib,"glScaled");
 if (_glScaled == NULL) return false;
 (FARPROC &)_glScalef = GetProcAddress(hglLib,"glScalef");
 if (_glScalef == NULL) return false;
 (FARPROC &)_glScissor = GetProcAddress(hglLib,"glScissor");
 if (_glScissor == NULL) return false;
 (FARPROC &)_glSelectBuffer = GetProcAddress(hglLib,"glSelectBuffer");
 if (_glSelectBuffer == NULL) return false;
 (FARPROC &)_glShadeModel = GetProcAddress(hglLib,"glShadeModel");
 if (_glShadeModel == NULL) return false;
 (FARPROC &)_glStencilFunc = GetProcAddress(hglLib,"glStencilFunc");
 if (_glStencilFunc == NULL) return false;
 (FARPROC &)_glStencilMask = GetProcAddress(hglLib,"glStencilMask");
 if (_glStencilMask == NULL) return false;
 (FARPROC &)_glStencilOp = GetProcAddress(hglLib,"glStencilOp");
 if (_glStencilOp == NULL) return false;
 (FARPROC &)_glTexCoord1d = GetProcAddress(hglLib,"glTexCoord1d");
 if (_glTexCoord1d == NULL) return false;
 (FARPROC &)_glTexCoord1dv = GetProcAddress(hglLib,"glTexCoord1dv");
 if (_glTexCoord1dv == NULL) return false;
 (FARPROC &)_glTexCoord1f = GetProcAddress(hglLib,"glTexCoord1f");
 if (_glTexCoord1f == NULL) return false;
 (FARPROC &)_glTexCoord1fv = GetProcAddress(hglLib,"glTexCoord1fv");
 if (_glTexCoord1fv == NULL) return false;
 (FARPROC &)_glTexCoord1i = GetProcAddress(hglLib,"glTexCoord1i");
 if (_glTexCoord1i == NULL) return false;
 (FARPROC &)_glTexCoord1iv = GetProcAddress(hglLib,"glTexCoord1iv");
 if (_glTexCoord1iv == NULL) return false;
 (FARPROC &)_glTexCoord1s = GetProcAddress(hglLib,"glTexCoord1s");
 if (_glTexCoord1s == NULL) return false;
 (FARPROC &)_glTexCoord1sv = GetProcAddress(hglLib,"glTexCoord1sv");
 if (_glTexCoord1sv == NULL) return false;
 (FARPROC &)_glTexCoord2d = GetProcAddress(hglLib,"glTexCoord2d");
 if (_glTexCoord2d == NULL) return false;
 (FARPROC &)_glTexCoord2dv = GetProcAddress(hglLib,"glTexCoord2dv");
 if (_glTexCoord2dv == NULL) return false;
 (FARPROC &)_glTexCoord2f = GetProcAddress(hglLib,"glTexCoord2f");
 if (_glTexCoord2f == NULL) return false;
 (FARPROC &)_glTexCoord2fv = GetProcAddress(hglLib,"glTexCoord2fv");
 if (_glTexCoord2fv == NULL) return false;
 (FARPROC &)_glTexCoord2i = GetProcAddress(hglLib,"glTexCoord2i");
 if (_glTexCoord2i == NULL) return false;
 (FARPROC &)_glTexCoord2iv = GetProcAddress(hglLib,"glTexCoord2iv");
 if (_glTexCoord2iv == NULL) return false;
 (FARPROC &)_glTexCoord2s = GetProcAddress(hglLib,"glTexCoord2s");
 if (_glTexCoord2s == NULL) return false;
 (FARPROC &)_glTexCoord2sv = GetProcAddress(hglLib,"glTexCoord2sv");
 if (_glTexCoord2sv == NULL) return false;
 (FARPROC &)_glTexCoord3d = GetProcAddress(hglLib,"glTexCoord3d");
 if (_glTexCoord3d == NULL) return false;
 (FARPROC &)_glTexCoord3dv = GetProcAddress(hglLib,"glTexCoord3dv");
 if (_glTexCoord3dv == NULL) return false;
 (FARPROC &)_glTexCoord3f = GetProcAddress(hglLib,"glTexCoord3f");
 if (_glTexCoord3f == NULL) return false;
 (FARPROC &)_glTexCoord3fv = GetProcAddress(hglLib,"glTexCoord3fv");
 if (_glTexCoord3fv == NULL) return false;
 (FARPROC &)_glTexCoord3i = GetProcAddress(hglLib,"glTexCoord3i");
 if (_glTexCoord3i == NULL) return false;
 (FARPROC &)_glTexCoord3iv = GetProcAddress(hglLib,"glTexCoord3iv");
 if (_glTexCoord3iv == NULL) return false;
 (FARPROC &)_glTexCoord3s = GetProcAddress(hglLib,"glTexCoord3s");
 if (_glTexCoord3s == NULL) return false;
 (FARPROC &)_glTexCoord3sv = GetProcAddress(hglLib,"glTexCoord3sv");
 if (_glTexCoord3sv == NULL) return false;
 (FARPROC &)_glTexCoord4d = GetProcAddress(hglLib,"glTexCoord4d");
 if (_glTexCoord4d == NULL) return false;
 (FARPROC &)_glTexCoord4dv = GetProcAddress(hglLib,"glTexCoord4dv");
 if (_glTexCoord4dv == NULL) return false;
 (FARPROC &)_glTexCoord4f = GetProcAddress(hglLib,"glTexCoord4f");
 if (_glTexCoord4f == NULL) return false;
 (FARPROC &)_glTexCoord4fv = GetProcAddress(hglLib,"glTexCoord4fv");
 if (_glTexCoord4fv == NULL) return false;
 (FARPROC &)_glTexCoord4i = GetProcAddress(hglLib,"glTexCoord4i");
 if (_glTexCoord4i == NULL) return false;
 (FARPROC &)_glTexCoord4iv = GetProcAddress(hglLib,"glTexCoord4iv");
 if (_glTexCoord4iv == NULL) return false;
 (FARPROC &)_glTexCoord4s = GetProcAddress(hglLib,"glTexCoord4s");
 if (_glTexCoord4s == NULL) return false;
 (FARPROC &)_glTexCoord4sv = GetProcAddress(hglLib,"glTexCoord4sv");
 if (_glTexCoord4sv == NULL) return false;
 (FARPROC &)_glTexCoordPointer = GetProcAddress(hglLib,"glTexCoordPointer");
 if (_glTexCoordPointer == NULL) return false;
 (FARPROC &)_glTexEnvf = GetProcAddress(hglLib,"glTexEnvf");
 if (_glTexEnvf == NULL) return false;
 (FARPROC &)_glTexEnvfv = GetProcAddress(hglLib,"glTexEnvfv");
 if (_glTexEnvfv == NULL) return false;
 (FARPROC &)_glTexEnvi = GetProcAddress(hglLib,"glTexEnvi");
 if (_glTexEnvi == NULL) return false;
 (FARPROC &)_glTexEnviv = GetProcAddress(hglLib,"glTexEnviv");
 if (_glTexEnviv == NULL) return false;
 (FARPROC &)_glTexGend = GetProcAddress(hglLib,"glTexGend");
 if (_glTexGend == NULL) return false;
 (FARPROC &)_glTexGendv = GetProcAddress(hglLib,"glTexGendv");
 if (_glTexGendv == NULL) return false;
 (FARPROC &)_glTexGenf = GetProcAddress(hglLib,"glTexGenf");
 if (_glTexGenf == NULL) return false;
 (FARPROC &)_glTexGenfv = GetProcAddress(hglLib,"glTexGenfv");
 if (_glTexGenfv == NULL) return false;
 (FARPROC &)_glTexGeni = GetProcAddress(hglLib,"glTexGeni");
 if (_glTexGeni == NULL) return false;
 (FARPROC &)_glTexGeniv = GetProcAddress(hglLib,"glTexGeniv");
 if (_glTexGeniv == NULL) return false;
 (FARPROC &)_glTexImage1D = GetProcAddress(hglLib,"glTexImage1D");
 if (_glTexImage1D == NULL) return false;
 (FARPROC &)_glTexImage2D = GetProcAddress(hglLib,"glTexImage2D");
 if (_glTexImage2D == NULL) return false;
 (FARPROC &)_glTexParameterf = GetProcAddress(hglLib,"glTexParameterf");
 if (_glTexParameterf == NULL) return false;
 (FARPROC &)_glTexParameterfv = GetProcAddress(hglLib,"glTexParameterfv");
 if (_glTexParameterfv == NULL) return false;
 (FARPROC &)_glTexParameteri = GetProcAddress(hglLib,"glTexParameteri");
 if (_glTexParameteri == NULL) return false;
 (FARPROC &)_glTexParameteriv = GetProcAddress(hglLib,"glTexParameteriv");
 if (_glTexParameteriv == NULL) return false;
 (FARPROC &)_glTexSubImage1D = GetProcAddress(hglLib,"glTexSubImage1D");
 if (_glTexSubImage1D == NULL) return false;
 (FARPROC &)_glTexSubImage2D = GetProcAddress(hglLib,"glTexSubImage2D");
 if (_glTexSubImage2D == NULL) return false;
 (FARPROC &)_glTranslated = GetProcAddress(hglLib,"glTranslated");
 if (_glTranslated == NULL) return false;
 (FARPROC &)_glTranslatef = GetProcAddress(hglLib,"glTranslatef");
 if (_glTranslatef == NULL) return false;
 (FARPROC &)_glVertex2d = GetProcAddress(hglLib,"glVertex2d");
 if (_glVertex2d == NULL) return false;
 (FARPROC &)_glVertex2dv = GetProcAddress(hglLib,"glVertex2dv");
 if (_glVertex2dv == NULL) return false;
 (FARPROC &)_glVertex2f = GetProcAddress(hglLib,"glVertex2f");
 if (_glVertex2f == NULL) return false;
 (FARPROC &)_glVertex2fv = GetProcAddress(hglLib,"glVertex2fv");
 if (_glVertex2fv == NULL) return false;
 (FARPROC &)_glVertex2i = GetProcAddress(hglLib,"glVertex2i");
 if (_glVertex2i == NULL) return false;
 (FARPROC &)_glVertex2iv = GetProcAddress(hglLib,"glVertex2iv");
 if (_glVertex2iv == NULL) return false;
 (FARPROC &)_glVertex2s = GetProcAddress(hglLib,"glVertex2s");
 if (_glVertex2s == NULL) return false;
 (FARPROC &)_glVertex2sv = GetProcAddress(hglLib,"glVertex2sv");
 if (_glVertex2sv == NULL) return false;
 (FARPROC &)_glVertex3d = GetProcAddress(hglLib,"glVertex3d");
 if (_glVertex3d == NULL) return false;
 (FARPROC &)_glVertex3dv = GetProcAddress(hglLib,"glVertex3dv");
 if (_glVertex3dv == NULL) return false;
 (FARPROC &)_glVertex3f = GetProcAddress(hglLib,"glVertex3f");
 if (_glVertex3f == NULL) return false;
 (FARPROC &)_glVertex3fv = GetProcAddress(hglLib,"glVertex3fv");
 if (_glVertex3fv == NULL) return false;
 (FARPROC &)_glVertex3i = GetProcAddress(hglLib,"glVertex3i");
 if (_glVertex3i == NULL) return false;
 (FARPROC &)_glVertex3iv = GetProcAddress(hglLib,"glVertex3iv");
 if (_glVertex3iv == NULL) return false;
 (FARPROC &)_glVertex3s = GetProcAddress(hglLib,"glVertex3s");
 if (_glVertex3s == NULL) return false;
 (FARPROC &)_glVertex3sv = GetProcAddress(hglLib,"glVertex3sv");
 if (_glVertex3sv == NULL) return false;
 (FARPROC &)_glVertex4d = GetProcAddress(hglLib,"glVertex4d");
 if (_glVertex4d == NULL) return false;
 (FARPROC &)_glVertex4dv = GetProcAddress(hglLib,"glVertex4dv");
 if (_glVertex4dv == NULL) return false;
 (FARPROC &)_glVertex4f = GetProcAddress(hglLib,"glVertex4f");
 if (_glVertex4f == NULL) return false;
 (FARPROC &)_glVertex4fv = GetProcAddress(hglLib,"glVertex4fv");
 if (_glVertex4fv == NULL) return false;
 (FARPROC &)_glVertex4i = GetProcAddress(hglLib,"glVertex4i");
 if (_glVertex4i == NULL) return false;
 (FARPROC &)_glVertex4iv = GetProcAddress(hglLib,"glVertex4iv");
 if (_glVertex4iv == NULL) return false;
 (FARPROC &)_glVertex4s = GetProcAddress(hglLib,"glVertex4s");
 if (_glVertex4s == NULL) return false;
 (FARPROC &)_glVertex4sv = GetProcAddress(hglLib,"glVertex4sv");
 if (_glVertex4sv == NULL) return false;
 (FARPROC &)_glVertexPointer = GetProcAddress(hglLib,"glVertexPointer");
 if (_glVertexPointer == NULL) return false;
 (FARPROC &)_glViewport = GetProcAddress(hglLib,"glViewport");
 if (_glViewport == NULL) return false;
 (FARPROC &)_wglUseFontOutlinesA = GetProcAddress(hglLib,"wglUseFontOutlinesA");
 if (_wglUseFontOutlinesA == NULL) return false;
 (FARPROC &)_wglUseFontOutlinesW = GetProcAddress(hglLib,"wglUseFontOutlinesW");
 if (_wglUseFontOutlinesW == NULL) return false;
 (FARPROC &)_wglUseFontBitmapsA = GetProcAddress(hglLib,"wglUseFontBitmapsA");
 if (_wglUseFontBitmapsA == NULL) return false;
 (FARPROC &)_wglUseFontBitmapsW = GetProcAddress(hglLib,"wglUseFontBitmapsW");
 if (_wglUseFontBitmapsW == NULL) return false;
 (FARPROC &)_wglCopyContext = GetProcAddress(hglLib,"wglCopyContext");
 if (_wglCopyContext == NULL) return false;
 (FARPROC &)_wglCreateContext = GetProcAddress(hglLib,"wglCreateContext");
 if (_wglCreateContext == NULL) return false;
 (FARPROC &)_wglCreateLayerContext = GetProcAddress(hglLib,"wglCreateLayerContext");
 if (_wglCreateLayerContext == NULL) return false;
 (FARPROC &)_wglDeleteContext = GetProcAddress(hglLib,"wglDeleteContext");
 if (_wglDeleteContext == NULL) return false;
 (FARPROC &)_wglGetCurrentContext = GetProcAddress(hglLib,"wglGetCurrentContext");
 if (_wglGetCurrentContext == NULL) return false;
 (FARPROC &)_wglGetCurrentDC = GetProcAddress(hglLib,"wglGetCurrentDC");
 if (_wglGetCurrentDC == NULL) return false;
 (FARPROC &)_wglGetProcAddress = GetProcAddress(hglLib,"wglGetProcAddress");
 if (_wglGetProcAddress == NULL) return false;
 (FARPROC &)_wglMakeCurrent = GetProcAddress(hglLib,"wglMakeCurrent");
 if (_wglMakeCurrent == NULL) return false;
 (FARPROC &)_wglShareLists = GetProcAddress(hglLib,"wglShareLists");
 if (_wglShareLists == NULL) return false;
 (FARPROC &)_wglDescribeLayerPlane = GetProcAddress(hglLib,"wglDescribeLayerPlane");
 if (_wglDescribeLayerPlane == NULL) return false;
 (FARPROC &)_wglSetLayerPaletteEntries = GetProcAddress(hglLib,"wglSetLayerPaletteEntries");
 if (_wglSetLayerPaletteEntries == NULL) return false;
 (FARPROC &)_wglGetLayerPaletteEntries = GetProcAddress(hglLib,"wglGetLayerPaletteEntries");
 if (_wglGetLayerPaletteEntries == NULL) return false;
 (FARPROC &)_wglRealizeLayerPalette = GetProcAddress(hglLib,"wglRealizeLayerPalette");
 if (_wglRealizeLayerPalette == NULL) return false;
 (FARPROC &)_wglSwapLayerBuffers = GetProcAddress(hglLib,"wglSwapLayerBuffers");
 if (_wglSwapLayerBuffers == NULL) return false;
 (FARPROC &)_wglChoosePixelFormat = GetProcAddress(hglLib,"wglChoosePixelFormat");
 if (_wglChoosePixelFormat == NULL) return false;
 (FARPROC &)_wglDescribePixelFormat = GetProcAddress(hglLib,"wglDescribePixelFormat");
 if (_wglDescribePixelFormat == NULL) return false;
 (FARPROC &)_wglGetPixelFormat = GetProcAddress(hglLib,"wglGetPixelFormat");
 if (_wglGetPixelFormat == NULL) return false;
 (FARPROC &)_wglSetPixelFormat = GetProcAddress(hglLib,"wglSetPixelFormat");
 if (_wglSetPixelFormat == NULL) return false;
 (FARPROC &)_wglSwapBuffers = GetProcAddress(hglLib,"wglSwapBuffers");
 if (_wglSwapBuffers == NULL) return false;
 (FARPROC &)_wglGetDefaultProcAddress = GetProcAddress(hglLib,"wglGetDefaultProcAddress");
 if (_wglGetDefaultProcAddress == NULL) return false;
 (FARPROC &)_DrvCopyContext = GetProcAddress(hglLib,"DrvCopyContext");
 if (_DrvCopyContext == NULL) return false;
 (FARPROC &)_DrvCreateContext = GetProcAddress(hglLib,"DrvCreateContext");
 if (_DrvCreateContext == NULL) return false;
 (FARPROC &)_DrvCreateLayerContext = GetProcAddress(hglLib,"DrvCreateLayerContext");
 if (_DrvCreateLayerContext == NULL) return false;
 (FARPROC &)_DrvDeleteContext = GetProcAddress(hglLib,"DrvDeleteContext");
 if (_DrvDeleteContext == NULL) return false;
 (FARPROC &)_DrvDescribeLayerPlane = GetProcAddress(hglLib,"DrvDescribeLayerPlane");
 if (_DrvDescribeLayerPlane == NULL) return false;
 (FARPROC &)_DrvDescribePixelFormat = GetProcAddress(hglLib,"DrvDescribePixelFormat");
 if (_DrvDescribePixelFormat == NULL) return false;
 (FARPROC &)_DrvSetLayerPaletteEntries = GetProcAddress(hglLib,"DrvSetLayerPaletteEntries");
 if (_DrvSetLayerPaletteEntries == NULL) return false;
 (FARPROC &)_DrvGetLayerPaletteEntries = GetProcAddress(hglLib,"DrvGetLayerPaletteEntries");
 if (_DrvGetLayerPaletteEntries == NULL) return false;
 (FARPROC &)_DrvRealizeLayerPalette = GetProcAddress(hglLib,"DrvRealizeLayerPalette");
 if (_DrvRealizeLayerPalette == NULL) return false;
 (FARPROC &)_DrvSwapLayerBuffers = GetProcAddress(hglLib,"DrvSwapLayerBuffers");
 if (_DrvSwapLayerBuffers == NULL) return false;
 (FARPROC &)_DrvShareLists = GetProcAddress(hglLib,"DrvShareLists");
 if (_DrvShareLists == NULL) return false;
 (FARPROC &)_DrvSetPixelFormat = GetProcAddress(hglLib,"DrvSetPixelFormat");
 if (_DrvSetPixelFormat == NULL) return false;
 (FARPROC &)_DrvSwapBuffers = GetProcAddress(hglLib,"DrvSwapBuffers");
 if (_DrvSwapBuffers == NULL) return false;
 (FARPROC &)_DrvGetProcAddress = GetProcAddress(hglLib,"DrvGetProcAddress");
 if (_DrvGetProcAddress == NULL) return false;
 (FARPROC &)_DrvSetContext = GetProcAddress(hglLib,"DrvSetContext");
 if (_DrvSetContext == NULL) return false;
 (FARPROC &)_DrvReleaseContext = GetProcAddress(hglLib,"DrvReleaseContext");
 if (_DrvReleaseContext == NULL) return false;
 (FARPROC &)_DrvValidateVersion = GetProcAddress(hglLib,"DrvValidateVersion");
 if (_DrvValidateVersion == NULL) return false;

 return true;
}

GLAPI void APIENTRY new_glAccum (GLenum op, GLfloat value)
{
 CHECKCONTEXT

 _glAccum(op,value);
}

GLAPI void APIENTRY new_glAlphaFunc (GLenum func, GLclampf ref)
{
 CHECKCONTEXT

 _glAlphaFunc(func,ref);
}

GLAPI GLboolean APIENTRY new_glAreTexturesResident (GLsizei n, const GLuint *textures, GLboolean *residences)
{
 CHECKCONTEXTFALSE

 return _glAreTexturesResident(n,textures,residences);
}

GLAPI void APIENTRY new_glArrayElement (GLint i)
{
 CHECKCONTEXT

 _glArrayElement(i);
}

GLAPI void APIENTRY new_glBitmap (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap)
{
 CHECKCONTEXT

 _glBitmap(width,height,xorig,yorig,xmove,ymove,bitmap);
}

GLAPI void APIENTRY new_glBlendFunc (GLenum sfactor, GLenum dfactor)
{
 CHECKCONTEXT

 _glBlendFunc(sfactor, dfactor);
}

GLAPI void APIENTRY new_glCallList (GLuint list)
{
 CHECKCONTEXT

 _glCallList(list);
}

GLAPI void APIENTRY new_glCallLists (GLsizei n, GLenum type, const GLvoid *lists)
{
 CHECKCONTEXT

 _glCallLists(n,type,lists);
}

GLAPI void APIENTRY new_glClear (GLbitfield mask)
{
 CHECKCONTEXT

 _glClear(mask);
}

GLAPI void APIENTRY new_glClearAccum (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
 CHECKCONTEXT

 _glClearAccum(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
 CHECKCONTEXT

 _glClearColor(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glClearDepth (GLclampd depth)
{
 CHECKCONTEXT

 _glClearDepth(depth);
}

GLAPI void APIENTRY new_glClearIndex (GLfloat c)
{
 CHECKCONTEXT

 _glClearIndex(c);
}

GLAPI void APIENTRY new_glClearStencil (GLint s)
{
 CHECKCONTEXT

 _glClearStencil(s);
}

GLAPI void APIENTRY new_glClipPlane (GLenum plane, const GLdouble *equation)
{
 CHECKCONTEXT

 _glClipPlane(plane,equation);
}

GLAPI void APIENTRY new_glColor3b (GLbyte red, GLbyte green, GLbyte blue)
{
 CHECKCONTEXT

 _glColor3b(red,green,blue);
}

GLAPI void APIENTRY new_glColor3bv (const GLbyte *v)
{
 CHECKCONTEXT

 _glColor3bv(v);
}

GLAPI void APIENTRY new_glColor3d (GLdouble red, GLdouble green, GLdouble blue)
{
 CHECKCONTEXT

 _glColor3d(red,green,blue);
}

GLAPI void APIENTRY new_glColor3dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glColor3dv(v);
}

GLAPI void APIENTRY new_glColor3f (GLfloat red, GLfloat green, GLfloat blue)
{
 CHECKCONTEXT

 _glColor3f(red,green,blue);
}

GLAPI void APIENTRY new_glColor3fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glColor3fv(v);
}

GLAPI void APIENTRY new_glColor3i (GLint red, GLint green, GLint blue)
{
 CHECKCONTEXT

 _glColor3i(red,green,blue);
}

GLAPI void APIENTRY new_glColor3iv (const GLint *v)
{
 CHECKCONTEXT

 _glColor3iv(v);
}

GLAPI void APIENTRY new_glColor3s (GLshort red, GLshort green, GLshort blue)
{
 CHECKCONTEXT

 _glColor3s(red,green,blue);
}

GLAPI void APIENTRY new_glColor3sv (const GLshort *v)
{
 CHECKCONTEXT

 _glColor3sv(v);
}

GLAPI void APIENTRY new_glColor3ub (GLubyte red, GLubyte green, GLubyte blue)
{
 CHECKCONTEXT

 _glColor3ub(red,green,blue);
}

GLAPI void APIENTRY new_glColor3ubv (const GLubyte *v)
{
 CHECKCONTEXT

 _glColor3ubv(v);
}

GLAPI void APIENTRY new_glColor3ui (GLuint red, GLuint green, GLuint blue)
{
 CHECKCONTEXT

 _glColor3ui(red,green,blue);
}

GLAPI void APIENTRY new_glColor3uiv (const GLuint *v)
{
 CHECKCONTEXT

 _glColor3uiv(v);
}

GLAPI void APIENTRY new_glColor3us (GLushort red, GLushort green, GLushort blue)
{
 CHECKCONTEXT

 _glColor3us(red,green,blue);
}

GLAPI void APIENTRY new_glColor3usv (const GLushort *v)
{
 CHECKCONTEXT

 _glColor3usv(v);
}

GLAPI void APIENTRY new_glColor4b (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
{
 CHECKCONTEXT

 _glColor4b(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4bv (const GLbyte *v)
{
 CHECKCONTEXT

 _glColor4bv(v);
}

GLAPI void APIENTRY new_glColor4d (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
{
 CHECKCONTEXT

 _glColor4d(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glColor4dv(v);
}

GLAPI void APIENTRY new_glColor4f (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
 CHECKCONTEXT

 _glColor4f(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glColor4fv(v);
}

GLAPI void APIENTRY new_glColor4i (GLint red, GLint green, GLint blue, GLint alpha)
{
 CHECKCONTEXT

 _glColor4i(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4iv (const GLint *v)
{
 CHECKCONTEXT

 _glColor4iv(v);
}

GLAPI void APIENTRY new_glColor4s (GLshort red, GLshort green, GLshort blue, GLshort alpha)
{
 CHECKCONTEXT

 _glColor4s(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4sv (const GLshort *v)
{
 CHECKCONTEXT

 _glColor4sv(v);
}

GLAPI void APIENTRY new_glColor4ub (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
 CHECKCONTEXT

 _glColor4ub(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4ubv (const GLubyte *v)
{
 CHECKCONTEXT

 _glColor4ubv(v);
}

GLAPI void APIENTRY new_glColor4ui (GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
 CHECKCONTEXT

 _glColor4ui(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4uiv (const GLuint *v)
{
 CHECKCONTEXT

 _glColor4uiv(v);
}

GLAPI void APIENTRY new_glColor4us (GLushort red, GLushort green, GLushort blue, GLushort alpha)
{
 CHECKCONTEXT

 _glColor4us(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColor4usv (const GLushort *v)
{
 CHECKCONTEXT

 _glColor4usv(v);
}

GLAPI void APIENTRY new_glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
 CHECKCONTEXT

 _glColorMask(red,green,blue,alpha);
}

GLAPI void APIENTRY new_glColorMaterial (GLenum face, GLenum mode)
{
 CHECKCONTEXT

 _glColorMaterial(face,mode);
}

GLAPI void APIENTRY new_glCopyPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
 CHECKCONTEXT

 _glCopyPixels(x,y,width,height,type);
}

GLAPI void APIENTRY new_glCopyTexImage1D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border)
{
 CHECKCONTEXT

 _glCopyTexImage1D(target,level,internalFormat,x,y,width,border);
}

GLAPI void APIENTRY new_glCopyTexImage2D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
 CHECKCONTEXT

 _glCopyTexImage2D(target,level,internalFormat,x,y,width,height,border);
}

GLAPI void APIENTRY new_glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
 CHECKCONTEXT

 _glCopyTexSubImage1D(target,level,xoffset,x,y,width);
}

GLAPI void APIENTRY new_glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
 CHECKCONTEXT

 _glCopyTexSubImage2D(target,level,xoffset,yoffset,x,y,width,height);
}

GLAPI void APIENTRY new_glCullFace (GLenum mode)
{
 CHECKCONTEXT

 _glCullFace(mode);
}

GLAPI void APIENTRY new_glDeleteLists (GLuint list, GLsizei range)
{
 CHECKCONTEXT

 _glDeleteLists(list,range);
}

GLAPI void APIENTRY new_glDeleteTextures (GLsizei n, const GLuint *textures)
{
 CHECKCONTEXT

 _glDeleteTextures(n,textures);
}

GLAPI void APIENTRY new_glDepthFunc (GLenum func)
{
 CHECKCONTEXT

 _glDepthFunc(func);
}

GLAPI void APIENTRY new_glDepthMask (GLboolean flag)
{
 CHECKCONTEXT

 _glDepthMask(flag);
}

GLAPI void APIENTRY new_glDepthRange (GLclampd zNear, GLclampd zFar)
{
 CHECKCONTEXT

 _glDepthRange(zNear,zFar);
}

GLAPI void APIENTRY new_glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
 CHECKCONTEXT

 _glDrawArrays(mode,first,count);
}

GLAPI void APIENTRY new_glDrawBuffer (GLenum mode)
{
 CHECKCONTEXT

 _glDrawBuffer(mode);
}

GLAPI void APIENTRY new_glDrawPixels (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
 CHECKCONTEXT

 _glDrawPixels(width,height,format,type,pixels);
}

GLAPI void APIENTRY new_glEdgeFlag (GLboolean flag)
{
 CHECKCONTEXT

 _glEdgeFlag(flag);
}

GLAPI void APIENTRY new_glEdgeFlagv (const GLboolean *flag)
{
 CHECKCONTEXT

 _glEdgeFlagv(flag);
}

GLAPI void APIENTRY new_glEndList (void)
{
 CHECKCONTEXT

 _glEndList();
}

GLAPI void APIENTRY new_glEvalCoord1d (GLdouble u)
{
 CHECKCONTEXT

 _glEvalCoord1d(u);
}

GLAPI void APIENTRY new_glEvalCoord1dv (const GLdouble *u)
{
 CHECKCONTEXT

 _glEvalCoord1dv(u);
}

GLAPI void APIENTRY new_glEvalCoord1f (GLfloat u)
{
 CHECKCONTEXT

 _glEvalCoord1f(u);
}

GLAPI void APIENTRY new_glEvalCoord1fv (const GLfloat *u)
{
 CHECKCONTEXT

 _glEvalCoord1fv(u);
}

GLAPI void APIENTRY new_glEvalCoord2d (GLdouble u, GLdouble v)
{
 CHECKCONTEXT

 _glEvalCoord2d(u,v);
}

GLAPI void APIENTRY new_glEvalCoord2dv (const GLdouble *u)
{
 CHECKCONTEXT

 _glEvalCoord2dv(u);
}

GLAPI void APIENTRY new_glEvalCoord2f (GLfloat u, GLfloat v)
{
 CHECKCONTEXT

 _glEvalCoord2f(u,v);
}

GLAPI void APIENTRY new_glEvalCoord2fv (const GLfloat *u)
{
 CHECKCONTEXT

 _glEvalCoord2fv(u);
}

GLAPI void APIENTRY new_glEvalMesh1 (GLenum mode, GLint i1, GLint i2)
{
 CHECKCONTEXT

 _glEvalMesh1(mode,i1,i2);
}

GLAPI void APIENTRY new_glEvalMesh2 (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{
 CHECKCONTEXT

 _glEvalMesh2(mode,i1,i2,j1,j2);
}

GLAPI void APIENTRY new_glEvalPoint1 (GLint i)
{
 CHECKCONTEXT

 _glEvalPoint1(i);
}

GLAPI void APIENTRY new_glEvalPoint2 (GLint i, GLint j)
{
 CHECKCONTEXT

 _glEvalPoint2(i,j);
}

GLAPI void APIENTRY new_glFeedbackBuffer (GLsizei size, GLenum type, GLfloat *buffer)
{
 CHECKCONTEXT

 _glFeedbackBuffer(size,type,buffer);
}

GLAPI void APIENTRY new_glFinish (void)
{
 CHECKCONTEXT

 _glFinish();
}

GLAPI void APIENTRY new_glFlush (void)
{
 CHECKCONTEXT

 _glFlush();
}

GLAPI void APIENTRY new_glFogf (GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glFogf(pname,param);
}

GLAPI void APIENTRY new_glFogfv (GLenum pname, const GLfloat *params)
{
 CHECKCONTEXT

 _glFogfv(pname,params);
}

GLAPI void APIENTRY new_glFogi (GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glFogi(pname,param);
}

GLAPI void APIENTRY new_glFogiv (GLenum pname, const GLint *params)
{
 CHECKCONTEXT

 _glFogiv(pname,params);
}

GLAPI void APIENTRY new_glFrontFace (GLenum mode)
{
 CHECKCONTEXT

 _glFrontFace(mode);
}

GLAPI void APIENTRY new_glFrustum (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
 CHECKCONTEXT

 _glFrustum(left,right,bottom,top,zNear,zFar);
}

GLAPI GLuint APIENTRY new_glGenLists (GLsizei range)
{
 CHECKCONTEXTFALSE

 return _glGenLists(range);
}

GLAPI void APIENTRY new_glGetClipPlane (GLenum plane, GLdouble *equation)
{
 CHECKCONTEXT

 _glGetClipPlane(plane,equation);
}

GLAPI GLenum APIENTRY new_glGetError (void)
{
 return _glGetError();
}

GLAPI void APIENTRY new_glGetLightfv (GLenum light, GLenum pname, GLfloat *params)
{
 CHECKCONTEXT

 _glGetLightfv(light,pname,params);
}

GLAPI void APIENTRY new_glGetLightiv (GLenum light, GLenum pname, GLint *params)
{
 CHECKCONTEXT

 _glGetLightiv(light,pname,params);
}

GLAPI void APIENTRY new_glGetMapdv (GLenum target, GLenum query, GLdouble *v)
{
 CHECKCONTEXT

 _glGetMapdv(target,query,v);
}

GLAPI void APIENTRY new_glGetMapfv (GLenum target, GLenum query, GLfloat *v)
{
 CHECKCONTEXT

 _glGetMapfv(target,query,v);
}

GLAPI void APIENTRY new_glGetMapiv (GLenum target, GLenum query, GLint *v)
{
 CHECKCONTEXT

 _glGetMapiv(target,query,v);
}

GLAPI void APIENTRY new_glGetMaterialfv (GLenum face, GLenum pname, GLfloat *params)
{
 CHECKCONTEXT

 _glGetMaterialfv(face,pname,params);
}

GLAPI void APIENTRY new_glGetMaterialiv (GLenum face, GLenum pname, GLint *params)
{
 CHECKCONTEXT

 _glGetMaterialiv(face,pname,params);
}

GLAPI void APIENTRY new_glGetPixelMapfv (GLenum map, GLfloat *values)
{
 CHECKCONTEXT

 _glGetPixelMapfv(map,values);
}

GLAPI void APIENTRY new_glGetPixelMapuiv (GLenum map, GLuint *values)
{
 CHECKCONTEXT

 _glGetPixelMapuiv(map,values);
}

GLAPI void APIENTRY new_glGetPixelMapusv (GLenum map, GLushort *values)
{
 CHECKCONTEXT

 _glGetPixelMapusv(map,values);
}

GLAPI void APIENTRY new_glGetPointerv (GLenum pname, GLvoid* *params)
{
 CHECKCONTEXT

 _glGetPointerv(pname,params);
}

GLAPI void APIENTRY new_glGetPolygonStipple (GLubyte *mask)
{
 CHECKCONTEXT

 _glGetPolygonStipple(mask);
}

GLAPI void APIENTRY new_glGetTexGendv (GLenum coord, GLenum pname, GLdouble *params)
{
 CHECKCONTEXT

 _glGetTexGendv(coord,pname,params);
}

GLAPI void APIENTRY new_glGetTexGenfv (GLenum coord, GLenum pname, GLfloat *params)
{
 CHECKCONTEXT

 _glGetTexGenfv(coord,pname,params);
}

GLAPI void APIENTRY new_glGetTexGeniv (GLenum coord, GLenum pname, GLint *params)
{
 CHECKCONTEXT

 _glGetTexGeniv(coord,pname,params);
}

GLAPI void APIENTRY new_glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
 CHECKCONTEXT

 _glGetTexImage(target,level,format,type,pixels);
}

GLAPI void APIENTRY new_glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params)
{
 CHECKCONTEXT

 _glGetTexLevelParameterfv(target,level,pname,params);
}

GLAPI void APIENTRY new_glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params)
{
 CHECKCONTEXT

 _glGetTexLevelParameteriv(target,level,pname,params);
}

GLAPI void APIENTRY new_glIndexMask (GLuint mask)
{
 CHECKCONTEXT

 _glIndexMask(mask);
}

GLAPI void APIENTRY new_glIndexPointer (GLenum type, GLsizei stride, const GLvoid *pointer)
{
 CHECKCONTEXT

 _glIndexPointer(type,stride,pointer);
}

GLAPI void APIENTRY new_glIndexd (GLdouble c)
{
 CHECKCONTEXT

 _glIndexd(c);
}

GLAPI void APIENTRY new_glIndexdv (const GLdouble *c)
{
 CHECKCONTEXT

 _glIndexdv(c);
}

GLAPI void APIENTRY new_glIndexf (GLfloat c)
{
 CHECKCONTEXT

 _glIndexf(c);
}

GLAPI void APIENTRY new_glIndexfv (const GLfloat *c)
{
 CHECKCONTEXT

 _glIndexfv(c);
}

GLAPI void APIENTRY new_glIndexi (GLint c)
{
 CHECKCONTEXT

 _glIndexi(c);
}

GLAPI void APIENTRY new_glIndexiv (const GLint *c)
{
 CHECKCONTEXT

 _glIndexiv(c);
}

GLAPI void APIENTRY new_glIndexs (GLshort c)
{
 CHECKCONTEXT

 _glIndexs(c);
}

GLAPI void APIENTRY new_glIndexsv (const GLshort *c)
{
 CHECKCONTEXT

 _glIndexsv(c);
}

GLAPI void APIENTRY new_glIndexub (GLubyte c)
{
 CHECKCONTEXT

 _glIndexub(c);
}

GLAPI void APIENTRY new_glIndexubv (const GLubyte *c)
{
 CHECKCONTEXT

 _glIndexubv(c);
}

GLAPI void APIENTRY new_glInitNames (void)
{
 CHECKCONTEXT

 _glInitNames();
}

GLAPI void APIENTRY new_glInterleavedArrays (GLenum format, GLsizei stride, const GLvoid *pointer)
{
 CHECKCONTEXT

 _glInterleavedArrays(format,stride,pointer);
}

GLAPI GLboolean APIENTRY new_glIsList (GLuint list)
{
 CHECKCONTEXTFALSE

 return _glIsList(list);
}

GLAPI GLboolean APIENTRY new_glIsTexture (GLuint texture)
{
 CHECKCONTEXTFALSE

 return _glIsTexture(texture);
}

GLAPI void APIENTRY new_glLightModelf (GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glLightModelf(pname,param);
}

GLAPI void APIENTRY new_glLightModelfv (GLenum pname, const GLfloat *params)
{
 CHECKCONTEXT

 _glLightModelfv(pname,params);
}

GLAPI void APIENTRY new_glLightModeli (GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glLightModeli(pname,param);
}

GLAPI void APIENTRY new_glLightModeliv (GLenum pname, const GLint *params)
{
 CHECKCONTEXT

 _glLightModeliv(pname,params);
}

GLAPI void APIENTRY new_glLightf (GLenum light, GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glLightf(light,pname,param);
}

GLAPI void APIENTRY new_glLightfv (GLenum light, GLenum pname, const GLfloat *params)
{
 CHECKCONTEXT

 _glLightfv(light,pname,params);
}

GLAPI void APIENTRY new_glLighti (GLenum light, GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glLighti(light,pname,param);
}

GLAPI void APIENTRY new_glLightiv (GLenum light, GLenum pname, const GLint *params)
{
 CHECKCONTEXT

 _glLightiv(light,pname,params);
}

GLAPI void APIENTRY new_glLineStipple (GLint factor, GLushort pattern)
{
 CHECKCONTEXT

 _glLineStipple(factor,pattern);
}

GLAPI void APIENTRY new_glLineWidth (GLfloat width)
{
 CHECKCONTEXT

 _glLineWidth(width);
}

GLAPI void APIENTRY new_glListBase (GLuint base)
{
 CHECKCONTEXT

 _glListBase(base);
}

GLAPI void APIENTRY new_glLoadName (GLuint name)
{
 CHECKCONTEXT

 _glLoadName(name);
}

GLAPI void APIENTRY new_glLogicOp (GLenum opcode)
{
 CHECKCONTEXT

 _glLogicOp(opcode);
}

GLAPI void APIENTRY new_glMap1d (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
 CHECKCONTEXT

 _glMap1d(target,u1,u2,stride,order,points);
}

GLAPI void APIENTRY new_glMap1f (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
 CHECKCONTEXT

 _glMap1f(target,u1,u2,stride,order,points);
}

GLAPI void APIENTRY new_glMap2d (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
 CHECKCONTEXT

 _glMap2d(target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points);
}

GLAPI void APIENTRY new_glMap2f (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
 CHECKCONTEXT

 _glMap2f(target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points);
}

GLAPI void APIENTRY new_glMapGrid1d (GLint un, GLdouble u1, GLdouble u2)
{
 CHECKCONTEXT

 _glMapGrid1d(un,u1,u2);
}

GLAPI void APIENTRY new_glMapGrid1f (GLint un, GLfloat u1, GLfloat u2)
{
 CHECKCONTEXT

 _glMapGrid1f(un,u1,u2);
}

GLAPI void APIENTRY new_glMapGrid2d (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2)
{
 CHECKCONTEXT

 _glMapGrid2d(un,u1,u2,vn,v1,v2);
}

GLAPI void APIENTRY new_glMapGrid2f (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{
 CHECKCONTEXT

 _glMapGrid2f(un,u1,u2,vn,v1,v2);
}

GLAPI void APIENTRY new_glMaterialf (GLenum face, GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glMaterialf(face,pname,param);
}

GLAPI void APIENTRY new_glMaterialfv (GLenum face, GLenum pname, const GLfloat *params)
{
 CHECKCONTEXT

 _glMaterialfv(face,pname,params);
}

GLAPI void APIENTRY new_glMateriali (GLenum face, GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glMateriali(face,pname,param);
}

GLAPI void APIENTRY new_glMaterialiv (GLenum face, GLenum pname, const GLint *params)
{
 CHECKCONTEXT

 _glMaterialiv(face,pname,params);
}

GLAPI void APIENTRY new_glNewList (GLuint list, GLenum mode)
{
 CHECKCONTEXT

 _glNewList(list,mode);
}

GLAPI void APIENTRY new_glNormal3b (GLbyte nx, GLbyte ny, GLbyte nz)
{
 CHECKCONTEXT

 _glNormal3b(nx,ny,nz);
}

GLAPI void APIENTRY new_glNormal3bv (const GLbyte *v)
{
 CHECKCONTEXT

 _glNormal3bv(v);
}

GLAPI void APIENTRY new_glNormal3d (GLdouble nx, GLdouble ny, GLdouble nz)
{
 CHECKCONTEXT

 _glNormal3d(nx,ny,nz);
}

GLAPI void APIENTRY new_glNormal3dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glNormal3dv(v);
}

GLAPI void APIENTRY new_glNormal3f (GLfloat nx, GLfloat ny, GLfloat nz)
{
 CHECKCONTEXT

 _glNormal3f(nx,ny,nz);
}

GLAPI void APIENTRY new_glNormal3fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glNormal3fv(v);
}

GLAPI void APIENTRY new_glNormal3i (GLint nx, GLint ny, GLint nz)
{
 CHECKCONTEXT

 _glNormal3i(nx,ny,nz);
}

GLAPI void APIENTRY new_glNormal3iv (const GLint *v)
{
 CHECKCONTEXT

 _glNormal3iv(v);
}

GLAPI void APIENTRY new_glNormal3s (GLshort nx, GLshort ny, GLshort nz)
{
 CHECKCONTEXT

 _glNormal3s(nx,ny,nz);
}

GLAPI void APIENTRY new_glNormal3sv (const GLshort *v)
{
 CHECKCONTEXT

 _glNormal3sv(v);
}

GLAPI void APIENTRY new_glOrtho (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
 CHECKCONTEXT

 _glOrtho(left,right,bottom,top,zNear,zFar);
}

GLAPI void APIENTRY new_glPassThrough (GLfloat token)
{
 CHECKCONTEXT

 _glPassThrough(token);
}

GLAPI void APIENTRY new_glPixelMapfv (GLenum map, GLsizei mapsize, const GLfloat *values)
{
 CHECKCONTEXT

 _glPixelMapfv(map,mapsize,values);
}

GLAPI void APIENTRY new_glPixelMapuiv (GLenum map, GLsizei mapsize, const GLuint *values)
{
 CHECKCONTEXT

 _glPixelMapuiv(map,mapsize,values);
}

GLAPI void APIENTRY new_glPixelMapusv (GLenum map, GLsizei mapsize, const GLushort *values)
{
 CHECKCONTEXT

 _glPixelMapusv(map,mapsize,values);
}

GLAPI void APIENTRY new_glPixelStoref (GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glPixelStoref(pname,param);
}

GLAPI void APIENTRY new_glPixelStorei (GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glPixelStorei(pname,param);
}

GLAPI void APIENTRY new_glPixelTransferf (GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glPixelTransferf(pname,param);
}

GLAPI void APIENTRY new_glPixelTransferi (GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glPixelTransferi(pname,param);
}

GLAPI void APIENTRY new_glPixelZoom (GLfloat xfactor, GLfloat yfactor)
{
 CHECKCONTEXT

 _glPixelZoom(xfactor,yfactor);
}

GLAPI void APIENTRY new_glPointSize (GLfloat size)
{
 CHECKCONTEXT

 _glPointSize(size);
}

GLAPI void APIENTRY new_glPolygonMode (GLenum face, GLenum mode)
{
 CHECKCONTEXT

 _glPolygonMode(face,mode);
}

GLAPI void APIENTRY new_glPolygonOffset (GLfloat factor, GLfloat units)
{
 CHECKCONTEXT

 _glPolygonOffset(factor,units);
}

GLAPI void APIENTRY new_glPolygonStipple (const GLubyte *mask)
{
 CHECKCONTEXT

 _glPolygonStipple(mask);
}

GLAPI void APIENTRY new_glPopAttrib (void)
{
 CHECKCONTEXT

 _glPopAttrib();
}

GLAPI void APIENTRY new_glPopClientAttrib (void)
{
 CHECKCONTEXT

 _glPopClientAttrib();
}

GLAPI void APIENTRY new_glPopMatrix (void)
{
 CHECKCONTEXT

 _glPopMatrix();
}

GLAPI void APIENTRY new_glPopName (void)
{
 CHECKCONTEXT

 _glPopName();
}

GLAPI void APIENTRY new_glPrioritizeTextures (GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
 CHECKCONTEXT

 _glPrioritizeTextures(n,textures,priorities);
}

GLAPI void APIENTRY new_glPushAttrib (GLbitfield mask)
{
 CHECKCONTEXT

 _glPushAttrib(mask);
}

GLAPI void APIENTRY new_glPushClientAttrib (GLbitfield mask)
{
 CHECKCONTEXT

 _glPushClientAttrib(mask);
}

GLAPI void APIENTRY new_glPushMatrix (void)
{
 CHECKCONTEXT

 _glPushMatrix();
}

GLAPI void APIENTRY new_glPushName (GLuint name)
{
 CHECKCONTEXT

 _glPushName(name);
}

GLAPI void APIENTRY new_glRasterPos2d (GLdouble x, GLdouble y)
{
 CHECKCONTEXT

 _glRasterPos2d(x,y);
}

GLAPI void APIENTRY new_glRasterPos2dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glRasterPos2dv(v);
}

GLAPI void APIENTRY new_glRasterPos2f (GLfloat x, GLfloat y)
{
 CHECKCONTEXT

 _glRasterPos2f(x,y);
}

GLAPI void APIENTRY new_glRasterPos2fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glRasterPos2fv(v);
}

GLAPI void APIENTRY new_glRasterPos2i (GLint x, GLint y)
{
 CHECKCONTEXT

 _glRasterPos2i(x,y);
}

GLAPI void APIENTRY new_glRasterPos2iv (const GLint *v)
{
 CHECKCONTEXT

 _glRasterPos2iv(v);
}

GLAPI void APIENTRY new_glRasterPos2s (GLshort x, GLshort y)
{
 CHECKCONTEXT

 _glRasterPos2s(x,y);
}

GLAPI void APIENTRY new_glRasterPos2sv (const GLshort *v)
{
 CHECKCONTEXT

 _glRasterPos2sv(v);
}

GLAPI void APIENTRY new_glRasterPos3d (GLdouble x, GLdouble y, GLdouble z)
{
 CHECKCONTEXT

 _glRasterPos3d(x,y,z);
}

GLAPI void APIENTRY new_glRasterPos3dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glRasterPos3dv(v);
}

GLAPI void APIENTRY new_glRasterPos3f (GLfloat x, GLfloat y, GLfloat z)
{
 CHECKCONTEXT

 _glRasterPos3f(x,y,z);
}

GLAPI void APIENTRY new_glRasterPos3fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glRasterPos3fv(v);
}

GLAPI void APIENTRY new_glRasterPos3i (GLint x, GLint y, GLint z)
{
 CHECKCONTEXT

 _glRasterPos3i(x,y,z);
}

GLAPI void APIENTRY new_glRasterPos3iv (const GLint *v)
{
 CHECKCONTEXT

 _glRasterPos3iv(v);
}

GLAPI void APIENTRY new_glRasterPos3s (GLshort x, GLshort y, GLshort z)
{
 CHECKCONTEXT

 _glRasterPos3s(x,y,z);
}

GLAPI void APIENTRY new_glRasterPos3sv (const GLshort *v)
{
 CHECKCONTEXT

 _glRasterPos3sv(v);
}

GLAPI void APIENTRY new_glRasterPos4d (GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
 CHECKCONTEXT

 _glRasterPos4d(x,y,z,w);
}

GLAPI void APIENTRY new_glRasterPos4dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glRasterPos4dv(v);
}

GLAPI void APIENTRY new_glRasterPos4f (GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
 CHECKCONTEXT

 _glRasterPos4f(x,y,z,w);
}

GLAPI void APIENTRY new_glRasterPos4fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glRasterPos4fv(v);
}

GLAPI void APIENTRY new_glRasterPos4i (GLint x, GLint y, GLint z, GLint w)
{
 CHECKCONTEXT

 _glRasterPos4i(x,y,z,w);
}

GLAPI void APIENTRY new_glRasterPos4iv (const GLint *v)
{
 CHECKCONTEXT

 _glRasterPos4iv(v);
}

GLAPI void APIENTRY new_glRasterPos4s (GLshort x, GLshort y, GLshort z, GLshort w)
{
 CHECKCONTEXT

 _glRasterPos4s(x,y,z,w);
}

GLAPI void APIENTRY new_glRasterPos4sv (const GLshort *v)
{
 CHECKCONTEXT

 _glRasterPos4sv(v);
}

GLAPI void APIENTRY new_glReadBuffer (GLenum mode)
{
 CHECKCONTEXT

 _glReadBuffer(mode);
}

GLAPI void APIENTRY new_glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
 CHECKCONTEXT

 _glReadPixels(x,y,width,height,format,type,pixels);
}

GLAPI void APIENTRY new_glRectd (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
 CHECKCONTEXT

 _glRectd(x1,y1,x2,y2);
}

GLAPI void APIENTRY new_glRectdv (const GLdouble *v1, const GLdouble *v2)
{
 CHECKCONTEXT

 _glRectdv(v1,v2);
}

GLAPI void APIENTRY new_glRectf (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
 CHECKCONTEXT

 _glRectf(x1,y1,x2,y2);
}

GLAPI void APIENTRY new_glRectfv (const GLfloat *v1, const GLfloat *v2)
{
 CHECKCONTEXT

 _glRectfv(v1,v2);
}

GLAPI void APIENTRY new_glRecti (GLint x1, GLint y1, GLint x2, GLint y2)
{
 CHECKCONTEXT

 _glRecti(x1,y1,x2,y2);
}

GLAPI void APIENTRY new_glRectiv (const GLint *v1, const GLint *v2)
{
 CHECKCONTEXT

 _glRectiv(v1,v2);
}

GLAPI void APIENTRY new_glRects (GLshort x1, GLshort y1, GLshort x2, GLshort y2)
{
 CHECKCONTEXT

 _glRects(x1,y1,x2,y2);
}

GLAPI void APIENTRY new_glRectsv (const GLshort *v1, const GLshort *v2)
{
 CHECKCONTEXT

 _glRectsv(v1,v2);
}

GLAPI GLint APIENTRY new_glRenderMode (GLenum mode)
{
 CHECKCONTEXTFALSE

 return _glRenderMode(mode);
}

GLAPI void APIENTRY new_glRotated (GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
 CHECKCONTEXT

 _glRotated(angle,x,y,z);
}

GLAPI void APIENTRY new_glRotatef (GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
 CHECKCONTEXT

 _glRotatef(angle,x,y,z);
}

GLAPI void APIENTRY new_glScaled (GLdouble x, GLdouble y, GLdouble z)
{
 CHECKCONTEXT

 _glScaled(x,y,z);
}

GLAPI void APIENTRY new_glScalef (GLfloat x, GLfloat y, GLfloat z)
{
 CHECKCONTEXT

 _glScalef(x,y,z);
}

GLAPI void APIENTRY new_glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
 CHECKCONTEXT

 _glScissor(x,y,width,height);
}

GLAPI void APIENTRY new_glSelectBuffer (GLsizei size, GLuint *buffer)
{
 CHECKCONTEXT

 _glSelectBuffer(size,buffer);
}

GLAPI void APIENTRY new_glShadeModel (GLenum mode)
{
 CHECKCONTEXT

 _glShadeModel(mode);
}

GLAPI void APIENTRY new_glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
 CHECKCONTEXT

 _glStencilFunc(func,ref,mask);
}

GLAPI void APIENTRY new_glStencilMask (GLuint mask)
{
 CHECKCONTEXT

 _glStencilMask(mask);
}

GLAPI void APIENTRY new_glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
 CHECKCONTEXT

 _glStencilOp(fail,zfail,zpass);
}

GLAPI void APIENTRY new_glTexCoord1d (GLdouble s)
{
 CHECKCONTEXT

 _glTexCoord1d(s);
}

GLAPI void APIENTRY new_glTexCoord1dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glTexCoord1dv(v);
}

GLAPI void APIENTRY new_glTexCoord1f (GLfloat s)
{
 CHECKCONTEXT

 _glTexCoord1f(s);
}

GLAPI void APIENTRY new_glTexCoord1fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glTexCoord1fv(v);
}

GLAPI void APIENTRY new_glTexCoord1i (GLint s)
{
 CHECKCONTEXT

 _glTexCoord1i(s);
}

GLAPI void APIENTRY new_glTexCoord1iv (const GLint *v)
{
 CHECKCONTEXT

 _glTexCoord1iv(v);
}

GLAPI void APIENTRY new_glTexCoord1s (GLshort s)
{
 CHECKCONTEXT

 _glTexCoord1s(s);
}

GLAPI void APIENTRY new_glTexCoord1sv (const GLshort *v)
{
 CHECKCONTEXT

 _glTexCoord1sv(v);
}

GLAPI void APIENTRY new_glTexCoord2d (GLdouble s, GLdouble t)
{
 CHECKCONTEXT

 _glTexCoord2d(s,t);
}

GLAPI void APIENTRY new_glTexCoord2dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glTexCoord2dv(v);
}

GLAPI void APIENTRY new_glTexCoord2f (GLfloat s, GLfloat t)
{
 CHECKCONTEXT

 _glTexCoord2f(s,t);
}

GLAPI void APIENTRY new_glTexCoord2fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glTexCoord2fv(v);
}

GLAPI void APIENTRY new_glTexCoord2i (GLint s, GLint t)
{
 CHECKCONTEXT

 _glTexCoord2i(s,t);
}

GLAPI void APIENTRY new_glTexCoord2iv (const GLint *v)
{
 CHECKCONTEXT

 _glTexCoord2iv(v);
}

GLAPI void APIENTRY new_glTexCoord2s (GLshort s, GLshort t)
{
 CHECKCONTEXT

 _glTexCoord2s(s,t);
}

GLAPI void APIENTRY new_glTexCoord2sv (const GLshort *v)
{
 CHECKCONTEXT

 _glTexCoord2sv(v);
}

GLAPI void APIENTRY new_glTexCoord3d (GLdouble s, GLdouble t, GLdouble r)
{
 CHECKCONTEXT

 _glTexCoord3d(s,t,r);
}

GLAPI void APIENTRY new_glTexCoord3dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glTexCoord3dv(v);
}

GLAPI void APIENTRY new_glTexCoord3f (GLfloat s, GLfloat t, GLfloat r)
{
 CHECKCONTEXT

 _glTexCoord3f(s,t,r);
}

GLAPI void APIENTRY new_glTexCoord3fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glTexCoord3fv(v);
}

GLAPI void APIENTRY new_glTexCoord3i (GLint s, GLint t, GLint r)
{
 CHECKCONTEXT

 _glTexCoord3i(s,t,r);
}

GLAPI void APIENTRY new_glTexCoord3iv (const GLint *v)
{
 CHECKCONTEXT

 _glTexCoord3iv(v);
}

GLAPI void APIENTRY new_glTexCoord3s (GLshort s, GLshort t, GLshort r)
{
 CHECKCONTEXT

 _glTexCoord3s(s,t,r);
}

GLAPI void APIENTRY new_glTexCoord3sv (const GLshort *v)
{
 CHECKCONTEXT

 _glTexCoord3sv(v);
}

GLAPI void APIENTRY new_glTexCoord4d (GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
 CHECKCONTEXT

 _glTexCoord4d(s,t,r,q);
}

GLAPI void APIENTRY new_glTexCoord4dv (const GLdouble *v)
{
 CHECKCONTEXT

 _glTexCoord4dv(v);
}

GLAPI void APIENTRY new_glTexCoord4f (GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
 CHECKCONTEXT

 _glTexCoord4f(s,t,r,q);
}

GLAPI void APIENTRY new_glTexCoord4fv (const GLfloat *v)
{
 CHECKCONTEXT

 _glTexCoord4fv(v);
}

GLAPI void APIENTRY new_glTexCoord4i (GLint s, GLint t, GLint r, GLint q)
{
 CHECKCONTEXT

 _glTexCoord4i(s,t,r,q);
}

GLAPI void APIENTRY new_glTexCoord4iv (const GLint *v)
{
 CHECKCONTEXT

 _glTexCoord4iv(v);
}

GLAPI void APIENTRY new_glTexCoord4s (GLshort s, GLshort t, GLshort r, GLshort q)
{
 CHECKCONTEXT

 _glTexCoord4s(s,t,r,q);
}

GLAPI void APIENTRY new_glTexCoord4sv (const GLshort *v)
{
 CHECKCONTEXT

 _glTexCoord4sv(v);
}

GLAPI void APIENTRY new_glTexGend (GLenum coord, GLenum pname, GLdouble param)
{
 CHECKCONTEXT

 _glTexGend(coord,pname,param);
}

GLAPI void APIENTRY new_glTexGendv (GLenum coord, GLenum pname, const GLdouble *params)
{
 CHECKCONTEXT

 _glTexGendv(coord,pname,params);
}

GLAPI void APIENTRY new_glTexGenf (GLenum coord, GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 _glTexGenf(coord,pname,param);
}

GLAPI void APIENTRY new_glTexGenfv (GLenum coord, GLenum pname, const GLfloat *params)
{
 CHECKCONTEXT

 _glTexGenfv(coord,pname,params);
}

GLAPI void APIENTRY new_glTexGeni (GLenum coord, GLenum pname, GLint param)
{
 CHECKCONTEXT

 _glTexGeni(coord,pname,param);
}

GLAPI void APIENTRY new_glTexGeniv (GLenum coord, GLenum pname, const GLint *params)
{
 CHECKCONTEXT

 _glTexGeniv(coord,pname,params);
}

GLAPI void APIENTRY new_glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
 CHECKCONTEXT

 _glTexImage1D(target,level,internalformat,width,border,format,type,pixels);
}

GLAPI void APIENTRY new_glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
 CHECKCONTEXT

 _glTexSubImage1D(target,level,xoffset,width,format,type,pixels);
}


GLAPI void APIENTRY new_glTranslated (GLdouble x, GLdouble y, GLdouble z)
{
 CHECKCONTEXT

 _glTranslated(x,y,z);
}

GLAPI void APIENTRY new_glTranslatef (GLfloat x, GLfloat y, GLfloat z)
{
 CHECKCONTEXT

 _glTranslatef(x,y,z);
}

GLAPI BOOL WINAPI new_wglUseFontOutlinesA (HDC hdc, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf )
{
 return _wglUseFontOutlinesA(hdc,first,count,listBase,deviation,extrusion,format,lpgmf);
}

GLAPI BOOL WINAPI new_wglUseFontOutlinesW (HDC hdc, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf )
{
 return _wglUseFontOutlinesW(hdc,first,count,listBase,deviation,extrusion,format,lpgmf);
}

GLAPI BOOL WINAPI new_wglUseFontBitmapsA (HDC hdc, DWORD first, DWORD count, DWORD listBase)
{
 return _wglUseFontBitmapsA(hdc,first,count,listBase);
}

GLAPI BOOL WINAPI new_wglUseFontBitmapsW (HDC hdc, DWORD first, DWORD count, DWORD listBase)
{
 return _wglUseFontBitmapsW(hdc,first,count,listBase);
}

GLAPI BOOL WINAPI new_wglCopyContext (HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask)
{
 return _wglCopyContext(hglrcSrc,hglrcDst,mask);
}

GLAPI HGLRC WINAPI new_wglCreateLayerContext (HDC hdc, int iLayerPlane)
{
 return _wglCreateLayerContext(hdc,iLayerPlane);
}

GLAPI HGLRC WINAPI new_wglGetCurrentContext (VOID)
{
 return _wglGetCurrentContext();
}

GLAPI HDC WINAPI new_wglGetCurrentDC (VOID)
{
 return _wglGetCurrentDC();
}

GLAPI BOOL WINAPI new_wglShareLists (HGLRC hglrc1, HGLRC hglrc2)
{
 return _wglShareLists(hglrc1,hglrc2);
}

GLAPI BOOL WINAPI new_wglDescribeLayerPlane (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nBytes, LPLAYERPLANEDESCRIPTOR plpd)
{
 return _wglDescribeLayerPlane(hdc,iPixelFormat,iLayerPlane,nBytes,plpd);
}

GLAPI int WINAPI new_wglSetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, CONST COLORREF *pcr)
{
 return _wglSetLayerPaletteEntries(hdc,iLayerPlane,iStart,cEntries,pcr);
}

GLAPI int WINAPI new_wglGetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, COLORREF *pcr)
{
 return _wglGetLayerPaletteEntries(hdc,iLayerPlane,iStart,cEntries,pcr);
}

GLAPI BOOL WINAPI new_wglRealizeLayerPalette (HDC hdc, int iLayerPlane, BOOL bRealize)
{
 return _wglRealizeLayerPalette(hdc,iLayerPlane,bRealize);
}

GLAPI BOOL WINAPI new_wglSwapLayerBuffers (HDC hdc, UINT fuPlanes)
{
 return _wglSwapLayerBuffers(hdc,fuPlanes);
}

GLAPI int WINAPI new_wglChoosePixelFormat (HDC hdc, CONST PIXELFORMATDESCRIPTOR * ppfd)
{
 return _wglChoosePixelFormat(hdc,ppfd);
}

GLAPI int WINAPI new_wglDescribePixelFormat (HDC hdc, int iPixelFormat, UINT nBytes, LPPIXELFORMATDESCRIPTOR ppfd)
{
 return _wglDescribePixelFormat(hdc,iPixelFormat,nBytes,ppfd);
}

GLAPI int WINAPI new_wglGetPixelFormat (HDC hdc)
{
 return _wglGetPixelFormat(hdc);
}

GLAPI BOOL WINAPI new_wglSetPixelFormat (HDC hdc, int iPixelFormat, CONST PIXELFORMATDESCRIPTOR * ppfd)
{
 return _wglSetPixelFormat(hdc,iPixelFormat,ppfd);
}

GLAPI BOOL WINAPI new_wglSwapBuffers (HDC hdc)
{
 return _wglSwapBuffers(hdc);
}

GLAPI DWORD WINAPI new_wglGetDefaultProcAddress (void)
{
 return _wglGetDefaultProcAddress();
}

GLAPI BOOL WINAPI new_DrvCopyContext (HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask)
{
 return _DrvCopyContext(hglrcSrc,hglrcDst,mask);
}

GLAPI HGLRC WINAPI new_DrvCreateContext (HDC hdc)
{
 return _DrvCreateContext(hdc);
}

GLAPI HGLRC WINAPI new_DrvCreateLayerContext (HDC hdc, int iLayerPlane)
{
 return _DrvCreateLayerContext(hdc,iLayerPlane);
}

GLAPI BOOL WINAPI new_DrvDeleteContext (HGLRC hglrc)
{
 return _DrvDeleteContext(hglrc);
}

GLAPI BOOL WINAPI new_DrvDescribeLayerPlane (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nBytes, LPLAYERPLANEDESCRIPTOR plpd)
{
 return _DrvDescribeLayerPlane(hdc,iPixelFormat,iLayerPlane,nBytes,plpd);
}

GLAPI int WINAPI new_DrvDescribePixelFormat (HDC hdc, int iPixelFormat, UINT nBytes, LPPIXELFORMATDESCRIPTOR ppfd)
{
 return _DrvDescribePixelFormat(hdc,iPixelFormat,nBytes,ppfd);
}

GLAPI int WINAPI new_DrvSetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, CONST COLORREF *pcr)
{
 return _DrvSetLayerPaletteEntries(hdc,iLayerPlane,iStart,cEntries,pcr);
}

GLAPI int WINAPI new_DrvGetLayerPaletteEntries (HDC hdc, int iLayerPlane, int iStart, int cEntries, COLORREF *pcr)
{
 return _DrvGetLayerPaletteEntries(hdc,iLayerPlane,iStart,cEntries,pcr);;
}

GLAPI BOOL WINAPI new_DrvRealizeLayerPalette (HDC hdc, int iLayerPlane, BOOL bRealize)
{
 return _DrvRealizeLayerPalette(hdc,iLayerPlane,bRealize);
}

GLAPI BOOL WINAPI new_DrvSwapLayerBuffers (HDC hdc, UINT fuPlanes)
{
 return _DrvSwapLayerBuffers(hdc,fuPlanes);
}

GLAPI BOOL WINAPI new_DrvShareLists (HGLRC hglrc1, HGLRC hglrc2)
{
 return _DrvShareLists(hglrc1,hglrc2);
}

GLAPI BOOL WINAPI new_DrvSetPixelFormat (HDC hdc, int iPixelFormat, CONST PIXELFORMATDESCRIPTOR * ppfd)
{
 return _DrvSetPixelFormat(hdc,iPixelFormat,ppfd);
}

GLAPI BOOL WINAPI new_DrvSwapBuffers (HDC hdc)
{
 return _DrvSwapBuffers(hdc);
}

GLAPI PROC WINAPI new_DrvGetProcAddress (LPCSTR lpszProc)
{
 return _DrvGetProcAddress(lpszProc);
}

GLAPI int WINAPI new_DrvSetContext (HDC hdc, HGLRC hglrc, SetContextCallBack callback)
{
 return _DrvSetContext(hdc,hglrc,callback);
}

GLAPI DWORD WINAPI new_DrvReleaseContext (VOID)
{
 return _DrvReleaseContext();
}

GLAPI DWORD WINAPI new_DrvValidateVersion (VOID)
{
 return _DrvValidateVersion();
}

GLOPT glopt[] = {
{"compress_all",0},
{"force_resolution",0},
{"xres",0},
{"yres",0},
{"bpp",0},
{"freq",0},
{"tex_large",0},
};

void QueryRegOpt(void)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
 unsigned char tmp[8];
 memset(tmp,0,sizeof(tmp));
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey) == ERROR_SUCCESS)
 {
  // получение необходимых параметров
  for(int a=0;a<countext;a++)
  {
   if (RegQueryValueEx(hkey,glext[a].extname,NULL,&ptype,tmp,&size) == ERROR_SUCCESS)
   {
    if (tmp[0] == 0) glext[a].bl = 0;
     else glext[a].bl = 1;
   }
  }
  RegCloseKey(hkey);
 }

 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey) == ERROR_SUCCESS)
 {
  // получение необходимых параметров
  for(int a=0;a<wcountext;a++)
  {
   if (RegQueryValueEx(hkey,wglext[a].extname,NULL,&ptype,tmp,&size) == ERROR_SUCCESS)
   {
    if (tmp[0] == 0) wglext[a].bl = 0;
     else wglext[a].bl = 1;
   }
  }
  RegCloseKey(hkey);
 }

 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,OPTPATH,&hkey) == ERROR_SUCCESS)
 {
  for (int i = 0; i < sizeof(glopt)/sizeof(GLOPT); i++)
  {
   memset(tmp,0,sizeof(tmp));
   if (RegQueryValueEx(hkey,glopt[i].name,NULL,&ptype,tmp,&size) == ERROR_SUCCESS)
   {
    glopt[i].value = ((int*)tmp)[0];
   }
  }
 }
}

static int resolutions[][2]=
 {{ 320,  200},
  { 320,  240},
  { 400,  256},
  { 400,  300},
  { 512,  256},
  { 512,  384},
  { 640,  200},
  { 640,  350},
  { 640,  400},
  { 640,  480},
  { 800,  600},
  { 856,  480},
  { 960,  720},
  { 1024, 768},
  { 1152, 864},
  { 1280, 960},
  { 1280,1024},
  { 1600,1024},
  { 1600,1200},
  { 1792,1344},
  { 1856,1392},
  { 1920,1440},
  { 2048,1536},
  { 2048,2048}};

HGLRC WINAPI new_wglCreateContext (HDC hdc)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"wglCreateContext(0x%X)\r\n",hdc);
 AddToLog(logbuf);
#endif

 if (glopt[1].value == 1) // force user resolution
 {
  BOOL bl;
  int i;

  DEVMODE devMode;
  devMode.dmSize = sizeof(devMode);

  for (i=0; ;i++)
  {
   bl = EnumDisplaySettings(NULL, i, &devMode);
   if (bl == FALSE) break;
   if (glopt[2].value == (int)devMode.dmPelsWidth &&   // xres
	   glopt[3].value == (int)devMode.dmPelsHeight &&  // yres
	   glopt[4].value == (int)devMode.dmBitsPerPel &&  // bpp
	   glopt[5].value == (int)devMode.dmDisplayFrequency)
   {
	if (devMode.dmDisplayFrequency == 0)
     devMode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;  // win9x
	else
	 devMode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;
	ChangeDisplaySettings(&devMode,CDS_FULLSCREEN);
	break;
   }
  }
 }
 else
 if (glopt[1].value == 2) // force window resolution
 {
  HWND hwnd = WindowFromDC(hdc);
  if (hwnd == 0) goto l1;
  // делаем окно активным
  ShowWindow(hwnd, SW_SHOWNORMAL);
  SetForegroundWindow(hwnd);

  // размеры исходного окна
  RECT rect;
  int xwin,ywin,bpp;

  GetClientRect(hwnd, &rect);
  xwin = rect.right;
  ywin = rect.bottom;

  // определение требуемого разрешения
  for(int i=0;i<sizeof(resolutions)/(sizeof(int)*2);i++)
  {
   if ((xwin<=resolutions[i][0]) && (ywin<=resolutions[i][1])) 
   {
    xwin = resolutions[i][0];
    ywin = resolutions[i][1];
    break;
   }
  }
 
  // определение глубины цвета десктопа
  bpp = GetDeviceCaps(hdc,BITSPIXEL);
  if (bpp < 15) bpp = 16;

  BOOL bl;

  DEVMODE devMode;
  devMode.dmSize = sizeof(devMode);

  for (i=0; ;i++)
  {
   bl = EnumDisplaySettings(NULL, i, &devMode);
   if (bl == FALSE) break;
   if (xwin == (int)devMode.dmPelsWidth &&   // xres
	   ywin == (int)devMode.dmPelsHeight &&  // yres
	   bpp == (int)devMode.dmBitsPerPel)     // bpp
   {
    devMode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	ChangeDisplaySettings(&devMode,CDS_FULLSCREEN);
	break;
   }
  }
 }
l1:;
 return _wglCreateContext(hdc);
}


BOOL WINAPI new_wglDeleteContext (HGLRC hglrc)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"wglDeleteContext(0x%X)\r\n",hglrc);
 AddToLog(logbuf);
#endif

 if (glopt[1].value != 0) // restore resolution
 {
  ChangeDisplaySettings(0,0);
 }

 return _wglDeleteContext(hglrc);
}

BOOL WINAPI new_wglMakeCurrent (HDC hdc, HGLRC hglrc)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"wglMakeCurrent(0x%X,0x%X)\r\n",hdc,hglrc);
 AddToLog(logbuf);
#endif
 
 if (hdc == 0 && hglrc == 0)
  ctx.makecontext = GL_FALSE;
 else
  ctx.makecontext = GL_TRUE;

 return _wglMakeCurrent(hdc,hglrc);
}

GLAPI void APIENTRY new_glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
 CHECKCONTEXT

 _glViewport (x,y,width,height);
}


