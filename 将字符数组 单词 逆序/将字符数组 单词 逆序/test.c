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
	//�ֲ���ת
	while (*cur)
	{
		//Ѱ���Ӵ�������β��
		char* start = cur;
		//Ѱ���Ӵ���β��
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		//��ת�Ӵ�
		reverse_str(start, cur - 1);
		//�ߵ���һ���Ӵ������
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
