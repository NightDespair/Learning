#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Add.h"

bool sushu(int x) {                       //用函数判断素数，bool为c99新增的本质上还是0和1
	for (int i = 3; i <= sqrt(x);i+=2){   //素数不为偶数
		if (x % i == 0) {
			return false;
		}	
	}
	return true;
}
void Add(int* p) {                        //指针
	(*p)++;                               //p==&num1  *p==num1
}

void print(unsigned int n) {           //递归！！！！！！！短短几行靠自己调用自己就能实现 （将难法由易法的方式打印出来）
	if (n > 9) {                       //把从  后往前打印(易)  自己调用自己一递一归变成   从前往后打印(难)
		print(n / 10);                 //个人理解：这样写相当于一层循环每一层n/10 退出条件是n<10 再开始一层一层往回执行
	}
	printf("%u ", n%10);
}

//int my_strlen(char* str) {    //常规解法   下面提供一个递归写法
//	int count = 0;
//	while (*str!=0)    //while (*str!='\0')
//	{
//		count++;
//		str++;         //找下一个字符
//	}
//	return count;
//}

int my_strlen(char* str) {     //递归    my_strlen(str) = 1+my_strlen(str+1) = 1+1+my_strlen(str+2)
	if (*str != 0) {
		return 1 + my_strlen(str + 1);
	}
	else {
		return 0;
	}
}


int main() {
	int sum = 0;                           //判断100-200之间的素数（除了1和自身外不能被整除的数）
	for (int i = 101; i < 200; i += 2) {   //素数不为偶数
		if (sushu(i)) {
			printf("%d ", i);
			sum++;
		}
	}
	printf("\n%d\n", sum);

	int num1 = 0;
	Add(&num1 );                            //传入地址
	printf("%d ",num1);
	for (int i = 1; i < 10; i++) {
		Add(&num1 );
		printf("%d ",num1);
	}
	printf("\n");
	for (int i = 1, j = 1; i <= 10; i++, j++) {
		printf("%d ", Add2(i, j));
	}
	printf("\n");

	unsigned int n = 0;
	scanf("%u", &n);
	print(n);                           //递归！！！！！！！！！！！！！！真的强
	printf("\n");
	//用函数求字符串的长度
	char chTemp[] ="abc";
	printf("%d", my_strlen(chTemp));

	printf("\n");
	system("pause");
	return 0;
}