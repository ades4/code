#define _CRT_SECURE_NO_WARNINGS 1 
#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("****      1.play      ****\n");
	printf("****      0.exit      ****\n");
	printf("**************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = { 0 };
	InitBoard(board, ROW, COL);
	PrintBoard(board, ROW, COL);
	while(1)
	{ 
		ComputerPlay(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
			break;
		PrintBoard(board, ROW, COL);
		GamerPlay(board, ROW, COL); 
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
			break;
		PrintBoard(board, ROW, COL);
	}
	if (ret == 'X')
	{
		printf("电脑赢\n");
	}
	else if (ret == '0')
	{
		printf("玩家赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	PrintBoard(board, ROW, COL);
}
int main()
{
	int select;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入选项\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("开始玩游戏！\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选项错误，请重新输入\n");
			break;
		}
	} while (select);
	return 0;
}

