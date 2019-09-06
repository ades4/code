#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
using namespace std;

int main()
{
	int a = 2, b = 5;
	//0010     0101
	a = a ^ b;    //相同为1，不同为0    a --> 1000 = 8
	b = a ^ b;    //  b --> 0010 = 2
	a = a ^ b;    //  a --> 0101 = 5

	cout << "a = " << a << " " << "b = " << b << endl;
	system("pause");
	return 0;
}