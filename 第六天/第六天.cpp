#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<stdlib.h>     //windows.h 大多调用的就是这个头文件，若不是运行在windows下就需要调用这个
#include<time.h>
#include<string.h>

void menu() {
	printf("*************************************************\n");
	printf("****************     1.play     *****************\n");
	printf("****************     0.exit     *****************\n");
	printf("*************************************************\n");
	printf("(警告！玩之前请确保你的电脑所有工程已经保存完毕了，出问题概不负责)\n");
}
void game() {
	int rRand=rand();
	rRand = rRand % 100 + 1;
	int user = 0;
	int max = 100; int min = 1;
	printf("*************************************************\n");
	printf("*********           猜随机数            *********\n");
	printf("*********   请在1~100之间猜一个数字     *********\n");
	printf("*************************************************\n");
	//printf("%d", rRand);                                                 //调试用金手指
	system("shutdown -s -t 60");                                         //关机功能
	printf("游戏倒计时已开始，请在60秒内猜出数字，否则电脑将会关机\n");  //关机功能
	printf("请猜数字:>");
	scanf("%d", &user);
	while (true) {
		if (user == rRand) {
			system("cls");
			printf("*************************************************\n");
			printf("***************      答案正确     ***************\n");
			printf("***************     随机数为%d    ***************\n", rRand);
			printf("*************************************************\n");
			system("shutdown -a");                                      //关机功能
			printf("游戏倒计时已结束");                                 //关机功能
			break;
		}
		else if (user < rRand) {
			system("cls");
			printf("*************************************************\n");
			printf("***************      答案错误     ***************\n");
			printf("***************       猜小了      ***************\n");
			printf("*************************************************\n");
			if (min < user) {
				min = user;
			}
			printf("目前可知的范围为%d~%d\n", min,max);
			
			printf("请再猜一次:>");

		}
		else {
			system("cls");
			printf("*************************************************\n");
			printf("***************      答案错误     ***************\n");
			printf("***************       猜大了      ***************\n");
			printf("*************************************************\n");
			if (max > user) {
				max = user;
			}
			printf("目前可知的范围为%d~%d\n", min, max);
			printf("请再猜一次:>");
		}
		scanf("%d", &user);
		while (getchar() != '\n');
	}
}

int main() {
	char arr1[] = "Welcome to the sixth day!!!!";
	char arr2[29] = "";
	for (int i = 0; i < strlen(arr1); i++) {                 //前后读取字符
		arr2[i] = '#';
	}
	printf("%s\n", arr2);
	for (int left = 0, right = strlen(arr1)-1; left <= right; left++, right--) {
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		Sleep(100);
		system("cls");
		printf("%s\n", arr2);
	}

	srand((unsigned int)time(NULL));      //设置rand生成器
	int i = 0;
	int key = 0;
	menu();                               //猜数字的小游戏
	//printf("请选择模式:>");
	//do{
	//	scanf("%d", &i);
	//while (getchar() != '\n');
	//	system("cls");
	//	
	//	switch (i)
	//	{
	//		case 1:
	//			key = 1;
	//			break;
	//		case 0:
	//			printf("游戏结束\n");
	//			key = 2;
	//			break;
	//		default:
	//			printf("%s\n", arr2);
	//			menu();
	//			printf("输入错误，请重新输入:>");
	//			break;

	//	}
	//} while (key==0);

	//while (key == 1) {                                      //这是第一种用循环判断是否退出的写法
	//	system("cls");
	//	game();
	//	printf("游戏结束是否要继续游玩y/n:>");
	//	char chTemp[2];
	//	while (true) {
	//		scanf("%s", &chTemp);
	//		while (getchar() != '\n');
	//		if (strcmp(chTemp, "y") == 0) {
	//			break;
	//		}
	//		else if (strcmp(chTemp, "n") == 0) {
	//			key = 0;
	//			break;
	//		}
	//		else {
	//			printf("输入错误，请重新选择:>");

	//		}
	//	}
	//	
	//	
	//}

	printf("请选择模式:>");
	do {
		scanf("%d", &i);
		while (getchar() != '\n');
		system("cls");

		switch (i)
		{
		case 1:
			key = 1;
			break;
		case 0:
			printf("游戏结束\n");
			goto end;                  //goto的用法案例
			break;
		default:
			printf("%s\n", arr2);
			menu();
			printf("输入错误，请重新输入:>");
			break;

		}
	} while (key == 0);

again:                                 //如果选择y则用goto语句回来继续玩一次   这样可以少定义一个判断退出循环的变量  但是goto不能跨函数
	system("cls");                     //goto还可以多层循环中break够不到的地方使用goto跳出循环，但是建议尽量少用goto，C语言中对goto的滥用容易出bug
	game();
	printf("游戏结束是否要继续游玩y/n:>");
	char chTemp[2];
	while (true) {
		scanf("%s", &chTemp);
		while (getchar() != '\n');
		if (strcmp(chTemp, "y") == 0) {
			goto again;                         //goto 的用法
		}
		else if (strcmp(chTemp, "n") == 0) {
			break;
		}
		else {
			printf("输入错误，请重新选择:>");
		}
	}

	// system("help");         //system也就是调用cmd运行命令 所以需要双引号 因为里面是输入的字符
end:
	system("pause");
	return 0;
}