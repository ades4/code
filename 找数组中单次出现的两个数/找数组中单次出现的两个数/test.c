#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
int main()
{
	
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	//���浥�����ֵ�Ԫ�ص������
	int ret = 0;
	//����������г���1��λ��
	int pos = 0;
	//���浥�����ֵ�Ԫ�ص�ֵ
	int x = 0, y = 0;
	int i;
	int sz = sizeof(arr)/sizeof(arr[0]);
	//������Ԫ�����Ľ��
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//Ѱ��������г���1��λ��
	for (i = 0; i < 32; i++)
	{
		if ((ret >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	//����pos�Ƿ�Ϊ1�ֳ���������
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("%d %d\n", x, y);
	
	////����ˮ����
	//int empty = 0;
	//int money = 0;
	//int bot = 0;
	//scanf("%d", &money);
	//empty = money;
	//bot = money;
	//while (empty > 1)
	//{
	//	//��ǰ�ܽ���������ƿ��
	//	bot += empty/2;
	//	//�´ο��õĿ�ƿ��
	//	empty = empty / 2 + empty % 2;
	//}
	//printf("%d\n", bot);
	system("pause");
	return 0;
}