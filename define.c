#include<stdio.h>
#include<float.h>
#define length 50
#define width 5
#define newline '\n'
int main()
{
	/*使用#define预处理器定义常量的形式*/
	int area;
	area = length *width;
	printf("value of area: %d",area);
	printf("%c",newline);
	return 0;
}