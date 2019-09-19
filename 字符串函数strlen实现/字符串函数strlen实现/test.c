#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>

size_t my_strlen(const char* str)  //指针相减其间为元素个数
{
	assert(str != NULL);
	char *p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}


//size_t my_strlen(const char* str)  //不创建临时变量
//{
//	assert(str != NULL);
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}

//size_t my_strlen(const char* str)
//{
//	int count = 0;    //计数器
//	assert(str != NULL);
//	while (*str++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}

int main()
{
	char *p = "hello";
	int num = my_strlen(p);
	printf("%d\n", num);
	system("pause");
	return 0;
}