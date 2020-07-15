#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once  //用于保证头文件只被编译一次

#include <stdio.h>
#include <malloc.h>

typedef int SLDateType;
typedef struct SListNode {
	SLDateType date;
	struct SListNode* next;
}SListNode;

void SListPrintf(SListNode* pList);
//后插 前插
void SListPushBack(SListNode** ppList, SLDateType x);
void SListPushfront(SListNode** ppList, SLDateType x);
//后删 前删
void SListPopBack(SListNode** ppList);
void SListPopfront(SListNode** ppList);
//查找 x 值的节点
SListNode* SListFind(SListNode* pList, SLDateType x); 
// 在pos的之后进行插入
void SListInsertAfter(SListNode* pos, SLDateType x); 
// 删除pos位置之后的节点
void SListEraseAfter(SListNode* pos);
//销毁
void SListDestory(SListNode** pList);

