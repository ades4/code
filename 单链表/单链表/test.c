#define _CRT_SECURE_NO_WARNINGS 1 
#include "Slist.h"

void TestSList1()
{
	SList s;
	SListInit(&s);

	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	SListPushFront(&s, 3);
	SListPushFront(&s, 4);
	SListPushFront(&s, 5);
	SListPushBack(&s, 5);
	SListPushBack(&s, 4);
	SListPushBack(&s, 3);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	
	SListPrint(&s);

	SListDestory(&s);
}

void TestSList2()
{
	SList s;
	SListInit(&s);

	SListPushBack(&s, 5);
	SListPushBack(&s, 4);
	SListPushBack(&s, 6);
	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	SListPushFront(&s, 3);
	SListPushFront(&s, 4);
	SListPushFront(&s, 5);
	SListPrint(&s);
	printf("\n");

	SListNode* cur = SListFind(&s, 6);
	SListInsertAfter(cur, 5);
	SListPrint(&s);
	printf("\n");

	SListEraseAfter(cur);
	SListPrint(&s);
	printf("\n");

	SListRemove(&s, 5);
	SListPrint(&s);
	printf("\n");
	SListRemove1(&s, 3);
	SListPrint(&s);
	printf("\n");


	SListDestory(&s);
}


int main()
{
//	TestSList1();
	TestSList2();
	system("pause");
	return 0;
}