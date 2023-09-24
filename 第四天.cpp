#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>


int main() {

	int a =48;

	int b = a / 8 * 10 + a % 8;  //��aת��Ϊ8������

	printf("%c\n",a);            //���a Ҳ����48��Ӧascii����ַ�
	printf("%s\n", "\60");       //ת���ַ�
	printf("%d\n", b);
	while (a<100)
	{
		printf("%c", a );
		a++;
	}
	printf("\n������һ���ַ���");

	char chTemp[50];            //�������һ������ʲô����ʲô��ѭ����ϰ  ���ҰѼ����Ϊ.
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
	
	for (int i = 1; i < z; i++) {     //���ַ���chTemp��ÿһ���ַ��м��һ��.
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





