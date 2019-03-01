#ifndef __LOG_H__
#define __LOG_H__

// enable RB_DEBUG - create opengl.log
#define RB_DEBUG 

void AddToLog(char*);
void LogGLTargetTexture(GLenum target);
void LogGLInternalFormat(GLenum internalformat);
void LogGLFormat(GLenum format);
void LogGLType(GLenum type);
void LogGLValTexParam(GLenum param);
void LogGLValTexParamVal(GLenum param);
void LogGLGetStrings(GLenum param);
void LogGLGetVal(GLenum param);
void LogGLEnabled(GLenum param);
void LogGLBegin(GLenum param);


extern char logbuf[];


#endif
