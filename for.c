#include<stdio.h>



/*打印九九乘法表*/
int main()
{
	int i,j;
	for(i=1;i<=9;i++){//控制第i行
		for(j=1;j<=i;j++){//控制第j列
			//if(i<=j){/*当i<j时就跳出第二层循环*/
			//	continue;
				printf("%d*%d=%d\t",i,j,i*j);
			//}
		}
		printf("\n");/*使程序每运行完一行都会换行*/
	}
	return 0;
}