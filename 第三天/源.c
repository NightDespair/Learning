#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef unsigned int unint;  //unsigned�޷��ŵ�����  ����unsigned int Ϊ unint  �޷�����Դ�룬�з����ö����Ʋ��� / �޷���Ϊ�Ǹ��� / �޷���int������ֵʱ��Ϊδ����
                             //  �޷���int��ȡֵ��Χ��0��2^ n - 1  / �з���int��ȡֵ��Χ��-2^(n-1)��2^(n-1)-1,��������ռһ��

struct MyStruct
{
	int data;
	struct Mysturct* next;   //*˵��next��ָ�����  next��Ŷ���ĵ�ַ  struct Mystruct ˵��next��ָ�Ķ����������struct Mystruct
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
static int x, y;  //���ⲿ��������ת��Ϊ�ڲ���������
#define ADD(x, y) (((x) + (y))) //define����� ����в���  ע�����ţ�
extern int i;  //�����ⲿ���ţ�����������Դ2��i
extern int add(int x, int y);
#define I 20               //define�����ʶ������

struct cClass {
	char name[20];
	int age;
	char sex[3];
	char phone[12];
};


void text() {          //void����Ҫ�κη���
	static int a = 1;  //static ���α����ͺ�����������������������
	a++;
	printf("%d ", a);
}

void print(struct cClass* ps) {

	printf("1.%s %d %s %s\n",(*ps).name,(*ps).age,(*ps).sex,(*ps).phone);     //(*ps)=s
	printf("2.%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->phone);         //psָ�����ĳ�Ա  ����
}


int main() {

	int sum,sum2;
	for (int a = -1; a <= 5; a++) {

		text();
		sum = add(a, i);  //������ֵ��ֵ��sum
		sum2 = ADD(a, i);
		i = i + 1;
		
	}
	printf("\n%d\nsum=%d\n", i, sum);
	printf("sum2=%d\n", sum2);
	
	struct cClass s = { "С��",28,"��","18888888888" };

	printf("������%s ���䣺%d �Ա�%s �绰���룺%s\n", s.name, s.age, s.sex, s.phone);
	print(&s);

	unint j = 1;
	struct MyStruct n2 = { 1 };
	struct MyStruct n = { 1,&n2 };
	printf("%d 0x%x", n.data,n.next);

	system("pause");
	return 0;
}
