#include <stdio.h>
 
int main()
{
   /* 我的第一个 C 程序 */
	/*
		auto 是局部变量的默认存储类, 限定变量只能在函数内部使用；

		register 代表了寄存器变量，不在内存中使用；

		static是全局变量的默认存储类,表示变量在程序生命周期内可见；

		extern 表示全局变量，即对程序内所有文件可见，类似于Java中的public关键字；
	*/
   printf("Hello, World! \n");
   
   return 0;
} 
