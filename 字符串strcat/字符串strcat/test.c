#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	//¿½±´
	while ((*dest++ = *src++))
	{
		;
	}
	return ret;
}

int main()
{
	char arr[20] = "hello ";
	my_strcat(arr, "you");
	printf("%s\n", arr);
	system("pause");
	return 0;
}
