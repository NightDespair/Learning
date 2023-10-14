#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

//��������
void compare(char* a,char* b) {
	char c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//�ݹ齻��λ��ʵ�ֵ���
void reverse(char* temp,int max,int min) {
	if (min < max) {
		reverse(temp, max - 1, min + 1);
	}
	compare(&temp[min], &temp[max]);
}

//�ݹ齻��λ��ʵ�ֵ���ڶ���д��
void reverse2(char* temp) {
	char tmp = *temp;
	int len = strlen(temp);
	*temp = *(temp + len - 1);
	*(temp + len - 1) = '\0';
	if (len > 2) {
		reverse2(temp+1);
	}
	*(temp + len - 1) = tmp;
}

//�ݹ�ʵ��num��num2�η�    �������Դ�pow����ʵ��ͬ�����ܣ������Ϊ��ϰ

double square(double num,double num2) {

	//�� num2 > 0
	if (num2 > 1) {
		return num * square(num, num2 - 1);
	}
	else if(num2 >0){
		return num;
	}

	//�� num2 = 0
	if (num2 == 0) {
		return 1;
	}

	//�� num2 < 0
	if (num2 < -1) {
		return 1/num * square(num, num2 + 1);
	}
	else {
		return 1/num;
	}
}

#define H 15
#define W H
#define S (W*H)

void renew(char map[H][W*2+2]) {      //���µ�ͼ
	system("cls");
	for (int i = 0; i < H; i++) {
		printf("%s", map[i]);
	}
}

void game() {                         //�ö�ά�����ӡһ����"[]"��ס�ĵ�ͼ printfΪ������
	char map[H][W*2+2] = { 0 };

	for (int c = 0,i=0;i<S;i++) {
		if (i % W==0 && i != 0) {
			map[i / (W + 1)][c] = '\n';
			c = 0;
			/*printf("\n");*/
		}
		if(!((i / W % (H - 1)) && i%W%(W-1) )|| i==0){
			map[i/W][c] = '[';
			map[i/W][c+1] = ']';
			c += 2;
			/*printf("[]");*/
		}
		else {
			map[i / W][c] = ' ';
			map[i / W][c + 1] = ' ';
			c += 2;
			/*printf("  ");*/
		}
	}
	/*printf("\n");
	system("cls");*/
	/*for (int i = 0; i < H; i++) {
		printf("%s", map[i]);
	}*/
	renew(map);//���µ�ͼ
	
	srand((unsigned)time(NULL));
	int move = 1;
	for (int i = 1;; _sleep(100)) {
		if (_kbhit()) {
			i = _getch() & 95;  //���۴�Сд һ�ɶ��޸�Ϊ��д
			if (i == 'A' && move != 1) {
				move = -1;
				map[H / 2][W] = 'R';
			}
			else if (i == 'D' && move != -1) {
				move = 1;
				map[H / 2][W] = 'L';
			}
			else if (i == 'W' && move != W)  {
				move = -W;
				map[H / 2][W] = 'U';
			}
			else if (i == 'S' && move != -W) {
				move = W;
				map[H / 2][W] = 'N';
			} 
		}
		if (i == 27) {         //�������esc���˳�
			break;
		} 


		renew(map);//���µ�ͼ
	}
}





int main() {

	char temp[] = { "abcdefg" };
	printf("����ǰ:%s\n", temp);
	int max = sizeof(temp) / sizeof(temp[0])-2;
	int min = 0;
	reverse(temp,max,min);
	printf("������:%s\n", temp);

	char temp2[] = { "hijklmno" };
	printf("����ǰ:%s\n", temp2);
	reverse2(temp2);
	printf("������:%s\n", temp2);

	int num = 0; int num2 = 0;
	/*printf("������һ�����ֺ���Ҫ���ƽ����: >");*/
	//scanf("%d %d", &num, &num2);
	//if (num2 < 0) {
	//	printf("%d��%d�η�Ϊ:%lf\n", num, num2, square(num, num2));
	//}
	//else {
	//	printf("%d��%d�η�Ϊ:%.0lf\n", num, num2, square(num, num2));
	//}
	//
	system("cls");
	game();



	printf("\n");
	system("pause");
	return 0;
}
