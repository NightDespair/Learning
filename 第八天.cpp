#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

int fac(int n) {       //递归阶乘写法
	if (n<=1) {
		return n;
	}
	else {
		return n*fac(n-1);
	}

}
int fib(int n) {        //用递归的方式算 斐波那契数列   效率低下十分不建议这么写
	if (n <= 2) {
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}
int fib2(int n) {       //用迭代的方式算 斐波那契数列   （循环）
	int a = 1, b = 1, c = 0;

	if (n <= 2) {
		return 1;
	}
	else {
		for (int i = 3; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}

}

void move(char a,char b) {
	printf("%c-->%c ",a,b);
}
     //盘子个数  起始位置 -> 中转位置 -> 目标位置
void hanic(int i, char pos1, char pos2, char pos3) {
	if (i == 1) {
		move(pos1,pos3);
	}
	else {
		hanic(i - 1, pos1, pos3, pos2);     //把除了最底下的移动到中转位置
		move(pos1, pos3);                   //把最底下的移动到目标位置
		hanic(i - 1, pos2, pos1, pos3);     //把剩下的移动到目标位置
	}
}


int main() {
	//int num = 0;
	//scanf("%d", &num);
	//printf("%d\n", fac(num));
	//printf("%d\n", fib2(num));

	hanic(4, 'A', 'B', 'C');



	system("pause");
	return 0;
}



