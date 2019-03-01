#ifndef __GET_H_
#define __GET_H_

const char * WINAPI wglGetExtensionsStringARB(HDC hdc);
const char * WINAPI wglGetExtensionsStringEXT(void);

char * __fastcall _strstr (const char * str1,const char * str2);

enum EXT_CARD
{
 vnc = 0,
 v5c = 1,
 v4c = 2,
 v3c = 3,
 vbc = 4,
 v2c = 5,
 v1c = 6,
};

struct GLEXT
{
 int bl;
 int v5;
 int v4;
 int v3;
 int vb;
 int v2;
 int v1;
 char extname[34];
 char extcomm[34];
};

extern GLEXT glext[];
extern int countext;
extern GLEXT wglext[];
extern int wcountext;
extern int setcard;

EXT_CARD _fastcall DetectCard(void);

#endif