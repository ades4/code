#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
void Adjust(int arr[10])
{
	int i = 0;
	int j =  9;
	int tmp = 0;
	while (i < j)
	{
		//��ͷ��ʼ�ҵ�һ��ż��
		while((i < j) && (arr[i] % 2 != 0))
		{
			i++;
		}
		//��β��ʼ�ҵ�һ������
		while ((i < j) && (arr[j] % 2 != 1))
		{
			j--;
		}
		if (i < j)
		{
			//�ѵ�һ��ż���ͺ����һ����������
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	Adjust(arr);
	system("pause");
	return 0;
}