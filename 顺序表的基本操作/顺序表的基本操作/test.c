#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 1024           //顺序表可能的最大长度
typedef int elemtype;          //定义为int型
typedef struct sequlist
{
	elemtype data[Maxsize];        //定义顺序表为一维数组
	int last;                //last为表中最后一个元素的下标
}SequenList;
SequenList * Init_SequenList()
{
	SequenList * L;                //定义顺序表指针变量
	L = (SequenList *)malloc(sizeof(SequenList));
	//申请分配内存空间
	if (L != NULL)
	{
		L->last = -1;   //设置顺序表的长度last为-1，表示为空
	}
	return L;                     //返回顺序表的首地址
}
SequenList *Indata_Seqlist(SequenList *L)
{
	elemtype x;
	printf("请输入元素（终止输入请输入0即可):\n");
	scanf("%d", &x);
	while (x != 0)
	{
		L->last += 1;
		L->data[L->last] = x;
		scanf("%d", &x);
	}
	printf("顺序表建立成功！");
	return L;
}
int SequenList_Length(SequenList *L)
{
	return(L->last + 1);              //返回顺序表的长度
}
int Insert_SequenList(SequenList *L, elemtype x, int i)
//L是sequenlist类型的指针变量
//x是待插入结点的数据元素值，i是顺序表中插入的位置
{
	int j;
	if (L->last >= Maxsize - 1)      //检查顺序表是否已满
	{
		return 0;
	}
	if (i<1 || i>L->last + 2)        //插入位置有效性检查
	{
		return -1;
	}
	for (j = L->last; j >= i - 1; j--)      //在第i个位置插入新结点x
		L->data[j + 1] = L->data[j]; //结点依次往后移动一个位置
	L->data[i - 1] = x;               //插入x到第i个位置
	L->last = L->last + 1;            //将顺序表长度加1
	return 1;
}
int Search_SequenList(SequenList *L, elemtype key)
{
	int i;
	for (i = 0; i <= L->last; i++)
		//表中元素依次与key进行比较
		if (L->data[i] == key)
			printf("%d\n", i + 1);
	//return (i + 1);
	return 0;
}
int Delete_SequenList(SequenList *L, int i)
//删除第i个位置上的结点
{
	int j;
	if (i<1 || i>L->last + 1)            //检查指定位置的有效性
	{
		return 0;
	}
	else
	{
		for (j = i; j <= L->last; j++)
			L->data[j - 1] = L->data[j];        //结点前移
		L->last--;                      //表长减1
	}
	return 1;
}
elemtype GetData_SequenList(SequenList *L, int i)
{
	if (i<1 || i>L->last + 1)            //位置有效性检查
	{
		return 0;
	}
	else
		printf("%d\n", L->data[i]);
	//return (L->data[i - 1]);         //返回所需结点的值
}
void show(SequenList *L)
{
	for (int i = 0; i <= L->last; i++)
		printf("%d\n", L->data[i]);
}
void menu()
{
	system("cls");
	printf("功能菜单\n");
	printf("===========\n");
	printf("1.录入数据\n");
	printf("2.输出长度\n");
	printf("3.查找功能\n");
	printf("4.取数据元素\n");
	printf("5.插入功能\n");
	printf("6.删除功能\n");
	printf("7.输出数据\n");
	printf("8.退出\n");
	printf("===========\n");
	printf("请输入要选择的功能:\n");
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
		menu();            //调用子函数
		scanf("%d", &select);
		switch (select)
		{
			/*case 0:        exit(0); break;*/
		case 1:
			*Indata_Seqlist(L); break;
		case 2: {
			len = SequenList_Length(L);
			printf("顺序表的长度为：%d\n", len);
		} break;
		case 3: {
			printf("请输入你要查找的数据:>");
			scanf("%d", &key);
			Search_SequenList(L, key);
		}break;
		case 4: {
			printf("请输入你要获取元素的下标:>");
			scanf("%d", &key);
			GetData_SequenList(L, key);
		} break;
		case 5: {
			printf("请输入你要插入的数据和位置:>");
			scanf("%d%d", &key, &pos);
			Insert_SequenList(L, key, pos);
		}break;
		case 6: {
			printf("请输入你要删除的数据的位置:>");
			scanf("%d", &pos);
			Delete_SequenList(L, pos);
		} break;
		case 7:            show(L); break;
		case 8: quit = 1; break;
		default:printf("请输入1~8之间的数字\n"); break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		getchar();                //提取到缓冲区中的回车键
		getchar();                //起到暂停的作用
		printf("程序结束！\n");
	}
	return 0;
}
