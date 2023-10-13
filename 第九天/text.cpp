#define	_CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {

	printf("*****************************************\n");
	printf("***************** 1.Play ****************\n");
	printf("***************** 0.Exit ****************\n");
	printf("*****************************************\n");
}

void game() {
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	initboard(board,ROW,COL);
	//打印棋盘
	display(board, ROW, COL);
	while (true)
	{
		//玩家下棋
		player(board, ROW, COL);
		display(board, ROW, COL);
		if (Text(board, ROW, COL) == 0) {
			break;
		}
		else if(Text(board, ROW, COL) == 2)
		{
			printf("你获胜了!\n");
			break;
		}
		//电脑下棋
		computer(board, ROW, COL);
		display(board, ROW, COL);
		if (Text(board, ROW, COL) == 0) {
			break;
		}
		else if (Text(board, ROW, COL) == 2)
		{
			printf("你输了!\n");
			break;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	menu();
	int input = 1;
	printf("请选择:>");
	while (input)
	{
		scanf("%d", &input);
		while (getchar() != '\n');
		switch (input)
		{
		case(1):
			system("cls");
			game();
			input = 0;
			break;
		case(0):
			printf("结束游戏");
			break;
		default:
			printf("非法输入请重新输入:>");
			break;
		}
	}

	system("pause");
	return 0;
}