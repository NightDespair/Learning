#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//��ʼ�����
void initboard(char board[ROW][COL],int row,int col);
//��ʾ���
void display(char board[ROW][COL], int row, int col);
//�������
void player(char board[ROW][COL], int row, int col);
//��������
void computer(char board[ROW][COL], int row, int col);
//�������
int Text(char board[ROW][COL], int row, int col);

