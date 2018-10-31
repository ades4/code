#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
//µÝ¹é
int i_strlen(char *arr)
{
	if ('\0' == *arr)
		return 0;
	else
		return i_strlen(++arr)+1;
}
//·ÇµÝ¹é
int strlen1(char *arr)
{
	int len = 0;
	for (len = 0; ; len++)
	{
		if (arr[len] == '\0')
			break;
	}
	return len;
}
int main()
{
	int len = 0;
	char arr[] = "abcdef";
	printf("%d\n", i_strlen(arr));
	printf("%d\n", strlen1(arr));
	system("pause");
	return 0;
}