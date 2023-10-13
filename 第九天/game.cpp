#define	_CRT_SECURE_NO_WARNINGS
#include "game.h"

void initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = ' ';
		}
	}
}

void display(char board[ROW][COL], int row, int col) {
	system("cls");
	for (row = 0; row < ROW; row++) {
		for (col = 0; col < COL; col++) {
			printf(" %c ", board[row][col]);
			if (col < COL - 1) {
				printf("|");
			}
			else {
				printf("\n");
			}
		}
		if (row < ROW - 1) {
			for (col = 0; col < COL; col++) {
				printf("---");
				if (col < COL - 1) {
					printf("|");
				}
				else {
					printf("\n");
				}
			}
		}
	}
}

void player(char board[ROW][COL], int row, int col) {
	row = 0; col = 0;
	printf("请输入你要下的坐标(范围为%d~%d):>",ROW,COL);
	while (true) {
		scanf("%d %d", &row, &col);
		while (getchar() != '\n');
		if ((row > ROW || row < 1) || (col > COL || col < 1)) {
			printf("违法输入，请在%d~%d的坐标内下棋:>", ROW, COL);
		}
		else if (board[row - 1][col - 1] != ' ') {
			printf("这里已经下过了，请重新下:>", ROW, COL);
		}
		else
		{
			break;
		}
	}
	board[row-1][col-1] = '*';
}

void computer(char board[ROW][COL], int row, int col) {
	row = rand() % ROW;
	col = rand() % COL;
	while (true) {
		if (board[row][col] != ' ') {
				row = rand() % ROW;
	            col = rand() % COL;
		}
		else
		{
			break;
		}
	}
	board[row][col] = '#';
}

int Text(char board[ROW][COL], int row, int col) {
	int key = 0;
	//横线获胜的情况
	for (row = 0 ; row < ROW ; row++) {
		for(int j=0 ; j < COL-1 ; j++){
			if (board[row][j] == ' ') {
				break;
			}
			if (board[row][j] == board[row][j+1]) {
				key += 1;
			}
		}
		if (key == COL-1) {
			return 2;
		}
		else {
			key = 0;
		}
	}
	//竖线获胜的情况
	for (col = 0; col < COL; col++) {
		for (int j = 0; j < ROW - 1; j++) {
			if (board[j][col] == ' ') {
				break;
			}
			if (board[j][col] == board[j + 1][col]) {
				key += 1;
			}
		}
		if (key == ROW-1) {
			return 2;
		}
		else {
			key = 0;
		}
	}
	//斜线获胜的情况
	col = 0; row = 0;
	for (int j = 1; j < ROW; j++) {
		if (board[row][col] == ' ') {
			break;
		}
		if (board[row][col] == board[row+j][col+j]) {
			key += 1;
		}
	}
	if (key == ROW - 1 && key == COL- 1) {
		return 2;
	}
	else {
		key = 0;
	}
	
	for (int j = 1; j < ROW ; j++) {
		if (board[row][COL-1] == ' ') {
			break;
		}
		if (board[row][COL-1] == board[row + j][COL-1 - j]) {
			key += 1;
		}
	}
	if (key == ROW - 1 && key == COL - 1) {
		return 2;
	}
	else {
		key = 0;
	}
	
	for (int i = 0; i < ROW ; i++) {
		for (int j = 0; j < COL; j++) {
			if (board[i][j] == ' ') {
				return 1;
			}
		}
	}
	printf("游戏结束\n");
	return 0;

}