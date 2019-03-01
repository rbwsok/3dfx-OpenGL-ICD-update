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
// добавление элемента 
//////////////////////////////////////////////////////////////////
// in:  adr - указатель на элемент, 0 - создание пустого элемента
// out: индекс элемента
// размер элемента указывается в конструкторе, при создании класса
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
  // место под элемент еще есть
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
  // места нет - выделяем еще один блок
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
// получение указателья на элемент по его индексу
//////////////////////////////////////////////////////////////////
// in:  element - индекс
// out: указатель, NULL - элемент за пределами массива
// размер элемента указывается в конструкторе, при создании класса
//////////////////////////////////////////////////////////////////
void* DYNARRAY::GetElement(int element)
{
 if (element >= currentsize) return NULL; // за пределами массива

 return (void*)(((char*)baseadress) + element*elementsize);
}

//////////////////////////////////////////////////////////////////
// удаление элемента
//////////////////////////////////////////////////////////////////
// in:  element - индекс
// out: true - элемент рельно удален, false - элемент не удален
// размер элемента указывается в конструкторе, при создании класса
// false - не признак неудачи удаления, а признак того, что 
// менеджеру памяти не хватило мозгов, чтобы удалить элемент и 
// он остался в памяти
//////////////////////////////////////////////////////////////////
bool DYNARRAY::DelElement(int element)
{
 if (element != currentfree - 1 && currentfree <= 0) return false; // не последний элемент
 
 currentfree--;

 return true;
}