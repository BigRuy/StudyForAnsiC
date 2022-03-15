#include<stdio.h>
int main()
{
	/*使用const前缀声明指定类型常量*/
	const int LENGTH = 10;
	const int WIDTH = 5;
	const char NEWLINE = '\n';
	int area;
	area = LENGTH * WIDTH;
	printf("value of area : %d",area);
	printf("%c",NEWLINE);
	return 0;
}