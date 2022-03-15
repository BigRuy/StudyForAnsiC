#include<stdio.h>

#include<math.h>
//自定义一个比较两个整数的，返回最大的一个
int getMax(int x,int y)
{
	int z = 0;
	if(x>y){
		z = x;
	}else{
		z = y;
	}
	return z;
}

//自定义一个函数可以交换两个整型的内容
void swap(int* px,int* py)//void表示无返回类型
{	
	int tmp = 0;//定义一个中间变量
	tmp = *px;
	*px = *py;
	*py = tmp;
}
//自定义一个函数能够判断是否为素数
int isPrime(int x)
{
	int j = 0;
	for(j=2;j<=sqrt(x);j++){
		if(x%j == 0){
			return 0;
		}
	}

	return 1;//如果是素数返回1
}
//自定义一个函数判断是否为闰年
int isLeapYear(int x)
{
	if(x%4==0 && x%100!=0){
		return 1;//是闰年返回1
	}else{
		return 0;//不是返回0
	}
}
//自定义一个函数通过二分法在有序数组中查找一个元素
int foundNum(int a[],int k,int s)
{
	int left = 0;
	int right = s-1;
	while(left<=right){
		int mid = (right+left)/2;//中间值等于左下标加上右下标除以2
		if(a[mid]>k){
			right = mid-1;//右下标等于中间组表减一
		}else if(a[mid]<k){
			left = mid+1;//左下标等于中间坐标加一
		}else{
			return mid;//找到了返回下标值
		}
	}
	return -1;//找不到返回-1
}
//自定义一个函数使得调用一次函数，num次数加一
void Add(int*p)
{
	(*p)++;
}

int main()
{
	//测试getMax函数
	int max = getMax(10,20);
	printf("最大的是：%d\n",max);
	printf("\n");

	//测试swap函数
	int x = 10;
	int y = 20;
	printf("交换前x=%d,y=%d\n",x,y);
	swap(&x,&y);//传入实参的地址
	printf("交换后x=%d,y=%d\n",x,y);
	printf("\n");

	//测试isPrime函数
	int i = 0;
	for(i=100;i<=200;i++){
		if(isPrime(i) ==1){
			printf("素数：%d\t",i);
		}
	}
	printf("\n");

	//测试isLeapyear函数
	int n = 0;
	for(n=1900;n<2022;n++){
		if(isLeapYear(n)==1){//判断返回是否为1
			printf("闰年：%d\t",n);
		}
	}
	printf("\n");

	//测试foundNum函数
	 int arr[] = {1,2,3,4,5,6,7,8,9,10};
	 int key = 7;
	 int sz = sizeof(arr)/sizeof(arr[0]);//计算数组大小

	 //找到了就返回找到位置的下标
	 //找不到就返回-1
	 //数组arr传参，传递的不是整个数组，实际传递的是数组首元素的地址
	 int ret = foundNum(arr,key,sz);
	 if(-1==ret){
	 	printf("找不到！\n");
	 }else{
	 	printf("找到了，下标是：%d\n",ret);
	 }
	 //测试Add函数
	 int num = 0;
	 Add(&num);


	return 0;
}