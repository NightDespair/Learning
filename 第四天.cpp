#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>


int main() {

	int a =48;

	int b = a / 8 * 10 + a % 8;  //将a转换为8进制数

	printf("%c\n",a);            //输出a 也就是48对应ascii码的字符
	printf("%s\n", "\60");       //转义字符
	printf("%d\n", b);
	while (a<100)
	{
		printf("%c", a );
		a++;
	}
	printf("\n请输入一串字符：");

	char chTemp[50];            //无意义的一个输入什么复制什么的循环练习  并且把间隔换为.
	char chNum;
	int j = 0; int z = 0; int end = 0;
	for (int i=1;i<=sizeof(chTemp)-1;i++) {
		chNum = getchar();
		if (chNum == '\n') {
			for (int a = j; a < z; a++) {
				printf("%c", chTemp[a]);

			}
			printf("\n");
			end = 0;
			j = z;
			chTemp[z] = '\0';
			break;
		}
		else if (chNum == ' ') {
			end = 1;
		}
		if (end == 1) {
			for (int a = j; a < z; a++) {
				printf("%c", chTemp[a]);
				if (a == z - 1) {
					printf(".");
				}
			}
			end = 0;
			j = z;
		}
		else {
			chTemp[z] = chNum;
			z++;
		}

	}
	if (chTemp[z] != '\0') {
		chTemp[z] = '\0';
	}
	
	for (int i = 1; i < z; i++) {     //在字符串chTemp的每一个字符中间加一个.
		if (i != z - 1) {
			printf("%c.", chTemp[i]);
		}
		else {
			printf("%c\n", chTemp[i]);
		}
		

	}
	printf("chTemp=%s\n", chTemp);
	system("pause");
	return 0;
}





