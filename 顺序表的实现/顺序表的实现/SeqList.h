#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include "common.h"

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _array; // ָ��̬���ٵ����� 
	size_t _size; // ��Ч���ݸ��� 
	size_t _capacity; // �����ռ�Ĵ�С 
}SeqList;

void SeqListInit(SeqList* psl,size_t capacity);
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);

void SeqListtest1();
void SeqListtest2();
void SeqListtest3();