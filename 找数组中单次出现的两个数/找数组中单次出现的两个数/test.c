#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
int main()
{
	
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	//保存单独出现的元素的异或结果
	int ret = 0;
	//保存异或结果中出现1的位置
	int pos = 0;
	//保存单独出现的元素的值
	int x = 0, y = 0;
	int i;
	int sz = sizeof(arr)/sizeof(arr[0]);
	//求所有元素异或的结果
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//寻找异或结果中出现1的位置
	for (i = 0; i < 32; i++)
	{
		if ((ret >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	//根据pos是否为1分成两个数组
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
	
	////换汽水问题
	//int empty = 0;
	//int money = 0;
	//int bot = 0;
	//scanf("%d", &money);
	//empty = money;
	//bot = money;
	//while (empty > 1)
	//{
	//	//当前能交换的饮料瓶数
	//	bot += empty/2;
	//	//下次可用的空瓶数
	//	empty = empty / 2 + empty % 2;
	//}
	//printf("%d\n", bot);
	system("pause");
	return 0;
}