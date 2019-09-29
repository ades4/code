#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <algorithm>
using namespace std;

struct NUM {
	int a;
	int b;
};

void Fun(int n, struct NUM num)
{
	int i = n - 1;
	if (n == 0)
		cout << num.a << "-" << num.b << endl;

	if (n > 0)
	{
		for (int j = 0; j <= i + 1; j++)
		{
			cout << num.a + j << '-' << num.b - n << ' ';
		}
		for (int j = 1; j <= i; j++)
		{
			cout << num.a - j << '-' << num.b - n + j << ' ';
		}
		for (int j = 0; j <= i; j++)
		{
			cout << num.a - n << '-' << num.b + j << ' ';
		}
		for (int j = 0; j <= i + 1; j++)
		{
			cout << num.a - j << '-' << num.b + n << ' ';
		}

		for (int j = 1; j <= i + 1; j++)
		{
			cout << num.a + j << '-' << num.b + n - j << ' ';
		}
		for (int j = 1; j <= i; j++)
		{
			cout << num.a + n << '-' << num.b - j << ' ';
		}
	}
	cout << endl;
}

int main()
{
	NUM num;
	num = { 60,62 };
	//cout << num.a << "-" << num.b << endl;
	int n = 0;   //²ãÊý
	while (cin >> n)
	{
		Fun(n, num);
	}
	system("pause");
	return 0;
}


