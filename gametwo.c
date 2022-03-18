/*
	实现简易扫雷游戏
	test.c扫雷游戏测试
	game.c游戏函数的实现
	game.h游戏函数的声明
*/
/*
	可以优化如下：1.如果不是雷，周围没有雷，展开一片--函数递归
				2.实现标记雷的坐标	
*/
/*
	一个数组存放布置好的雷的信息
	一个数组存放排查出的雷的信息
*/

//声明包含头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
//定义标识符常量
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2


//函数实现
//菜单提醒
void menu()
{
	printf("******扫雷游戏***\n");
	printf("******1. play***\n");
	printf("******0. exit***\n");
	printf("****************\n");
}
// 初始化棋盘
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i = 0;
	int j = 0;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			board[i][j] = set;
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("-------扫雷游戏-------\n");
	//打印列号
	for(i=0;i<=col;i++){
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++){
		printf("%d ",i);
		for(j=1;j<=col;j++){
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("-------扫雷游戏-------\n");
}
//布置雷
void SetMine(char mine[ROWS][COLS],int row,int col)
{
	int count = 10;
	while(count){
		//生成随机下标
		int x = rand()%row+1;//生成范围0～9的随机数无符号整数作为x坐标
		int y = rand()%col+1;//生成范围0～9的随机数无符号整数作为y坐标
		//检查是否已经有雷
		if(mine[x][y] == '0'){
			mine[x][y] = '1';
			count--;
		}

	}
}
//统计坐标
int GetMineSum(char mine[ROWS][COLS],int x,int y)
{
	return mine[x-1][y]+mine[x-1][y+1]+mine[x][y+1]+mine[x+1][y+1]+mine[x+1][y]+mine[x+1][y-1]+mine[x][y-1]+mine[x-1][y-1]-8*'0';
}
//排查雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	//输入排查的坐标
	//检查坐标初是不是雷
		//是雷，很遗憾炸死了 游戏结束
		//不是雷，统计坐标周围有几个雷 存储排查信息到show数组，游戏继续
	int x = 0;
	int y = 0;
	int win = 0;
	while(win<row*col-10){
		printf("请输入要排查的坐标:>");
		scanf("%d %d",&x,&y);//坐标范围x-(1,9),y-(1,9)
		//判断坐标的合法性
		if(x>=1 && x<=row && y>=1 && y<=col){
			if(mine[x][y]=='1'){
				printf("很遗憾，你被炸死了！");
				DisplayBoard(mine,row,col);
				break;
			}else{
				//不是雷，统计x，y坐标周围的雷
				int count = GetMineSum(mine,x,y);
				show[x][y] = count+'0';//数字转化为字符
				DisplayBoard(show,row,col);//显示出排查的信息
				win++;
			}
		}else{
			printf("坐标不合法，请重新输入！");
		}
	}
	if(win==row*col-10){
		printf("恭喜你挑战成功！");
		DisplayBoard(mine,row,col);
	}
}
//扫雷游戏主体
void game()
{
	char mine[ROWS][COLS];//存放布置好的雷的信息
	char show[ROWS][COLS];//存放排查出的雷的信息
	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');//'0'
	InitBoard(show,ROWS,COLS,'*');//'*'
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine,ROW,COL);
	//排查雷
	FindMine(mine,show,ROW,COL);
}
int main()
{
	//srand((unsigned int)time(NULL));//强制类型转换
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择:");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("游戏退出");
				break;
			default:
				printf("输入错误，请重新输入");
				break;
		}
	}while(input);
	return 0;
}