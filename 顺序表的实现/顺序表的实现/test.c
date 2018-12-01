#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

void SeqListtest1()
{
	printf("\n测试1\n");
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 1);
	SeqListPrint(&s);
	printf("\n");

	printf("在第3个位置插入元素5\n");
	SeqListInsert(&s, 2, 5);
	SeqListPrint(&s);
	printf("\n");

	printf("删除下标为3即第4个元素\n");
	SeqListErase(&s, 3);
	SeqListPrint(&s);
	printf("\n");

/*
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	*/
	SeqListDestory(&s);
}
void SeqListtest2()
{
	SeqList s;
	SeqListInit(&s, 10);
	printf("\n测试2\n");
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	printf("\n");

	printf("删除元素 2\n");
	SeqListRemove(&s, 2);	
	SeqListPrint(&s);
	printf("\n");

	printf("将下标为2即第三个元素的值更改为5\n");
	SeqListModify(&s, 2, 5);
	SeqListPrint(&s);
	printf("\n");

	printf("找到元素3并返回它的位置\n");
	int pos = SeqListFind(&s, 3);
	printf("%d\n", pos);
	printf("\n");

//	SeqListPrint(&s);
	SeqListDestory(&s);
}

void SeqListtest3()
{
	SeqList s;
	SeqListInit(&s, 10);
	printf("\n测试3\n");
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 1);

	SeqListPrint(&s);

	printf("\n从小到大排序\n");
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	printf("\n");

	printf("用二分查找找出5的值并返回下标\n");
	int pos = SeqListBinaryFind(&s, 5);
	printf("%d\n",pos);

	printf("\n删除所有为4的值\n");
	SeqListRemoveAll(&s, 4);
	SeqListPrint(&s);
	printf("\n");

}

int main()
{
	SeqListtest1();
	SeqListtest2();
	SeqListtest3();
	system("pause");
	return 0;
}
