#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<stdlib.h>     //windows.h �����õľ������ͷ�ļ���������������windows�¾���Ҫ�������
#include<time.h>
#include<string.h>

void menu() {
	printf("*************************************************\n");
	printf("****************     1.play     *****************\n");
	printf("****************     0.exit     *****************\n");
	printf("*************************************************\n");
	printf("(���棡��֮ǰ��ȷ����ĵ������й����Ѿ���������ˣ�������Ų�����)\n");
}
void game() {
	int rRand=rand();
	rRand = rRand % 100 + 1;
	int user = 0;
	int max = 100; int min = 1;
	printf("*************************************************\n");
	printf("*********           �������            *********\n");
	printf("*********   ����1~100֮���һ������     *********\n");
	printf("*************************************************\n");
	//printf("%d", rRand);                                                 //�����ý���ָ
	system("shutdown -s -t 60");                                         //�ػ�����
	printf("��Ϸ����ʱ�ѿ�ʼ������60���ڲ³����֣�������Խ���ػ�\n");  //�ػ�����
	printf("�������:>");
	scanf("%d", &user);
	while (true) {
		if (user == rRand) {
			system("cls");
			printf("*************************************************\n");
			printf("***************      ����ȷ     ***************\n");
			printf("***************     �����Ϊ%d    ***************\n", rRand);
			printf("*************************************************\n");
			system("shutdown -a");                                      //�ػ�����
			printf("��Ϸ����ʱ�ѽ���");                                 //�ػ�����
			break;
		}
		else if (user < rRand) {
			system("cls");
			printf("*************************************************\n");
			printf("***************      �𰸴���     ***************\n");
			printf("***************       ��С��      ***************\n");
			printf("*************************************************\n");
			if (min < user) {
				min = user;
			}
			printf("Ŀǰ��֪�ķ�ΧΪ%d~%d\n", min,max);
			
			printf("���ٲ�һ��:>");

		}
		else {
			system("cls");
			printf("*************************************************\n");
			printf("***************      �𰸴���     ***************\n");
			printf("***************       �´���      ***************\n");
			printf("*************************************************\n");
			if (max > user) {
				max = user;
			}
			printf("Ŀǰ��֪�ķ�ΧΪ%d~%d\n", min, max);
			printf("���ٲ�һ��:>");
		}
		scanf("%d", &user);
		while (getchar() != '\n');
	}
}

int main() {
	char arr1[] = "Welcome to the sixth day!!!!";
	char arr2[29] = "";
	for (int i = 0; i < strlen(arr1); i++) {                 //ǰ���ȡ�ַ�
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

	srand((unsigned int)time(NULL));      //����rand������
	int i = 0;
	int key = 0;
	menu();                               //�����ֵ�С��Ϸ
	//printf("��ѡ��ģʽ:>");
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
	//			printf("��Ϸ����\n");
	//			key = 2;
	//			break;
	//		default:
	//			printf("%s\n", arr2);
	//			menu();
	//			printf("�����������������:>");
	//			break;

	//	}
	//} while (key==0);

	//while (key == 1) {                                      //���ǵ�һ����ѭ���ж��Ƿ��˳���д��
	//	system("cls");
	//	game();
	//	printf("��Ϸ�����Ƿ�Ҫ��������y/n:>");
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
	//			printf("�������������ѡ��:>");

	//		}
	//	}
	//	
	//	
	//}

	printf("��ѡ��ģʽ:>");
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
			printf("��Ϸ����\n");
			goto end;                  //goto���÷�����
			break;
		default:
			printf("%s\n", arr2);
			menu();
			printf("�����������������:>");
			break;

		}
	} while (key == 0);

again:                                 //���ѡ��y����goto������������һ��   ���������ٶ���һ���ж��˳�ѭ���ı���  ����goto���ܿ纯��
	system("cls");                     //goto�����Զ��ѭ����break�������ĵط�ʹ��goto����ѭ�������ǽ��龡������goto��C�����ж�goto���������׳�bug
	game();
	printf("��Ϸ�����Ƿ�Ҫ��������y/n:>");
	char chTemp[2];
	while (true) {
		scanf("%s", &chTemp);
		while (getchar() != '\n');
		if (strcmp(chTemp, "y") == 0) {
			goto again;                         //goto ���÷�
		}
		else if (strcmp(chTemp, "n") == 0) {
			break;
		}
		else {
			printf("�������������ѡ��:>");
		}
	}

	// system("help");         //systemҲ���ǵ���cmd�������� ������Ҫ˫���� ��Ϊ������������ַ�
end:
	system("pause");
	return 0;
}