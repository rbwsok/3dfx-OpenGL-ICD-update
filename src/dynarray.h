#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

class DYNARRAY
{
public:
 DYNARRAY(int basesize, int sizeelement);
 ~DYNARRAY();
 void *baseadress;     // базовый адрес массива
 int basesize;         // бфзовый размер массива (в элементах)
 int currentsize;      // текущий размер массива (в элементах)
 int elementsize;      // размер элемента
 int currentfree;      // первый свободный элемент

 int AddElement(void* adr);     // добавить элемент
 void* GetElement(int element); // получить указатель на элемент
 bool DelElement(int element);  // удалить элемени
};

#endif
