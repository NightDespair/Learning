#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

int fac(int n) {       //�ݹ�׳�д��
	if (n<=1) {
		return n;
	}
	else {
		return n*fac(n-1);
	}

}
int fib(int n) {        //�õݹ�ķ�ʽ�� 쳲���������   Ч�ʵ���ʮ�ֲ�������ôд
	if (n <= 2) {
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}
int fib2(int n) {       //�õ����ķ�ʽ�� 쳲���������   ��ѭ����
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
     //���Ӹ���  ��ʼλ�� -> ��תλ�� -> Ŀ��λ��
void hanic(int i, char pos1, char pos2, char pos3) {
	if (i == 1) {
		move(pos1,pos3);
	}
	else {
		hanic(i - 1, pos1, pos3, pos2);     //�ѳ�������µ��ƶ�����תλ��
		move(pos1, pos3);                   //������µ��ƶ���Ŀ��λ��
		hanic(i - 1, pos2, pos1, pos3);     //��ʣ�µ��ƶ���Ŀ��λ��
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



