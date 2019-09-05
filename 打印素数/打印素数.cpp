#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <math.h>
using namespace std;

//打印100—200之间的素数
//素数--->只能被1和它本身整除
//int main()
//{
//	for (int i = 100; i < 200; i++)
//	{
//		int flag = 0;
//		for (int j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			cout << i << " ";
//		}
//	}
//
//	system("pause");
//	return 0;
//}

//优化
int main()
{
	int j = 0;
	for (int i = 100; i < 200; i++)
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
				break;
		}

		if(j > sqrt(i))
		{
			cout << i << " ";
		}
	}

	system("pause");
	return 0;
}