#include "stdafx.h"

DYNARRAY::DYNARRAY(int basesize, int sizeelement)
{
 currentsize = basesize;
 DYNARRAY::basesize = basesize;
 elementsize = sizeelement;
 baseadress = GlobalAllocPtr(GPTR,basesize*sizeelement);
#ifdef RB_DEBUG
 wsprintf(logbuf," - constructor baseadress = 0x%X\r\n", baseadress);
 AddToLog(logbuf);
#endif

 currentfree = 0;
}

DYNARRAY::~DYNARRAY()
{
 if (baseadress != NULL) GlobalFree(baseadress);
}

//////////////////////////////////////////////////////////////////
// ���������� �������� 
//////////////////////////////////////////////////////////////////
// in:  adr - ��������� �� �������, 0 - �������� ������� ��������
// out: ������ ��������
// ������ �������� ����������� � ������������, ��� �������� ������
//////////////////////////////////////////////////////////////////
int DYNARRAY::AddElement(void *adr)
{

#ifdef RB_DEBUG
 wsprintf(logbuf," - currentfree = %d\r\n", currentfree);
 AddToLog(logbuf);
 wsprintf(logbuf," - currentsize = %d\r\n", currentsize);
 AddToLog(logbuf);
#endif

 if (currentfree < currentsize)
 {
  // ����� ��� ������� ��� ����
  if (adr == NULL) memset(((char*)baseadress + currentfree*elementsize),0,elementsize);
  else memcpy(((char*)baseadress + currentfree*elementsize),adr,elementsize);
 }
 else
 {
#ifdef RB_DEBUG
 wsprintf(logbuf," - baseadress = 0x%X\r\n", baseadress);
 AddToLog(logbuf);
 wsprintf(logbuf," - oldsize = %d\r\n", currentsize*elementsize);
 AddToLog(logbuf);
#endif
  // ����� ��� - �������� ��� ���� ����
  //baseadress = GlobalReAllocPtr(baseadress,(currentsize + basesize)*elementsize,GMEM_ZEROINIT);
  void *adr2 = baseadress;
  baseadress = GlobalReAllocPtr(adr2,(currentsize + basesize)*elementsize,GMEM_ZEROINIT);
 if (baseadress == 0) 
 {
#ifdef RB_DEBUG
  if (baseadress == 0) 
  {
   wsprintf(logbuf," - ERROR GlobalReAllocPtr = 0x%X\r\n", GetLastError());
   AddToLog(logbuf);
  }
#endif
  baseadress = GlobalAllocPtr(GPTR,(currentsize + basesize)*elementsize);
#ifdef RB_DEBUG
  if (baseadress == 0) 
  {
   wsprintf(logbuf," - ERROR GlobalAllocPtr = 0x%X\r\n", GetLastError());
   AddToLog(logbuf);
  }
#endif
  memcpy(baseadress,adr2,basesize*elementsize);
  GlobalFree(adr2);
 }
#ifdef RB_DEBUG
 wsprintf(logbuf," - baseadress = 0x%X\r\n", baseadress);
 AddToLog(logbuf);

 wsprintf(logbuf," - newsize = %d\r\n", (currentsize + basesize)*elementsize);
 AddToLog(logbuf);
#endif
  currentsize += basesize;

#ifdef RB_DEBUG
 wsprintf(logbuf," - elementsize = %d\r\n", elementsize);
 AddToLog(logbuf);
#endif
  
  if (adr == NULL) memset(((char*)baseadress + currentfree*elementsize),0,elementsize);
  else memcpy(((char*)baseadress + currentfree*elementsize),adr,elementsize);
 }
 currentfree++;
 return currentfree - 1;
}

//////////////////////////////////////////////////////////////////
// ��������� ���������� �� ������� �� ��� �������
//////////////////////////////////////////////////////////////////
// in:  element - ������
// out: ���������, NULL - ������� �� ��������� �������
// ������ �������� ����������� � ������������, ��� �������� ������
//////////////////////////////////////////////////////////////////
void* DYNARRAY::GetElement(int element)
{
 if (element >= currentsize) return NULL; // �� ��������� �������

 return (void*)(((char*)baseadress) + element*elementsize);
}

//////////////////////////////////////////////////////////////////
// �������� ��������
//////////////////////////////////////////////////////////////////
// in:  element - ������
// out: true - ������� ������ ������, false - ������� �� ������
// ������ �������� ����������� � ������������, ��� �������� ������
// false - �� ������� ������� ��������, � ������� ����, ��� 
// ��������� ������ �� ������� ������, ����� ������� ������� � 
// �� ������� � ������
//////////////////////////////////////////////////////////////////
bool DYNARRAY::DelElement(int element)
{
 if (element != currentfree - 1 && currentfree <= 0) return false; // �� ��������� �������
 
 currentfree--;

 return true;
}