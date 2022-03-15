#include<stdio.h>
/*switch循环的实例*/
int main()
{
	int num;
	printf("请输入一个1～7的数字(输入“0”退出): ");
    scanf("%d",&num);
    if(num!=0&&num<=7&&num>=1){
    	switch(num)
    	{
        	case 1:printf("Monday\n");
        	break;
        	case 2:printf("Tuesday\n");
        	break;
        	case 3:printf("Wednesday\n");
        	break;
        	case 4:printf("Thursday\n");
        	break;
        	case 5:printf("Friday\n");
        	break;
        	case 6:printf("Saturday\n");
        	break;
        	case 7:printf("Sunday\n");
        	break;
    	}
    }else if(num==0){
    	printf("谢谢使用！\n");
    }else{
    	printf("请按要求输入数字！\n");
    }
	return 0;
}