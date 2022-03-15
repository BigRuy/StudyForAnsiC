#include<stdio.h>
/*三目运算符的实例*/
int A = 10;
int B = 20;
char buy;
int sum,number;

int main()
{
	printf("以下是本店商品的价格：\n A 商品每个10元\t B 商品每个20元\n");
	printf("请输入你所需的商品（A或者B）:");
	scanf("%c",&buy);
	printf("请输入所需的数量：");
	scanf("%d",&number);
	sum = buy=='A' ? A*number:B*number;
	printf("\n你所需要的%d个%c商品总共需要%d元\n",number,buy,sum);
	
	return 0;
}