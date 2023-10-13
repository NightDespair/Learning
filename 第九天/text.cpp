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
	//��ʼ������
	initboard(board,ROW,COL);
	//��ӡ����
	display(board, ROW, COL);
	while (true)
	{
		//�������
		player(board, ROW, COL);
		display(board, ROW, COL);
		if (Text(board, ROW, COL) == 0) {
			break;
		}
		else if(Text(board, ROW, COL) == 2)
		{
			printf("���ʤ��!\n");
			break;
		}
		//��������
		computer(board, ROW, COL);
		display(board, ROW, COL);
		if (Text(board, ROW, COL) == 0) {
			break;
		}
		else if (Text(board, ROW, COL) == 2)
		{
			printf("������!\n");
			break;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	menu();
	int input = 1;
	printf("��ѡ��:>");
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
			printf("������Ϸ");
			break;
		default:
			printf("�Ƿ���������������:>");
			break;
		}
	}

	system("pause");
	return 0;
}