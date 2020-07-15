#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

void test1()
{
	SListNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushfront(&s, 0);

	SListPrintf(s);
	SListPopBack(&s);
	SListPrintf(s);
}

void test2()
{
	SListNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushfront(&s, 0);

	SListPrintf(s);
	SListPopfront(&s);
	SListPopfront(&s);
	SListPopfront(&s);
	SListPrintf(s);
	SListPopfront(&s);
	SListPopfront(&s);
	SListPrintf(s);

}


void test3()
{
	SListNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushfront(&s, 0);

	SListPrintf(s);
	SListNode* cur = SListFind(s, 2);
	cur->date = 30;
	SListPrintf(s);

}

void test4()
{
	SListNode* s = NULL;
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushfront(&s, 0);

	SListPrintf(s);
	SListNode* cur = SListFind(s, 0);

	SListInsertAfter(cur, 40);
	SListPrintf(s);

	SListEraseAfter(cur);
	SListEraseAfter(cur);

	SListPrintf(s);

	SListDestory(&s);
	SListPrintf(s);
}

int main()
{
	test4();


	system("pause");
	return 0;
}