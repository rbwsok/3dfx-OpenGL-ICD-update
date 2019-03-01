#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

class DYNARRAY
{
public:
 DYNARRAY(int basesize, int sizeelement);
 ~DYNARRAY();
 void *baseadress;     // ������� ����� �������
 int basesize;         // ������� ������ ������� (� ���������)
 int currentsize;      // ������� ������ ������� (� ���������)
 int elementsize;      // ������ ��������
 int currentfree;      // ������ ��������� �������

 int AddElement(void* adr);     // �������� �������
 void* GetElement(int element); // �������� ��������� �� �������
 bool DelElement(int element);  // ������� �������
};

#endif
