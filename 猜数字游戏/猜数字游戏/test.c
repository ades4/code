#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <time.h>
void Menu()
{
	printf("\t\t********************\t\t\n");
	printf("\t\t��ӭ����������С��Ϸ\t\t\n");
	printf("\t\t********************\t\t\n");
	printf("\t\t*****0.�˳���Ϸ*****\t\t\n");
	printf("\t\t*****1.��ʼ��Ϸ*****\t\t\n");
	printf("\t\t********************\t\t\n");
}
void PlayGame()
{
	int x = rand() % 100;	//����1��99֮�������
	int t = 0;
	while (1)
	{
		printf("������µ�����:");
		scanf("%d", &t);
		if (t > x)
		{
			printf("��´��ˣ��������\n");
		}
		if (t < x)
		{
			printf("���С�ˣ��������\n");
		}
		if (t == x)
		{
			printf("��ϲ��¶���!\n");
			break;
		}
	}
}

int main()
{
	srand(time(NULL));
	while (1)
	{
		Menu();
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			PlayGame();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}
	return 0;
}