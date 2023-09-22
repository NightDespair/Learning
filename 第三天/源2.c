#define	_CRT_SECURE_NO_WARNINGS

int i = 1;   //全局变量具有外部链接属性

int add(int x, int y) {  //如果写成void则没有返回值
	return x + y;       //add返回值为x+y
}