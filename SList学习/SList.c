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
	//1. ����ʱ��Ҫ���ǵ�Ϊ�յ����
	//2. ��Ҫ�����ַ
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
	//�����������������Ϊ�գ�ֻ��һ���ڵ㣬����ڵ�
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

// ��find�ҵ�ĳ��ֵ�Ľڵ�  ��pos�ĺ���в���  
void SListInsertAfter(SListNode* pos, SLDateType x)
{
	SListNode* next = pos->next;
	SListNode* newnode = BuySListNode(x);
	newnode->next = next;
	pos->next = newnode;
}

// ɾ��pos֮��λ�õĽڵ�  1 2 3 4 5  -  3
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




//��չ
//ɾ����ǰ�ڵ����ѡ���ú�һ�����ǰһ����ֵ��β��㲻��
	
	


//���������
//
//typedef struct ListNode Node;
//struct ListNode* reverseList(struct ListNode* head)
//{
//	Node* newhead = NULL;
//	Node* cur = head;
//	while (cur)
//	{
//		//�������������curΪ�յ����
//		Node* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//}

//������K�������     ��Ҫ���������ֵ�����ڵ����

//
////�ϲ��������������
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