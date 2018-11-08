#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char ElemType;
typedef struct BiTreeNode
{
	ElemType data;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
}BiTreeNode, *BiTree;

BiTree  CreateBiTree(char str[])
{
	BiTree bt;
	char ch;
	static int i = 0;
	ch = str[i++];
	if (ch == '.')
		bt = NULL;		//��������
	else
	{
		bt = (BiTree)malloc(sizeof(BiTreeNode));
		bt->data = ch;		//�������ڵ�
		bt->lchild = CreateBiTree(str);		//����������
		bt->rchild = CreateBiTree(str);		//����������
	}
	return bt;
}

void PreOrder1(BiTree  bt)		//btΪָ�������ָ��
{
	if (bt != NULL)
	{
		printf("%c ", bt->data);		//���ʸ��ڵ�
		PreOrder1(bt->lchild);		//�������������
		PreOrder1(bt->rchild);		//����������
	}
}

void InOrder1(BiTree bt)
{
	if (bt != NULL)
	{
		InOrder1(bt->lchild);		//�������������	
		printf("%c ", bt->data);		//���ʸ��ڵ�
		InOrder1(bt->rchild);		//����������
	}
}

void PostOrder1(BiTree bt)
{
	if (bt != NULL)
	{
		PostOrder1(bt->lchild);		//�������������	
		PostOrder1(bt->rchild);	 	//����������
		printf("%c ", bt->data);		//���ʸ��ڵ�

	}
}

int BitreeLeaf(BiTree bt)
{
	if (bt == NULL)
		return 0;
	if (bt->lchild == NULL && bt->rchild == NULL)
		//ֻ��һ�����ڵ�
		return 1;
	else
		return (BitreeLeaf(bt->lchild) + BitreeLeaf(bt->rchild));
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int BitreeDepth(BiTree bt)
{
	int d = 0, depthL, depthR;	//depthL,depthR�ֱ��ʾ�����������
	if (bt == NULL)
		return 0;			//���������Ϊ0
	depthL = BitreeDepth(bt->lchild);
	depthR = BitreeDepth(bt->rchild);
	d = Max(depthL, depthR);
	return d + 1;
}

//�ǵݹ��������
void PreOrder2(BiTree bt) //btΪָ�����������ĳһ������������ָ��
{
	BiTree s[MAX], p = bt;//����ջs
	int top = -1;//ջ��ָ��
	if (p == NULL)//��Ϊ�ն����� ��������
		return;
	do
	{
		while (p != NULL)//����������ջ  ֱ��������Ϊ��
		{
			if (top >= MAX - 1)
			{
				printf("ջ���������ʧ�ܣ�\n");
				return;
			}
			printf("%c ", p->data);
			s[++top] = p;//��ǰָ��p��ջ
			p = p->lchild;//ָ��ָ��p�����ӽ��
		}
		if (top == -1)//ջ��ʱ����
			return;
		else
		{
			p = s[top--];//����ջ��Ԫ��
			//printf("%c ", p->data);//���ʸ����
			p = p->rchild;//ָ��ָ��p���Һ��ӽ��
		}
	} while (p != NULL || top != -1);
}

//�ǵݹ��������
void InOrder2(BiTree bt)  //btΪָ�����������ĳһ������������ָ��
{
	BiTree s[MAX], p = bt;//����ջs
	int top = -1;//ջ��ָ��
	if (p == NULL)//��Ϊ�ն����� ��������
		return;
	do
	{
		while (p != NULL)//����������ջ  ֱ��������Ϊ��
		{
			if (top >= MAX - 1)
			{
				printf("ջ���������ʧ�ܣ�\n");
				return;
			}
			s[++top] = p;//��ǰָ��p��ջ
			p = p->lchild;//ָ��ָ��p�����ӽ��
		}
		if (top == -1)//ջ��ʱ����
			return;
		else
		{
			p = s[top--];//����ջ��Ԫ��
			printf("%c ", p->data);//���ʸ����
			p = p->rchild;//ָ��ָ��p���Һ��ӽ��
		}
	} while (p != NULL || top != -1);
}

//�ǵݹ�������
void PostOrder2(BiTree T)
{
	BiTree s[MAX];
	int top = -1;
	BiTree p = T, r = NULL;

	while (p || top > -1)
	{
		if (p)
		{  //�ߵ������ 
			s[++top] = p;
			p = p->lchild;
		}
		else 
		{  //����
			p = s[top];  //ȡջ��Ԫ�� 
			if (p->rchild && p->rchild != r) 
			{ //���������գ���δ����� 
				p = p->rchild;  //ת���� 
				s[++top] = p;   //ѹջ 
				p = p->lchild;  //���ߵ����� 
			}
			else
			{   //���򵯳�ջ�������� 
				p = s[top--];//��ջ�������ջ��Ԫ��
				printf("%c ", p->data);
				r = p;   //��¼������ʹ��Ľ�� 
				p = NULL; //�����ʹ�������pָ�� 
			}
		}
	}
}

void menu()
{
	system("cls");
	printf("------------------------------------------\n");
	printf("-----------    �� �� ѡ ��     -----------\n");
	printf("----------- 1.�������������   -----------\n");
	printf("----------- 2.�������������   -----------\n");
	printf("----------- 3.�������������   -----------\n");
	printf("----------- 4.���Ҷ�ӽ����� -----------\n");
	printf("----------- 5.����������ĸ߶� -----------\n");
	printf("-----------    6.�˳�          -----------\n");
	printf("------------------------------------------\n");
}
int main()
{
	BiTree bt;
	BiTree *p = (BiTree *)malloc(sizeof(BiTree));
	int deepth = 0, num = 0;
	int i = 0, quit = 0;
	char arr[100];
	printf("�������У�\n");
	scanf("%c", &arr[i]);
	while (arr[i] != '0'&&i < 100)
	{
		i++;
		scanf("%c", &arr[i]);
	}
	bt = CreateBiTree(arr);
	getchar();
	int n = 0;
	while (1)
	{
		menu();
		printf("������ѡ�");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("�ݹ����������������\n");
			PreOrder1(bt);
			printf("\n");
			printf("�ǵݹ����������������\n");
			PreOrder2(bt);
			printf("\n");
			break;
		case 2:
			printf("�ݹ����������������\n");
			InOrder1(bt);
			printf("\n");
			printf("�ǵݹ����������������\n");
			InOrder2(bt);
			printf("\n");
			break;
		case 3:
			printf("�ݹ���������������\n");
			PostOrder1(bt);
			printf("\n");
			printf("�ǵݹ���������������\n");
			PostOrder2(bt);
			printf("\n");
			break;
		case 4:
			printf("�������Ϊ��%d", deepth);
			deepth = BitreeDepth(bt);
			printf("\n");
			break;
		case 5:
			printf("����Ҷ�ӽ�����Ϊ��%d", num);
			num = BitreeLeaf(bt);
			printf("\n");
			break;
		case 6:
			quit = 1; break;
		default:
			printf("ѡ��������������룡");
			break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("��������������˵���\n");
		getchar();				//��ȡ���������еĻس���
		getchar();				//����ͣ������
		printf("���������\n");
	}
	return 0;
}
