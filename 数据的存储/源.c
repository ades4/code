#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int b = -10;
//	return 0;
//}


//#include <stdio.h>
//
//int check_sys()
//{
//	int i = 1;
//	return (*(char *)&i);
//}
//int main() {
//	int ret = check_sys();
//	if (ret == 1)
//		printf("С��\n");
//	else
//		printf("���\n");
//
//	system("pause");
//	return 0;
//}


//

////����2
//int check_sys() {
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main() {
//	int ret = check_sys();
//	if (ret == 1)
//		printf("С��\n");
//	else
//		printf("���\n");
//
//	system("pause");
//	return 0;
//}


//
//int main()
//{
//	char a = -1;   //-1
//	signed char b = -1;   //-1
//	unsigned char c = -1;   //255   -->�޷�������
//	printf("a = %d, b = %d, c = %d\n",a,b,c);  
//	system("pause");
//	return 0;
//}

int main()
{
	char a = -128;
	char b = 128;
	printf("%u, %u\n", a, b);
	system("pause");
	return 0;
}
