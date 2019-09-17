#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);
//		i = i + 1;
//	}
//	//输出 1 2 3 4 ,break为永久终止循环
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i = i + 1;
//	}
//	system("pause");
//	return 0;
//}



//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i = i + 1;
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//	}
//	//输出 2 3 4 6 7 8 9 10 11, continue为用于终止本次循环的，
//	//也就是本次循环中continue后边的代码不会再执行，而是直接跳转到while
//	//语句的判断部分。进行下一次循环的入口判断。
//	system("pause");
//	return 0;
//}



//
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)  
//		putchar(ch);
//	//读入数据  
//	//换行之后 输出
//	system("pause");
//	return 0;
//}


int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch > '9')
			continue;
		putchar(ch);
	}
	//输入为数字时，输出
	//输出为除数字之外的数，满足条件，continue
	system("pause");
	return 0;
}