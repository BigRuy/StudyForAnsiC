#include<stdio.h>
//冒泡排序实现函数
//两两相邻的元素进行比较
void BubbleSort(int arr[],int sz)
{
	//确定趟数
	int i = 0;
	for(i=0;i<sz-1;i++){
		int j = 0;
		int flag = 1;
		for(j=0;j<sz-1-i;j++){
			if(arr[j]>arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = arr[j];
				flag = 0;
			}
		}
		if(flag==1){
			break;
		}
	}
}


int main()
{
	//sizeof(数组名)计算的是整个数组的大小，单位是字节
	//int arr[8];//创建数组
	//char ch[5];//创建数组
	int arr[10] = {0};//创建数组并且不完全初始化
	char ch[] = {'r','u','y'};//字符数组
	int arr1[3][4] = {1,2,3,4,5};//不完全初始化二维数组
	int arr2[3][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4}};//完全初始化二维数组
	int i = 0;
	int j = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);//数组的长度/第一个数组的大小可以求得数组中数字的个数
	int* p1= &arr1[0][0];//获得二维数组的第一个元素的地址
	for(i=0;i<sz;i++){
		arr[i] = i;
		printf("%d\n",arr[i]);
	}
	for(i=0;i<sz;i++){
		printf("&arr[%d]=%p\n",i,&arr[i]);
	}
	int* p = arr;
	for(i=0;i<sz;i++){
		printf("%d",*p);
		p++;
	}
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%2d",arr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("&arr1[%d][%d]=%p\n",i,j,&arr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<12;i++){
		printf("%d ",*p1);
		p1++;
	}
	printf("\n");

	//冒泡排序
	int arry[] = {9,8,7,6,5,4,3,2,1,0};
	int sz1 = sizeof(arry)/sizeof(arry[0]);//计算数组个数
	BubbleSort(arry,sz1);//数组传参的时候传的是数组手元素的地址
	return 0;
}