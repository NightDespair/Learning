#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Add.h"

bool sushu(int x) {                       //�ú����ж�������boolΪc99�����ı����ϻ���0��1
	for (int i = 3; i <= sqrt(x);i+=2){   //������Ϊż��
		if (x % i == 0) {
			return false;
		}	
	}
	return true;
}
void Add(int* p) {                        //ָ��
	(*p)++;                               //p==&num1  *p==num1
}

void print(unsigned int n) {           //�ݹ飡�������������̶̼��п��Լ������Լ�����ʵ�� �����ѷ����׷��ķ�ʽ��ӡ������
	if (n > 9) {                       //�Ѵ�  ����ǰ��ӡ(��)  �Լ������Լ�һ��һ����   ��ǰ�����ӡ(��)
		print(n / 10);                 //������⣺����д�൱��һ��ѭ��ÿһ��n/10 �˳�������n<10 �ٿ�ʼһ��һ������ִ��
	}
	printf("%u ", n%10);
}

//int my_strlen(char* str) {    //����ⷨ   �����ṩһ���ݹ�д��
//	int count = 0;
//	while (*str!=0)    //while (*str!='\0')
//	{
//		count++;
//		str++;         //����һ���ַ�
//	}
//	return count;
//}

int my_strlen(char* str) {     //�ݹ�    my_strlen(str) = 1+my_strlen(str+1) = 1+1+my_strlen(str+2)
	if (*str != 0) {
		return 1 + my_strlen(str + 1);
	}
	else {
		return 0;
	}
}


int main() {
	int sum = 0;                           //�ж�100-200֮�������������1�������ⲻ�ܱ�����������
	for (int i = 101; i < 200; i += 2) {   //������Ϊż��
		if (sushu(i)) {
			printf("%d ", i);
			sum++;
		}
	}
	printf("\n%d\n", sum);

	int num1 = 0;
	Add(&num1 );                            //�����ַ
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
	print(n);                           //�ݹ飡�����������������������������ǿ
	printf("\n");
	//�ú������ַ����ĳ���
	char chTemp[] ="abc";
	printf("%d", my_strlen(chTemp));

	printf("\n");
	system("pause");
	return 0;
}