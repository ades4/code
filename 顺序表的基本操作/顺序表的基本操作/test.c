#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 1024           //˳�����ܵ���󳤶�
typedef int elemtype;          //����Ϊint��
typedef struct sequlist
{
	elemtype data[Maxsize];        //����˳���Ϊһά����
	int last;                //lastΪ�������һ��Ԫ�ص��±�
}SequenList;
SequenList * Init_SequenList()
{
	SequenList * L;                //����˳���ָ�����
	L = (SequenList *)malloc(sizeof(SequenList));
	//��������ڴ�ռ�
	if (L != NULL)
	{
		L->last = -1;   //����˳���ĳ���lastΪ-1����ʾΪ��
	}
	return L;                     //����˳�����׵�ַ
}
SequenList *Indata_Seqlist(SequenList *L)
{
	elemtype x;
	printf("������Ԫ�أ���ֹ����������0����):\n");
	scanf("%d", &x);
	while (x != 0)
	{
		L->last += 1;
		L->data[L->last] = x;
		scanf("%d", &x);
	}
	printf("˳������ɹ���");
	return L;
}
int SequenList_Length(SequenList *L)
{
	return(L->last + 1);              //����˳���ĳ���
}
int Insert_SequenList(SequenList *L, elemtype x, int i)
//L��sequenlist���͵�ָ�����
//x�Ǵ������������Ԫ��ֵ��i��˳����в����λ��
{
	int j;
	if (L->last >= Maxsize - 1)      //���˳����Ƿ�����
	{
		return 0;
	}
	if (i<1 || i>L->last + 2)        //����λ����Ч�Լ��
	{
		return -1;
	}
	for (j = L->last; j >= i - 1; j--)      //�ڵ�i��λ�ò����½��x
		L->data[j + 1] = L->data[j]; //������������ƶ�һ��λ��
	L->data[i - 1] = x;               //����x����i��λ��
	L->last = L->last + 1;            //��˳����ȼ�1
	return 1;
}
int Search_SequenList(SequenList *L, elemtype key)
{
	int i;
	for (i = 0; i <= L->last; i++)
		//����Ԫ��������key���бȽ�
		if (L->data[i] == key)
			printf("%d\n", i + 1);
	//return (i + 1);
	return 0;
}
int Delete_SequenList(SequenList *L, int i)
//ɾ����i��λ���ϵĽ��
{
	int j;
	if (i<1 || i>L->last + 1)            //���ָ��λ�õ���Ч��
	{
		return 0;
	}
	else
	{
		for (j = i; j <= L->last; j++)
			L->data[j - 1] = L->data[j];        //���ǰ��
		L->last--;                      //����1
	}
	return 1;
}
elemtype GetData_SequenList(SequenList *L, int i)
{
	if (i<1 || i>L->last + 1)            //λ����Ч�Լ��
	{
		return 0;
	}
	else
		printf("%d\n", L->data[i]);
	//return (L->data[i - 1]);         //�����������ֵ
}
void show(SequenList *L)
{
	for (int i = 0; i <= L->last; i++)
		printf("%d\n", L->data[i]);
}
void menu()
{
	system("cls");
	printf("���ܲ˵�\n");
	printf("===========\n");
	printf("1.¼������\n");
	printf("2.�������\n");
	printf("3.���ҹ���\n");
	printf("4.ȡ����Ԫ��\n");
	printf("5.���빦��\n");
	printf("6.ɾ������\n");
	printf("7.�������\n");
	printf("8.�˳�\n");
	printf("===========\n");
	printf("������Ҫѡ��Ĺ���:\n");
}
int main()
{
	SequenList *L;
	int  quit = 0;
	int len, key, x, i;
	elemtype *e = 0;
	int  select;
	L = Init_SequenList();
	/*int key;*/
	//scanf("%d", &key);
	int pos = 0;
	while (1)
	{
		menu();            //�����Ӻ���
		scanf("%d", &select);
		switch (select)
		{
			/*case 0:        exit(0); break;*/
		case 1:
			*Indata_Seqlist(L); break;
		case 2: {
			len = SequenList_Length(L);
			printf("˳���ĳ���Ϊ��%d\n", len);
		} break;
		case 3: {
			printf("��������Ҫ���ҵ�����:>");
			scanf("%d", &key);
			Search_SequenList(L, key);
		}break;
		case 4: {
			printf("��������Ҫ��ȡԪ�ص��±�:>");
			scanf("%d", &key);
			GetData_SequenList(L, key);
		} break;
		case 5: {
			printf("��������Ҫ��������ݺ�λ��:>");
			scanf("%d%d", &key, &pos);
			Insert_SequenList(L, key, pos);
		}break;
		case 6: {
			printf("��������Ҫɾ�������ݵ�λ��:>");
			scanf("%d", &pos);
			Delete_SequenList(L, pos);
		} break;
		case 7:            show(L); break;
		case 8: quit = 1; break;
		default:printf("������1~8֮�������\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		getchar();                //��ȡ���������еĻس���
		getchar();                //����ͣ������
		printf("���������\n");
	}
	return 0;
}
