#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include "common.h"

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _array; // 指向动态开辟的数组 
	size_t _size; // 有效数据个数 
	size_t _capacity; // 容量空间的大小 
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
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);

void SeqListtest1();
void SeqListtest2();
void SeqListtest3();