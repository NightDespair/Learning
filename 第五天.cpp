#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

int main() {   
	/*
	//�����ĸ���Ѱ�����ֵ
	int arr[3] = { 0 };
	int max = 0;
	scanf("%d", &max);             //scanfÿ��ֻ�����ո�Ͳ�����  gets�ǿ��Զ��ո��
	for (int i =0; i < 3; i++) {


		scanf("%d", &arr[i]);
		if (arr[i]> max) {
			max = arr[i];
		}


	}
	
	printf("���ֵΪ��%d", max);
	*/

	//�׳�
	int ret[10] = {0};
	int x = 1;
	int len = 0;
	int sum = 0;

	printf("���֧������10��������");
	len = sizeof(ret) / sizeof(ret[0]);     //�������鳤��
	for (int i = 0; i < len; i++) {
		scanf("%d", &ret[i]);
		if (getchar() == '\n') {            //�����س���ֹͣ����
			break;
		}
	}
	printf("��ѡ������ֱַ���:");
	for (int i = len-1; i >=0 ; i--) {
		if (ret[i] != 0 || i==0 ) {
			break;
		}
		else {
			len = len - 1;                  //ֻɾ��ĩβ��0��ռ�ĳ��� �������������ѭ��
		}
	}
	for (int i = 0; i < len; i++) {         //ѭ�����ѡ�������
		printf("%d ",ret[i]);
	}
	printf("\n����������ָ���Ϊ��%d\n", len);
	for (int i = 0; i < len;i++) {
		printf("(%d)%d�Ľ׳�Ϊ ",i+1,ret[i]);
		if (ret[i] == 0) {                  //�ж��������Ƿ���0 ����0����������ѭ��  ����û���������0 �����ﵱ 0��=1
			ret[i] = 1;
			sum++;
			printf("%d", ret[i]);
			printf("���������������0�Ľ׳�������ʾ��0��=1��\n", ret[i]);
			continue;
		}
		for (int j = 0; j < ret[i]; j++) {  //�׳�
			x= x * (j+1);
		}
		ret[i] = x;
		x = 1;
		sum = sum + ret[i];                //�׳����
		printf("%d\n", ret[i]);
	}
	
	printf("�������׳���Ӻ�Ľ��Ϊ��%d\n", sum);         //������




	int arr[10] = { 4,2,6,8,5,3,9,1,10,15 };
	int key =0;
	for (int i = 9; i >0; i--) {                   //ð������
		for (int j = i; j >0; j--) {
			if (arr[j] < arr[j - 1]) {
				arr[j] = arr[j - 1] ^ arr[j];
				arr[j-1] = arr[j - 1] ^ arr[j];
				arr[j] = arr[j - 1] ^ arr[j];
			}
		}	
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("������Ҫ���ҵ����֣�");
	scanf("%d", &key);
	printf("\n���ҹ�������Ϊ��");
	int x2 = 0;
	int mid = 0;
	for (int i = 1,j = 10;i<=j; ) {                     //���ֲ���
		mid = (j+i) / 2;                                //mid = (j+i) / 2;���� mid = i + (j - i) / 2;
		if (arr[mid-1] == key) {
			printf("%d\n", arr[mid-1]);
			printf("�ҵ���Ϊ�����ĵ�%d������\n", mid);
			x2++;
			printf("��������%d��\n", x2);
			break;
		}
		else if (arr[mid-1] < key) {
			i = mid+1;
			printf("%d ", arr[mid-1]);
		}
		else if (arr[mid-1] > key) {
			j = mid-1;
			printf("%d ", arr[mid-1]);
		}
		x2++;
	}
	


	system("pause");
	return 0;
}
