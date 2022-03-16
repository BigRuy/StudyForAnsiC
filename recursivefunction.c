#include<stdio.h>
/*
	函数递归的学习
*/

//自定义一个递归函数可以实现打印参数部分的每一位
void Print(unsigned int n)
{
	if(n>9){
		Print(n/10);
	}
	printf("%d\n",n%10);
}
//自定义一个函数对数组字符串长度进行识别
int myStrlen(char* str)
{

	int count = 0;
	while(*str!='\0'){
		count++;
		str++;
	}
	return count;
}
//自定义一个递归函数，在不声明变量的情况下，实现对数组字符串长度的识别
int myStrlen2(char* str)
{
	if(*str!='\0'){
		return 1+myStrlen2(str+1);
	}else{
		return 0;
	}
}
//自定义一个递归函数，实现打印n的阶乘
int Fac(int n)
{
	if(n<=1){
		return 1;
	}else{
		return n*Fac(n-1);
	}

}
//自定义一个函数计算第n个斐波那契数（不考虑溢出）
//此处实现方法不宜用递归来写
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while(n>2){
		c = a+b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
//自定义一个递归函数实现，输入一个非法负整数，返回组成它的每一位数字之和
int DigitSum(int n)
{
	int sum = 0;
	if(n>9){
		return DigitSum(n/10) + n%10;
	}else{
		return n;
	}
}
//自定义一个递归函数实现n的k次方
double Pow(int n,int k)
{
	if(k==0){
		return 1;
	}else if(k>0){
		return n*Pow(n,k-1);
	}else{
		return 1.0/Pow(n,-k);
	}

}
int main()
{
	//测试Print()函数
	unsigned int num = 0;
	scanf("%d",&num);//1234
	Print(num);//Print函数可以实现打印参数部分的每一位

	//测试myStrlen()函数
	char arr[] = "hello";
	printf("%d\n",myStrlen(arr));

	//测试Fac()函数
	int n = 3;
	int ret = Fac(n);
	printf("%d\n",ret);

	//测试Fib()函数
	int n2 = 3;
	printf("%d\n",Fib(n2));

	//测试DigSum()函数
	int num1 = 1729;
	int sum = DigitSum(num1);
	printf("%d\n",sum);

	//测试
	int n3 = 0;
	int k = 0;
	scanf("%d %d",&n3,&k);
	double ret2 = Pow(n3,k);
	printf("%lf\n",ret2);


	return 0;
}