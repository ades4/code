#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elemtype;      //结点的数据类型，设为整型
typedef struct node         //定义单链表结点类型
{
	elemtype data;
	struct node * next;
}LinkList;

LinkList * Init_LinkList()
{
	LinkList * head;
	head = (LinkList *)malloc(sizeof(LinkList));
	//申请分配内存空间
	if (head == NULL)
	{
		printf("初始化失败!\n");
		return 0;
	}
	else
	{
		printf("初始化成功！\n");
		return head;            //返回顺序表的首地址
	}
}

LinkList *Create_LinkListR(LinkList *head)
{
	LinkList * p, *tail = NULL;
	elemtype ix;
	head->next = NULL;
	tail = head;
	printf("请输入元素（终止输入请输入0即可):\n");
	getchar();
	scanf("%c", &ix);
	while (ix != '0')
	{
		p = (LinkList *)malloc(sizeof(LinkList));
		if (p == NULL)
			return head;
		p->data = ix;
		tail->next = p;
		tail = p;
		tail->next = NULL;
		scanf("%c", &ix);
	}
	printf("单链表建立成功！");
	return head;
}

int LinkList_Length(LinkList * head)
{
	LinkList * p = head;
	int j = 0;
	while (p->next != NULL)
	{
		p = p->next;
		j++;
	}
	printf("单链表长度为：%d\n", j);
	return j;
}

LinkList * GetData_LinkList(LinkList * head, int i)
{
	LinkList * p;
	int j = 0;
	if (i <= 0)
		return NULL;
	p = head;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (i == j)
	{
		p = p->next;
		return p;
	}
	else
	{
		printf("输入位置错误！\n");
		return NULL;
	}
}

LinkList * Search_LinkList(LinkList * head, elemtype key)
{
	LinkList * p;
	p = head->next;
	int num = 0;
	while (p != NULL)
		if (p->data != key)
		{
			p = p->next;
			num++;
		}
		else
			break;
	printf("该元素是第%d个\n", num + 1);
	return p;
}

void InsertAfter_LinkList(LinkList * head, LinkList *s)
{
	LinkList * p = NULL;
	s->next = p->next;
	p->next = s;
}

int InsertNo_LinkList(LinkList * head, int pos, char key)
{
	LinkList * p, *s;
	int i = 0;
	p = head;
	while (p != NULL && i < pos - 1)
	{
		p = p->next;
		i = i + 1;
	}
	if (!p)
	{
		printf("插入位置不合理！");
		return 0;
	}
	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = key;
	s->next = p->next;
	p->next = s;
	return 1;
}

int DeleteNo_LinkList(LinkList *head, int i)
{
	LinkList *p, *r;
	if (i <= 0)p = NULL;
	else if (i == 1)p = head;
	else
		p = GetData_LinkList(head, i - 1);
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		r = p->next;
		if (r == NULL)return 0;
		p->next = r->next;
		free(r);
		return 1;
	}
}

void PrintfList(LinkList * head)
{
	LinkList * temp = head;
	while (temp->next)
	{
		temp = temp->next;
		printf("%c ", temp->data);
	}
	printf("\n");
}

void menu()
{
	system("cls");
	printf("功能菜单\n");
	printf("===========\n");
	printf("1.初始化\n");
	printf("2.录入数据\n");
	printf("3.输出长度\n");
	printf("4.查找功能\n");
	printf("5.取数据位置\n");
	printf("6.插入功能\n");
	printf("7.删除功能\n");
	printf("8.输出数据\n");
	printf("9.退出\n");
	printf("===========\n");
	printf("请输入要选择的功能:\n");
}

int main()
{
	LinkList *head = NULL;
	LinkList *p;
	int  quit = 0, pos = 0;
	char key;
	int select;
	while (1)
	{
		menu();            //调用子函数
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			head = Init_LinkList(); break;
		case 2:
			Create_LinkListR(head); break;
		case 3:LinkList_Length(head); break;
		case 4: {
			printf("请输入你要查找的数据:>");
			getchar();
			scanf("%c", &key);
			Search_LinkList(head, key);
		}break;
		case 5: {
			printf("请输入你要获取元素的下标:>");
			getchar();
			scanf("%d", &pos);
			p = GetData_LinkList(head, pos);
			printf("%c\n", p->data);
		} break;
		case 6: {
			printf("请输入你要插入的位置:>");
			scanf("%d", &pos);
			getchar();
			printf("请输入你要插入的数据:>");
			scanf("%c", &key);
			InsertNo_LinkList(head, pos, key);
			PrintfList(head); break;
		}break;
		case 7: {
			printf("请输入你要删除元素的下标:>");
			scanf("%d", &pos);
			DeleteNo_LinkList(head, pos);
			PrintfList(head); break;
		}break;
		case 8: PrintfList(head); break;
		case 9: quit = 1; break;
		default:printf("请输入1~8之间的数字\n");
			break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		getchar();             //提取到缓冲区中的回车键
		getchar();            //起到暂停的作用
		printf("程序结束！\n");
	}
	return 0;
}
