#ifndef __GAME_H_
#define __GAME_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINE 10

#include <time.h>

void Init_mine(char mine[ROWS][COLS],int rows,int cols, char sc);
void Print_mine(char show[ROWS][COLS],int row,int col);
void Set_mine(char mine[ROWS][COLS],int row,int col);
void Find_mine(char mine[ROWS][COLS],char show[ROWS][COLS],int rows,int cols);
int  Get_mineCount(char mine[ROWS][COLS],int x,int y);

#endif