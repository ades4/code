#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int i_pow(int x, int y)
{
	if (y > 0)
	{
		return i_pow(x, y - 1)*x;
	}
	return 1;
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n,&k);
	printf("%d\n",i_pow(n, k));
	system("pause");
	return 0;
}