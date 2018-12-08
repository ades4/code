#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include "common.h"

// 1����ͷ�����ѭ��������ɾ���ʵ�� 
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopBack(SList* plist);

SListNode* SListFind(SList* plist, SLTDataType x);
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в��� 
void SListInsertbefore(SListNode* pos, SLTDataType x);
void SListErase(SList* plist, SListNode* pos);
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListRemove1(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList1();
void TestSList2();

