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
//	//��� 1 2 3 4 ,breakΪ������ֹѭ��
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
//	//��� 2 3 4 6 7 8 9 10 11, continueΪ������ֹ����ѭ���ģ�
//	//Ҳ���Ǳ���ѭ����continue��ߵĴ��벻����ִ�У�����ֱ����ת��while
//	//�����жϲ��֡�������һ��ѭ��������жϡ�
//	system("pause");
//	return 0;
//}



//
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)  
//		putchar(ch);
//	//��������  
//	//����֮�� ���
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
	//����Ϊ����ʱ�����
	//���Ϊ������֮�����������������continue
	system("pause");
	return 0;
}