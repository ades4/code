#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

void SeqListtest1()
{
	printf("\n����1\n");
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

	printf("�ڵ�3��λ�ò���Ԫ��5\n");
	SeqListInsert(&s, 2, 5);
	SeqListPrint(&s);
	printf("\n");

	printf("ɾ���±�Ϊ3����4��Ԫ��\n");
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
	printf("\n����2\n");
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	printf("\n");

	printf("ɾ��Ԫ�� 2\n");
	SeqListRemove(&s, 2);	
	SeqListPrint(&s);
	printf("\n");

	printf("���±�Ϊ2��������Ԫ�ص�ֵ����Ϊ5\n");
	SeqListModify(&s, 2, 5);
	SeqListPrint(&s);
	printf("\n");

	printf("�ҵ�Ԫ��3����������λ��\n");
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
	printf("\n����3\n");
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

	printf("\n��С��������\n");
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	printf("\n");

	printf("�ö��ֲ����ҳ�5��ֵ�������±�\n");
	int pos = SeqListBinaryFind(&s, 5);
	printf("%d\n",pos);

	printf("\nɾ������Ϊ4��ֵ\n");
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
