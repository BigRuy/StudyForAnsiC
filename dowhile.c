#include<stdio.h>

/*用dowhile循环求算术平方根*/
double DoSqrt(double z){
 	double a = 1;
 	double b = 0;
 	double c = 0;
 	do{
 		if(b*b<z){
 			b+=a;
 		}else{
 			c=b;
 			b-=a;
 			a/=10;
 		}
 	}while(a>0.000001);

 	return (b+c)/2;
 }	
 int main()
 {
 	double x;
 	double y;
 	do{
 		printf("请输入一个数字(输入“0”退出)：");
 		scanf("%lf",&x);
 		if(x!=0){	
 			if(x<0){
 				printf("无法计算");
 			}else{
 				y=DoSqrt(x);
 				printf("%g的平方根为：%g\n",x,y);
 			}
 		}else{
 			printf("谢谢使用!\n");
 		}
 	}while(x!=0);
 	return 0;
 } 	
