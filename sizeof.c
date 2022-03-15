#include<stdio.h>
#include<limits.h>
int main(void)
{
	/*sizeof()运算符的使用*/
	/*%lu为32位无符号整数*/
	/*
	  以0开头为八进制
	  以0x开头为十六进制
	  不带前缀默认为十进制
	*/
	printf("int存储大小：%lu\n",sizeof(int));
	printf("char存储大小：%lu\n",sizeof(char));
	printf("float存储大小：%lu\n",sizeof(float));
	printf("double存储大小：%lu\n",sizeof(double));
	return 0;
}