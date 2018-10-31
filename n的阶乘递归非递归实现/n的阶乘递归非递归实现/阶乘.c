#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
//µÝ¹é
int num_fac(int n)
{
	if (n == 0||n == 1)
		return 1;
	else
		return n * num_fac(n - 1);
}
//·ÇµÝ¹é
int num_fac1(int n)
{
	int i = 0;
	int tmp = 1;
	for(i = 1;i <= n; i++)
	{

		tmp = tmp * i;
	}
	return tmp;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",num_fac(n));
	printf("%d\n", num_fac1(n));
	system("pause");
	return 0;
}

