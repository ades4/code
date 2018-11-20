#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

void init_arr(int arr[], int sz,int set)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		arr[i] = set;
	}
}
void print_arr(int arr[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void empty_arr(int arr[], int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
void Reverse_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp = 0;
	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	int arr[10];
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
//	init_arr(arr, sz, 1);
//	print_arr(arr, sz);
//	empty_arr(arr, sz);   //清空数组
//	print_arr(arr, sz);
	Reverse_arr(arr, sz);   //逆置数组
	print_arr(arr, sz);
	system("pause");
	return 0;
}
