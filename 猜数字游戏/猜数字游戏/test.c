#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <time.h>
void Menu()
{
	printf("\t\t********************\t\t\n");
	printf("\t\t欢迎来到猜数字小游戏\t\t\n");
	printf("\t\t********************\t\t\n");
	printf("\t\t*****0.退出游戏*****\t\t\n");
	printf("\t\t*****1.开始游戏*****\t\t\n");
	printf("\t\t********************\t\t\n");
}
void PlayGame()
{
	int x = rand() % 100;	//产生1到99之间的数字
	int t = 0;
	while (1)
	{
		printf("输入你猜的数字:");
		scanf("%d", &t);
		if (t > x)
		{
			printf("你猜大了，请继续猜\n");
		}
		if (t < x)
		{
			printf("你猜小了，请继续猜\n");
		}
		if (t == x)
		{
			printf("恭喜你猜对了!\n");
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
			printf("输入错误，请重新输入\n");
			break;
		}
	}
	return 0;
}