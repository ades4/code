#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"

//��ʼ��
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->_array = (SLDataType* )malloc(sizeof(SLDataType)* capacity);//���������������С
	psl->_size = 0;
	psl->_capacity = capacity;
}
//��������Ƿ����ˣ����˾Ϳ���2��������
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->_size == psl->_capacity)
	{
		psl->_capacity *= 2;
		psl->_array = (SLDataType* )realloc(psl->_array,psl->_capacity * sizeof(SLDataType));
	}
}
//���ݵĺ��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->_array[psl->_size++] = x;
}
//�����������ɾ��
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->_size--;
}
//���ݵ�ǰ��
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
//��ɾ����һ����
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
//�ҵ����������������λ�ã�û���ҵ��򷵻�-1
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
//��ָ��λ�ò���,posΪ�±�
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
//ɾ��ָ��λ�õ�Ԫ��,posΪ�±�
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
//ɾ��ָ��Ԫ��
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
//���±�Ϊpos��Ԫ���滻Ϊx
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl&&pos <= psl->_size-1);
	psl->_array[pos] = x;
}
//��ӡ����
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (size_t i = 0; i < psl->_size; i++)
	{
		printf("%d ", psl->_array[i]);
	}
	printf("\n");
}
//����
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
//ð������,��С��������
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
//���ֲ��ҷ���Ԫ���±�
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
//ɾ������ΪX��Ԫ��
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
