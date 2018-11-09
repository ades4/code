#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fib(int x)
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (x <= 2)
		return 1;
	int i = 0;
	for (i = 2; i < x; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", fib(num));
	system("pause");
	return 0;
}