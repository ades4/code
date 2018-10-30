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
		printf("����Ӯ\n");
	}
	else if (ret == '0')
	{
		printf("���Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("������ѡ��\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��ʼ����Ϸ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
			break;
		}
	} while (select);
	return 0;
}

