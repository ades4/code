#define _CRT_SECURE_NO_WARNINGS 1 
#include "ɨ��.h"
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
		printf("������ѡ�");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (select);
	
	return 0;
}