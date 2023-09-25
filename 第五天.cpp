#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

int main() {   
	/*
	//输入四个数寻找最大值
	int arr[3] = { 0 };
	int max = 0;
	scanf("%d", &max);             //scanf每次只读到空格就不读了  gets是可以读空格的
	for (int i =0; i < 3; i++) {


		scanf("%d", &arr[i]);
		if (arr[i]> max) {
			max = arr[i];
		}


	}
	
	printf("最大值为：%d", max);
	*/

	//阶乘
	int ret[10] = {0};
	int x = 1;
	int len = 0;
	int sum = 0;

	printf("最多支持输入10个正数：");
	len = sizeof(ret) / sizeof(ret[0]);     //计算数组长度
	for (int i = 0; i < len; i++) {
		scanf("%d", &ret[i]);
		if (getchar() == '\n') {            //遇到回车就停止输入
			break;
		}
	}
	printf("您选择的数字分别是:");
	for (int i = len-1; i >=0 ; i--) {
		if (ret[i] != 0 || i==0 ) {
			break;
		}
		else {
			len = len - 1;                  //只删除末尾的0所占的长度 不计入接下来的循环
		}
	}
	for (int i = 0; i < len; i++) {         //循环输出选择的数字
		printf("%d ",ret[i]);
	}
	printf("\n您输入的数字个数为：%d\n", len);
	for (int i = 0; i < len;i++) {
		printf("(%d)%d的阶乘为 ",i+1,ret[i]);
		if (ret[i] == 0) {                  //判断数组中是否有0 若有0则跳过本次循环  如果用户有意输入0 则这里当 0！=1
			ret[i] = 1;
			sum++;
			printf("%d", ret[i]);
			printf("（因您有意向计算0的阶乘这里提示你0！=1）\n", ret[i]);
			continue;
		}
		for (int j = 0; j < ret[i]; j++) {  //阶乘
			x= x * (j+1);
		}
		ret[i] = x;
		x = 1;
		sum = sum + ret[i];                //阶乘相加
		printf("%d\n", ret[i]);
	}
	
	printf("所有数阶乘相加后的结果为：%d\n", sum);         //输出结果




	int arr[10] = { 4,2,6,8,5,3,9,1,10,15 };
	int key =0;
	for (int i = 9; i >0; i--) {                   //冒泡排序
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
	printf("请输入要查找的数字：");
	scanf("%d", &key);
	printf("\n查找过的数字为：");
	int x2 = 0;
	int mid = 0;
	for (int i = 1,j = 10;i<=j; ) {                     //二分查找
		mid = (j+i) / 2;                                //mid = (j+i) / 2;或者 mid = i + (j - i) / 2;
		if (arr[mid-1] == key) {
			printf("%d\n", arr[mid-1]);
			printf("找到了为排序后的第%d个数字\n", mid);
			x2++;
			printf("共查找了%d次\n", x2);
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
