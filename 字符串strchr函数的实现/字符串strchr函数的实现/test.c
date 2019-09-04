#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <string.h>
char* my_strchr( char* s, char c)
{
	char* str = s;
	while (*s != '\0'&&*s != c)
	{
		s++;
	}
	return *s == c ? s : NULL;
}
int main()
{
	char *p = "abcdbc";
//	printf("%s\n", strchr(p, 'b'));
	printf("%s\n", my_strchr(p, 'b'));
	system("pause");
	return 0;
}