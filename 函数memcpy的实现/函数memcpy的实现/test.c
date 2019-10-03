#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
#include <string.h>
//内存拷贝函数
//源src所指的内存地址的起始位置开始拷贝n个"字节"到目标dest所指的内存地址的起始位置中
void* my_memcpy(void* dest, const void* src, int n)
{	
	void *ret = dest;			//记录初始地址
	assert(dest != NULL);
	assert(src != NULL);

	while (n--)
	{
		*(char*)dest = *(char*)src;		//将src第一个字节给dest
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}

int main()
{
	int* arr1[] = { 1,2,3,4,5,6,7,8 };
	int arr2[20] = { 0 };
	my_memcpy(arr2, arr1, 12);		//12个字节，前三个数

	system("pause");
	return 0;
}
