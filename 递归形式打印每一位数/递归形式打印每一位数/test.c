
#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
//ÄæÐò´òÓ¡
void Print_num(int n)
{
	if (n != 0)
	{
		printf("%d ", n % 10);
		Print_num(n / 10);
	}
}
//Ë³Ðò´òÓ¡
int Print_num1(int n)
{
	if (n > 9)
	{
		Print_num1(n / 10);
	}
	printf("%d ", n % 10);
	return 0;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	Print_num(n);
	printf("\n");
	Print_num1(n);
	system("pause");
	return 0;
}



