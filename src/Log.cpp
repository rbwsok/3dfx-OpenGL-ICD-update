#include "stdafx.h"

#ifdef RB_DEBUG

char logbuf[256];
char logname[] = "opengl.log";

////////////////////////////////////////////////////////////////////// 
// Добавить в log файл
////////////////////////////////////////////////////////////////////// 
void AddToLog(char* log)
{
 int hFile;
 hFile = _lopen(logname, OF_WRITE);
 if (hFile == -1)
 {
  _lcreat(logname,0);
  hFile = _lopen(logname, OF_WRITE);
 }
 _llseek(hFile, 0, 2);
 _lwrite(hFile,log,lstrlen(log));
 _lclose(hFile);
}

void LogGLTargetTexture(GLenum target)
{
 switch(target)
 {
  case GL_TEXTURE_1D:
       wsprintf(logbuf,"GL_TEXTURE_1D");
	   break;
  case GL_TEXTURE_2D:
       wsprintf(logbuf,"GL_TEXTURE_2D");
	   break;
  case GL_TEXTURE_3D:
       wsprintf(logbuf,"GL_TEXTURE_3D");
	   break;
  default:
       wsprintf(logbuf,"0x%X",target);
 }
 AddToLog(logbuf);
}

void LogGLInternalFormat(GLenum internalformat)
{
 switch (internalformat)
 {
  case 1:
       wsprintf(logbuf,"3");
	   break;
  case 2:
       wsprintf(logbuf,"3");
	   break;
  case 3:
       wsprintf(logbuf,"3");
	   break;
  case 4:
       wsprintf(logbuf,"3");
	   break;
  case GL_RGB:
       wsprintf(logbuf,"GL_RGB");
	   break;
  case GL_R3_G3_B2:
       wsprintf(logbuf,"GL_R3_G3_B2");
	   break;
  case GL_RGB4:
       wsprintf(logbuf,"GL_RGB4");
	   break;
  case GL_RGB5:
       wsprintf(logbuf,"GL_RGB5");
	   break;
  case GL_RGB8:
       wsprintf(logbuf,"GL_RGB8");
	   break;
  case GL_RGB10:
       wsprintf(logbuf,"GL_RGB10");
	   break;
  case GL_RGB12:
       wsprintf(logbuf,"GL_RGB12");
	   break;
  case GL_RGB16:
       wsprintf(logbuf,"GL_RGB16");
	   break;
  case GL_RGBA:
       wsprintf(logbuf,"GL_RGBA");
	   break;
  case GL_RGBA2:
       wsprintf(logbuf,"GL_RGBA2");
	   break;
  case GL_RGBA4:
       wsprintf(logbuf,"GL_RGBA4");
	   break;
  case GL_RGBA8:
       wsprintf(logbuf,"GL_RGBA8");
	   break;
  case GL_RGB10_A2:
       wsprintf(logbuf,"GL_RGB10_A2");
	   break;
  case GL_RGBA12:
       wsprintf(logbuf,"GL_RGBA12");
	   break;
  case GL_RGBA16:
       wsprintf(logbuf,"GL_RGBA16");
	   break;
  case GL_RGB5_A1:
       wsprintf(logbuf,"GL_RGB5_A1");
	   break;
  case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
       wsprintf(logbuf,"GL_COMPRESSED_RGB_S3TC_DXT1_EXT");
	   break;
  case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
       wsprintf(logbuf,"GL_COMPRESSED_RGBA_S3TC_DXT1_EXT");
	   break;
  case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
       wsprintf(logbuf,"GL_COMPRESSED_RGBA_S3TC_DXT3_EXT");
	   break;
  case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
       wsprintf(logbuf,"GL_COMPRESSED_RGBA_S3TC_DXT5_EXT");
	   break;
  case GL_RGB_S3TC:
       wsprintf(logbuf,"GL_RGB_S3TC");
	   break;
  case GL_RGB4_S3TC:
       wsprintf(logbuf,"GL_RGB4_S3TC");
	   break;
  case GL_RGBA_S3TC:
       wsprintf(logbuf,"GL_RGBA_S3TC");
	   break;
  case GL_RGBA4_S3TC:
       wsprintf(logbuf,"GL_RGBA4_S3TC");
	   break;
  case GL_ALPHA:
       wsprintf(logbuf,"GL_ALPHA");
	   break;
  case GL_ALPHA4:
       wsprintf(logbuf,"GL_ALPHA4");
	   break;
  case GL_ALPHA8:
       wsprintf(logbuf,"GL_ALPHA8");
	   break;
  case GL_ALPHA12:
       wsprintf(logbuf,"GL_ALPHA12");
	   break;
  case GL_ALPHA16:
       wsprintf(logbuf,"GL_ALPHA16");
	   break;
  case GL_LUMINANCE:
       wsprintf(logbuf,"GL_LUMINANCE");
	   break;
  case GL_LUMINANCE4:
       wsprintf(logbuf,"GL_LUMINANCE4");
	   break;
  case GL_LUMINANCE8:
       wsprintf(logbuf,"GL_LUMINANCE8");
	   break;
  case GL_LUMINANCE12:
       wsprintf(logbuf,"GL_LUMINANCE12");
	   break;
  case GL_LUMINANCE16:
       wsprintf(logbuf,"GL_LUMINANCE16");
	   break;
  case GL_LUMINANCE_ALPHA:
       wsprintf(logbuf,"GL_LUMINANCE_ALPHA");
	   break;
  case GL_LUMINANCE4_ALPHA4:
       wsprintf(logbuf,"GL_LUMINANCE4_ALPHA4");
	   break;
  case GL_LUMINANCE6_ALPHA2:
       wsprintf(logbuf,"GL_LUMINANCE6_ALPHA2");
	   break;
  case GL_LUMINANCE8_ALPHA8:
       wsprintf(logbuf,"GL_LUMINANCE8_ALPHA8");
	   break;
  case GL_LUMINANCE12_ALPHA4:
       wsprintf(logbuf,"GL_LUMINANCE12_ALPHA4");
	   break;
  case GL_LUMINANCE12_ALPHA12:
       wsprintf(logbuf,"GL_LUMINANCE12_ALPHA12");
	   break;
  case GL_LUMINANCE16_ALPHA16:
       wsprintf(logbuf,"GL_LUMINANCE16_ALPHA16");
	   break;
  case GL_INTENSITY:
       wsprintf(logbuf,"GL_INTENSITY");
	   break;
  case GL_INTENSITY4:
       wsprintf(logbuf,"GL_INTENSITY4");
	   break;
  case GL_INTENSITY8:
       wsprintf(logbuf,"GL_INTENSITY8");
	   break;
  case GL_INTENSITY12:
       wsprintf(logbuf,"GL_INTENSITY12");
	   break;
  case GL_INTENSITY16:
       wsprintf(logbuf,"GL_INTENSITY16");
	   break;
  default:
       wsprintf(logbuf,"0x%X",internalformat);
 }
 AddToLog(logbuf);
}

void LogGLFormat(GLenum format)
{
 switch (format)
 {
  case GL_COLOR_INDEX:
       wsprintf(logbuf,"GL_COLOR_INDEX");
	   break;
  case GL_RED:
       wsprintf(logbuf,"GL_RED");
	   break;
  case GL_GREEN:
       wsprintf(logbuf,"GL_GREEN");
	   break;
  case GL_BLUE:
       wsprintf(logbuf,"GL_BLUE");
	   break;
  case GL_RGBA:
       wsprintf(logbuf,"GL_RGBA");
	   break;
  case GL_RGB:
       wsprintf(logbuf,"GL_RGB");
	   break;
  case GL_LUMINANCE:
       wsprintf(logbuf,"GL_LUMINANCE");
	   break;
  case GL_LUMINANCE_ALPHA:
       wsprintf(logbuf,"GL_LUMINANCE_ALPHA");
	   break;
  case GL_BGRA_EXT:
       wsprintf(logbuf,"GL_BGRA_EXT");
	   break;
  case GL_BGR_EXT:
       wsprintf(logbuf,"GL_BGR_EXT");
	   break;  
  default:
       wsprintf(logbuf,"0x%X",format);
 }
 AddToLog(logbuf);
}

void LogGLType(GLenum type)
{
 switch (type)
 {
  case GL_UNSIGNED_BYTE:
       wsprintf(logbuf,"GL_UNSIGNED_BYTE");
	   break;
  case GL_BYTE:
       wsprintf(logbuf,"GL_BYTE");
	   break;
  case GL_BITMAP:
       wsprintf(logbuf,"GL_BITMAP");
	   break;
  case GL_UNSIGNED_SHORT:
       wsprintf(logbuf,"GL_UNSIGNED_SHORT");
	   break;
  case GL_SHORT:
       wsprintf(logbuf,"GL_SHORT");
	   break;
  case GL_UNSIGNED_INT:
       wsprintf(logbuf,"GL_UNSIGNED_INT");
	   break;
  case GL_INT:
       wsprintf(logbuf,"GL_INT");
	   break;
  case GL_FLOAT:
       wsprintf(logbuf,"GL_FLOAT");
	   break;
  default:
       wsprintf(logbuf,"0x%X",type);
 }
 AddToLog(logbuf);
}

void LogGLValTexParam(GLenum param)
{
 switch (param)
 {
  case GL_TEXTURE_MIN_FILTER:
       wsprintf(logbuf,"GL_TEXTURE_MIN_FILTER");
	   break;
  case GL_TEXTURE_MAG_FILTER:
       wsprintf(logbuf,"GL_TEXTURE_MAG_FILTER");
	   break;
  case GL_TEXTURE_WRAP_S:
       wsprintf(logbuf,"GL_TEXTURE_WRAP_S");
	   break;
  case GL_TEXTURE_WRAP_T:
       wsprintf(logbuf,"GL_TEXTURE_WRAP_T");
	   break;
  case GL_TEXTURE_BORDER_COLOR:
       wsprintf(logbuf,"GL_TEXTURE_BORDER_COLOR");
	   break;
  case GL_TEXTURE_PRIORITY:
       wsprintf(logbuf,"GL_TEXTURE_PRIORITY");
	   break;  
  case GL_GENERATE_MIPMAP_SGIS:
       wsprintf(logbuf,"GL_GENERATE_MIPMAP_SGIS");
	   break;
  case GL_TEXTURE_MAX_ANISOTROPY_EXT:
       wsprintf(logbuf,"GL_TEXTURE_MAX_ANISOTROPY_EXT");
	   break;
  default:
       wsprintf(logbuf,"0x%X",param);
 }
 AddToLog(logbuf);
}

void LogGLValTexParamVal(GLenum param)
{
 switch (param)
 {
  case GL_NEAREST:
       wsprintf(logbuf,"GL_NEAREST");
	   break;
  case GL_LINEAR:
       wsprintf(logbuf,"GL_LINEAR");
	   break;
  case GL_NEAREST_MIPMAP_NEAREST:
       wsprintf(logbuf,"GL_NEAREST_MIPMAP_NEAREST");
	   break;
  case GL_LINEAR_MIPMAP_NEAREST:
       wsprintf(logbuf,"GL_LINEAR_MIPMAP_NEAREST");
	   break;
  case GL_NEAREST_MIPMAP_LINEAR:
       wsprintf(logbuf,"GL_NEAREST_MIPMAP_LINEAR");
	   break;
  case GL_LINEAR_MIPMAP_LINEAR:
       wsprintf(logbuf,"GL_LINEAR_MIPMAP_LINEAR");
	   break;
  case GL_CLAMP:
       wsprintf(logbuf,"GL_CLAMP");
	   break;
  case GL_REPEAT:
       wsprintf(logbuf,"GL_REPEAT");
	   break;

  default:
       wsprintf(logbuf,"0x%X",param);
 }
 AddToLog(logbuf);
}
 
void LogGLGetStrings(GLenum param)
{
 switch (param)
 {
  case GL_VENDOR:
       wsprintf(logbuf,"GL_VENDOR");
	   break;
  case GL_RENDERER:
       wsprintf(logbuf,"GL_RENDERER");
	   break;
  case GL_VERSION:
       wsprintf(logbuf,"GL_VERSION");
	   break;
  case GL_EXTENSIONS:
       wsprintf(logbuf,"GL_EXTENSIONS");
	   break;
  default:
       wsprintf(logbuf,"0x%X",param);
 }
 AddToLog(logbuf);
}

void LogGLGetVal(GLenum param)
{
 switch (param)
 {
  case GL_ACCUM_RED_BITS:
       wsprintf(logbuf,"GL_ACCUM_RED_BITS");
       break;
  case GL_ACCUM_GREEN_BITS:
       wsprintf(logbuf,"GL_ACCUM_GREEN_BITS");
       break;
  case GL_ACCUM_BLUE_BITS:
       wsprintf(logbuf,"GL_ACCUM_BLUE_BITS");
       break;
  case GL_ACCUM_ALPHA_BITS:
       wsprintf(logbuf,"GL_ACCUM_ALPHA_BITS");
       break;
  case GL_ACCUM_CLEAR_VALUE:
       wsprintf(logbuf,"GL_ACCUM_CLEAR_VALUE");
       break;
  case GL_ALPHA_BIAS:
       wsprintf(logbuf,"GL_ALPHA_BIAS");
       break;
  case GL_ALPHA_BITS:
       wsprintf(logbuf,"GL_ALPHA_BITS");
       break;
  case GL_ALPHA_SCALE:
       wsprintf(logbuf,"GL_ALPHA_SCALE");
       break;
  case GL_ALPHA_TEST:
       wsprintf(logbuf,"GL_ALPHA_TEST");
       break;
  case GL_ALPHA_TEST_FUNC:
       wsprintf(logbuf,"GL_ALPHA_TEST_FUNC");
       break;
  case GL_ALPHA_TEST_REF:
       wsprintf(logbuf,"GL_ALPHA_TEST_REF");
       break;
  case GL_ATTRIB_STACK_DEPTH:
       wsprintf(logbuf,"GL_ATTRIB_STACK_DEPTH");
       break;
  case GL_AUTO_NORMAL:
       wsprintf(logbuf,"GL_AUTO_NORMAL");
       break;
  case GL_AUX_BUFFERS:
       wsprintf(logbuf,"GL_AUX_BUFFERS");
       break;
  case GL_BLEND:
       wsprintf(logbuf,"GL_BLEND");
       break;
  case GL_BLEND_DST:
       wsprintf(logbuf,"GL_BLEND_DST");
       break;
  case GL_BLEND_SRC:
       wsprintf(logbuf,"GL_BLEND_SRC");
       break;
  case GL_BLUE_BIAS:
       wsprintf(logbuf,"GL_BLUE_BIAS");
       break;
  case GL_BLUE_BITS:
       wsprintf(logbuf,"GL_BLUE_BITS");
       break;
  case GL_BLUE_SCALE:
       wsprintf(logbuf,"GL_BLUE_SCALE");
       break;
  case GL_CLIENT_ATTRIB_STACK_DEPTH:
       wsprintf(logbuf,"GL_CLIENT_ATTRIB_STACK_DEPTH");
       break;
  case GL_CLIP_PLANE0:
       wsprintf(logbuf,"GL_CLIP_PLANE0");
       break;
  case GL_CLIP_PLANE1:
       wsprintf(logbuf,"GL_CLIP_PLANE1");
       break;
  case GL_CLIP_PLANE2:
       wsprintf(logbuf,"GL_CLIP_PLANE2");
       break;
  case GL_CLIP_PLANE3:
       wsprintf(logbuf,"GL_CLIP_PLANE3");
       break;
  case GL_CLIP_PLANE4:
       wsprintf(logbuf,"GL_CLIP_PLANE4");
       break;
  case GL_CLIP_PLANE5:
       wsprintf(logbuf,"GL_CLIP_PLANE5");
       break;
  case GL_COLOR_CLEAR_VALUE:
       wsprintf(logbuf,"GL_COLOR_CLEAR_VALUE");
       break;
  case GL_COLOR_MATERIAL:
       wsprintf(logbuf,"GL_COLOR_MATERIAL");
       break;
  case GL_COLOR_MATERIAL_FACE:
       wsprintf(logbuf,"GL_COLOR_MATERIAL_FACE");
       break;
  case GL_COLOR_MATERIAL_PARAMETER:
       wsprintf(logbuf,"GL_COLOR_MATERIAL_PARAMETER");
       break;
  case GL_COLOR_WRITEMASK:
       wsprintf(logbuf,"GL_COLOR_WRITEMASK");
       break;
  case GL_CULL_FACE:
       wsprintf(logbuf,"GL_CULL_FACE");
       break;
  case GL_CULL_FACE_MODE:
       wsprintf(logbuf,"GL_CULL_FACE_MODE");
       break;
  case GL_CURRENT_COLOR:
       wsprintf(logbuf,"GL_CURRENT_COLOR");
       break;
  case GL_CURRENT_INDEX:
       wsprintf(logbuf,"GL_CURRENT_INDEX");
       break;
  case GL_CURRENT_NORMAL:
       wsprintf(logbuf,"GL_CURRENT_NORMAL");
       break;
  case GL_CURRENT_RASTER_COLOR:
       wsprintf(logbuf,"GL_CURRENT_RASTER_COLOR");
       break;
  case GL_CURRENT_RASTER_DISTANCE:
       wsprintf(logbuf,"GL_CURRENT_RASTER_DISTANCE");
       break;
  case GL_CURRENT_RASTER_INDEX:
       wsprintf(logbuf,"GL_CURRENT_RASTER_INDEX");
       break;
  case GL_CURRENT_RASTER_POSITION:
       wsprintf(logbuf,"GL_CURRENT_RASTER_POSITION");
       break;
  case GL_CURRENT_RASTER_TEXTURE_COORDS:
       wsprintf(logbuf,"GL_CURRENT_RASTER_TEXTURE_COORDS");
       break;
  case GL_CURRENT_RASTER_POSITION_VALID:
       wsprintf(logbuf,"GL_CURRENT_RASTER_POSITION_VALID");
       break;
  case GL_CURRENT_TEXTURE_COORDS:
       wsprintf(logbuf,"GL_CURRENT_TEXTURE_COORDS");
       break;
  case GL_DEPTH_BIAS:
       wsprintf(logbuf,"GL_DEPTH_BIAS");
       break;
  case GL_DEPTH_BITS:
       wsprintf(logbuf,"GL_DEPTH_BITS");
       break;
  case GL_DEPTH_CLEAR_VALUE:
       wsprintf(logbuf,"GL_DEPTH_CLEAR_VALUE");
       break;
  case GL_DEPTH_FUNC:
       wsprintf(logbuf,"GL_DEPTH_FUNC");
       break;
  case GL_DEPTH_RANGE:
       wsprintf(logbuf,"GL_DEPTH_RANGE");
       break;
  case GL_DEPTH_SCALE:
       wsprintf(logbuf,"GL_DEPTH_SCALE");
       break;
  case GL_DEPTH_TEST:
       wsprintf(logbuf,"GL_DEPTH_TEST");
       break;
  case GL_DEPTH_WRITEMASK:
       wsprintf(logbuf,"GL_DEPTH_WRITEMASK");
       break;
  case GL_DITHER:
       wsprintf(logbuf,"GL_DITHER");
       break;
  case GL_DOUBLEBUFFER:
       wsprintf(logbuf,"GL_DOUBLEBUFFER");
       break;
  case GL_DRAW_BUFFER:
       wsprintf(logbuf,"GL_DRAW_BUFFER");
       break;
  case GL_EDGE_FLAG:
       wsprintf(logbuf,"GL_EDGE_FLAG");
       break;
  case GL_FEEDBACK_BUFFER_SIZE:
       wsprintf(logbuf,"GL_FEEDBACK_BUFFER_SIZE");
       break;
  case GL_FEEDBACK_BUFFER_TYPE:
       wsprintf(logbuf,"GL_FEEDBACK_BUFFER_TYPE");
       break;
  case GL_FOG:
       wsprintf(logbuf,"GL_FOG");
       break;
  case GL_FOG_COLOR:
       wsprintf(logbuf,"GL_FOG_COLOR");
       break;
  case GL_FOG_DENSITY:
       wsprintf(logbuf,"GL_FOG_DENSITY");
       break;
  case GL_FOG_END:
       wsprintf(logbuf,"GL_FOG_END");
       break;
  case GL_FOG_HINT:
       wsprintf(logbuf,"GL_FOG_HINT");
       break;
  case GL_FOG_INDEX:
       wsprintf(logbuf,"GL_FOG_INDEX");
       break;
  case GL_FOG_MODE:
       wsprintf(logbuf,"GL_FOG_MODE");
       break;
  case GL_FOG_START:
       wsprintf(logbuf,"GL_FOG_START");
       break;
  case GL_FRONT_FACE:
       wsprintf(logbuf,"GL_FRONT_FACE");
       break;
  case GL_GREEN_BIAS:
       wsprintf(logbuf,"GL_GREEN_BIAS");
       break;
  case GL_GREEN_BITS:
       wsprintf(logbuf,"GL_GREEN_BITS");
       break;
  case GL_GREEN_SCALE:
       wsprintf(logbuf,"GL_GREEN_SCALE");
       break;
  case GL_INDEX_BITS:
       wsprintf(logbuf,"GL_INDEX_BITS");
       break;
  case GL_INDEX_CLEAR_VALUE:
       wsprintf(logbuf,"GL_INDEX_CLEAR_VALUE");
       break;
  case GL_INDEX_MODE:
       wsprintf(logbuf,"GL_INDEX_MODE");
       break;
  case GL_INDEX_OFFSET:
       wsprintf(logbuf,"GL_INDEX_MODE");
       break;
  case GL_INDEX_SHIFT:
       wsprintf(logbuf,"GL_INDEX_SHIFT");
       break;
  case GL_INDEX_WRITEMASK:
       wsprintf(logbuf,"GL_INDEX_WRITEMASK");
       break;
  case GL_LIGHT0:
       wsprintf(logbuf,"GL_LIGHT0");
       break;
  case GL_LIGHT1:
       wsprintf(logbuf,"GL_LIGHT1");
       break;
  case GL_LIGHT2:
       wsprintf(logbuf,"GL_LIGHT2");
       break;
  case GL_LIGHT3:
       wsprintf(logbuf,"GL_LIGHT3");
       break;
  case GL_LIGHT4:
       wsprintf(logbuf,"GL_LIGHT4");
       break;
  case GL_LIGHT5:
       wsprintf(logbuf,"GL_LIGHT5");
       break;
  case GL_LIGHT6:
       wsprintf(logbuf,"GL_LIGHT6");
       break;
  case GL_LIGHT7:
       wsprintf(logbuf,"GL_LIGHT7");
       break;
  case GL_LIGHTING:
       wsprintf(logbuf,"GL_LIGHTING");
       break;
  case GL_LIGHT_MODEL_AMBIENT:
       wsprintf(logbuf,"GL_LIGHT_MODEL_AMBIENT");
       break;
  case GL_LIGHT_MODEL_COLOR_CONTROL:
       wsprintf(logbuf,"GL_LIGHT_MODEL_COLOR_CONTROL");
       break;
  case GL_LIGHT_MODEL_LOCAL_VIEWER:
       wsprintf(logbuf,"GL_LIGHT_MODEL_LOCAL_VIEWER");
       break;
  case GL_LIGHT_MODEL_TWO_SIDE:
       wsprintf(logbuf,"GL_LIGHT_MODEL_TWO_SIDE");
       break;
  case GL_LINE_SMOOTH:
       wsprintf(logbuf,"GL_LINE_SMOOTH");
       break;
  case GL_LINE_SMOOTH_HINT:
       wsprintf(logbuf,"GL_LINE_SMOOTH_HINT");
       break;
  case GL_LINE_STIPPLE:
       wsprintf(logbuf,"GL_LINE_STIPPLE");
       break;
  case GL_LINE_STIPPLE_PATTERN:
       wsprintf(logbuf,"GL_LINE_STIPPLE_PATTERN");
       break;
  case GL_LINE_STIPPLE_REPEAT:
       wsprintf(logbuf,"GL_LINE_STIPPLE_REPEAT");
       break;
  case GL_LINE_WIDTH:
       wsprintf(logbuf,"GL_LINE_WIDTH");
       break;
  case GL_LINE_WIDTH_GRANULARITY:
       wsprintf(logbuf,"GL_LINE_WIDTH_GRANULARITY");
       break;
  case GL_LINE_WIDTH_RANGE:
       wsprintf(logbuf,"GL_LINE_WIDTH_RANGE");
       break;
  case GL_ALIASED_LINE_WIDTH_RANGE:
       wsprintf(logbuf,"GL_ALIASED_LINE_WIDTH_RANGE");
       break;
  case GL_LIST_BASE:
       wsprintf(logbuf,"GL_LIST_BASE");
       break;
  case GL_LIST_INDEX:
       wsprintf(logbuf,"GL_LIST_INDEX");
       break;
  case GL_LIST_MODE:
       wsprintf(logbuf,"GL_LIST_MODE");
       break;
  case GL_INDEX_LOGIC_OP:
       wsprintf(logbuf,"GL_INDEX_LOGIC_OP");
       break;
  case GL_COLOR_LOGIC_OP:
       wsprintf(logbuf,"GL_COLOR_LOGIC_OP");
       break;
  case GL_LOGIC_OP_MODE:
       wsprintf(logbuf,"GL_LOGIC_OP_MODE");
       break;
  case GL_MAP1_COLOR_4:
       wsprintf(logbuf,"GL_MAP1_COLOR_4");
       break;
  case GL_MAP1_GRID_DOMAIN:
       wsprintf(logbuf,"GL_MAP1_GRID_DOMAIN");
       break;
  case GL_MAP1_GRID_SEGMENTS:
       wsprintf(logbuf,"GL_MAP1_GRID_SEGMENTS");
       break;
  case GL_MAP1_INDEX:
       wsprintf(logbuf,"GL_MAP1_INDEX");
       break;
  case GL_MAP1_NORMAL:
       wsprintf(logbuf,"GL_MAP1_NORMAL");
       break;
  case GL_MAP1_TEXTURE_COORD_1:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_1");
       break;
  case GL_MAP1_TEXTURE_COORD_2:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_2");
       break;
  case GL_MAP1_TEXTURE_COORD_3:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_3");
       break;
  case GL_MAP1_TEXTURE_COORD_4:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_4");
       break;
  case GL_MAP1_VERTEX_3:
       wsprintf(logbuf,"GL_MAP1_VERTEX_3");
       break;
  case GL_MAP1_VERTEX_4:
       wsprintf(logbuf,"GL_MAP1_VERTEX_4");
       break;
  case GL_MAP2_COLOR_4:
       wsprintf(logbuf,"GL_MAP2_COLOR_4");
       break;
  case GL_MAP2_GRID_DOMAIN:
       wsprintf(logbuf,"GL_MAP2_GRID_DOMAIN");
       break;
  case GL_MAP2_GRID_SEGMENTS:
       wsprintf(logbuf,"GL_MAP2_GRID_SEGMENTS");
       break;
  case GL_MAP2_INDEX:
       wsprintf(logbuf,"GL_MAP2_INDEX");
       break;
  case GL_MAP2_NORMAL:
       wsprintf(logbuf,"GL_MAP2_NORMAL");
       break;
  case GL_MAP2_TEXTURE_COORD_1:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_1");
       break;
  case GL_MAP2_TEXTURE_COORD_2:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_2");
       break;
  case GL_MAP2_TEXTURE_COORD_3:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_3");
       break;
  case GL_MAP2_TEXTURE_COORD_4:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_4");
       break;
  case GL_MAP2_VERTEX_3:
       wsprintf(logbuf,"GL_MAP2_VERTEX_3");
       break;
  case GL_MAP2_VERTEX_4:
       wsprintf(logbuf,"GL_MAP2_VERTEX_4");
       break;
  case GL_MAP_COLOR:
       wsprintf(logbuf,"GL_MAP_COLOR");
       break;
  case GL_MAP_STENCIL:
       wsprintf(logbuf,"GL_MAP_STENCIL");
       break;
  case GL_MATRIX_MODE:
       wsprintf(logbuf,"GL_MATRIX_MODE");
       break;
  case GL_MAX_ATTRIB_STACK_DEPTH:
       wsprintf(logbuf,"GL_MAX_ATTRIB_STACK_DEPTH");
       break;
  case GL_MAX_CLIENT_ATTRIB_STACK_DEPTH:
       wsprintf(logbuf,"GL_MAX_CLIENT_ATTRIB_STACK_DEPTH");
       break;
  case GL_MAX_CLIP_PLANES:
       wsprintf(logbuf,"GL_MAX_CLIP_PLANES");
       break;
  case GL_MAX_EVAL_ORDER:
       wsprintf(logbuf,"GL_MAX_EVAL_ORDER");
       break;
  case GL_MAX_LIGHTS:
       wsprintf(logbuf,"GL_MAX_LIGHTS");
       break;
  case GL_MAX_LIST_NESTING:
       wsprintf(logbuf,"GL_MAX_LIST_NESTING");
       break;
  case GL_MAX_MODELVIEW_STACK_DEPTH:
       wsprintf(logbuf,"GL_MAX_MODELVIEW_STACK_DEPTH");
       break;
  case GL_MAX_NAME_STACK_DEPTH:
       wsprintf(logbuf,"GL_MAX_NAME_STACK_DEPTH");
       break;
  case GL_MAX_PIXEL_MAP_TABLE:
       wsprintf(logbuf,"GL_MAX_PIXEL_MAP_TABLE");
       break;
  case GL_MAX_PROJECTION_STACK_DEPTH:
       wsprintf(logbuf,"GL_MAX_PROJECTION_STACK_DEPTH");
       break;
  case GL_MAX_TEXTURE_SIZE:
       wsprintf(logbuf,"GL_MAX_TEXTURE_SIZE");
       break;
  case GL_MAX_TEXTURE_STACK_DEPTH:
       wsprintf(logbuf,"GL_MAX_TEXTURE_STACK_DEPTH");
       break;
  case GL_MAX_VIEWPORT_DIMS:
       wsprintf(logbuf,"GL_MAX_VIEWPORT_DIMS");
       break;
  case GL_MODELVIEW_MATRIX:
       wsprintf(logbuf,"GL_MODELVIEW_MATRIX");
       break;
  case GL_MODELVIEW_STACK_DEPTH:
       wsprintf(logbuf,"GL_MODELVIEW_STACK_DEPTH");
       break;
  case GL_NAME_STACK_DEPTH:
       wsprintf(logbuf,"GL_NAME_STACK_DEPTH");
       break;
  case GL_NORMALIZE:
       wsprintf(logbuf,"GL_NORMALIZE");
	   break;
  case GL_PACK_ALIGNMENT:
       wsprintf(logbuf,"GL_PACK_ALIGNMENT");
       break;
  case GL_PACK_LSB_FIRST:
       wsprintf(logbuf,"GL_PACK_LSB_FIRST");
       break;
  case GL_PACK_ROW_LENGTH:
       wsprintf(logbuf,"GL_PACK_ROW_LENGTH");
       break;
  case GL_PACK_SKIP_PIXELS:
       wsprintf(logbuf,"GL_PACK_SKIP_PIXELS");
       break;
  case GL_PACK_SKIP_ROWS:
       wsprintf(logbuf,"GL_PACK_SKIP_ROWS");
       break;
  case GL_PACK_SWAP_BYTES:
       wsprintf(logbuf,"GL_PACK_SWAP_BYTES");
       break;
  case GL_PERSPECTIVE_CORRECTION_HINT:
       wsprintf(logbuf,"GL_PERSPECTIVE_CORRECTION_HINT");
       break;
  case GL_PIXEL_MAP_A_TO_A_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_A_TO_A_SIZE");
       break;
  case GL_PIXEL_MAP_B_TO_B_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_B_TO_B_SIZE");
       break;
  case GL_PIXEL_MAP_G_TO_G_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_G_TO_G_SIZE");
       break;
  case GL_PIXEL_MAP_I_TO_A_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_I_TO_A_SIZE");
       break;
  case GL_PIXEL_MAP_I_TO_B_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_I_TO_B_SIZE");
       break;
  case GL_PIXEL_MAP_I_TO_G_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_I_TO_G_SIZE");
       break;
  case GL_PIXEL_MAP_I_TO_I_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_I_TO_I_SIZE");
       break;
  case GL_PIXEL_MAP_I_TO_R_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_I_TO_R_SIZE");
       break;
  case GL_PIXEL_MAP_R_TO_R_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_R_TO_R_SIZE");
       break;
  case GL_PIXEL_MAP_S_TO_S_SIZE:
       wsprintf(logbuf,"GL_PIXEL_MAP_S_TO_S_SIZE");
       break;
  case GL_POINT_SIZE:
       wsprintf(logbuf,"GL_POINT_SIZE");
       break;
  case GL_POINT_SIZE_GRANULARITY:
       wsprintf(logbuf,"GL_POINT_SIZE_GRANULARITY");
       break;
  case GL_POINT_SIZE_RANGE:
       wsprintf(logbuf,"GL_POINT_SIZE_RANGE");
       break;
  case GL_POINT_SMOOTH:
       wsprintf(logbuf,"GL_POINT_SMOOTH");
       break;
  case GL_POINT_SMOOTH_HINT:
       wsprintf(logbuf,"GL_POINT_SMOOTH_HINT");
       break;
  case GL_POLYGON_MODE:
       wsprintf(logbuf,"GL_POLYGON_MODE");
       break;
  case GL_POLYGON_OFFSET_FACTOR:
       wsprintf(logbuf,"GL_POLYGON_OFFSET_FACTOR");
       break;
  case GL_POLYGON_OFFSET_UNITS:
       wsprintf(logbuf,"GL_POLYGON_OFFSET_UNITS");
       break;
  case GL_POLYGON_SMOOTH:
       wsprintf(logbuf,"GL_POLYGON_SMOOTH");
       break;
  case GL_POLYGON_SMOOTH_HINT:
       wsprintf(logbuf,"GL_POLYGON_SMOOTH_HINT");
       break;
  case GL_POLYGON_STIPPLE:
       wsprintf(logbuf,"GL_POLYGON_STIPPLE");
       break;
  case GL_PROJECTION_MATRIX:
       wsprintf(logbuf,"GL_PROJECTION_MATRIX");
       break;
  case GL_PROJECTION_STACK_DEPTH:
       wsprintf(logbuf,"GL_PROJECTION_STACK_DEPTH");
       break;
  case GL_READ_BUFFER:
       wsprintf(logbuf,"GL_READ_BUFFER");
       break;
  case GL_RED_BIAS:
       wsprintf(logbuf,"GL_RED_BIAS");
       break;
  case GL_RED_BITS:
       wsprintf(logbuf,"GL_RED_BITS");
       break;
  case GL_RED_SCALE:
       wsprintf(logbuf,"GL_RED_SCALE");
       break;
  case GL_RENDER_MODE:
       wsprintf(logbuf,"GL_RENDER_MODE");
       break;
  case GL_RGBA_MODE:
       wsprintf(logbuf,"GL_RGBA_MODE");
       break;
  case GL_SCISSOR_BOX:
       wsprintf(logbuf,"GL_SCISSOR_BOX");
       break;
  case GL_SCISSOR_TEST:
       wsprintf(logbuf,"GL_SCISSOR_TEST");
       break;
  case GL_SELECTION_BUFFER_SIZE:
       wsprintf(logbuf,"GL_SELECTION_BUFFER_SIZE");
       break;
  case GL_SHADE_MODEL:
       wsprintf(logbuf,"GL_SHADE_MODEL");
       break;
  case GL_SHARED_TEXTURE_PALETTE_EXT:
       wsprintf(logbuf,"GL_SHARED_TEXTURE_PALETTE_EXT");
       break;
  case GL_STENCIL_BITS:
       wsprintf(logbuf,"GL_STENCIL_BITS");
       break;
  case GL_STENCIL_CLEAR_VALUE:
       wsprintf(logbuf,"GL_STENCIL_CLEAR_VALUE");
       break;
  case GL_STENCIL_FAIL:
       wsprintf(logbuf,"GL_STENCIL_FAIL");
       break;
  case GL_STENCIL_FUNC:
       wsprintf(logbuf,"GL_STENCIL_FUNC");
       break;
  case GL_STENCIL_PASS_DEPTH_FAIL:
       wsprintf(logbuf,"GL_STENCIL_PASS_DEPTH_FAIL");
       break;
  case GL_STENCIL_PASS_DEPTH_PASS:
       wsprintf(logbuf,"GL_STENCIL_PASS_DEPTH_PASS");
       break;
  case GL_STENCIL_REF:
       wsprintf(logbuf,"GL_STENCIL_REF");
       break;
  case GL_STENCIL_TEST:
       wsprintf(logbuf,"GL_STENCIL_TEST");
       break;
  case GL_STENCIL_VALUE_MASK:
       wsprintf(logbuf,"GL_STENCIL_VALUE_MASK");
       break;
  case GL_STENCIL_WRITEMASK:
       wsprintf(logbuf,"GL_STENCIL_WRITEMASK");
       break;
  case GL_STEREO:
       wsprintf(logbuf,"GL_STEREO");
       break;
  case GL_SUBPIXEL_BITS:
       wsprintf(logbuf,"GL_SUBPIXEL_BITS");
       break;
  case GL_TEXTURE_1D:
       wsprintf(logbuf,"GL_TEXTURE_1D");
       break;
  case GL_TEXTURE_2D:
       wsprintf(logbuf,"GL_TEXTURE_2D");
       break;
  case GL_TEXTURE_BINDING_1D:
       wsprintf(logbuf,"GL_TEXTURE_BINDING_1D");
       break;
  case GL_TEXTURE_BINDING_2D:
       wsprintf(logbuf,"GL_TEXTURE_BINDING_2D");
       break;
  case GL_TEXTURE_ENV_COLOR:
       wsprintf(logbuf,"GL_TEXTURE_ENV_COLOR");
       break;
  case GL_TEXTURE_ENV_MODE:
       wsprintf(logbuf,"GL_TEXTURE_ENV_MODE");
       break;
  case GL_TEXTURE_GEN_S:
       wsprintf(logbuf,"GL_TEXTURE_GEN_S");
       break;
  case GL_TEXTURE_GEN_T:
       wsprintf(logbuf,"GL_TEXTURE_GEN_T");
       break;
  case GL_TEXTURE_GEN_R:
       wsprintf(logbuf,"GL_TEXTURE_GEN_R");
       break;
  case GL_TEXTURE_GEN_Q:
       wsprintf(logbuf,"GL_TEXTURE_GEN_Q");
       break;
  case GL_TEXTURE_MATRIX:
       wsprintf(logbuf,"GL_TEXTURE_MATRIX");
       break;
  case GL_TEXTURE_STACK_DEPTH:
       wsprintf(logbuf,"GL_TEXTURE_STACK_DEPTH");
       break;
  case GL_UNPACK_ALIGNMENT:
       wsprintf(logbuf,"GL_UNPACK_ALIGNMENT");
       break;
  case GL_UNPACK_LSB_FIRST:
       wsprintf(logbuf,"GL_UNPACK_LSB_FIRST");
       break;
  case GL_UNPACK_ROW_LENGTH:
       wsprintf(logbuf,"GL_UNPACK_ROW_LENGTH");
       break;
  case GL_UNPACK_SKIP_PIXELS:
       wsprintf(logbuf,"GL_UNPACK_SKIP_PIXELS");
       break;
  case GL_UNPACK_SKIP_ROWS:
       wsprintf(logbuf,"GL_UNPACK_SKIP_ROWS");
       break;
  case GL_UNPACK_SWAP_BYTES:
       wsprintf(logbuf,"GL_UNPACK_SWAP_BYTES");
       break;
  case GL_UNPACK_SKIP_IMAGES_EXT:
       wsprintf(logbuf,"GL_UNPACK_SKIP_IMAGES_EXT");
       break;
  case GL_UNPACK_IMAGE_HEIGHT_EXT:
       wsprintf(logbuf,"GL_UNPACK_IMAGE_HEIGHT_EXT");
       break;
  case GL_VIEWPORT:
       wsprintf(logbuf,"GL_VIEWPORT");
       break;
  case GL_ZOOM_X:
       wsprintf(logbuf,"GL_ZOOM_X");
       break;
  case GL_ZOOM_Y:
       wsprintf(logbuf,"GL_ZOOM_Y");
       break;
  case GL_VERTEX_ARRAY:
       wsprintf(logbuf,"GL_VERTEX_ARRAY");
       break;
  case GL_VERTEX_ARRAY_SIZE:
       wsprintf(logbuf,"GL_VERTEX_ARRAY_SIZE");
       break;
  case GL_VERTEX_ARRAY_TYPE:
       wsprintf(logbuf,"GL_VERTEX_ARRAY_TYPE");
       break;
  case GL_VERTEX_ARRAY_STRIDE:
       wsprintf(logbuf,"GL_VERTEX_ARRAY_STRIDE");
       break;
  case GL_VERTEX_ARRAY_COUNT_EXT:
       wsprintf(logbuf,"GL_VERTEX_ARRAY_COUNT_EXT");
       break;
  case GL_NORMAL_ARRAY:
       wsprintf(logbuf,"GL_NORMAL_ARRAY");
       break;
  case GL_NORMAL_ARRAY_TYPE:
       wsprintf(logbuf,"GL_NORMAL_ARRAY_TYPE");
       break;
  case GL_NORMAL_ARRAY_STRIDE:
       wsprintf(logbuf,"GL_NORMAL_ARRAY_STRIDE");
       break;
  case GL_NORMAL_ARRAY_COUNT_EXT:
       wsprintf(logbuf,"GL_NORMAL_ARRAY_COUNT_EXT");
       break;
  case GL_COLOR_ARRAY:
       wsprintf(logbuf,"GL_COLOR_ARRAY");
       break;
  case GL_COLOR_ARRAY_SIZE:
       wsprintf(logbuf,"GL_COLOR_ARRAY_SIZE");
       break;
  case GL_COLOR_ARRAY_TYPE:
       wsprintf(logbuf,"GL_COLOR_ARRAY_TYPE");
       break;
  case GL_COLOR_ARRAY_STRIDE:
       wsprintf(logbuf,"GL_COLOR_ARRAY_STRIDE");
       break;
  case GL_COLOR_ARRAY_COUNT_EXT:
       wsprintf(logbuf,"GL_COLOR_ARRAY_COUNT_EXT");
       break;
  case GL_INDEX_ARRAY:
       wsprintf(logbuf,"GL_INDEX_ARRAY");
       break;
  case GL_INDEX_ARRAY_TYPE:
       wsprintf(logbuf,"GL_INDEX_ARRAY_TYPE");
       break;
  case GL_INDEX_ARRAY_STRIDE:
       wsprintf(logbuf,"GL_INDEX_ARRAY_STRIDE");
       break;
  case GL_INDEX_ARRAY_COUNT_EXT:
       wsprintf(logbuf,"GL_INDEX_ARRAY_COUNT_EXT");
       break;
  case GL_TEXTURE_COORD_ARRAY:
       wsprintf(logbuf,"GL_TEXTURE_COORD_ARRAY");
       break;
  case GL_TEXTURE_COORD_ARRAY_SIZE:
       wsprintf(logbuf,"GL_TEXTURE_COORD_ARRAY_SIZE");
       break;
  case GL_TEXTURE_COORD_ARRAY_TYPE:
       wsprintf(logbuf,"GL_TEXTURE_COORD_ARRAY_TYPE");
       break;
  case GL_TEXTURE_COORD_ARRAY_STRIDE:
       wsprintf(logbuf,"GL_TEXTURE_COORD_ARRAY_STRIDE");
       break;
  case GL_TEXTURE_COORD_ARRAY_COUNT_EXT:
       wsprintf(logbuf,"GL_TEXTURE_COORD_ARRAY_COUNT_EXT");
       break;
  case GL_EDGE_FLAG_ARRAY:
       wsprintf(logbuf,"GL_EDGE_FLAG_ARRAY");
       break;
  case GL_EDGE_FLAG_ARRAY_STRIDE:
       wsprintf(logbuf,"GL_EDGE_FLAG_ARRAY_STRIDE");
       break;
  case GL_EDGE_FLAG_ARRAY_COUNT_EXT:
       wsprintf(logbuf,"GL_EDGE_FLAG_ARRAY_COUNT_EXT");
       break;
  case GL_MAX_TEXTURE_UNITS_ARB:
       wsprintf(logbuf,"GL_MAX_TEXTURE_UNITS_ARB");
       break;
  case GL_ACTIVE_TEXTURE_ARB:
       wsprintf(logbuf,"GL_ACTIVE_TEXTURE_ARB");
       break;
  case GL_CLIENT_ACTIVE_TEXTURE_ARB:
       wsprintf(logbuf,"GL_CLIENT_ACTIVE_TEXTURE_ARB");
       break;

  case GL_MAX_ELEMENTS_VERTICES_EXT:
       wsprintf(logbuf,"GL_MAX_ELEMENTS_VERTICES_EXT");
       break;	  
  case GL_MAX_ELEMENTS_INDICES_EXT:
       wsprintf(logbuf,"GL_MAX_ELEMENTS_INDICES_EXT");
       break;	  
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_ALPHA_TO_COVERAGE_ARB");
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_ALPHA_TO_ONE_ARB");
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_COVERAGE_ARB");
	   break;
  case GL_SAMPLE_BUFFERS_ARB:
       wsprintf(logbuf,"GL_SAMPLE_BUFFERS_ARB");
	   break;
  case GL_SAMPLES_ARB:
       wsprintf(logbuf,"GL_SAMPLES_ARB");
	   break;
  case GL_SAMPLE_COVERAGE_VALUE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_COVERAGE_VALUE_ARB");
	   break;
  case GL_SAMPLE_COVERAGE_INVERT_ARB:
       wsprintf(logbuf,"GL_SAMPLE_COVERAGE_INVERT_ARB");
	   break;
  case GL_GENERATE_MIPMAP_HINT_SGIS:
       wsprintf(logbuf,"GL_GENERATE_MIPMAP_HINT_SGIS");
       break;
  case GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT:
       wsprintf(logbuf,"GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT");
       break;
  case GL_MAX_SHININESS_NV:
       wsprintf(logbuf,"GL_MAX_SHININESS_NV");
       break;
  case GL_MAX_SPOT_EXPONENT_NV:
       wsprintf(logbuf,"GL_MAX_SPOT_EXPONENT_NV");
       break;
  case GL_RESCALE_NORMAL_EXT:
       wsprintf(logbuf,"GL_RESCALE_NORMAL_EXT");
	   break;
  case GL_TRANSPOSE_MODELVIEW_MATRIX_ARB:
       wsprintf(logbuf,"GL_TRANSPOSE_MODELVIEW_MATRIX_ARB");
	   break;
  case GL_TRANSPOSE_PROJECTION_MATRIX_ARB:
       wsprintf(logbuf,"GL_TRANSPOSE_PROJECTION_MATRIX_ARB");
	   break;
  case GL_TRANSPOSE_TEXTURE_MATRIX_ARB:
       wsprintf(logbuf,"GL_TRANSPOSE_TEXTURE_MATRIX_ARB");
	   break;
  case GL_MAX_TEXTURE_LOD_BIAS:
       wsprintf(logbuf,"GL_MAX_TEXTURE_LOD_BIAS");
	   break;
  default:
       wsprintf(logbuf,"0x%X",param);
 }
 AddToLog(logbuf);
}

void LogGLEnabled(GLenum param)
{
 switch (param)
 {
  case GL_ALPHA_TEST:
       wsprintf(logbuf,"GL_ALPHA_TEST");
       break;
  case GL_AUTO_NORMAL:
       wsprintf(logbuf,"GL_AUTO_NORMAL");
       break;
  case GL_BLEND:
       wsprintf(logbuf,"GL_BLEND");
       break;
  case GL_CLIP_PLANE0:
       wsprintf(logbuf,"GL_CLIP_PLANE0");
       break;
  case GL_CLIP_PLANE1:
       wsprintf(logbuf,"GL_CLIP_PLANE1");
       break;
  case GL_CLIP_PLANE2:
       wsprintf(logbuf,"GL_CLIP_PLANE2");
       break;
  case GL_CLIP_PLANE3:
       wsprintf(logbuf,"GL_CLIP_PLANE3");
       break;
  case GL_CLIP_PLANE4:
       wsprintf(logbuf,"GL_CLIP_PLANE4");
       break;
  case GL_CLIP_PLANE5:
       wsprintf(logbuf,"GL_CLIP_PLANE5");
       break;
  case GL_COLOR_MATERIAL:
       wsprintf(logbuf,"GL_COLOR_MATERIAL");
       break;
  case GL_CULL_FACE:
       wsprintf(logbuf,"GL_CULL_FACE");
       break;
  case GL_DEPTH_TEST:
       wsprintf(logbuf,"GL_DEPTH_TEST");
       break;
  case GL_DITHER:
       wsprintf(logbuf,"GL_DITHER");
       break;
  case GL_FOG:
       wsprintf(logbuf,"GL_FOG");
       break;
  case GL_LIGHT0:
       wsprintf(logbuf,"GL_LIGHT0");
       break;
  case GL_LIGHT1:
       wsprintf(logbuf,"GL_LIGHT1");
       break;
  case GL_LIGHT2:
       wsprintf(logbuf,"GL_LIGHT2");
       break;
  case GL_LIGHT3:
       wsprintf(logbuf,"GL_LIGHT3");
       break;
  case GL_LIGHT4:
       wsprintf(logbuf,"GL_LIGHT4");
       break;
  case GL_LIGHT5:
       wsprintf(logbuf,"GL_LIGHT5");
       break;
  case GL_LIGHT6:
       wsprintf(logbuf,"GL_LIGHT6");
       break;
  case GL_LIGHT7:
       wsprintf(logbuf,"GL_LIGHT7");
       break;
  case GL_LIGHTING:
       wsprintf(logbuf,"GL_LIGHTING");
       break;
  case GL_LINE_SMOOTH:
       wsprintf(logbuf,"GL_LINE_SMOOTH");
       break;
  case GL_LINE_STIPPLE:
       wsprintf(logbuf,"GL_LINE_STIPPLE");
       break;
  case GL_INDEX_LOGIC_OP:
       wsprintf(logbuf,"GL_INDEX_LOGIC_OP");
       break;
  case GL_COLOR_LOGIC_OP:
       wsprintf(logbuf,"GL_COLOR_LOGIC_OP");
       break;
  case GL_MAP1_COLOR_4:
       wsprintf(logbuf,"GL_MAP1_COLOR_4");
       break;
  case GL_MAP1_INDEX:
       wsprintf(logbuf,"GL_MAP1_INDEX");
       break;
  case GL_MAP1_NORMAL:
       wsprintf(logbuf,"GL_MAP1_NORMAL");
       break;
  case GL_MAP1_TEXTURE_COORD_1:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_1");
       break;
  case GL_MAP1_TEXTURE_COORD_2:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_2");
       break;
  case GL_MAP1_TEXTURE_COORD_3:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_3");
       break;
  case GL_MAP1_TEXTURE_COORD_4:
       wsprintf(logbuf,"GL_MAP1_TEXTURE_COORD_4");
       break;
  case GL_MAP1_VERTEX_3:
       wsprintf(logbuf,"GL_MAP1_VERTEX_3");
       break;
  case GL_MAP1_VERTEX_4:
       wsprintf(logbuf,"GL_MAP1_VERTEX_4");
       break;
  case GL_MAP2_COLOR_4:
       wsprintf(logbuf,"GL_MAP2_COLOR_4");
       break;
  case GL_MAP2_INDEX:
       wsprintf(logbuf,"GL_MAP2_INDEX");
       break;
  case GL_MAP2_NORMAL:
       wsprintf(logbuf,"GL_MAP2_NORMAL");
       break;
  case GL_MAP2_TEXTURE_COORD_1:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_1");
       break;
  case GL_MAP2_TEXTURE_COORD_2:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_2");
       break;
  case GL_MAP2_TEXTURE_COORD_3:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_3");
       break;
  case GL_MAP2_TEXTURE_COORD_4:
       wsprintf(logbuf,"GL_MAP2_TEXTURE_COORD_4");
       break;
  case GL_MAP2_VERTEX_3:
       wsprintf(logbuf,"GL_MAP2_VERTEX_3");
       break;
  case GL_MAP2_VERTEX_4:
       wsprintf(logbuf,"GL_MAP2_VERTEX_4");
       break;
  case GL_MINMAX:
       wsprintf(logbuf,"GL_MINMAX");
       break;
  case GL_NORMALIZE:
       wsprintf(logbuf,"GL_NORMALIZE");
       break;
  case GL_POINT_SMOOTH:
       wsprintf(logbuf,"GL_POINT_SMOOTH");
       break;
  case GL_POLYGON_SMOOTH:
       wsprintf(logbuf,"GL_POLYGON_SMOOTH");
       break;
  case GL_POLYGON_STIPPLE:
       wsprintf(logbuf,"GL_POLYGON_STIPPLE");
       break;
  case GL_POLYGON_OFFSET_POINT:
       wsprintf(logbuf,"GL_POLYGON_OFFSET_POINT");
       break;
  case GL_POLYGON_OFFSET_LINE:
       wsprintf(logbuf,"GL_POLYGON_OFFSET_LINE");
       break;
  case GL_POLYGON_OFFSET_FILL:
       wsprintf(logbuf,"GL_POLYGON_OFFSET_FILL");
       break;
  case GL_SCISSOR_TEST:
       wsprintf(logbuf,"GL_SCISSOR_TEST");
       break;
  case GL_STENCIL_TEST:
       wsprintf(logbuf,"GL_STENCIL_TEST");
       break;
  case GL_TEXTURE_1D: 
       wsprintf(logbuf,"GL_TEXTURE_1D");
       break;
  case GL_TEXTURE_2D:
       wsprintf(logbuf,"GL_TEXTURE_2D");
	   break;
  case GL_TEXTURE_GEN_Q: 
       wsprintf(logbuf,"GL_TEXTURE_GEN_Q");
       break;
  case GL_TEXTURE_GEN_R: 
       wsprintf(logbuf,"GL_TEXTURE_GEN_R");
       break;
  case GL_TEXTURE_GEN_S: 
       wsprintf(logbuf,"GL_TEXTURE_GEN_S");
       break;
  case GL_TEXTURE_GEN_T:
       wsprintf(logbuf,"GL_TEXTURE_GEN_T");
       break;
  case GL_MULTISAMPLE_ARB:
       wsprintf(logbuf,"GL_MULTISAMPLE_ARB");
       break;
  case GL_SAMPLE_ALPHA_TO_COVERAGE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_ALPHA_TO_COVERAGE_ARB");
	   break;
  case GL_SAMPLE_ALPHA_TO_ONE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_ALPHA_TO_ONE_ARB");
	   break;
  case GL_SAMPLE_COVERAGE_ARB:
       wsprintf(logbuf,"GL_SAMPLE_COVERAGE_ARB");
	   break;
  case GL_RESCALE_NORMAL_EXT:
       wsprintf(logbuf,"GL_RESCALE_NORMAL_EXT");
	   break;
  case GL_POINT_SPRITE_ARB:
       wsprintf(logbuf,"GL_POINT_SPRITE_ARB");
	   break;

  default:
       wsprintf(logbuf,"0x%X",param);
 }
 AddToLog(logbuf);
}

void LogGLBegin(GLenum param)
{
 switch (param)
 {
  case GL_POINTS:
       wsprintf(logbuf,"GL_POINTS");
       break;
  case GL_LINES:
       wsprintf(logbuf,"GL_LINES");
       break;
  case GL_LINE_LOOP:
       wsprintf(logbuf,"GL_LINE_LOOP");
       break;
  case GL_LINE_STRIP:
       wsprintf(logbuf,"GL_LINE_STRIP");
       break;
  case GL_TRIANGLES:
       wsprintf(logbuf,"GL_TRIANGLES");
       break;
  case GL_TRIANGLE_STRIP:
       wsprintf(logbuf,"GL_TRIANGLE_STRIP");
       break;
  case GL_TRIANGLE_FAN:
       wsprintf(logbuf,"GL_TRIANGLE_FAN");
       break;
  case GL_QUADS:
       wsprintf(logbuf,"GL_QUADS");
       break;
  case GL_QUAD_STRIP:
       wsprintf(logbuf,"GL_QUAD_STRIP");
       break;
  case GL_POLYGON:
       wsprintf(logbuf,"GL_POLYGON");
       break;
  default:
       wsprintf(logbuf,"0x%X",param);
 }
 AddToLog(logbuf);
}

#endif

