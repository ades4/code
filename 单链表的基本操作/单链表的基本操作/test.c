#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char elemtype;      //�����������ͣ���Ϊ����
typedef struct node         //���嵥����������
{
	elemtype data;
	struct node * next;
}LinkList;

LinkList * Init_LinkList()
{
	LinkList * head;
	head = (LinkList *)malloc(sizeof(LinkList));
	//��������ڴ�ռ�
	if (head == NULL)
	{
		printf("��ʼ��ʧ��!\n");
		return 0;
	}
	else
	{
		printf("��ʼ���ɹ���\n");
		return head;            //����˳�����׵�ַ
	}
}

LinkList *Create_LinkListR(LinkList *head)
{
	LinkList * p, *tail = NULL;
	elemtype ix;
	head->next = NULL;
	tail = head;
	printf("������Ԫ�أ���ֹ����������0����):\n");
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
	printf("���������ɹ���");
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
	printf("��������Ϊ��%d\n", j);
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
		printf("����λ�ô���\n");
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
	printf("��Ԫ���ǵ�%d��\n", num + 1);
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
		printf("����λ�ò�����");
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
	printf("���ܲ˵�\n");
	printf("===========\n");
	printf("1.��ʼ��\n");
	printf("2.¼������\n");
	printf("3.�������\n");
	printf("4.���ҹ���\n");
	printf("5.ȡ����λ��\n");
	printf("6.���빦��\n");
	printf("7.ɾ������\n");
	printf("8.�������\n");
	printf("9.�˳�\n");
	printf("===========\n");
	printf("������Ҫѡ��Ĺ���:\n");
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
		menu();            //�����Ӻ���
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			head = Init_LinkList(); break;
		case 2:
			Create_LinkListR(head); break;
		case 3:LinkList_Length(head); break;
		case 4: {
			printf("��������Ҫ���ҵ�����:>");
			getchar();
			scanf("%c", &key);
			Search_LinkList(head, key);
		}break;
		case 5: {
			printf("��������Ҫ��ȡԪ�ص��±�:>");
			getchar();
			scanf("%d", &pos);
			p = GetData_LinkList(head, pos);
			printf("%c\n", p->data);
		} break;
		case 6: {
			printf("��������Ҫ�����λ��:>");
			scanf("%d", &pos);
			getchar();
			printf("��������Ҫ���������:>");
			scanf("%c", &key);
			InsertNo_LinkList(head, pos, key);
			PrintfList(head); break;
		}break;
		case 7: {
			printf("��������Ҫɾ��Ԫ�ص��±�:>");
			scanf("%d", &pos);
			DeleteNo_LinkList(head, pos);
			PrintfList(head); break;
		}break;
		case 8: PrintfList(head); break;
		case 9: quit = 1; break;
		default:printf("������1~8֮�������\n");
			break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		getchar();             //��ȡ���������еĻس���
		getchar();            //����ͣ������
		printf("���������\n");
	}
	return 0;
}
