#ifndef __TEX_H_
#define __TEX_H_

struct GLTEXTURE
{
 unsigned int numtex;
 
 GLboolean point_sprite;
 GLboolean generate_mipmap;
 GLfloat anisotropy;

 GLfloat texture_min_lod;
 GLfloat texture_max_lod;
 GLint texture_base_level;
 GLint texture_max_level;

 GLfloat texture_lod_bias;
};

#endif