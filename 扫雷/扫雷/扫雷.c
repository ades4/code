#define _CRT_SECURE_NO_WARNINGS 1 
#include "扫雷.h"

void Init_mine(char mine[ROWS][COLS], int rows,int cols, char sc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = sc;
		}
	}
}
void Print_mine(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);		
		}
		printf("\n");
	}
}
void Set_mine(char mine[ROWS][COLS], int row, int col)//布雷
{
	int count = MINE;
	while (count)
	{
		int x = 0;
		int y = 0;
		x = rand() % row+1;
		y = rand() % col+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - MINE)
	{
		printf("请输入坐标->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				Print_mine(mine, row, col);
				break;
			}
			else
			{
				int count = Get_mineCount(mine, x, y);
				show[x][y] = count + '0';
				Print_mine(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入坐标不合法,请重新输入\n");
		}
	}
	if (win == row * col - MINE)
	{
		printf("排雷成功\n");
	}
}

int Get_mineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] + 
		mine[x - 1][y] +
		mine[x - 1][y + 1]+ 
		mine[x][y - 1] + 
		mine[x][y + 1]+ 
		mine[x + 1][y - 1] + 
		mine[x + 1][y] + 
		mine[x + 1][y + 1]-8*'0');
}


