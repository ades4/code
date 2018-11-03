#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	int i = 0;
	//返回1的位数
	for (i = 0; i < 32; i++)
	{
		if (((value >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}

int count_one_bits1(unsigned int value)
{
	int count = 0;
	unsigned int i = 0;
	for (i = 1; i != 0; i <<= 1)
	{
		if ((value & 1) == 1)
		{
			count++;
		}
		value >>= 1;
	}
	return count;
}

int count_one_bits2(unsigned int value)
{
	int count = 0;
	while(value)
	{
		value = value & (value - 1);
			count++;
	}
	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d中1的个数是：%d\n", num, count_one_bits(num));
	printf("%d中1的个数是：%d\n", num, count_one_bits1(num));
	printf("%d中1的个数是：%d\n", num, count_one_bits2(num));
	system("pause");
	return 0;
}