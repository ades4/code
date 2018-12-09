#define _CRT_SECURE_NO_WARNINGS 1 
#include "List.h"

//�����½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node =(ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;
	return node;
}
//��ʼ��
void ListInit(List* plist)
{
	assert(plist);
	plist->_head = BuyListNode(-1);
	ListNode* head = plist->_head;
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}
//����
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
	//����ͷ�ͷ���
	free(plist->_head);
}
//β��
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
//βɾ
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
//ͷ��
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
//ͷɾ
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
//����
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
//��pos��ǰ����в��� 
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
//ɾ��posλ�õĽڵ� 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}
//ɾ��xԪ�صĽڵ�
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