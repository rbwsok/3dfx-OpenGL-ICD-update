//
// glGet.cpp : glGet* function overloading
//

//{1,1,1,1,1,"GL_EXT_pixel_buffer_object"}, 

#include "stdafx.h"

GLEXT glext[] = {
{1,1,1,0,0,0,0,"GL_3DFX_multisample",              "native 3dfx icd"},
{1,1,0,0,0,0,0,"GL_3DFX_tbuffer",                  ""},
{1,1,1,0,0,0,0,"GL_3DFX_texture_compression_FXT1", "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_APPLE_packed_pixels",           ""},
{1,1,1,0,0,0,0,"GL_ARB_multisample",               ""},
{1,1,1,1,0,1,0,"GL_ARB_multitexture",              "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_ARB_point_parameters",          ""},
{1,1,1,1,1,1,0,"GL_ARB_point_sprite",              ""},
{1,1,1,0,0,0,0,"GL_ARB_texture_compression",       "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_ARB_texture_env_add",           ""},
{1,1,1,0,0,0,0,"GL_ARB_texture_env_combine",       "incomplete support"},
{1,1,1,1,1,1,0,"GL_ARB_transpose_matrix",          ""},
{1,1,1,1,1,1,0,"GL_ARB_vertex_buffer_object",      ""},
{1,1,1,1,1,1,0,"GL_ARB_window_pos",                ""},
{1,1,1,1,1,1,0,"GL_EXT_abgr",                      "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_bgra",                      "native 3dfx icd"},
{1,1,1,0,0,0,0,"GL_EXT_blend_subtract",            "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_clip_volume_hint",          "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_compiled_vertex_array",     "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_draw_range_elements",       ""},
{1,1,1,1,1,1,0,"GL_EXT_fog_coord",                 "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_generate_mipmap",           ""},
{1,1,1,1,1,1,0,"GL_EXT_multi_draw_arrays",         ""},
{1,1,1,1,1,1,0,"GL_EXT_packed_pixels",             "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_paletted_texture",          ""},
{1,1,1,1,1,1,0,"GL_EXT_point_parameters",          "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_rescale_normal",            ""},
{1,1,1,1,1,1,0,"GL_EXT_shared_texture_palette",    ""},
{1,1,1,1,1,1,0,"GL_EXT_stencil_wrap",              "native 3dfx icd"},
{1,1,1,0,0,0,0,"GL_EXT_texture_compression_s3tc",  "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_texture_edge_clamp",        ""},
{1,1,1,1,1,1,0,"GL_EXT_texture_env_add",           "native 3dfx icd"},
{1,1,1,0,0,0,0,"GL_EXT_texture_env_combine",       "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_EXT_texture_filter_anisotropic","fake"},
{1,1,1,1,1,1,0,"GL_EXT_texture_lod_bias",          "fake"},
{1,1,1,1,1,1,0,"GL_EXT_vertex_array",              "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_IBM_multimode_draw_arrays",     ""},
{1,1,1,1,1,1,0,"GL_MESA_window_pos",               ""},
{1,1,1,1,1,1,0,"GL_NV_fence",                      "fake"},
{1,1,1,1,1,1,0,"GL_NV_light_max_exponent",         "fake"},
{1,1,1,0,0,0,0,"GL_NV_multisample_filter_hint",    "fake"},
{1,1,1,1,1,1,0,"GL_NV_pixel_data_range",           "fake"},
{1,1,1,1,1,1,0,"GL_NV_point_sprite",               ""},
{1,1,1,1,1,1,0,"GL_NV_vertex_array_range",         "fake"},
{1,1,1,1,1,1,0,"GL_NV_vertex_array_range2",        "fake"},
{1,1,1,0,0,0,0,"GL_S3_s3tc",                       "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_SGI_texture_edge_clamp",        ""},
{1,1,1,1,1,1,0,"GL_SGIS_generate_mipmap",          ""},
{1,1,1,1,0,1,0,"GL_SGIS_multitexture",             "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_SGIS_texture_edge_clamp",       "native 3dfx icd"},
{1,1,1,1,1,1,0,"GL_SGIS_texture_lod",              "fake"},
{1,1,1,1,1,1,0,"GL_SUN_multi_draw_arrays",         ""},
{1,1,1,1,1,1,0,"GL_WIN_swap_hint",                 ""},
{1,1,1,1,1,1,0,"WGL_3DFX_gamma_control",           "native 3dfx icd"},
{1,1,1,1,1,1,0,"WGL_ARB_extensions_string",        "native 3dfx icd"},
{1,1,1,1,1,1,0,"WGL_EXT_extensions_string",        "native 3dfx icd"},
{1,1,1,1,1,1,0,"WGL_EXT_swap_control",             "native 3dfx icd"}
};

GLEXT wglext[] = {
{1,1,1,1,1,1,0,"WGL_3DFX_gamma_control",           "native 3dfx icd"},
{1,1,1,0,0,0,0,"WGL_3DFX_multisample",             "native 3dfx icd"},
{1,1,1,1,1,1,0,"WGL_ARB_extensions_string",        "native 3dfx icd"},
{1,1,1,0,0,0,0,"WGL_ARB_multisample",              ""},
{1,1,1,1,1,0,0,"WGL_ARB_pixel_format",             "native 3dfx icd"},
{1,1,1,1,1,1,0,"WGL_EXT_extensions_string",        "native 3dfx icd"},
{1,1,1,1,1,1,0,"WGL_EXT_swap_control",             "native 3dfx icd"}
}; 
 
unsigned char* extstr = 0; 
 
int countext = sizeof(glext)/sizeof(GLEXT); 
int wcountext = sizeof(wglext)/sizeof(GLEXT) ;
 
void *GetExtList(void) 
{ 
 return (void*)glext;
}

void *GetWGLExtList(void)
{
 return (void*)wglext;
}

int GetExtCount(void)
{
 return countext;
}

int GetWGLExtCount(void)
{
 return wcountext;
}

int GetVerBuild(void)
{
 return 12;
}

int setcard = 0;

EXT_CARD _fastcall DetectCard(void)
{
 const char * called_renderer;
 
 if (setcard != 0) return (EXT_CARD)setcard;

 called_renderer = (const char*) _glGetString(GL_RENDERER);
 if (_strstr(called_renderer,"Voodoo5")) setcard = v5c;
  else
 if (_strstr(called_renderer,"Voodoo4")) setcard = v4c;
  else
 if (_strstr(called_renderer,"Voodoo3")) setcard = v3c;
  else
 if (_strstr(called_renderer,"Voodoo Banshee")) setcard = vbc;
  else
 if (_strstr(called_renderer,"Voodoo2")) setcard = v2c;
  else
 if (_strstr(called_renderer,"Voodoo1")) setcard = v1c;
  else setcard = vnc;

 return (EXT_CARD)setcard;
}

char * __fastcall _strstr (const char * str1,const char * str2)
{
 char *cp = (char *) str1;
 char *s1, *s2;

 if ( !*str2 ) return((char *)str1);

 while (*cp)
 {
  s1 = cp;
  s2 = (char *) str2;

  while ( *s1 && *s2 && !(*s1-*s2) )
       s1++, s2++;

  if (!*s2) return(cp);

  cp++;
 }

 return(NULL);
}

unsigned char * GetExtensionsList(int card)
{
 // расчет требуемого места
 int siz = 0;
 char* tmp;

 for (int i = 0;i < countext; i++)
 {
  if (glext[i].bl == 1 &&
	  (card == v5c && glext[i].v5 == 1) ||
      (card == v4c && glext[i].v4 == 1) ||
      (card == v3c && glext[i].v3 == 1) ||
      (card == vbc && glext[i].vb == 1) ||
	  (card == v2c && glext[i].v2 == 1))
  siz += lstrlen(glext[i].extname);
 }

 if (extstr != 0) GlobalFree(extstr);
 extstr = (unsigned char*)GlobalAllocPtr(GPTR,siz + countext + 1);
 extstr[0] = 0;
 tmp = (char*)extstr;
 for (i = 0;i < countext; i++)
 {
  if (glext[i].bl == 1 &&
	  (card == v5c && glext[i].v5 == 1) ||
      (card == v4c && glext[i].v4 == 1) ||
      (card == v3c && glext[i].v3 == 1) ||
      (card == vbc && glext[i].vb == 1) ||
	  (card == v2c && glext[i].v2 == 1))
  {
   memcpy(tmp,glext[i].extname,lstrlen(glext[i].extname));
   tmp += lstrlen(glext[i].extname);
   tmp[0] = ' ';
   tmp++;
  }
 }
 tmp--;
 tmp[0] = 0;
 return extstr;
}

unsigned char * GetWglExtensionsList(int card)
{
 // расчет требуемого места
 int siz = 0;
 char* tmp;

 for (int i = 0;i < wcountext; i++)
 {
  if (wglext[i].bl == 1 &&
	  (card == v5c && wglext[i].v5 == 1) ||
      (card == v4c && wglext[i].v4 == 1) ||
      (card == v3c && wglext[i].v3 == 1) ||
      (card == vbc && wglext[i].vb == 1) ||
	  (card == v2c && wglext[i].v2 == 1))
  siz += lstrlen(wglext[i].extname);
 }

 if (extstr != 0) GlobalFree(extstr);
 extstr = (unsigned char*)GlobalAllocPtr (GPTR,siz + wcountext + 1);
 extstr[0] = 0;
 tmp = (char*)extstr;
 for (i = 0;i < wcountext; i++)
 {
  if (wglext[i].bl == 1 &&
	  (card == v5c && wglext[i].v5 == 1) ||
      (card == v4c && wglext[i].v4 == 1) ||
      (card == v3c && wglext[i].v3 == 1) ||
      (card == vbc && wglext[i].vb == 1) ||
	  (card == v2c && wglext[i].v2 == 1))
  {
   memcpy(tmp,wglext[i].extname,lstrlen(wglext[i].extname));
   tmp += lstrlen(wglext[i].extname);
   tmp[0] = ' ';
   tmp++;
  }
 }
 tmp--;
 tmp[0] = 0;
 return extstr;
}

//
// Overloaded glGetString
//

const GLubyte * APIENTRY new_glGetString (GLenum name)
{
#ifdef RB_DEBUG
 AddToLog("glGetString (");
 LogGLGetStrings(name);
 AddToLog(")\r\n");
#endif

 CHECKCONTEXTFALSE
	
 const char * called_gl_string = (const char*) _glGetString(name);
 const char * called_renderer = (const char*) _glGetString(GL_RENDERER);

 if (name == GL_VENDOR)
 {
  //return (const GLubyte *)"3Dfx Interactive Inc., Colourless, Rainbow";
  return (const GLubyte *)"3Dfx Interactive Inc.";
 }
 else if (name == GL_VERSION)
 {
  return (const GLubyte *)"1.1.0.012";
 }
 else if (name == GL_RENDERER)
 {
  static GLubyte * gl_renderer= 0;
  static const char * old_gl_renderer= 0;
  static const char _build[] = "ICD (Feb 07 2006)";
  if (gl_renderer && old_gl_renderer != called_gl_string)
  {
   GlobalFree(gl_renderer);
   gl_renderer = 0;
  }
  old_gl_renderer = called_gl_string;
  if (!gl_renderer)
  {
   gl_renderer = (GLubyte*) GlobalAllocPtr (GPTR,strlen(old_gl_renderer) + sizeof(_build));
   strcpy((char*)gl_renderer, old_gl_renderer);
   gl_renderer[lstrlen((char*)gl_renderer) - 25] = 0;
   strcat((char*)gl_renderer, _build);
  }
  return gl_renderer;
 }
 else if (name == GL_EXTENSIONS)
 {
  GLubyte * ext;

  if (DetectCard() == vnc) ext = (GLubyte *)called_gl_string;
   else ext = GetExtensionsList(setcard);

  return ext;
 }
 return (GLubyte *) called_gl_string;
}

void APIENTRY new_glGetBooleanv (GLenum pname, GLboolean *params)
{
#ifdef RB_DEBUG
 AddToLog("glGetBooleanv(");
 LogGLGetVal(pname);
 AddToLog(")\r\n");
#endif

 CHECKCONTEXT

 switch (pname)
 {
  case GL_MAX_ELEMENTS_VERTICES_EXT:
	   *params = (GLboolean)65535;
	   return;
       break;	  
  case GL_MAX_ELEMENTS_INDICES_EXT:
	   *params = (GLboolean)65535;
	   return;
       break;	  
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   *params = (GLboolean)ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   *params = (GLboolean)ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
	   *params = (GLboolean)ctx.gl_SAMPLE_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_BUFFERS_ARB:
       _glGetBooleanv(GL_SAMPLE_BUFFERS_3DFX,params);
	   return;
	   break;
  case GL_SAMPLES_ARB:
       _glGetBooleanv(GL_SAMPLES_3DFX,params);
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_VALUE_ARB:
	   *params = (GLboolean)ctx.ARB_multisample_value;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_INVERT_ARB:
	   *params = (GLboolean)ctx.ARB_multisample_invert;
	   return;
	   break;
  case GL_GENERATE_MIPMAP_HINT_SGIS:
	   *params = (GLboolean)ctx.SGIS_generate_mipmaps_hint;
	   return;
       break;	  
  case GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT:
	   *params = (GLboolean)2;
	   return;
       break;	  
  case GL_MAX_SHININESS_NV:
	   *params = (GLboolean)128;
	   return;
       break;
  case GL_MAX_SPOT_EXPONENT_NV:
	   *params = (GLboolean)128;
	   return;
       break;
  case GL_RESCALE_NORMAL_EXT:
	   *params = (GLboolean)ctx.gl_RESCALE_NORMAL_EXT;
	   return;
	   break;
  case GL_NORMALIZE:
	   *params = (GLboolean)ctx.gl_NORMALIZE;
	   return;
	   break;
  case GL_TRANSPOSE_MODELVIEW_MATRIX_ARB:
	  {
       static GLboolean n[16];
	   _glGetBooleanv(GL_MODELVIEW_MATRIX,n);
	   transpose_GLboolean(n,params);
	  }
	   break;
  case GL_TRANSPOSE_PROJECTION_MATRIX_ARB:
	  {
       static GLboolean n[16];
	   _glGetBooleanv(GL_PROJECTION_MATRIX,n);
	   transpose_GLboolean(n,params);
	  }
	   break;
  case GL_TRANSPOSE_TEXTURE_MATRIX_ARB:
	  {
       static GLboolean n[16];
	   _glGetBooleanv(GL_TEXTURE_MATRIX,n);
	   transpose_GLboolean(n,params);
	  }
	   break;
  case GL_MULTISAMPLE_FILTER_HINT_NV:
	   *params = (GLboolean)ctx.NV_multisample_filter_hint;
	   return;
       break;
  case GL_MAX_TEXTURE_LOD_BIAS_EXT:
	   *params = (GLboolean)4;
	   return;
       break;
/*  case GL_MAX_TEXTURE_SIZE:
	   if (glopt[6].value == 1) // support large texture
	   {
	    *params = (GLboolean)2048;
		return;
	   }  
	   break;*/
 }

 _glGetBooleanv(pname,params);
}

void APIENTRY new_glGetDoublev (GLenum pname, GLdouble *params)
{
#ifdef RB_DEBUG
 AddToLog("glGetDoublev(");
 LogGLGetVal(pname);
 AddToLog(")\r\n");
#endif
	
 CHECKCONTEXT

 switch (pname)
 {
  case GL_MAX_ELEMENTS_VERTICES_EXT:
	   *params = (GLdouble)65535;
	   return;
       break;	  
  case GL_MAX_ELEMENTS_INDICES_EXT:
	   *params = (GLdouble)65535;
	   return;
       break;	  
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   *params = (GLdouble)ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   *params = (GLdouble)ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
	   *params = (GLdouble)ctx.gl_SAMPLE_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_BUFFERS_ARB:
       _glGetDoublev(GL_SAMPLE_BUFFERS_3DFX,params);
	   return;
	   break;
  case GL_SAMPLES_ARB:
       _glGetDoublev(GL_SAMPLES_3DFX,params);
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_VALUE_ARB:
	   *params = (GLdouble)ctx.ARB_multisample_value;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_INVERT_ARB:
	   *params = (GLdouble)ctx.ARB_multisample_invert;
	   return;
	   break;
  case GL_GENERATE_MIPMAP_HINT_SGIS:
	   *params = (GLdouble)ctx.SGIS_generate_mipmaps_hint;
	   return;
       break;	  
  case GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT:
	   *params = (GLdouble)2.0;
	   return;
       break;
  case GL_MAX_SHININESS_NV:
	   *params = (GLdouble)128.0;
	   return;
       break;
  case GL_MAX_SPOT_EXPONENT_NV:
	   *params = (GLdouble)128.0;
	   return;
       break;
  case GL_RESCALE_NORMAL_EXT:
	   *params = (GLdouble)ctx.gl_RESCALE_NORMAL_EXT;
	   return;
	   break;
  case GL_NORMALIZE:
	   *params = (GLdouble)ctx.gl_NORMALIZE;
	   return;
	   break;
/*  case GL_MAX_TEXTURE_SIZE:
	   if (glopt[6].value == 1) // support large texture
	   {
	    *params = (GLdouble)2048;
		return;
	   }  
	   break;*/
  case GL_TRANSPOSE_MODELVIEW_MATRIX_ARB:
	  {
       static double n[16];
	   _glGetDoublev(GL_MODELVIEW_MATRIX,n);
	   transpose_double(n,params);
	  }
	   break;
  case GL_TRANSPOSE_PROJECTION_MATRIX_ARB:
	  {
       static double n[16];
	   _glGetDoublev(GL_PROJECTION_MATRIX,n);
	   transpose_double(n,params);
	  }
	   break;
  case GL_TRANSPOSE_TEXTURE_MATRIX_ARB:
	  {
       static double n[16];
	   _glGetDoublev(GL_TEXTURE_MATRIX,n);
	   transpose_double(n,params);
	  }
	   break;
  case GL_MULTISAMPLE_FILTER_HINT_NV:
	   *params = (GLdouble)ctx.NV_multisample_filter_hint;
	   return;
       break;
  case GL_MAX_TEXTURE_LOD_BIAS_EXT:
	   *params = (GLdouble)4;
	   return;
       break;

 }

 _glGetDoublev(pname,params);
}

void APIENTRY new_glGetFloatv (GLenum pname, GLfloat *params)
{
#ifdef RB_DEBUG
 AddToLog("glGetFloatv(");
 LogGLGetVal(pname);
 AddToLog(")\r\n");
#endif

 CHECKCONTEXT

 switch (pname)
 {
  case GL_MAX_ELEMENTS_VERTICES_EXT:
	   *params = (GLfloat)65535;
	   return;
       break;	  
  case GL_MAX_ELEMENTS_INDICES_EXT:
	   *params = (GLfloat)65535;
	   return;
       break;	  
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   *params = (GLfloat)ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   *params = (GLfloat)ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
	   *params = (GLfloat)ctx.gl_SAMPLE_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_BUFFERS_ARB:
       _glGetFloatv(GL_SAMPLE_BUFFERS_3DFX,params);
	   return;
	   break;
  case GL_SAMPLES_ARB:
       _glGetFloatv(GL_SAMPLES_3DFX,params);
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_VALUE_ARB:
	   *params = (GLfloat)ctx.ARB_multisample_value;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_INVERT_ARB:
	   *params = (GLfloat)ctx.ARB_multisample_invert;
	   return;
	   break;
  case GL_GENERATE_MIPMAP_HINT_SGIS:
	   *params = (GLfloat)ctx.SGIS_generate_mipmaps_hint;
	   return;
       break;
  case GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT:
	   *params = (GLfloat)2.0;
	   return;
       break;
  case GL_MAX_SHININESS_NV:
	   *params = (GLfloat)128.0;
	   return;
       break;
  case GL_MAX_SPOT_EXPONENT_NV:
	   *params = (GLfloat)128.0;
	   return;
       break;
  case GL_RESCALE_NORMAL_EXT:
	   *params = (GLfloat)ctx.gl_RESCALE_NORMAL_EXT;
	   return;
	   break;
  case GL_NORMALIZE:
	   *params = (GLfloat)ctx.gl_NORMALIZE;
	   return;
	   break;
  case GL_TRANSPOSE_MODELVIEW_MATRIX_ARB:
	  {
       static float n[16];
	   _glGetFloatv(GL_MODELVIEW_MATRIX,n);
	   transpose_float(n,params);
	  }
	   break;
  case GL_TRANSPOSE_PROJECTION_MATRIX_ARB:
	  {
       static float n[16];
	   _glGetFloatv(GL_PROJECTION_MATRIX,n);
	   transpose_float(n,params);
	  }
	   break;
  case GL_TRANSPOSE_TEXTURE_MATRIX_ARB:
	  {
       static float n[16];
	   _glGetFloatv(GL_TEXTURE_MATRIX,n);
	   transpose_float(n,params);
	  }
	   break;
/*  case GL_MAX_TEXTURE_SIZE:
	   if (glopt[6].value == 1) // support large texture
	   {
	    *params = (GLfloat)2048;
		return;
	   }  
	   break;*/
  case GL_MULTISAMPLE_FILTER_HINT_NV:
	   *params = (GLfloat)ctx.NV_multisample_filter_hint;
	   return;
       break;
  case GL_MAX_TEXTURE_LOD_BIAS_EXT:
	   *params = (GLfloat)4;
	   return;
       break;
 }

 _glGetFloatv(pname,params);
}

void APIENTRY new_glGetIntegerv (GLenum pname, GLint *params)
{
#ifdef RB_DEBUG
 AddToLog("glGetIntegerv(");
 LogGLGetVal(pname);
 AddToLog(")\r\n");
#endif

 CHECKCONTEXT

 switch (pname)
 {
  case GL_MAX_ELEMENTS_VERTICES_EXT:
	   *params = (GLint)65535;
	   return;
       break;	  
  case GL_MAX_ELEMENTS_INDICES_EXT:
	   *params = (GLint)65535;
	   return;
       break;	  
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
	   *params = (GLint)ctx.gl_SAMPLE_ALPHA_TO_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
	   *params = (GLint)ctx.gl_SAMPLE_ALPHA_TO_ONE_ARB;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
	   *params = (GLint)ctx.gl_SAMPLE_COVERAGE_ARB;
	   return;
	   break;
  case GL_SAMPLE_BUFFERS_ARB:
       _glGetIntegerv(GL_SAMPLE_BUFFERS_3DFX,params);
	   return;
	   break;
  case GL_SAMPLES_ARB:
       _glGetIntegerv(GL_SAMPLES_3DFX,params);
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_VALUE_ARB:
	   *params = (GLint)ctx.ARB_multisample_value;
	   return;
	   break;
  case GL_SAMPLE_COVERAGE_INVERT_ARB:
	   *params = (GLint)ctx.ARB_multisample_invert;
	   return;
	   break;
  case GL_GENERATE_MIPMAP_HINT_SGIS:
	   *params = (GLint)ctx.SGIS_generate_mipmaps_hint;
	   return;
       break;	  
  case GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT:
	   *params = (GLint)2;
	   return;
       break;	  
  case GL_MAX_SHININESS_NV:
	   *params = (GLint)128;
	   return;
       break;
  case GL_MAX_SPOT_EXPONENT_NV:
	   *params = (GLint)128;
	   return;
       break;
  case GL_RESCALE_NORMAL_EXT:
	   *params = (GLint)ctx.gl_RESCALE_NORMAL_EXT;
	   return;
	   break;
  case GL_NORMALIZE:
	   *params = (GLint)ctx.gl_NORMALIZE;
	   return;
	   break;
  case GL_TRANSPOSE_MODELVIEW_MATRIX_ARB:
	  {
       static int n[16];
	   _glGetIntegerv(GL_MODELVIEW_MATRIX,n);
	   transpose_int(n,params);
	  }
	   break;
  case GL_TRANSPOSE_PROJECTION_MATRIX_ARB:
	  {
       static int n[16];
	   _glGetIntegerv(GL_PROJECTION_MATRIX,n);
	   transpose_int(n,params);
	  }
	   break;
  case GL_TRANSPOSE_TEXTURE_MATRIX_ARB:
	  {
       static int n[16];
	   _glGetIntegerv(GL_TEXTURE_MATRIX,n);
	   transpose_int(n,params);
	  }
	   break;
  case GL_MULTISAMPLE_FILTER_HINT_NV:
	   *params = (GLint)ctx.NV_multisample_filter_hint;
	   return;
       break;	  
  case GL_MAX_TEXTURE_LOD_BIAS_EXT:
	   *params = (GLint)4;
	   return;
       break;
/*  case GL_MAX_TEXTURE_SIZE:
	   if (glopt[6].value == 1) // support large texture
	   {
	    *params = (GLint)2048;
		return;
	   }  
	   break;*/
 }

 _glGetIntegerv(pname,params);
}


const char * WINAPI wglGetExtensionsStringARB(HDC hdc)
{
 if (DetectCard() == vnc) return "";
  
 return (char*)GetWglExtensionsList(setcard);
}

const char * WINAPI wglGetExtensionsStringEXT(void)
{  
 return (char*)wglGetExtensionsStringARB(0);
}
