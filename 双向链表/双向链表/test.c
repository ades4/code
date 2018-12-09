#define _CRT_SECURE_NO_WARNINGS 1 
#include "List.h"

void TestList()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPushFront(&list, 6);
	ListPushFront(&list, 5);
	ListPushFront(&list, 4);
	ListPushFront(&list, 3);
	ListPushFront(&list, 2);
	ListPushFront(&list, 1);

	ListPrint(&list);
	printf("\n");
	ListPopBack(&list);
	ListPopBack(&list);
	ListPopFront(&list);
	ListPopFront(&list);


	ListPrint(&list);
	printf("\n");

	ListNode* cur = ListFind(&list, 4);
	ListInsert(cur, 7);
	ListPrint(&list);
	printf("\n");

	ListErase(cur);
	ListPrint(&list);
	printf("\n");

	ListRemove(&list, 3);
	ListPrint(&list);
	printf("\n");
	ListDestory(&list);
}

int main()
{
	TestList();
	system("pause");
	return 0;
}
