#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
int ave1(int a,int b)
{
	return (a + b)>>1;
}
int ave2(int a, int b)
{
	return (a + (b - a)) >> 1 ;
}
int ave3(int a, int b)
{
	//&����ͬΪ1��λ��^���治��ͬ��λ
	return a & b + (a ^ b >> 1) ;
}

int main()
{
	int a = 0;
	int b = 0;
	int num = 0;
	scanf("%d%d", &a, &b);
	printf("%d\n", ave1(a, b));
	printf("%d\n", ave1(a, b));
	printf("%d\n", ave1(a, b));
	system("pause");
	return 0;
}