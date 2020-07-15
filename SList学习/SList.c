#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

//1->2->3->4
void SListPrintf(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL) {
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}

SListNode* BuySListNode(SLDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->date = x;
	newNode->next = NULL;
	return newNode;
}

void SListPushBack(SListNode** ppList, SLDateType x)
{
	//1. 插入时需要考虑到为空的情况
	//2. 需要传入地址
	SListNode* newNode = BuySListNode(x);
	if (*ppList == NULL) {
		*ppList = newNode;
	}
	else {
		SListNode* tail = *ppList;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
	}	
}

void SListPushfront(SListNode** ppList, SLDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}

//1->2->3->4
void SListPopBack(SListNode** ppList)
{
	//考虑三种情况，本身为空，只有一个节点，多个节点
	if (*ppList == NULL) {
		return;
	}
	else if ((*ppList)->next == NULL) {
		free(*ppList);
		*ppList == NULL;
	}
	else {
		SListNode* tail = *ppList;
		SListNode* prev = NULL;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPopfront(SListNode** ppList) {
	if (*ppList == NULL) {
		return ;
	}
	else {
		SListNode* newhead = (*ppList)->next;
		free(*ppList);
		*ppList = newhead;
	}
}

SListNode* SListFind(SListNode* pList, SLDateType x)
{
	if (pList == NULL) {
		return;
	}
	else {
		SListNode* cur = pList;
		while (cur) {
			if (cur->date == x) {
				return cur;
			}
			cur = cur->next;
		}
	}
	return NULL;
}

// 用find找到某个值的节点  在pos的后进行插入  
void SListInsertAfter(SListNode* pos, SLDateType x)
{
	SListNode* next = pos->next;
	SListNode* newnode = BuySListNode(x);
	newnode->next = next;
	pos->next = newnode;
}

// 删除pos之后位置的节点  1 2 3 4 5  -  3
void SListEraseAfter(SListNode* pos)
{
	if (pos->next) {
		SListNode* next = pos->next;
		pos->next = next->next;
	}
	else {
		return;
	}
}

void SListDestory(SListNode** pList)
{
	if (*pList == NULL) {
		return;
	}
	else {
		while (*pList) {
			SListNode* next = (*pList)->next;
			free(*pList);
			*pList = next;
		}
		*pList = NULL;
	}
}




//拓展
//删除当前节点可以选择用后一个替代前一个的值，尾结点不行
	
	


//链表的逆置
//
//typedef struct ListNode Node;
//struct ListNode* reverseList(struct ListNode* head)
//{
//	Node* newhead = NULL;
//	Node* cur = head;
//	while (cur)
//	{
//		//放在里面避免了cur为空的情况
//		Node* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//}

//倒数第K个结点题     需要考虑输入的值不存在的情况

//
////合并两个有序的链表
//typedef struct ListNode {
//	int val;
//	struct ListNode* next;
//}Node;
//
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL && l2 != NULL) {
//		return l2;
//	}
//
//	if (l2 == NULL && l1 != NULL) {
//		return l1;
//	}
//	Node* newhead = NULL, *tail = NULL;
//	while (l1 && l2) {
//		// 1 2 3 4      2 3 4 5
//		if (l1->val <= l2->val) {
//			if (tail == NULL) {
//				tail = newhead = l1;
//			}
//			else {
//				tail->next = l1;
//				tail = l1;
//			}
//			l1 = l1->next;
//		}
//		else {
//			if (newhead == NULL) {
//				tail = newhead = l2;
//			}
//			else {
//				tail->next = l2;
//				tail = l2;
//			}
//			l2 = l2->next;
//		}
//	}
//	if (l1) {
//		tail->next = l1;
//	}
//	if (l2) {
//		tail->next = l2;
//	}
//	return newhead;
//}; 