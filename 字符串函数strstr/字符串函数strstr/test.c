#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* str1,const char* str2)
{
	const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;
	if (*str2 == '\0')
		return  (char *)str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (char *)cp;
		cp++;
	}
	return NULL;
}
int main()
{
	char *p = "abcdabcdeffdd";
	printf("%s\n",my_strstr(p,"abcdef"));
	system("pause");
	return 0;
}