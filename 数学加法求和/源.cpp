#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;

int main()
{
	//1 -1/2 +1/3 -1/4 +1/5...
	int i;
	float sum = 0;
	for (i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			//-i;
			sum -= 1.0 / i;
		}
		else
		{
			sum += 1.0 / i;
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}