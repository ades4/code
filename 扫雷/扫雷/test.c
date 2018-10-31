#define _CRT_SECURE_NO_WARNINGS 1 
#include "扫雷.h"
void menu()
{
	printf("**********************\n");
	printf("****    1.play    ****\n");
	printf("****    0.exit    ****\n");
	printf("**********************\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	Init_mine(mine, ROWS, COLS, '0');
	Init_mine(show, ROWS, COLS, '*');
	Print_mine(show, ROW, COL);
	Set_mine(mine, ROW, COL);
	Find_mine(mine, show, ROW, COL);
}
int main()
{
	int select;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("请输入选项：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (select);
	
	return 0;
}