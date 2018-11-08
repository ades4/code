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
		bt = NULL;		//创建空树
	else
	{
		bt = (BiTree)malloc(sizeof(BiTreeNode));
		bt->data = ch;		//创建根节点
		bt->lchild = CreateBiTree(str);		//创建左子树
		bt->rchild = CreateBiTree(str);		//创建右子树
	}
	return bt;
}

void PreOrder1(BiTree  bt)		//bt为指向根结点的指针
{
	if (bt != NULL)
	{
		printf("%c ", bt->data);		//访问根节点
		PreOrder1(bt->lchild);		//先序遍历左子树
		PreOrder1(bt->rchild);		//遍历右子树
	}
}

void InOrder1(BiTree bt)
{
	if (bt != NULL)
	{
		InOrder1(bt->lchild);		//中序遍历左子树	
		printf("%c ", bt->data);		//访问根节点
		InOrder1(bt->rchild);		//遍历右子树
	}
}

void PostOrder1(BiTree bt)
{
	if (bt != NULL)
	{
		PostOrder1(bt->lchild);		//后序遍历左子树	
		PostOrder1(bt->rchild);	 	//遍历右子树
		printf("%c ", bt->data);		//访问根节点

	}
}

int BitreeLeaf(BiTree bt)
{
	if (bt == NULL)
		return 0;
	if (bt->lchild == NULL && bt->rchild == NULL)
		//只有一个根节点
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
	int d = 0, depthL, depthR;	//depthL,depthR分别表示左右子树深度
	if (bt == NULL)
		return 0;			//空树，深度为0
	depthL = BitreeDepth(bt->lchild);
	depthR = BitreeDepth(bt->rchild);
	d = Max(depthL, depthR);
	return d + 1;
}

//非递归先序遍历
void PreOrder2(BiTree bt) //bt为指向二叉树（或某一子树）根结点的指针
{
	BiTree s[MAX], p = bt;//定义栈s
	int top = -1;//栈顶指针
	if (p == NULL)//若为空二叉树 遍历结束
		return;
	do
	{
		while (p != NULL)//沿左子树入栈  直到左子树为空
		{
			if (top >= MAX - 1)
			{
				printf("栈溢出，创建失败！\n");
				return;
			}
			printf("%c ", p->data);
			s[++top] = p;//当前指针p入栈
			p = p->lchild;//指针指向p的左孩子结点
		}
		if (top == -1)//栈空时结束
			return;
		else
		{
			p = s[top--];//弹出栈顶元素
			//printf("%c ", p->data);//访问根结点
			p = p->rchild;//指针指向p的右孩子结点
		}
	} while (p != NULL || top != -1);
}

//非递归中序遍历
void InOrder2(BiTree bt)  //bt为指向二叉树（或某一子树）根结点的指针
{
	BiTree s[MAX], p = bt;//定义栈s
	int top = -1;//栈顶指针
	if (p == NULL)//若为空二叉树 遍历结束
		return;
	do
	{
		while (p != NULL)//沿左子树入栈  直到左子树为空
		{
			if (top >= MAX - 1)
			{
				printf("栈溢出，创建失败！\n");
				return;
			}
			s[++top] = p;//当前指针p入栈
			p = p->lchild;//指针指向p的左孩子结点
		}
		if (top == -1)//栈空时结束
			return;
		else
		{
			p = s[top--];//弹出栈顶元素
			printf("%c ", p->data);//访问根结点
			p = p->rchild;//指针指向p的右孩子结点
		}
	} while (p != NULL || top != -1);
}

//非递归后序遍历
void PostOrder2(BiTree T)
{
	BiTree s[MAX];
	int top = -1;
	BiTree p = T, r = NULL;

	while (p || top > -1)
	{
		if (p)
		{  //走到最左边 
			s[++top] = p;
			p = p->lchild;
		}
		else 
		{  //向右
			p = s[top];  //取栈顶元素 
			if (p->rchild && p->rchild != r) 
			{ //右子树不空，且未陪访问 
				p = p->rchild;  //转向右 
				s[++top] = p;   //压栈 
				p = p->lchild;  //再走到最左 
			}
			else
			{   //否则弹出栈，并访问 
				p = s[top--];//出栈，并获得栈顶元素
				printf("%c ", p->data);
				r = p;   //记录最近访问过的结点 
				p = NULL; //结点访问过，重置p指针 
			}
		}
	}
}

void menu()
{
	system("cls");
	printf("------------------------------------------\n");
	printf("-----------    菜 单 选 择     -----------\n");
	printf("----------- 1.先序遍历二叉树   -----------\n");
	printf("----------- 2.中序遍历二叉树   -----------\n");
	printf("----------- 3.后序遍历二叉树   -----------\n");
	printf("----------- 4.输出叶子结点个数 -----------\n");
	printf("----------- 5.输出二叉树的高度 -----------\n");
	printf("-----------    6.退出          -----------\n");
	printf("------------------------------------------\n");
}
int main()
{
	BiTree bt;
	BiTree *p = (BiTree *)malloc(sizeof(BiTree));
	int deepth = 0, num = 0;
	int i = 0, quit = 0;
	char arr[100];
	printf("输入序列：\n");
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
		printf("请输入选项：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("递归先序遍历二叉树：\n");
			PreOrder1(bt);
			printf("\n");
			printf("非递归先序遍历二叉树：\n");
			PreOrder2(bt);
			printf("\n");
			break;
		case 2:
			printf("递归中序遍历二叉树：\n");
			InOrder1(bt);
			printf("\n");
			printf("非递归中序遍历二叉树：\n");
			InOrder2(bt);
			printf("\n");
			break;
		case 3:
			printf("递归后序遍历二叉树：\n");
			PostOrder1(bt);
			printf("\n");
			printf("非递归后序遍历二叉树：\n");
			PostOrder2(bt);
			printf("\n");
			break;
		case 4:
			printf("树的深度为：%d", deepth);
			deepth = BitreeDepth(bt);
			printf("\n");
			break;
		case 5:
			printf("树的叶子结点个数为：%d", num);
			num = BitreeLeaf(bt);
			printf("\n");
			break;
		case 6:
			quit = 1; break;
		default:
			printf("选项错误，请重新输入！");
			break;
		}
		if (quit == 1)
		{
			break;
		}
		printf("按任意键返回主菜单！\n");
		getchar();				//提取到缓冲区中的回车键
		getchar();				//起到暂停的作用
		printf("程序结束！\n");
	}
	return 0;
}
