#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

int my_strcmp1(const char* str1, const char* str2)
{
	/*不可用while(*str1++==*str2++)来比较，当不相等时仍会执行一次++，
		return返回的比较值实际上是下一个字符。应将++放到循环体中进行。*/
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;

		str1++;
		str2++;
	}
	return *str1 - *str2;
}	

int my_strcmp2(const char * src, const char * dst)
{
	int ret = 0;
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
	{
		++src, ++dst;
	}
	return ret;
}

int main()
{
	char* p = "abcdgc";
	char* q = "abcddc";
	printf("%d\n", my_strcmp1(p, q));
	system("pause");
	return 0;
}