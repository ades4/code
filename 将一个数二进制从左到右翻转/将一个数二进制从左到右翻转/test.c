#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <math.h>
unsigned int reverse_bit(unsigned int num)
{
	int i = 0;
	unsigned int sum = 0;
	for (i = 0; i < 32; i++)
	{
		sum += ((num >> i) & 1) * pow(2, 31 - i);
	}
	return  sum;
}
unsigned int reverse_bit1(unsigned int num)
{
	int i = 0;
	unsigned int tmp = 0;
	for (i = 0; i < 32; i++)
	{
		tmp <<= 1;
		tmp |= (num >> i) & 1;
	}
	return  tmp;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%u\n", reverse_bit(n));
	printf("%u\n", reverse_bit1(n));
	system("pause");
	return 0;
}