#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
int strlen(char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

void reverse_str(char* start, char* end)
{
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void reverse(char *str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	char* cur = str;
	reverse_str(left, right);
	//局部逆转
	while (*cur)
	{
		//寻找子串的起点和尾点
		char* start = cur;
		//寻找子串的尾点
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		//逆转子串
		reverse_str(start, cur - 1);
		//走到下一个子串的起点
		if (*cur == ' ')
		{
			cur++;
		}
	}
}

int main()
{
	char arr[] = "student a am i";
	int sz = sizeof(arr) / sizeof(arr[0]);
	reverse(arr, sz);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
