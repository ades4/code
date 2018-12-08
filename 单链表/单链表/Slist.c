#define _CRT_SECURE_NO_WARNINGS 1 
#include "Slist.h"
//链表的初始化
void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
//销毁    野指针也叫垂悬指针
void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next ;
	}
	plist->_head = NULL;
}
//创建新节点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pnode = (SListNode* )malloc(sizeof(SListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	return pnode;
}
//前插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newnode = BuySListNode(x);
	newnode->_next  = plist->_head;
	plist->_head = newnode;
}
//尾插
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = plist->_head;
	if (plist->_head  == NULL)
	{
		plist->_head = newnode;
	}
	else
	{
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
		newnode->_next = NULL;
	}
}
//前删
void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* newhead = plist->_head->_next;
	free(plist->_head);
	plist->_head = newhead;
}
//尾删
void SListPopBack(SList* plist)
{
	assert(plist);
	if (plist->_head->_next == NULL)
	{
		free(plist->_head);
	}
	else
	{
		SListNode* cur = NULL;
		SListNode* tail = plist->_head;
		while (tail->_next)
		{
			cur = tail;
			tail = tail->_next;
		}
		free(tail);
		cur->_next = NULL;
	}
}
//查找
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
			return cur;
		else
			cur = cur->_next;
	}
	return cur;
}
//在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* tmp = pos->_next;
	SListNode* newnode = BuySListNode(x);
	pos->_next = newnode;
	newnode->_next = tmp;
}
/*/删除pos位置上的节点  
void SListErase(SList* plist, SListNode* pos)
{
	assert(plist);
	//如果pos为空或者链表为空
	if (NULL == plist && NULL == pos)
	{
		return;
	}
	//如果pos等于第一个节点
	if (pos == plist->_head)
	{
		SListPopFront(&plist);
	}
	//不为第一个节点
	else
	{
		SListNode* cur = plist->_head;
		while (cur->_next)
		{
			if (cur->_next == pos)
			{
				SListNode* next = cur->_next->_next;
				free(pos);
				cur->_next = next;
			}
			cur = cur->_next;
		}
	}
}*/
//把pos后面的数删除
void SListEraseAfter(SListNode* pos)
{
	assert(pos->_next);
	SListNode* tmp = pos->_next->_next;
	free(pos->_next);
	pos->_next = tmp;
}
//删除x
void SListRemove(SList* plist, SLTDataType x)
{
	SListNode* cur = SListFind(plist, x);
	if (cur == plist->_head)
	{
		SListPopFront(plist);
		return;
	}
	else
	{
		SListNode* pos = plist->_head;
		while (pos->_next)
		{
			if (pos->_next == cur)
			{
				SListNode* next = pos->_next->_next;
				free(pos->_next);
				pos->_next = next;
			}
			pos = pos->_next;
		}
	}
}
void SListRemove1(SList* plist, SLTDataType x)
{
if (plist->_head->_data == x)
	{
		SListPopFront(plist);
		return;
	}
	else
	{
		SListNode* cur = plist->_head;
		SListNode* prev = NULL;
		while(cur)
		{
			if (cur->_data == x)
			{
				prev->_next = cur->_next;
				free(cur);
				cur = NULL;
				break;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
			
		}
	}
}
//打印
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
