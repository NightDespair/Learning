#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//初始化表格
void initboard(char board[ROW][COL],int row,int col);
//显示输出
void display(char board[ROW][COL], int row, int col);
//玩家下棋
void player(char board[ROW][COL], int row, int col);
//电脑下棋
void computer(char board[ROW][COL], int row, int col);
//检测棋盘
int Text(char board[ROW][COL], int row, int col);

