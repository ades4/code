#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
//µÝ¹é
int fib(int x)
{
	if (x <= 2)
		return 1;
	else
		return (fib(x - 1) + fib(x - 2));
}
//·ÇµÝ¹é
int fib1(int x)
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (x <= 2)
		return a;
	else
	{
		int i;
		for (i = 2; i < x; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
	}
	return c;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", fib(num));
	printf("%d\n", fib1(num));
	system("pause");
	return 0;
}