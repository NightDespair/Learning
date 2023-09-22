#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef unsigned int unint;  //unsigned无符号的整形  定义unsigned int 为 unint  无符号用源码，有符号用二进制补码 / 无符号为非负数 / 无符号int遇到负值时行为未定义
                             //  无符号int的取值范围是0到2^ n - 1  / 有符号int的取值范围是-2^(n-1)到2^(n-1)-1,正负数各占一半

struct MyStruct
{
	int data;
	struct Mysturct* next;   //*说明next是指针变量  next存放对象的地址  struct Mystruct 说明next所指的对象的类型是struct Mystruct
};

//int main1() {
//
//	unint j = 1;
//	struct MyStruct n2 = { 1 };
//	struct MyStruct n = { 1,&n2 };
//	
//
//	printf("%d Ox%x", n.data,n.next);
//
//}
static int x, y;  //把外部链接属性转换为内部链接属性
#define ADD(x, y) (((x) + (y))) //define定义宏 宏具有参数  注意括号！
extern int i;  //声明外部符号，这里声明了源2的i
extern int add(int x, int y);
#define I 20               //define定义标识符常量

struct cClass {
	char name[20];
	int age;
	char sex[3];
	char phone[12];
};


void text() {          //void不需要任何返回
	static int a = 1;  //static 修饰变量和函数，变量出了作用域不销毁
	a++;
	printf("%d ", a);
}

void print(struct cClass* ps) {

	printf("1.%s %d %s %s\n",(*ps).name,(*ps).age,(*ps).sex,(*ps).phone);     //(*ps)=s
	printf("2.%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->phone);         //ps指向对象的成员  常用
}


int main() {

	int sum,sum2;
	for (int a = -1; a <= 5; a++) {

		text();
		sum = add(a, i);  //将返回值赋值给sum
		sum2 = ADD(a, i);
		i = i + 1;
		
	}
	printf("\n%d\nsum=%d\n", i, sum);
	printf("sum2=%d\n", sum2);
	
	struct cClass s = { "小王",28,"男","18888888888" };

	printf("姓名：%s 年龄：%d 性别：%s 电话号码：%s\n", s.name, s.age, s.sex, s.phone);
	print(&s);

	unint j = 1;
	struct MyStruct n2 = { 1 };
	struct MyStruct n = { 1,&n2 };
	printf("%d 0x%x", n.data,n.next);

	system("pause");
	return 0;
}
