#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;

//�����ĳ˻�������С�����������Լ���ĳ˻�
int main()
{
	int x, y, min, i, mul = 0;		// x = 4, y = 8
	cin >> x >> y;
	mul = x * y;
	//�������
	min = x;
	if (x > y)
	{
		min = y;
	}

	for (i = min; i >= 1; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			break;
		}
	}
	//��С������
	int j = 0;
	j = mul / i;

	cout << i << " " << j << endl;
	system("pause");
	return 0;
}


