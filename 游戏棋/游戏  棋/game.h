#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void ComputerPlay(char board[ROW][COL],int row,int col);
void GamerPlay(char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL],int row,int col);
//IsWin
//���ء�X��������Ӯ
//���ء�0�������Ӯ
//���ء�Q����ƽ��
//���ء� ����������Ϸ
int IsFull(char board[ROW][COL], int row, int col);


#endif