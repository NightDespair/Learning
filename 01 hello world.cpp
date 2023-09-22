#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib> 
#include <stdio.h>
#include <string.h>

using namespace std;
#define day 7

int main() {
	
	/*
	cout << "a" << endl;
	printf("day");
	cout << endl;
	
	float f1 = 3.1415926f;
	double d1 = 3.1415926;
	cout << "f1=" << f1 << endl;
	cout << "d1=" << d1 << endl;
	printf("%f,%f", f1, d1); cout << endl;

	float f2 = 3e2;    //  e2=10^2
	double f3 = 3e-2;   //  e-2=10^-2
	int f4 = 3 ^ -2;
	printf("3e2= %f,3e-2= %f, 3^-2= %d\n", f2,f3,f4 ); cout << endl;
	*/
	/*
	short num1 = 1;
	int num2 = 2;
	long num3 = 3;
	long long num4 = 4;

	int array[4];

	for (int x = 0; x <= 3; x++) {
		array[x] = x + 1;
		char chTemp[5];
		snprintf(chTemp, sizeof(chTemp), "num%d", x + 1); //限制了最大长度的赋值防止缓冲区溢出 有一格为\0所以需要给出n+1个空间
		if (array[x] == 1) {
			printf("%s=%hd\n", chTemp, array[x]); //short 类型需要%hd
		}
		else {
			printf("%s=%d\n", chTemp, array[x]);
		}
	}
	int nNum1; int nNum2; int nNum3;
		scanf_s("%d",&nNum1);  //VC中认为函数scanf没有限制长度不安全，所以改成scanf_s
		scanf_s("%9d",&nNum2); //
		scanf_s("%1d",&nNum3);
		printf("nNum1=%d\n", nNum1);
		printf("nNum2=%d\n", nNum2);
		printf("nNum3=%d\n", nNum3);

		*/

	
	
	char Key[20]="qaq12345";
	int end = 1;
	char root[20];
	char end2=3 ;
	char end3[5];
	printf("请输入密码(我不会告诉你密码是%s):",Key);
	while (end2>=1) {
		
		scanf("%s", root);
		// 比较密码
		if (strcmp(root, Key) == 0) {
			end = 0;
			while (getchar() != '\n');
			break;
		}
		end2--;
		printf("密码错误,请重新输入:");
		while (getchar() != '\n');
	}

	if (end == 0) {
		printf("密码正确,验证成功!\n");
	}
	else {
		printf("输入错误超过3次,程序自动退出。\n");
	}
	while (end==0)
	{
		int num1;

		printf("---------------\n接下来为您制作一个三角形\n请输入三角形的高度(请在1~95之间选择):");
		while (true)
		{
			if (scanf("%d", &num1) != 1 || num1 < 1) {

				while (getchar() != '\n');  // 清空缓冲区
				printf("非法输入,请重试:");
			}
			else if (num1 > 95) {
				while (getchar() != '\n');
				printf("数值过大,请重试:");
			}
			else {
				printf("您选择的高度为:%d\n---------------\n", num1);

				break;
			}
		}
		while (getchar() != '\n');  // 清空缓冲区
		char chTemp1[10];
		printf("请输入三角形的符号:");
		scanf("%s", chTemp1);
		printf("您选择的符号为:%s\n", chTemp1);
		int sSize = strlen(chTemp1);
		printf("您选择的长度为:%d\n---------------\n", sSize);
		for (int lenth = 1; lenth <= num1; lenth++) {


			/*  每行多打印一个空格
			for (int wide = num1; wide> lenth; wide--) {

				printf(" ");

			}
			*/
			for (int re = num1 * sSize; re > lenth * sSize; re--) {
					printf(" ");
			}
			for (int wide = 1; wide <= lenth*2-1; wide++) {
				
				printf("%s", chTemp1);
				
			}
			printf("\n");

		}
		printf("三角形一共有%d个符号\n", ((num1 - 1) * (num1 + 1) + 1));
		printf("---------------\n导出完成\n");
		printf("请问您要退出吗y/n\n");
		while (getchar() != '\n');
		scanf("%s", end3);
		while (true)
		{
			if (strcmp(end3, "y") == 0) {
				while (getchar() != '\n');  // 清空缓冲区
				end = 1;
				break;
			}
			else if (strcmp(end3, "n")!=0) {
				while (getchar() != '\n');
				printf("非法输入,请重新选择y/n\n");
				scanf("%s", end3);
			}
			else {
				break;
			}
		}
	}
	
	printf("---------------\n程序结束\n");

	


/*
 double fArea1 = 3.16;
 float fArea2 = 3.16f;
 //浮点比较错误案例
 if (fArea1 == fArea2) {
	 printf("fArea1=fArea2\n");
 }
 else if (fArea1 < fArea2) {
	 printf("fArea2>fArea1\n");
 }
 else if (fArea2 < fArea1) {
	 printf("fArea1>fArea2\n");
 }

 //浮点比较正确案例
 if (abs(fArea1 - fArea2)<0.0001) {
	printf("fArea1=fArea2\n");
}
 else if (fArea1 - fArea2< 0) {
	printf("fArea2>fArea1\n");
}
 else if(fArea2-fArea1< 0){
	printf("fArea1>fArea2\n");
}



 double a;
 float b=0.0f, c = 0.0f;
 printf("%f,%f\n",b,c);
 printf("请输入第一个数:");
 scanf("%lf", &a);
 printf("请输入第二个数:");
 scanf("%f", &b);
 c = a + b;
 printf("%f\n", c);
 printf("%d,%d,%d", sizeof(a), sizeof(b), sizeof(c));

 */



	system("pause");
	return 0;
}




