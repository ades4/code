#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <math.h>
using namespace std;

//��ӡ100��200֮�������
//����--->ֻ�ܱ�1������������
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

//�Ż�
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