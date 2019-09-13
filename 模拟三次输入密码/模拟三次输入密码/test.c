#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

int main()
{
	int input = 0;
	int key = 12345;
	int n = 3;//n为可输入密码的次数
	while (n--)
	{
		printf("请输入密码：\n");
		scanf("%d", &input);
		if (input == key)
		{
			printf("密码输入正确！\n");
			break;
		}
		else
			printf("密码输入不正确。\n");
	}
	system("pause");
	return 0;
}