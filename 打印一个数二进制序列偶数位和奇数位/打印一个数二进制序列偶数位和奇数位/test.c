#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

void Print(unsigned int n)
{
	int i = 0;
	//偶数序列
	for (i = 31; i > 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	//奇数序列
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Print( num);
	system("pause");
	return 0;
}