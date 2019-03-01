#include "stdafx.h"

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

struct GLOPT
{
 char name[32];
 int value;
};

GLOPT glopt[] = {
{"compress_all",0},
{"force_resolution",0},
{"xres",0},
{"yres",0},
{"bpp",0},
{"freq",0},
{"tex_large",0},
};

int countopt = sizeof(glopt)/sizeof(GLOPT);

GLEXT *glext,*wglext;
typedef void *(*GETEXTLIST)(void);
GETEXTLIST GetExtList = NULL;
GETEXTLIST GetWGLExtList = NULL;
typedef int (*GETEXTCOUNT)(void);
GETEXTCOUNT GetExtCount = NULL;
GETEXTCOUNT GetWGLExtCount = NULL;
GETEXTCOUNT GetVerBuild = NULL;

#define EXTPATH1 "SOFTWARE\\Rainbow\\OpenGL_Control\\GLExtensions"
#define EXTPATH2 "SOFTWARE\\Rainbow\\OpenGL_Control\\WGLExtensions"
#define OPTPATH  "SOFTWARE\\Rainbow\\OpenGL_Control\\Options"
#define PATHGL   "SOFTWARE\\Rainbow\\OpenGL_Control"

int countext,wcountext;

void SetReg(void);
void QueryReg(void);
void InitProperty(HWND hWnd);
void SelAll(BOOL flag);
void SelAllOpt(void);
void SetKey(char*,int);
void QueryOpt(HWND hwnd);
void SetRegWGL(void);
void DelReg(void);
void QueryCards(HWND hDlg);
void SetCard(HWND hDlg);
void SetCardRes(HWND hDlg);

HWND hmWnd,listext,listext2,hpw[10];
HINSTANCE hInst;
int actpage = 0;
LV_COLUMN lvc;
LV_ITEM lvi;
RECT winbox;
int ver = 0;

LRESULT CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK pWndProc3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
void ViewTabPage(int curt,HWND hWnd);
int DetectICD(void);

HMODULE hLib = 0;

BOOL (WINAPI* pEnumDisplayDevices)(PVOID,DWORD,PVOID,DWORD);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 MSG msg;
 hInst = hInstance;

 static char mutexname[] = "rb_3dfxopenglctrl";
 HANDLE hh = OpenMutex(MUTEX_ALL_ACCESS, false, mutexname);
 if (hh == 0) hh = CreateMutex(0, false, mutexname);
  else return 0;
 if (hh == 0) return 0;

 ver = DetectICD();
 if (ver == 0)
 {
  MessageBox(NULL,"Use 3dfx icd driver v1.0.0.0508 for Voodoo2 or v1.0.0.0761 for Voodoo Banshee/3/4/5","OpenGL Control error", MB_ICONSTOP);
  return 0;	 
 }

 hLib = LoadLibrary("opengl32.dll");                     
 if (hLib == NULL) 
 {
  MessageBox(NULL,"Can't load opengl32.dll or initialisation of dll is false","OpenGL Control error", MB_ICONSTOP);
  return 0;	 
 }

 (FARPROC &)GetExtList = GetProcAddress(hLib, "GetExtList");
 (FARPROC &)GetExtCount = GetProcAddress(hLib, "GetExtCount");
 (FARPROC &)GetWGLExtList = GetProcAddress(hLib, "GetWGLExtList");
 (FARPROC &)GetWGLExtCount = GetProcAddress(hLib, "GetWGLExtCount");
 (FARPROC &)GetVerBuild = GetProcAddress(hLib, "GetVerBuild");
 if (GetExtList == NULL     || 
	 GetExtCount == NULL    || 
	 GetWGLExtList == NULL  || 
	 GetWGLExtCount == NULL ||
	 GetVerBuild == NULL    ||
	 GetVerBuild() < 10)
 {
  MessageBox(NULL,"Wrong opengl32.dll - use build 010 or above.","OpenGL Control error", MB_ICONSTOP);
  return 0;	 
 }

 countext = GetExtCount();
 glext = (GLEXT*)GetExtList();
 wcountext = GetWGLExtCount();
 wglext = (GLEXT*)GetWGLExtList();

 InitCommonControls();

 hmWnd = CreateDialog(hInst, (LPCTSTR)IDD_MAINWND, HWND_DESKTOP, (DLGPROC)WndProc);
 while(1)
 {
  while( PeekMessage(&msg,NULL,0,0,PM_NOREMOVE) )
   if (GetMessage(&msg,NULL,0,0))
     {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
     }
    else return 0;
 }
 return msg.wParam;


}


LRESULT CALLBACK WndProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       GetWindowRect(hDlg,&winbox);
	   MoveWindow(hDlg,GetSystemMetrics(SM_CXSCREEN)/2-(winbox.right-winbox.left)/2,GetSystemMetrics(SM_CYSCREEN)/2-(winbox.bottom-winbox.top)/2,winbox.right-winbox.left,winbox.bottom-winbox.top,TRUE);
       InitProperty(hDlg);
       ViewTabPage(0,hDlg);
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDAPPLY:
             SetReg();
             SetRegWGL();
			 SetCardRes(hpw[2]);
             SelAllOpt();
             break;
        case IDOK:
             SetReg();
             SetRegWGL();
			 SetCardRes(hpw[2]);
			 SelAllOpt();
        case IDCANCEL:
			 ChangeDisplaySettings(NULL,0);
             SendMessage(hDlg,WM_DESTROY,0,0);
             break;
        case IDC_DEFAULT:
             DelReg();
			 MessageBox(NULL,"Please restart OpenGL control.","OpenGL control", MB_ICONSTOP);
             SendMessage(hDlg,WM_DESTROY,0,0);
             break;			 
	   }
       break;
  case WM_CLOSE:
  case WM_DESTROY:
	   if (hLib != 0) FreeLibrary(hLib);
       PostQuitMessage(0);
       break;
  case WM_NOTIFY:
       LPNMHDR pnmh = (LPNMHDR) lParam;
       switch (pnmh->code)
       {
        case TCN_SELCHANGE:
             ViewTabPage(TabCtrl_GetCurSel(GetDlgItem(hDlg,IDC_TAB1)),hDlg);
             break;
       }
       break;
 }
 return FALSE;
}

void InitProperty(HWND hWnd)
{
 TCITEM tci[10];
 tci[0].mask = TCIF_TEXT;
 tci[0].pszText = "GL Extensions";
 tci[1].mask = TCIF_TEXT;
 tci[1].pszText = "WGL Extensions";
 tci[2].mask = TCIF_TEXT;
 tci[2].pszText = "Options";
 tci[3].mask = TCIF_TEXT;
 tci[3].pszText = "About";

 for (int i=0;i<4;i++)
  TabCtrl_InsertItem(GetDlgItem(hWnd,IDC_TAB1),i,&tci[i]);

 hpw[0] = CreateDialog(hInst,(LPCTSTR)IDD_PROP2,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc2);
 hpw[1] = CreateDialog(hInst,(LPCTSTR)IDD_PROP3,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc3);
 hpw[2] = CreateDialog(hInst,(LPCTSTR)IDD_PROP1,GetDlgItem(hWnd,IDC_TAB1),(DLGPROC)pWndProc1);
 hpw[3] = CreateDialog(hInst,(LPCTSTR)IDD_ABOUT,GetDlgItem(hWnd,IDC_TAB1),NULL);
}

void ViewTabPage(int curt,HWND hWnd)
{
 RECT rect,rectc;
 GetClientRect(GetDlgItem(hWnd,IDC_TAB1),&rect);
 GetClientRect(hpw[curt],&rectc);
 TabCtrl_AdjustRect(GetDlgItem(hWnd,IDC_TAB1),FALSE,&rect);
 ShowWindow(hpw[actpage],SW_HIDE);
 MoveWindow(hpw[curt],rect.left,rect.top,rectc.right,rectc.bottom,FALSE);
 ShowWindow(hpw[curt],SW_SHOW);
 UpdateWindow(hpw[curt]);
 actpage = curt;
}

LRESULT CALLBACK pWndProc1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
	   QueryCards(hDlg);
	   QueryOpt(hDlg);

	   {
		char bl[128];
		wsprintf(bl,"build 0%d",GetVerBuild());
	    SetDlgItemText(hDlg,IDC_VERDRVUPD,bl);
       }

	   if (ver == 1)
	   {
		SetDlgItemText(hDlg,IDC_VERDRV,"v1.0.0.0508 ICD for Voodoo2");
        SetKey("compress_all",0);
		SendDlgItemMessage(hDlg,IDC_COMPRESS,BM_SETCHECK,0,0);
		EnableWindow(GetDlgItem(hDlg,IDC_COMPRESS),FALSE);
	   }
	   else
	   if (ver == 2)
	   {
        SetDlgItemText(hDlg,IDC_VERDRV,"v1.0.0.0761 ICD for Voodoo Banshee/3/4/5");
		SendDlgItemMessage(hDlg,IDC_NONERES,BM_SETCHECK,1,0);
        SetKey("force_resolution",0);
        EnableWindow(GetDlgItem(hDlg,IDC_FRES),FALSE);
		EnableWindow(GetDlgItem(hDlg,IDC_NONERES),FALSE);
		EnableWindow(GetDlgItem(hDlg,IDC_WINRES),FALSE);
		EnableWindow(GetDlgItem(hDlg,IDC_URES),FALSE);		
	    EnableWindow(GetDlgItem(hDlg,IDC_RESOLUTION),FALSE);
	   }
	   else SetDlgItemText(hDlg,IDC_VERDRV,"<Unknown>");
	   break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDC_COMPRESS:
             if (SendDlgItemMessage(hDlg,IDC_COMPRESS,BM_GETCHECK,0,0))
              SetKey("compress_all",1);
             else
              SetKey("compress_all",0);
             break;
        case IDC_LARGETEXTURE:
             if (SendDlgItemMessage(hDlg,IDC_LARGETEXTURE,BM_GETCHECK,0,0))
              SetKey("tex_large",1);
             else
              SetKey("tex_large",0);
             break;
        case IDC_NONERES:
             SetKey("force_resolution",0);
			 EnableWindow(GetDlgItem(hDlg,IDC_RESOLUTION),FALSE);
			 break;
        case IDC_WINRES:
             SetKey("force_resolution",2);
			 EnableWindow(GetDlgItem(hDlg,IDC_RESOLUTION),FALSE);
			 break;
        case IDC_URES:
             SetKey("force_resolution",1);
			 EnableWindow(GetDlgItem(hDlg,IDC_RESOLUTION),TRUE);
			 break;
	   }
       break;
 }
 return FALSE;
}

LRESULT CALLBACK pWndProc2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       listext = GetDlgItem(hDlg,IDC_EXTLIST);
       lvc.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
       lvc.fmt = LVCFMT_LEFT;
       lvc.cchTextMax = 255;
       lvc.pszText = "Extensions";
       lvc.cx = 210;
       lvc.iSubItem = 0;
       ListView_InsertColumn(GetDlgItem(hDlg,IDC_EXTLIST),1,&lvc);
       lvc.pszText = "Comments";
       lvc.cx = 190;
       lvc.iSubItem = 0;
       ListView_InsertColumn(listext,1,&lvc);
       ListView_SetExtendedListViewStyle(listext,LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES);
       QueryReg();
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDC_SELALL:
             SelAll(TRUE);
             break;
        case IDC_UNSELALL:
             SelAll(FALSE);
             break;
	   }
       break;
 }
 return FALSE;
}

void AddString(int pos,int state,char* text1,char* text2)
{
 int zz;
 lvi.mask = LVIF_STATE | LVIF_TEXT;
 lvi.iItem = pos;
 lvi.iSubItem = 0;
 lvi.state = 0;
 lvi.stateMask = 0;
 lvi.cchTextMax = 256;
 lvi.pszText = text1;
 zz = ListView_InsertItem(listext,&lvi);
 ListView_SetItemText(listext,pos,1,text2);
 if (state == 1) ListView_SetCheckState(listext,zz,TRUE);
 if (state == 0) ListView_SetCheckState(listext,zz,FALSE);
}

void AddStringWGL(int pos,int state,char* text1,char* text2)
{
 int zz;
 lvi.mask = LVIF_STATE | LVIF_TEXT;
 lvi.iItem = pos;
 lvi.iSubItem = 0;
 lvi.state = 0;
 lvi.stateMask = 0;
 lvi.cchTextMax = 256;
 lvi.pszText = text1;
 zz = ListView_InsertItem(listext2,&lvi);
 ListView_SetItemText(listext2,pos,1,text2);
 if (state == 1) ListView_SetCheckState(listext2,zz,TRUE);
 if (state == 0) ListView_SetCheckState(listext2,zz,FALSE);
}

void QueryReg(void)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
 unsigned char tmp[8];
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey);
 }
 // получение необходимых параметров
 for(int a=0;a<countext;a++)
 {
  if (RegQueryValueEx(hkey,glext[a].extname,NULL,&ptype,tmp,&size) != ERROR_SUCCESS)
  {
   RegSetValueEx(hkey,glext[a].extname,NULL,REG_DWORD,(LPBYTE)&glext[a].bl,sizeof(DWORD));
   tmp[0] = (char)glext[a].bl;
  }
  if (tmp[0] == 0) glext[a].bl = 0;
   else glext[a].bl = 1;
  //AddString(exten[a].val,exten[a].extname,exten[a].comments);
  AddString(a,glext[a].bl,glext[a].extname,glext[a].extcomm);
 }
 RegCloseKey(hkey);
}

void SetReg(void)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey);
 }
 // получение необходимых параметров
 for(int a=0;a<countext;a++)
 {
  if (ListView_GetCheckState(listext,a) == TRUE) glext[a].bl = 1;
   else glext[a].bl = 0;
  RegSetValueEx(hkey,glext[a].extname,NULL,REG_DWORD,(LPBYTE)&glext[a].bl,sizeof(DWORD));
 }
 RegCloseKey(hkey);
}

void SelAll(BOOL flag)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
// unsigned char tmp[8];
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,EXTPATH1,&hkey);
 }

 // получение необходимых параметров
 for(int a=0;a<countext;a++)
 {
  if (flag == TRUE) glext[a].bl = 1;
   else glext[a].bl = 0;

 // if (RegQueryValueEx(hkey,glext[a].extname,NULL,&ptype,tmp,&size) != ERROR_SUCCESS)
 // {
   //RegSetValueEx(hkey,glext[a].extname,NULL,REG_DWORD,(LPBYTE)&glext[a].bl,sizeof(DWORD));
   RegSetValueEx(hkey,glext[a].extname,NULL,REG_DWORD,(LPBYTE)&glext[a].bl,sizeof(DWORD));
//   tmp[0] = (char)glext[a].bl;
 // }
  ListView_SetCheckState(listext,a,flag);
 }
 RegCloseKey(hkey);
}

void SelAllOpt(void)
{
 HKEY hkey;
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,OPTPATH,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,OPTPATH,&hkey);
 }

 for(int a=0;a<countopt;a++)
 {
  RegSetValueEx(hkey,glopt[a].name,NULL,REG_DWORD,(LPBYTE)&glopt[a].value,sizeof(DWORD));
 }
 RegCloseKey(hkey);
}

void SetKey(char* key,int val)
{
 for(int a=0;a<countopt;a++)
 {
  if (strncmp(glopt[a].name,key,strlen(key)) == 0)
  {
   glopt[a].value = val;
  }
 }
}

void QueryRegWGL(void)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
 unsigned char tmp[8];
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey);
 }
 // получение необходимых параметров
 for(int a=0;a<wcountext;a++)
 {
  if (RegQueryValueEx(hkey,wglext[a].extname,NULL,&ptype,tmp,&size) != ERROR_SUCCESS)
  {
   RegSetValueEx(hkey,wglext[a].extname,NULL,REG_DWORD,(LPBYTE)&wglext[a].bl,sizeof(DWORD));
   tmp[0] = (char)glext[a].bl;
  }
  if (tmp[0] == 0) wglext[a].bl = 0;
   else wglext[a].bl = 1;
  //AddString(exten[a].val,exten[a].extname,exten[a].comments);
 AddStringWGL(a,wglext[a].bl,wglext[a].extname,wglext[a].extcomm);
 }
 RegCloseKey(hkey);
}

void SetRegWGL(void)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey);
 }
 // получение необходимых параметров
 for(int a=0;a<wcountext;a++)
 {
  if (ListView_GetCheckState(listext2,a) == TRUE) wglext[a].bl = 1;
   else wglext[a].bl = 0;
  RegSetValueEx(hkey,wglext[a].extname,NULL,REG_DWORD,(LPBYTE)&wglext[a].bl,sizeof(DWORD));
 }
 RegCloseKey(hkey);
}

void SelAllWGL(BOOL flag)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
// unsigned char tmp[8];
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,EXTPATH2,&hkey);
 }

 // получение необходимых параметров
 for(int a=0;a<wcountext;a++)
 {
  if (flag == TRUE) wglext[a].bl = 1;
   else wglext[a].bl = 0;

  RegSetValueEx(hkey,wglext[a].extname,NULL,REG_DWORD,(LPBYTE)&wglext[a].bl,sizeof(DWORD));
  ListView_SetCheckState(listext2,a,flag);
 }
 RegCloseKey(hkey);
}


LRESULT CALLBACK pWndProc3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 switch (message)
 {
  case WM_INITDIALOG:
       listext2 = GetDlgItem(hDlg,IDC_EXTLIST);
       lvc.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;
       lvc.fmt = LVCFMT_LEFT;
       lvc.cchTextMax = 255;
       lvc.pszText = "Extensions";
       lvc.cx = 210;
       lvc.iSubItem = 0;
       ListView_InsertColumn(GetDlgItem(hDlg,IDC_EXTLIST),1,&lvc);
       lvc.pszText = "Comments";
       lvc.cx = 190;
       lvc.iSubItem = 0;
       ListView_InsertColumn(listext2,1,&lvc);
       ListView_SetExtendedListViewStyle(listext2,LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES);
       QueryRegWGL();
       break;
  case WM_COMMAND:
       switch (LOWORD(wParam))
       {
        case IDC_SELALL:
             SelAllWGL(TRUE);
             break;
        case IDC_UNSELALL:
             SelAllWGL(FALSE);
             break;
	   }
       break;
 }
 return FALSE;
}


void QueryOpt(HWND hwnd)
{
 HKEY hkey;
 unsigned long size = 8;
 unsigned long ptype = REG_DWORD;
 unsigned char tmp[8];
 int val_one=1;
 int val_zero=0;
 memset(tmp,0,sizeof(tmp));
 // открытие соответствующего раздела в реестре
 if (RegOpenKey(HKEY_LOCAL_MACHINE,OPTPATH,&hkey) != ERROR_SUCCESS)
 {
  // если нету - создаем
  RegCreateKey(HKEY_LOCAL_MACHINE,OPTPATH,&hkey);
 }

 for (int i = 0;i < countopt;i++)
 {
  if (RegQueryValueEx(hkey,glopt[i].name,NULL,&ptype,tmp,&size) != ERROR_SUCCESS)
  {
   RegSetValueEx(hkey,glopt[i].name,NULL,REG_DWORD,(LPBYTE)&val_zero,sizeof(DWORD));
   tmp[0] = (char)val_zero;
  }
  glopt[i].value = ((int*)tmp)[0];
  SetKey(glopt[i].name,(int)glopt[i].value);
 }
 RegCloseKey(hkey);
 
 SendDlgItemMessage(hwnd,IDC_COMPRESS,BM_SETCHECK,glopt[0].value,0); // compress

 SendDlgItemMessage(hwnd,IDC_LARGETEXTURE,BM_SETCHECK,glopt[6].value,0); // large texture

 if (glopt[1].value == 0)
 {
  SendDlgItemMessage(hwnd,IDC_NONERES,BM_SETCHECK,1,0);
  EnableWindow(GetDlgItem(hwnd,IDC_RESOLUTION),FALSE);
 }
 else
 if (glopt[1].value == 1)
 {
  DEVMODE devMode;
  devMode.dmSize = sizeof(devMode);
  BOOL bl;
  int sel = 0;

  for (i=0; ;i++)
  {
   bl = EnumDisplaySettings(NULL, i, &devMode);
   if (bl == FALSE) break;
   if (devMode.dmBitsPerPel >= 15)
   {
    if (glopt[2].value == (int)devMode.dmPelsWidth &&   // xres 
	    glopt[3].value == (int)devMode.dmPelsHeight &&  // yres
	    glopt[4].value == (int)devMode.dmBitsPerPel &&  // bpp
	    glopt[5].value == (int)devMode.dmDisplayFrequency)
    {
     SendDlgItemMessage(hwnd, IDC_RESOLUTION, CB_SETCURSEL, (WPARAM)sel,(LPARAM)0);    
     break;
    }
    sel++;
   }
  }
  EnableWindow(GetDlgItem(hwnd,IDC_RESOLUTION),TRUE);
  SendDlgItemMessage(hwnd,IDC_URES,BM_SETCHECK,1,0);
 }
 else 
 if (glopt[1].value == 2)
 {
  SendDlgItemMessage(hwnd,IDC_WINRES,BM_SETCHECK,1,0);
  EnableWindow(GetDlgItem(hwnd,IDC_RESOLUTION),FALSE);
 }
}

void DelReg(void)
{
 RegDeleteKey(HKEY_LOCAL_MACHINE,OPTPATH);
 RegDeleteKey(HKEY_LOCAL_MACHINE,EXTPATH1);
 RegDeleteKey(HKEY_LOCAL_MACHINE,EXTPATH2);
 RegDeleteKey(HKEY_LOCAL_MACHINE,PATHGL);
}

int curres = -1;

void QueryCards(HWND hDlg)
{
 BOOL bl;
 int i;

 DEVMODE devMode;
 devMode.dmSize = sizeof(devMode);

 char buf[256];

 for (i=0; ;i++)
 {
  bl = EnumDisplaySettings(NULL, i, &devMode);
  if (bl == FALSE) break;
  if (devMode.dmBitsPerPel >= 15 && devMode.dmPelsWidth >= 512 && devMode.dmPelsWidth <= 1024)
  {
   if (curres == -1) curres = i;
   wsprintf(buf,"%dx%dx%d [%d Hz]",devMode.dmPelsWidth, devMode.dmPelsHeight,  devMode.dmBitsPerPel, devMode.dmDisplayFrequency);
   SendDlgItemMessage(hDlg, IDC_RESOLUTION, CB_ADDSTRING,(WPARAM)0,(LPARAM)buf);
  }
 }
 SendDlgItemMessage(hDlg, IDC_RESOLUTION, CB_SETCURSEL, (WPARAM)0,(LPARAM)0);
}

void SetCardRes(HWND hDlg)
{
 DISPLAY_DEVICE dd;
 ZeroMemory(&dd, sizeof(dd));
 dd.cb = sizeof(dd);
 BOOL bl;
 int cursel = SendDlgItemMessage(hDlg, IDC_RESOLUTION, CB_GETCURSEL, (WPARAM)0,(LPARAM)0);
 int sel = 0;

 DEVMODE devMode;
 devMode.dmSize = sizeof(devMode);

 for (int i=0; ;i++)
 {
  bl = EnumDisplaySettings(NULL, i, &devMode);
  if (bl == FALSE) break;
  if (devMode.dmBitsPerPel >= 15)
  {
   if (cursel == sel)
   {
	SetKey("xres",devMode.dmPelsWidth);
	SetKey("yres",devMode.dmPelsHeight);
	SetKey("bpp",devMode.dmBitsPerPel);
	SetKey("freq",devMode.dmDisplayFrequency);
	break;
   }
   sel++;
  }
 }
 
}

int DetectICD(void)
{
 DWORD dwScratch = 0;
 char *verbuf;
 int *pdwLangChar;
 char szResource [80];
 UINT uSize;
 char szVersion [32];
 char *pszVersion = szVersion;
 int lenvinfo = GetFileVersionInfoSize("3dfxogl.dll",&dwScratch);
 verbuf = (char*)GlobalAllocPtr(GPTR,lenvinfo);
 if (lenvinfo != NULL)
 {
  if (GetFileVersionInfo("3dfxogl.dll",0,lenvinfo,verbuf) == TRUE)
  {
   if (VerQueryValue (verbuf,"\\VarFileInfo\\Translation",(void**)(&pdwLangChar),&uSize))
   {
	// Product Version
    wsprintf (szResource, "\\StringFileInfo\\%04X%04X\\ProductVersion",LOWORD (*pdwLangChar), HIWORD (*pdwLangChar));
    if (VerQueryValue (verbuf,szResource,(void**)(&pszVersion),&uSize) == TRUE)
	{
   	 if (pszVersion[1] != 0)
	 {
	  goto l1;
	 }
	}
   }
  }
 }
 return 0;
l1:;

 if (strcmp(pszVersion,"1.0.0.0508 ICD") == 0) return 1;
 if (strcmp(pszVersion,"1.0.0.0761 ICD") == 0) return 2;
 
 return 0;
}

