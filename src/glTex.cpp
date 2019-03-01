//
// glTex.cpp : glTex* function overloading
//

#include "stdafx.h"

bool subfl = false;

int GetComponents(int format);

//
// Overloaded glTexImage2D
//
// To allow me to fix DXT5 Support
//
// Export: glTexImage2D

// Setup CompressedSurface
static IGXP_D3DSurface8 *surf = 0;

// Hacky source surface
static IGXP_D3DSurface8 *source = 0;

PFNGLCOMPRESSEDTEXIMAGE2DARBPROC imp_glCompressedTexImage2DARB = 0;

void APIENTRY new_glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glTexImage2D(");
 AddToLog(logbuf);	 
 LogGLTargetTexture(target);
 wsprintf(logbuf,",%d,",level);
 AddToLog(logbuf); 
 LogGLInternalFormat(internalformat);
 wsprintf(logbuf,",%d,%d,%d,",width, height, border);
 AddToLog(logbuf); 
 LogGLFormat(format);
 AddToLog(","); 
 LogGLType(type);
 wsprintf(logbuf,",0x%X)\r\n",pixels);
 AddToLog(logbuf);
#endif
 CHECKCONTEXT
 // for auto compress all RGB/RGBA textures
 DetectCard();
 if (glopt[0].value == 1 && (setcard == v5c || setcard == v4c) && border == 0) 
 {
  switch (internalformat)
  {
   case 3:
   case GL_RGB:
   case GL_R3_G3_B2:
   case GL_RGB4:
   case GL_RGB5:
   case GL_RGB8:
   case GL_RGB10:
   case GL_RGB12:
   case GL_RGB16:
	    if (format == GL_RGB || format == GL_BGR_EXT)
	     internalformat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
	    break;
   case 4:
   case GL_RGBA:
   case GL_RGBA2:
   case GL_RGBA4:
   case GL_RGBA8:
   case GL_RGB10_A2:
   case GL_RGBA12:
   case GL_RGBA16:
   case GL_RGB5_A1:
	    if (format == GL_RGBA || format == GL_BGRA_EXT)
	     internalformat = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
	    break;
  }
 }

 switch (internalformat)
 {
  case GL_RGB_S3TC:
  case GL_RGB4_S3TC:
       internalformat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
       break;
  case GL_RGBA_S3TC:
  case GL_RGBA4_S3TC:
       internalformat = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
       break;
 }

 // Translation from GL_S3_s3tc to GL_EXT_texture_compression_s3tc
 //if (internalformat == GL_RGB_S3TC || internalformat == GL_RGB4_S3TC) internalformat = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;

 // Translation from GL_S3_s3tc to GL_EXT_texture_compression_s3tc
 //if (internalformat == GL_RGBA_S3TC || internalformat == GL_RGBA4_S3TC) internalformat = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;

 // We'll compress DXTC ourselves
 if (internalformat >= GL_COMPRESSED_RGB_S3TC_DXT1_EXT && internalformat <= GL_COMPRESSED_RGBA_S3TC_DXT5_EXT &&
		(format == GL_RGBA || format == GL_RGB || format == GL_BGR_EXT || format == GL_BGRA_EXT ) &&
		type == GL_UNSIGNED_BYTE)
 {
  D3DFORMAT d3dFormat;

  // Setup the Direct3D Stuff
  if (!lpD3D) lpD3D = IDirectHack::DirectHackCreate8();
  if (!lpD3DDevice) lpD3D->CreateDevice(0, D3DDEVTYPE_HAL, 0, 0, 0, & lpD3DDevice);

  // Make sure we have the correct opengl Extensions
  //SetupExtensions();
  imp_glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)_wglGetProcAddress("glCompressedTexImage2DARB");

  switch (internalformat)
  {
   case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
   case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
	    d3dFormat = D3DFMT_DXT1;
		break;
   case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
	    d3dFormat = D3DFMT_DXT3;
		break;
   case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
	    d3dFormat = D3DFMT_DXT5;
		break;
  }

/*  // Get the D3DFORMAT for DXT1
  if (internalformat == GL_COMPRESSED_RGB_S3TC_DXT1_EXT || internalformat == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT)
      d3dFormat = D3DFMT_DXT1;
  // Get the D3DFORMAT for DXT3
  else if (internalformat == GL_COMPRESSED_RGBA_S3TC_DXT3_EXT)
		   d3dFormat = D3DFMT_DXT3;
  // Get the D3DFORMAT for DXT5
  else if (internalformat == GL_COMPRESSED_RGBA_S3TC_DXT5_EXT)
           d3dFormat = D3DFMT_DXT5;
*/
  // Setup CompressedSurface
  if (!surf) surf = IGXP_D3DSurface8::Create(d3dFormat, width, height);
   else surf->ReallocSurface(d3dFormat, width, height);

  // GL_RGBA - Needs Conversion
  if (format == GL_RGBA)
  {
   if (!source) source = IGXP_D3DSurface8::Create(D3DFMT_A8R8G8B8, width, height);
	else source->ReallocSurface(D3DFMT_A8R8G8B8, width, height);
   source->CopyFromOpenGL(format, pixels);
  }
  // GL_RGB - Needs Conversion
  else if (format == GL_RGB)
  {
   if (!source) source = IGXP_D3DSurface8::Create(D3DFMT_R8G8B8, width, height);
 	else source->ReallocSurface(D3DFMT_R8G8B8, width, height);
   source->CopyFromOpenGL(format, pixels);
  }
  // GL_BGRA_EXT - No Conversion Required
  if (format == GL_BGRA_EXT)
  {
   if (!source) source = IGXP_D3DSurface8::Create(D3DFMT_A8R8G8B8, width, height, (BYTE*)pixels);
	else source->ReallocSurface(D3DFMT_A8R8G8B8, width, height, (BYTE*)pixels);
  }
  // GL_BGR_EXT - No Conversion Required
  else if (format == GL_BGR_EXT)
  {
   if (!source) source = IGXP_D3DSurface8::Create(D3DFMT_R8G8B8, width, height, (BYTE*)pixels);
    else source->ReallocSurface(D3DFMT_R8G8B8, width, height, (BYTE*)pixels);
  }

  // Compress it
  HRESULT res = D3DXLoadSurfaceFromSurface(
					surf,				// pDestSurface 
					0,					// pDestPalette
					0,					// pDestRect
					source,				// pSrcSurface
					0,					// SrcPalette
					0,					// pSrcRect
					D3DX_DEFAULT,		// Filter 
					0);					// ColorKey


  // Information about the compressed image
  D3DSURFACE_DESC Desc;
  surf->GetDesc(&Desc);

  // Lock it
  D3DLOCKED_RECT locked;
  surf->LockRect(&locked,0,0);

  // Upload it!
  imp_glCompressedTexImage2DARB(target, level, internalformat, width, height, border, Desc.Size, locked.pBits);

  // Unlock
  surf->UnlockRect();

  return;
 }

 // generate mipmap
 if (subfl == false)
 {
  GLTEXTURE *gltex = NULL;
  // поиск текстуры в списке
  for (int i = 0; i < ctx.textures->currentfree; i++)
  {
   gltex = (GLTEXTURE *)ctx.textures->GetElement(i);
   if (gltex == NULL || gltex->numtex != ctx.current_texture) continue;
   if (gltex->generate_mipmap == GL_TRUE)
   {
    subfl = true;
    gluBuild2DMipmaps(GL_TEXTURE_2D,internalformat,width,height,format,type,pixels);
    subfl = false;
    return;
   }
  }
 }

/*
 // rescale large texture down to 256
 if (glopt[6].value == 1 && setcard != v5c && setcard != v4c)
 {
  int scale = 0,smin,smax;
 
  if (width >= height) 
  {
   smax = width;
   smin = height;
  }
  else 
  {
   smax = height;
   smin = width;
  }

  if (smax == 512  && smin > 32)  scale = 2;
  if (smax == 1024 && smin > 64)  scale = 4;
  if (smax == 2048 && smin > 128) scale = 8;

  if (scale > 0)
  {
   if (internalformat == 3 || internalformat == GL_RGB)
   {
#ifdef RB_DEBUG
    AddToLog(" - internalformat = 3\r\n");
#endif
    
	char* src = (char*)pixels;
    char* dst = (char*)GlobalAllocPtr(GPTR,(width/scale)*(height/scale)*3*2);
#ifdef RB_DEBUG
  if (dst == 0) 
  {
   wsprintf(logbuf," - ERROR GlobalAllocPtr = 0x%X\r\n", GetLastError());
   AddToLog(logbuf);
  }
#endif

    char* stdst = dst;
#ifdef RB_DEBUG
    wsprintf(logbuf," - src: 0x%X, dst: 0x%X\r\n",src,dst);
    AddToLog(logbuf);
    wsprintf(logbuf," - src_size_calc: %d(0x%X), dst_size_calc: %d(0x%X)\r\n",width*3*height,width*3*height,(width/scale)*(height/scale)*3,(width/scale)*(height/scale)*3);
    AddToLog(logbuf);
    wsprintf(logbuf," - src_end_calc: 0x%X, dst_end_calc: 0x%X\r\n",src + width*3*height,dst + (width/scale)*(height/scale)*3);
    AddToLog(logbuf);
#endif
    for (int y = 0;y < height/scale ;y++)
    {
     for (int x = 0;x < (width/scale)*3;x+=3)
     {
      dst[x+0] = src[x*scale+0];
      dst[x+1] = src[x*scale+1];
      dst[x+2] = src[x*scale+2];
     }
 	 src += width*3*scale; 
	 dst += (width/scale)*3;
	}   

#ifdef RB_DEBUG
    wsprintf(logbuf," - src_end: 0x%X, dst_end: 0x%X\r\n",src,dst);
    AddToLog(logbuf);
#endif

#ifdef RB_DEBUG
    wsprintf(logbuf," - rescaled(%d,%d) to (%d,%d)\r\n", width, height,width/scale, height/scale);
    AddToLog(logbuf);
    wsprintf(logbuf," - rescaled glTexImage2D(0x%X,0x%X,0x%X,%d,%d,%d,0x%X,0x%X,0x%X)\r\n",target, level, internalformat, width/scale, height/scale, border, format, type, stdst);
    AddToLog(logbuf);
#endif
    _glTexImage2D(target, level, internalformat, width/2, height/2, border, format, type, stdst);
#ifdef RB_DEBUG
    AddToLog(" - rescaled glTexImage2D passed\r\n");
#endif
    GlobalFree(stdst);
    return;
   }
   else
////////////////////////////////////////////////////////////////////////	   
////////////////////////////////////////////////////////////////////////	   
   if (internalformat == 4 || internalformat == GL_RGBA)
   {
#ifdef RB_DEBUG
    AddToLog("internalformat = 4\r\n");
#endif

    char* src = (char*)pixels;
    char* dst = (char*)GlobalAllocPtr(GPTR,(width/scale)*(height/scale)*4*2);

#ifdef RB_DEBUG
  if (dst == 0) 
  {
   wsprintf(logbuf," - ERROR GlobalAllocPtr = 0x%X\r\n", GetLastError());
   AddToLog(logbuf);
  }
#endif
    
	char* stdst = dst;

#ifdef RB_DEBUG
    wsprintf(logbuf," - src: 0x%X, dst: 0x%X\r\n",src,dst);
    AddToLog(logbuf);
    wsprintf(logbuf," - src_size_calc: %d(0x%X), dst_size_calc: %d(0x%X)\r\n",width*4*height,width*4*height,(width/scale)*(height/scale)*4,(width/scale)*(height/scale)*4);
    AddToLog(logbuf);
    wsprintf(logbuf," - src_end_calc: 0x%X, dst_end_calc: 0x%X\r\n",src + width*4*height,dst + (width/scale)*(height/scale)*4);
    AddToLog(logbuf);
#endif

    for (int y = 0;y < height/scale ;y++)
    {
     for (int x = 0;x < (width/scale)*4;x+=4)
     {
      dst[x+0] = src[x*scale+0];
      dst[x+1] = src[x*scale+1];
      dst[x+2] = src[x*scale+2];
      dst[x+3] = src[x*scale+3];
     }
 	 src += width*4*scale;
	 dst += (width/scale)*4;
	}   

#ifdef RB_DEBUG
    wsprintf(logbuf," - src_end: 0x%X, dst_end: 0x%X\r\n",src,dst);
    AddToLog(logbuf);
#endif

#ifdef RB_DEBUG
    wsprintf(logbuf," - rescaled(%d,%d) to (%d,%d)\r\n", width, height,width/scale, height/scale);
    AddToLog(logbuf);
    wsprintf(logbuf," - rescaled glTexImage2D(0x%X,0x%X,0x%X,%d,%d,%d,0x%X,0x%X,0x%X)\r\n",target, level, internalformat, width/scale, height/scale, border, format, type, stdst);
    AddToLog(logbuf);
#endif
    _glTexImage2D(target, level, internalformat, width/scale, height/scale, border, format, type, stdst);
#ifdef RB_DEBUG
    AddToLog(" - rescaled glTexImage2D passed\r\n");
#endif
    GlobalFree(stdst);
    return;
   }
  }
 }
 */
 // Pass it onto the original function
 _glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}



void APIENTRY new_glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glTexParameterf (");
 AddToLog(logbuf); 
 LogGLTargetTexture(target);
 AddToLog(","); 
 LogGLValTexParam(pname);
 sprintf(logbuf,",%g)\r\n",param);
 AddToLog(logbuf); 
#endif

 CHECKCONTEXT
 GLTEXTURE *gltex = NULL;

 if (target == GL_TEXTURE_2D)
 {
  gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
  if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

  switch (pname)
  {
   case GL_GENERATE_MIPMAP_SGIS:
        gltex->generate_mipmap = (GLboolean)param;
	    return;
	    break;
   case GL_TEXTURE_MIN_LOD_SGIS:
        gltex->texture_min_lod = (GLfloat)param;
	    return;
	    break;
   case GL_TEXTURE_MAX_LOD_SGIS:
	    gltex->texture_max_lod = (GLfloat)param;
	    return;
	    break;
   case GL_TEXTURE_BASE_LEVEL_SGIS:
	    gltex->texture_base_level = (GLint)param;
	    return;
	    break;
   case GL_TEXTURE_MAX_LEVEL_SGIS:
	    gltex->texture_max_level = (GLint)param;
	    return;
	    break;
  }
 }
l1:;

 _glTexParameterf(target,pname,param);
}

void APIENTRY new_glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glTexParameterfv (");
 AddToLog(logbuf); 
 LogGLTargetTexture(target);
 AddToLog(","); 
 LogGLValTexParam(pname);
 wsprintf(logbuf,",0x%X)\r\n",params);
 AddToLog(logbuf); 
#endif
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;

 if (target == GL_TEXTURE_2D)
 {
  gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
  if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

  switch (pname)
  {
   case GL_GENERATE_MIPMAP_SGIS:
        gltex->generate_mipmap = (GLboolean)params[0];
	    return;
	    break;
   case GL_TEXTURE_MAX_ANISOTROPY_EXT:
	    gltex->anisotropy = params[0];
	    return;
	    break;
   case GL_TEXTURE_MIN_LOD_SGIS:
        gltex->texture_min_lod = (GLfloat)params[0];
	    return;
	    break;
   case GL_TEXTURE_MAX_LOD_SGIS:
	    gltex->texture_max_lod = (GLfloat)params[0];
	    return;
	    break;
   case GL_TEXTURE_BASE_LEVEL_SGIS:
	    gltex->texture_base_level = (GLint)params[0];
	    return;
	    break;
   case GL_TEXTURE_MAX_LEVEL_SGIS:
	    gltex->texture_max_level = (GLint)params[0];
	    return;
	    break;
  }
 }
l1:;

 _glTexParameterfv(target,pname,params);
}

void APIENTRY new_glTexParameteri (GLenum target, GLenum pname, GLint param)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glTexParameteri (");
 AddToLog(logbuf);
 LogGLTargetTexture(target); 
 AddToLog(",");
 LogGLValTexParam(pname);
 AddToLog(",");
 LogGLValTexParamVal(param);
 AddToLog(")\r\n"); 
#endif

 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;

 if (target == GL_TEXTURE_2D)
 {
  gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
  if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

  switch (pname)
  {
   case GL_GENERATE_MIPMAP_SGIS:
        gltex->generate_mipmap = param;
	    return;
	    break;
   case GL_TEXTURE_MIN_LOD_SGIS:
        gltex->texture_min_lod = (GLfloat)param;
	    return;
	    break;
   case GL_TEXTURE_MAX_LOD_SGIS:
	    gltex->texture_max_lod = (GLfloat)param;
	    return;
	    break;
   case GL_TEXTURE_BASE_LEVEL_SGIS:
	    gltex->texture_base_level = (GLint)param;
	    return;
	    break;
   case GL_TEXTURE_MAX_LEVEL_SGIS:
	    gltex->texture_max_level = (GLint)param;
	    return;
	    break;
  }
 }
l1:;

 _glTexParameteri(target,pname,param);
}

void APIENTRY new_glTexParameteriv (GLenum target, GLenum pname, const GLint *params)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glTexParameteriv (");
 AddToLog(logbuf);
 LogGLTargetTexture(target); 
 AddToLog(","); 
 LogGLValTexParam(pname);
 wsprintf(logbuf,",0x%X)\r\n",params);
 AddToLog(logbuf); 
#endif

 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;

 if (target == GL_TEXTURE_2D)
 {
  gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
  if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

  switch (pname)
  {
   case GL_GENERATE_MIPMAP_SGIS:
        gltex->generate_mipmap = params[0];
	    return;
	    break;
   case GL_TEXTURE_MAX_ANISOTROPY_EXT:
	    gltex->anisotropy = (float)params[0];
	    return;
	    break;
   case GL_TEXTURE_MIN_LOD_SGIS:
        gltex->texture_min_lod = (GLfloat)params[0];
	    return;
	    break;
   case GL_TEXTURE_MAX_LOD_SGIS:
	    gltex->texture_max_lod = (GLfloat)params[0];
	    return;
	    break;
   case GL_TEXTURE_BASE_LEVEL_SGIS:
	    gltex->texture_base_level = (GLint)params[0];
	    return;
	    break;
   case GL_TEXTURE_MAX_LEVEL_SGIS:
	    gltex->texture_max_level = (GLint)params[0];
	    return;
	    break;
  }
 }
l1:;
 _glTexParameteriv(target,pname,params);
}

void APIENTRY new_glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glTexSubImage2D (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;

 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 if (gltex->generate_mipmap == GL_TRUE)
 {
  subfl = true;
  gluBuild2DMipmaps(GL_TEXTURE_2D,GetComponents(format),width,height,format,type,pixels);
  subfl = false;
  return;
 }

l1:;
 _glTexSubImage2D (target,level,xoffset,yoffset,width,height,format,type,pixels);
}

int GetComponents(int format)
{
  switch (format)
  {
   case GL_ALPHA:
   case GL_ALPHA4:
   case GL_ALPHA8:
   case GL_ALPHA12:
   case GL_ALPHA16:
   case GL_LUMINANCE:
   case GL_LUMINANCE4:
   case GL_LUMINANCE8:
   case GL_LUMINANCE12:
   case GL_LUMINANCE16:
   case GL_INTENSITY:
   case GL_INTENSITY4:
   case GL_INTENSITY8:
   case GL_INTENSITY12:
   case GL_INTENSITY16:
	    return 1;
	    break;
   case GL_LUMINANCE4_ALPHA4:
   case GL_LUMINANCE6_ALPHA2:
   case GL_LUMINANCE8_ALPHA8:
   case GL_LUMINANCE12_ALPHA4:
   case GL_LUMINANCE12_ALPHA12:
   case GL_LUMINANCE16_ALPHA16:
	    return 2;
	    break;
   case GL_RGB:
   case GL_R3_G3_B2:
   case GL_RGB4:
   case GL_RGB5:
   case GL_RGB8:
   case GL_RGB10:
   case GL_RGB12:
   case GL_RGB16:
   case GL_BGR:
	    return 3;
	    break;
   case GL_RGBA:
   case GL_RGBA2:
   case GL_RGBA4:
   case GL_RGB5_A1:
   case GL_RGBA8:
   case GL_RGB10_A2:
   case GL_RGBA12:
   case GL_RGBA16:
   case GL_BGRA:
   case GL_ABGR_EXT:
	    return 4;
	    break;
  }
 return 0;
}

void APIENTRY new_glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glGetTexParameterfv (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;

 if (target == GL_TEXTURE_2D)
 {
  gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
  if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;
 
  switch (pname)
  {
   case GL_GENERATE_MIPMAP_SGIS:
        params[0] = gltex->generate_mipmap;
	    return;
	    break;
   case GL_TEXTURE_MAX_ANISOTROPY_EXT:
	    params[0] = gltex->anisotropy;
	    return;
	    break;
   case GL_TEXTURE_MIN_LOD_SGIS:
        params[0] = (GLfloat)gltex->texture_min_lod;
	    return;
	    break;
   case GL_TEXTURE_MAX_LOD_SGIS:
	    params[0] = (GLfloat)gltex->texture_max_lod;
	    return;
	    break;
   case GL_TEXTURE_BASE_LEVEL_SGIS:
	    params[0] = (GLfloat)gltex->texture_base_level;
	    return;
	    break;
   case GL_TEXTURE_MAX_LEVEL_SGIS:
	    params[0] = (GLfloat)gltex->texture_max_level;
	    return;
	    break;
  }
 }

l1:;

 _glGetTexParameterfv (target,pname,params);
}

void APIENTRY new_glGetTexParameteriv (GLenum target, GLenum pname, GLint *params)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glGetTexParameteriv (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;

 if (target == GL_TEXTURE_2D)
 {
  gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
  if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;
  
  switch (pname)
  {
   case GL_GENERATE_MIPMAP_SGIS:
        params[0] = gltex->generate_mipmap;
	    return;
	    break;
   case GL_TEXTURE_MAX_ANISOTROPY_EXT:
	    params[0] = (int)gltex->anisotropy;
	    return;
	    break;
   case GL_TEXTURE_MIN_LOD_SGIS:
        params[0] = (GLint)gltex->texture_min_lod;
	    return;
	    break;
   case GL_TEXTURE_MAX_LOD_SGIS:
	    params[0] = (GLint)gltex->texture_max_lod;
	    return;
	    break;
   case GL_TEXTURE_BASE_LEVEL_SGIS:
	    params[0] = (GLint)gltex->texture_base_level;
	    return;
	    break;
   case GL_TEXTURE_MAX_LEVEL_SGIS:
	    params[0] = (GLint)gltex->texture_max_level;
	    return;
	    break;
  }
 }

l1:;
 _glGetTexParameteriv (target,pname,params);
}

void APIENTRY new_glHint (GLenum target, GLenum mode)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glHint (..)\r\n");
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 switch (target)
 {
  case GL_GENERATE_MIPMAP_HINT_SGIS:
	   ctx.SGIS_generate_mipmaps_hint = mode;
	   return;
	   break;
  case GL_MULTISAMPLE_FILTER_HINT_NV:
	   ctx.NV_multisample_filter_hint = mode;
	   return;
       break;
 }
 _glHint (target,mode);
}

void APIENTRY new_glBindTexture (GLenum target, GLuint texture)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glBindTexture (");
 AddToLog(logbuf);
 LogGLTargetTexture(target);
 wsprintf(logbuf,",0x%X)\r\n",texture);
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 if (target == GL_TEXTURE_2D) ctx.current_texture = texture;
 _glBindTexture(target, texture);
}

void APIENTRY new_glGenTextures (GLsizei n, GLuint *textures)
{
#ifdef RB_DEBUG
 wsprintf(logbuf,"glGenTextures (%d,..)\r\n", n);
 AddToLog(logbuf);
#endif

 CHECKCONTEXT

 _glGenTextures(n,textures);

 if (ctx.textures->currentfree == 0) ctx.textures->AddElement(0);

 for (int i = 0;i < n;i++)
 {
  GLTEXTURE gltex;
  gltex.anisotropy = 1;
  gltex.generate_mipmap = GL_FALSE;
  gltex.point_sprite = GL_FALSE;
  gltex.numtex = textures[i];

#ifdef RB_DEBUG
 wsprintf(logbuf," gltex.numtex = %d\r\n", textures[i]);
 AddToLog(logbuf);
#endif

  ctx.textures->AddElement(&gltex);
#ifdef RB_DEBUG
 AddToLog("AddElement - passed\r\n");
#endif

 }
}

void APIENTRY new_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params)
{
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;
 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 switch (target)
 {
  case GL_POINT_SPRITE_ARB:
       if (pname == GL_COORD_REPLACE_ARB)
	   {
        params[0] = gltex->point_sprite;
        return;
	   }
       break;
  case GL_TEXTURE_FILTER_CONTROL_EXT:
       if (pname == GL_TEXTURE_LOD_BIAS_EXT)
	   {
        params[0] = gltex->texture_lod_bias;
        return;
	   }
       break;
 }

l1:;

 _glGetTexEnvfv(target,pname,params);
}

void APIENTRY new_glGetTexEnviv(GLenum target, GLenum pname, GLint *params)
{
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;
 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 switch (target)
 {
  case GL_POINT_SPRITE_ARB:
       if (pname == GL_COORD_REPLACE_ARB)
	   {
        params[0] = gltex->point_sprite;
        return;
	   }
       break;
  case GL_TEXTURE_FILTER_CONTROL_EXT:
       if (pname == GL_TEXTURE_LOD_BIAS_EXT)
	   {
        params[0] = (GLint)gltex->texture_lod_bias;
        return;
	   }
       break;
 }

l1:;
 
 _glGetTexEnviv(target,pname,params);
}

void APIENTRY new_glTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;
 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 switch (target)
 {
  case GL_POINT_SPRITE_ARB:
       if (pname == GL_COORD_REPLACE_ARB)
	   {
        gltex->point_sprite = (GLboolean)param;
        return;
	   }
       break;
  case GL_TEXTURE_FILTER_CONTROL_EXT:
       if (pname == GL_TEXTURE_LOD_BIAS_EXT)
	   {
        gltex->texture_lod_bias = (GLfloat)param;
        return;
	   }
       break;
 }

l1:;

 _glTexEnvf(target,pname,param);
}

void APIENTRY new_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params)
{
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;
 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 switch (target)
 {
  case GL_POINT_SPRITE_ARB:
       if (pname == GL_COORD_REPLACE_ARB)
	   {
        gltex->point_sprite = (GLboolean)params[0];
        return;
	   }
       break;
  case GL_TEXTURE_FILTER_CONTROL_EXT:
       if (pname == GL_TEXTURE_LOD_BIAS_EXT)
	   {
        gltex->texture_lod_bias = (GLfloat)params[0];
        return;
	   }
       break;
 }

l1:;

 _glTexEnvfv(target,pname,params);
}

void APIENTRY new_glTexEnvi(GLenum target, GLenum pname, GLint param)
{
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;
 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 switch (target)
 {
  case GL_POINT_SPRITE_ARB:
       if (pname == GL_COORD_REPLACE_ARB)
	   {
        gltex->point_sprite = (GLboolean)param;
        return;
	   }
       break;
  case GL_TEXTURE_FILTER_CONTROL_EXT:
       if (pname == GL_TEXTURE_LOD_BIAS_EXT)
	   {
        gltex->texture_lod_bias = (GLfloat)param;
        return;
	   }
       break;
 }

l1:;
 
 _glTexEnvi(target,pname,param);
}

void APIENTRY new_glTexEnviv(GLenum target, GLenum pname, const GLint *params)
{
 CHECKCONTEXT

 GLTEXTURE *gltex = NULL;
 gltex = (GLTEXTURE *)ctx.textures->GetElement(ctx.current_texture);
 if (gltex == NULL || gltex->numtex != ctx.current_texture) goto l1;

 switch (target)
 {
  case GL_POINT_SPRITE_ARB:
       if (pname == GL_COORD_REPLACE_ARB)
	   {
        gltex->point_sprite = (GLboolean)params[0];
        return;
	   }
       break;
  case GL_TEXTURE_FILTER_CONTROL_EXT:
       if (pname == GL_TEXTURE_LOD_BIAS_EXT)
	   {
        gltex->texture_lod_bias = (GLfloat)params[0];
        return;
	   }
       break;
 }

l1:;

 _glTexEnviv(target,pname,params);
}