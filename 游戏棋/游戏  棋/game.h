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
//返回‘X’，电脑赢
//返回‘0’，玩家赢
//返回‘Q’，平局
//返回‘ ’，继续游戏
int IsFull(char board[ROW][COL], int row, int col);


#endif