#include<stdio.h>
#include<string.h>//引入包含strcpy库函数的头文件
int main()
{
	//库函数strcpy的学习例子
	char arr1[20] = {0};
	char arr2[] = "hello world";
	strcpy(arr1,arr2);
	printf("%s\n", arr1);//%s以字符串的形式打印

	//库函数memset的学习例子
	char arr3[] = "hello world";
	memset(arr3,'x',5);//将arr3空间的前五个字节替换成x
	printf("%s\n",arr3);

}