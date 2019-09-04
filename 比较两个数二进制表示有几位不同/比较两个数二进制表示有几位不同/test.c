#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
int dec_t(int n, int m)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) != ((m >> i) & 1))
		{
			count++;
		}
	} 
	return count;
}

int dec_t1(int n, int m)
{
	//
	int tmp = 0;
	int count = 0;
	tmp = n ^ m;
	while (tmp)
	{
		tmp = tmp & (tmp - 1);
		count++;
	}
	return count;
}

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);
	printf("两个数二进制不同位的个数：%d\n", dec_t(n, m));
	printf("两个数二进制不同位的个数：%d\n", dec_t1(n, m));
	system("pause");
	return 0;
}