#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
#include <string.h>
//�ڴ濽������
//Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n��"�ֽ�"��Ŀ��dest��ָ���ڴ��ַ����ʼλ����
void* my_memcpy(void* dest, const void* src, int n)
{	
	void *ret = dest;			//��¼��ʼ��ַ
	assert(dest != NULL);
	assert(src != NULL);

	while (n--)
	{
		*(char*)dest = *(char*)src;		//��src��һ���ֽڸ�dest
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}

int main()
{
	int* arr1[] = { 1,2,3,4,5,6,7,8 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 12);		//12���ֽڣ�ǰ������

	system("pause");
	return 0;
}
