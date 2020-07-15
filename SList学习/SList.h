#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once  //���ڱ�֤ͷ�ļ�ֻ������һ��

#include <stdio.h>
#include <malloc.h>

typedef int SLDateType;
typedef struct SListNode {
	SLDateType date;
	struct SListNode* next;
}SListNode;

void SListPrintf(SListNode* pList);
//��� ǰ��
void SListPushBack(SListNode** ppList, SLDateType x);
void SListPushfront(SListNode** ppList, SLDateType x);
//��ɾ ǰɾ
void SListPopBack(SListNode** ppList);
void SListPopfront(SListNode** ppList);
//���� x ֵ�Ľڵ�
SListNode* SListFind(SListNode* pList, SLDateType x); 
// ��pos��֮����в���
void SListInsertAfter(SListNode* pos, SLDateType x); 
// ɾ��posλ��֮��Ľڵ�
void SListEraseAfter(SListNode* pos);
//����
void SListDestory(SListNode** pList);

