/*
	c语言指针的学习
*/
#include<stdio.h>







int main()
{
	//指针类型决定了解引用权限的大小
	//指针类型决定了指针走一步的大小
	int a = 0;
	int* pa = &a;
	*pa = 10;

	//1.指针没有初始化 会产生也指针
	//2.指针越界会产生也野指针
	//3.指针指向的内存被释放也会产生也指针

	

	printf("pointer\n");

	return 0;
}