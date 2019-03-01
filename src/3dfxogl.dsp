# Microsoft Developer Studio Project File - Name="3dfxogl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=3dfxogl - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "3dfxogl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "3dfxogl.mak" CFG="3dfxogl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "3dfxogl - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "3dfxogl - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G6 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 glu32.lib ddraw.lib d3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"Release/opengl32.dll"
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 glu32.lib ddraw.lib d3dx8.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "3dfxogl - Win32 Release"
# Name "3dfxogl - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\3dfxogl.def
# End Source File
# Begin Source File

SOURCE=.\3dfxogl.rc

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD BASE RSC /l 0x419
# ADD RSC /l 0x419 /d "_CONFIGCP_Win32_20Release" /d "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD BASE RSC /l 0x419
# ADD RSC /l 0x419 /d "_CONFIGCP_Win32_20Debug" /d "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\d3ddevice.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\d3dobject.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\D3dsurf.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dynarray.cpp
# End Source File
# Begin Source File

SOURCE=.\Enable.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\glGet.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\glTex.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Log.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\main.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MATRIX.CPP

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\multidrawarray.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\multisample.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pixelformat.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\setglext.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vbo.cpp

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\vertex.cpp
# End Source File
# Begin Source File

SOURCE=.\WINPOS.CPP

!IF  "$(CFG)" == "3dfxogl - Win32 Release"

# ADD CPP /D "_CONFIGCP_Win32_20Release" /D "_PRJCP_3dfxogl_2Evprj"

!ELSEIF  "$(CFG)" == "3dfxogl - Win32 Debug"

# ADD CPP /D "_CONFIGCP_Win32_20Debug" /D "_PRJCP_3dfxogl_2Evprj"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\d3ddevice.h
# End Source File
# Begin Source File

SOURCE=.\d3dobject.h
# End Source File
# Begin Source File

SOURCE=.\D3dsurf.h
# End Source File
# Begin Source File

SOURCE=.\dynarray.h
# End Source File
# Begin Source File

SOURCE=.\ENABLE.H
# End Source File
# Begin Source File

SOURCE=.\glext.h
# End Source File
# Begin Source File

SOURCE=.\GLGET.H
# End Source File
# Begin Source File

SOURCE=.\GLTEX.H
# End Source File
# Begin Source File

SOURCE=.\Log.h
# End Source File
# Begin Source File

SOURCE=.\main.h
# End Source File
# Begin Source File

SOURCE=.\MATRIX.H
# End Source File
# Begin Source File

SOURCE=.\multidrawarray.h
# End Source File
# Begin Source File

SOURCE=.\multisample.h
# End Source File
# Begin Source File

SOURCE=.\pixelformat.h
# End Source File
# Begin Source File

SOURCE=.\RESOURCE.H
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\vbo.h
# End Source File
# Begin Source File

SOURCE=.\vertex.h
# End Source File
# Begin Source File

SOURCE=.\wglext.h
# End Source File
# Begin Source File

SOURCE=.\WINPOS.H
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\README.TXT
# End Source File
# End Target
# End Project
