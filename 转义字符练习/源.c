#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

//int main()
//{
//	printf("%c\n", '\'');
//
//	printf("%c\n", '\"');
//	printf("%s\n", "\"");
//
//	printf("%c\n", '\n');
//	system("pause");
//	return 0;
//}

int main()
{
	printf("%d\n", strlen("abcdef"));     //6
	// \32��������һ��ת���ַ� \t
	printf("%d\n", strlen("c:\test\32\test.c"));   //13
	system("pause");
	return 0;
}