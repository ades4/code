#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
using namespace std;
//
//void Swap(int &a, int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 2, b = 5;
//	Swap(a, b);
//	cout << "a = " << a << " " << "b = " << b << endl;
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int a = 2, b = 5, c = 0;
//	c = a + b;
//	a = c - a;
//	b = c - a;
//
//	cout << "a = " << a << " " << "b = " << b << endl;
//	system("pause");
//	return 0;
//}


int main()
{
	int a = 2, b = 5;
	a = a + b;   //a = 7
	b = a - b;   //b = 2
	a = a - b;   //a = 5

	cout << "a = " << a << " " << "b = " << b << endl;
	system("pause");
	return 0;
}


//int main()
//{
//	int a = 2, b = 5;
//	//0010     0101
//	a = a ^ b;    //相同为1，不同为0    a --> 1000 = 8
//	b = a ^ b;    //  b --> 0010 = 2
//	a = a ^ b;    //  a --> 0101 = 5
//
//	cout << "a = " << a << " " << "b = " << b << endl;
//	system("pause");
//	return 0;
//}