#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

//初始化
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->_array = (SLDataType* )malloc(sizeof(SLDataType)* capacity);//开辟容量个数组大小
	psl->_size = 0;
	psl->_capacity = capacity;
}
//检查容量是否满了，满了就开辟2倍的容量
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->_size == psl->_capacity)
	{
		psl->_capacity *= 2;
		psl->_array = (SLDataType* )realloc(psl->_array,psl->_capacity * sizeof(SLDataType));
	}
}
//数据的后插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_array[psl->_size++] = x;
}
//将后面的数据删除
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->_size--;
}
//数据的前插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int end = psl->_size - 1;
	while (end >= 0)
	{
		psl->_array[end+1] = psl->_array[end];
		end--;
	}
	psl->_array[0] = x;
	psl->_size ++;
}
//从删除第一个数
void SeqListPopFront(SeqList* psl)
{
	assert(psl && psl->_size >0);
	size_t begin = 0;
	while (begin <= psl->_size-1)
	{
		psl->_array[begin] = psl->_array[begin + 1];
		begin++;
	}
	psl->_size --;
}
//找到这个数并返回所在位置，没有找到则返回-1
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		if (psl->_array[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}
//在指定位置插入,pos为下标
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl && pos<= psl->_size - 1);
	CheckCapacity(psl);
	size_t end = psl->_size - 1;
	while (end >= pos)
	{
		psl->_array[end+1] = psl->_array[end];
		end--;
	}
	psl->_array[pos] = x;
	psl->_size++;
}
//删除指定位置的元素,pos为下标
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl && pos < psl->_size);
	size_t begin = pos;
	while (begin < psl->_size - 1)
	{
		psl->_array[begin] = psl->_array[begin+1];
		++begin;
	}
	psl->_size--;
}
//删除指定元素
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t end = psl->_size - 1;
	for (size_t i = 0; i < end; i++)
	{
		if (psl->_array[i] == x)
		{
			SeqListErase(psl, i);
		}
	}
}
//将下标为pos的元素替换为x
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl&&pos <= psl->_size-1);
	psl->_array[pos] = x;
}
//打印数据
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		printf("%d ", psl->_array[i]);
	}
	printf("\n");
}
//销毁
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if (psl->_array)
	{
		free(psl->_array);
		psl->_array = NULL;
		psl->_capacity = psl->_size = 0;
	}
}
//冒泡排序,从小到大排列
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);
	size_t end = psl->_size - 1;
	while (end)
	{
		int exchange = 0;
		for (size_t i = 0; i < psl->_size - 1; i++)
		{
			if (psl->_array[i] > psl->_array[i + 1])
			{
				int tmp = psl->_array[i];
				psl->_array[i] = psl->_array[i + 1];
				psl->_array[i + 1] = tmp;
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
		end--;
	}
}
//二分查找返回元素下标
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	//[begin,end)
	size_t begin = 0;
	size_t end = psl->_size;
	while (begin < end)
	{
		int mid = (begin + end) / 2;
		
		if (psl->_array[mid] < x)
		{
			begin = mid + 1;
		}
		else  if(psl->_array[mid] > x)
		{
			end = mid;
		}
		else 
		{
			return mid;
		}
	}
	return -1;
}
//删除所有为X的元素
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	size_t cur = 0;
	size_t dst = 0;
	while(cur <= psl->_size - 1)
	{
		if (psl->_array[cur] != x)
		{
			psl->_array[dst] = psl->_array[cur];
			dst++;
		}
		cur++;
	}
	psl->_size = dst;
}
