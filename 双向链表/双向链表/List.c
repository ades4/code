#define _CRT_SECURE_NO_WARNINGS 1 
#include "List.h"

//建立新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node =(ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;
	return node;
}
//初始化
void ListInit(List* plist)
{
	assert(plist);
	plist->_head = BuyListNode(-1);
	ListNode* head = plist->_head;
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}
//销毁
void ListDestory(List* plist)   
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	ListNode* tmp = NULL;
	while (cur != plist->_head)
	{
		tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	//最后释放头结点
	free(plist->_head);
}
//尾插
void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	tail->_next = newnode;
	newnode->_next = head;
	newnode->_prev = tail;
	head->_prev = newnode;
}
//尾删
void ListPopBack(List* plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* tail = head->_prev;
	ListNode* newtail = tail->_prev;
	free(tail);
	newtail->_next = head;
	head->_prev = newtail;	
}
//头插
void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = cur;
	cur->_prev = newnode;
}
//头删
void ListPopFront(List* plist)
{
	assert(plist && plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* newnext = cur->_next;
	free(head->_next);
	head->_next = newnext;
	newnext->_prev = head;
}
//查找
ListNode* ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = plist->_head;
	while (cur->_next != cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return cur;
}
//在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	newnode->_next = pos;
	newnode->_prev = prev;
	prev->_next = newnode;
	pos->_prev = newnode;
}
//删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}
//删除x元素的节点
void ListRemove(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* cur = ListFind(plist, x);
	ListErase(cur);
}


void ListPrint(List* plist)
{
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	printf("<-head->");
	while (cur != head)
	{
		printf("<-%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}