#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>

int main()
{
	int input = 0;
	int key = 12345;
	int n = 3;//nΪ����������Ĵ���
	while (n--)
	{
		printf("���������룺\n");
		scanf("%d", &input);
		if (input == key)
		{
			printf("����������ȷ��\n");
			break;
		}
		else
			printf("�������벻��ȷ��\n");
	}
	system("pause");
	return 0;
}