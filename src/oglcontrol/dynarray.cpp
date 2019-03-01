#include "stdafx.h"

DYNARRAY::DYNARRAY(int basesize, int sizeelement)
{
 currentsize = basesize;
 DYNARRAY::basesize = basesize;
 elementsize = sizeelement;
 baseadress = GlobalAllocPtr(GPTR,basesize*sizeelement);
 currentfree = 0;
}

DYNARRAY::~DYNARRAY()
{
 if (baseadress != NULL) GlobalFree(baseadress);
}

int DYNARRAY::AddElement(void *adr)
{
 if (currentfree < currentsize)
 {
  // место под элемент еще есть
  memcpy(((char*)baseadress + currentfree*elementsize),adr,elementsize);
 }
 else
 {
  // места нет - выделяем еще один блок
  baseadress = GlobalReAllocPtr(baseadress,(currentsize + basesize)*elementsize,GMEM_ZEROINIT);
  currentsize += basesize;
  memcpy(((char*)baseadress + currentfree*elementsize),adr,elementsize);
 }
 currentfree++;
 return currentfree - 1;
}

void* DYNARRAY::GetElement(int element)
{
 if (element >= currentsize) return NULL; // за пределами массива

 return (void*)(((char*)baseadress) + element*elementsize);
}