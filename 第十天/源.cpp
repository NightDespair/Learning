#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

//交换函数
void compare(char* a,char* b) {
	char c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

//递归交换位置实现倒序
void reverse(char* temp,int max,int min) {
	if (min < max) {
		reverse(temp, max - 1, min + 1);
	}
	compare(&temp[min], &temp[max]);
}

//递归交换位置实现倒序第二种写法
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

//递归实现num的num2次方    库中有自带pow函数实现同样功能，这里仅为练习

double square(double num,double num2) {

	//当 num2 > 0
	if (num2 > 1) {
		return num * square(num, num2 - 1);
	}
	else if(num2 >0){
		return num;
	}

	//当 num2 = 0
	if (num2 == 0) {
		return 1;
	}

	//当 num2 < 0
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

void renew(char map[H][W*2+2]) {      //更新地图
	system("cls");
	for (int i = 0; i < H; i++) {
		printf("%s", map[i]);
	}
}

void game() {                         //用二维数组打印一个用"[]"框住的地图 printf为测试用
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
	renew(map);//更新地图
	
	srand((unsigned)time(NULL));
	int move = 1;
	for (int i = 1;; _sleep(100)) {
		if (_kbhit()) {
			i = _getch() & 95;  //无论大小写 一律都修改为大写
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
		if (i == 27) {         //如果按了esc则退出
			break;
		} 


		renew(map);//更新地图
	}
}





int main() {

	char temp[] = { "abcdefg" };
	printf("交换前:%s\n", temp);
	int max = sizeof(temp) / sizeof(temp[0])-2;
	int min = 0;
	reverse(temp,max,min);
	printf("交换后:%s\n", temp);

	char temp2[] = { "hijklmno" };
	printf("交换前:%s\n", temp2);
	reverse2(temp2);
	printf("交换后:%s\n", temp2);

	int num = 0; int num2 = 0;
	/*printf("请输入一个数字和你要算的平方数: >");*/
	//scanf("%d %d", &num, &num2);
	//if (num2 < 0) {
	//	printf("%d的%d次方为:%lf\n", num, num2, square(num, num2));
	//}
	//else {
	//	printf("%d的%d次方为:%.0lf\n", num, num2, square(num, num2));
	//}
	//
	system("cls");
	game();



	printf("\n");
	system("pause");
	return 0;
}
