#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,4,3,2,1 };
	int i = 0;
	int tmp = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		tmp ^= arr[i];
	}
	printf("%d\n", tmp);
	system("pause");
	return 0;
}