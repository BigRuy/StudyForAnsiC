#include<stdio.h>
int main()
{
	int i;
	int a;
	int j;
	int sum = 1;
	printf("请输入你需要计算阶乘的数->:");
	scanf("%d",&a);
	for(i = 1;i<=a;i++){
		sum*=i;
	}

		//sum+=sum;
		//printf("%d",sum)
	
	printf("%d\n",sum);
}