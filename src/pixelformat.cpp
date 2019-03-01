//
// WGL_ARB_pixel_format
//

#include "stdafx.h"

PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivA;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvA;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatA;

BOOL WINAPI wglGetPixelFormatAttribiv_ARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues)
{
(FARPROC &)wglGetPixelFormatAttribivA = _wglGetProcAddress("wglGetPixelFormatAttribivARB");
 bool v5 = false;
 bool v4 = false;
 const char *renderer = (const char*)_glGetString(GL_RENDERER);
 if (strstr(renderer,"Voodoo5")) v5 = true;
 if (strstr(renderer,"Voodoo4")) v4 = true;
 int sba = -1,sa = -1;

 int *iAttributes = (int*)piAttributes;
 for (unsigned int i = 0;i<nAttributes;i++)
 {
  switch (iAttributes[i])
  {
   case WGL_SAMPLE_BUFFERS_ARB:
        iAttributes[i] = WGL_SAMPLE_BUFFERS_3DFX;
		sba = i;
        break;
   case WGL_SAMPLES_ARB:
        iAttributes[i] = WGL_SAMPLES_3DFX;
		sa = i;
        break;
  }
 }

 BOOL rget = wglGetPixelFormatAttribivA(hdc,iPixelFormat,iLayerPlane,nAttributes,piAttributes,piValues);

 for (i = 0;i<nAttributes;i++)
 {
  switch (iAttributes[i])
  {
   case WGL_SAMPLE_BUFFERS_3DFX:
        if ((iPixelFormat == 4 && v5 == true) ||
            (iPixelFormat == 3 && v4 == true))
         piValues[i] = 1;
        break;
   case WGL_SAMPLES_3DFX:
		if (iPixelFormat == 4 && v5 == true)
         piValues[i] = 4;
		if (iPixelFormat == 3 && v4 == true)
         piValues[i] = 2;
        break;
  }
 }

 if (sba != -1)
  iAttributes[sba] = WGL_SAMPLE_BUFFERS_ARB;
 if (sa != -1)
  iAttributes[sa] = WGL_SAMPLES_ARB;

 return rget;
}

BOOL WINAPI wglGetPixelFormatAttribfv_ARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues)
{
 (FARPROC &)wglGetPixelFormatAttribfvA = _wglGetProcAddress("wglGetPixelFormatAttribfvARB");
 bool v5 = false;
 bool v4 = false;
 const char *renderer = (const char*)_glGetString(GL_RENDERER);
 if (strstr(renderer,"Voodoo5")) v5 = true;
 if (strstr(renderer,"Voodoo4")) v4 = true;
 int sba = -1,sa = -1;

 int *iAttributes = (int*)piAttributes;
 for (unsigned int i = 0;i<nAttributes;i++)
 {
  switch (iAttributes[i])
  {
   case WGL_SAMPLE_BUFFERS_ARB:
        iAttributes[i] = WGL_SAMPLE_BUFFERS_3DFX;
		sba = i;
        break;
   case WGL_SAMPLES_ARB:
        iAttributes[i] = WGL_SAMPLES_3DFX;
		sa = i;
        break;
  }
 }

 BOOL rget = wglGetPixelFormatAttribfvA(hdc,iPixelFormat,iLayerPlane,nAttributes,piAttributes,pfValues);

 for (i = 0;i<nAttributes;i++)
 {
  switch (iAttributes[i])
  {
   case WGL_SAMPLE_BUFFERS_3DFX:
        if ((iPixelFormat == 4 && v5 == true) ||
            (iPixelFormat == 3 && v4 == true))
         pfValues[i] = 1;
        break;
   case WGL_SAMPLES_3DFX:
		if (iPixelFormat == 4 && v5 == true)
         pfValues[i] = 4;
		if (iPixelFormat == 3 && v4 == true)
         pfValues[i] = 2;
        break;
  }
 }

 if (sba != -1)
  iAttributes[sba] = WGL_SAMPLE_BUFFERS_ARB;
 if (sa != -1)
  iAttributes[sa] = WGL_SAMPLES_ARB;

 return rget;
}

BOOL WINAPI wglChoosePixelFormat_ARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)
{
 (FARPROC &)wglChoosePixelFormatA = _wglGetProcAddress("wglChoosePixelFormatARB");
 int *iAttributes = (int*)piAttribIList;
 float *fAttributes = (float*)pfAttribFList;
 bool change = false;
 bool iatr = true,fatr = true;

 if (iAttributes == 0) iatr = false;
 if (fAttributes == 0) fatr = false;

 for (int i=0;;i+=2)
 {
  if (iatr == true)
  {
   switch (iAttributes[i])
   {
    case 0: 
         iatr = false;
	     break;
    case WGL_SAMPLE_BUFFERS_ARB:
	     iAttributes[i] = WGL_SAMPLE_BUFFERS_3DFX;
	     change = true;
         break;
    case WGL_SAMPLES_ARB:
         iAttributes[i] = WGL_SAMPLES_3DFX;
	     change = true;
         break;
   }
  }
  if (fatr == true)
  {
   switch ((int)(fAttributes[i]))
   {
    case 0: 
         fatr = false;
	     break;
    case WGL_SAMPLE_BUFFERS_ARB:
	     fAttributes[i] = WGL_SAMPLE_BUFFERS_3DFX;
	     change = true;
         break;
    case WGL_SAMPLES_ARB:
         fAttributes[i] = WGL_SAMPLES_3DFX;
	     change = true;
         break;
   }
  }
  if (fatr == false && iatr == false) break;
 }

 BOOL rget = wglChoosePixelFormatA(hdc,piAttribIList,pfAttribFList,nMaxFormats,piFormats,nNumFormats);

 iatr = fatr = true;
 if (iAttributes == 0) iatr = false;
 if (fAttributes == 0) fatr = false;
 
 bool patr = true;
 
 if (change == true)
 {
  for (int i=0;;i+=2)
  {
   if (iatr == true)
   {
    switch (iAttributes[i])
    {
     case 0: 
          iatr = false;
	      break;
     case WGL_SAMPLE_BUFFERS_ARB:
	      iAttributes[i] = WGL_SAMPLE_BUFFERS_3DFX;
          break;
     case WGL_SAMPLES_ARB:
          iAttributes[i] = WGL_SAMPLES_3DFX;
          break;
    }
   }
   if (fatr == true)
   {
    switch ((int)(fAttributes[i]))
    {
     case 0: 
          fatr = false;
	      break;
     case WGL_SAMPLE_BUFFERS_ARB:
	      fAttributes[i] = WGL_SAMPLE_BUFFERS_3DFX;
          break;
     case WGL_SAMPLES_ARB:
          fAttributes[i] = WGL_SAMPLES_3DFX;
          break;
    }
   }
   if (patr == true)
   {
    switch (piFormats[i])
    {
     case 0: 
          patr = false;
          break;
     case WGL_SAMPLE_BUFFERS_3DFX:
          piFormats[i] = WGL_SAMPLE_BUFFERS_ARB;
          break;
     case WGL_SAMPLES_3DFX:
          piFormats[i] = WGL_SAMPLES_ARB;
          break;
    }
   }
   if (fatr == false && iatr == false && patr == false) break;
  }
 }

 return rget;
}

PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB = wglGetPixelFormatAttribiv_ARB;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB = wglGetPixelFormatAttribfv_ARB;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = wglChoosePixelFormat_ARB;
