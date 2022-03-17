/*
	三字棋游戏的实现
	test.c 测试游戏逻辑
	game.h 关于游戏相关的函数声明，符号声明头文件包含
	game.c 游戏相关函数的实现
*/
/*
	玩家赢了 -返回*
	电脑赢了 -赶回#
	平局 -返回Q
	游戏继续 -返回c
*/

//头文件的包含
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
//符号的定义
#define Col 3
#define Row 3

//输出提示菜单
void menu()
{
	printf("**********************\n");
	printf("********1. play*******\n");
	printf("********0. exit*******\n");
	printf("**********************\n");
}
//初始化棋盘
void InitBoard(char board[Row][Col],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[Row][Col],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++){//打印每一行
		for(j=0;j<col;j++){//打印每一列
			printf(" %c ",board[i][j]);
			if(j<col-1){
			printf("|"); 
			}
		}
		printf("\n");
		if(i<row-1){//打印第二行
			for(j=0;j<col;j++){
				printf("---");
				if(j<col-1){
					printf("|");
				}
			}
			printf("\n");
		}
	}	
}
//玩家下棋
void PlayerMove(char board[Row][Col],int row,int col)
{
	int x = 0;
	int y = 0;
	while(1){
		printf("玩家走:>\n");
		printf("请输入下棋坐标:>");
		scanf("%d %d",&x,&y);
		//判断坐标合法性
		if(x>=1 && x<=row && y>=1 && y<=col){
			//下棋
			//判断坐标是否被占用
			if(board[x-1][y-1] == ' '){
				board[x-1][y-1] = '*';
				break;
			}else{
				printf("坐标被占用，请重新输入");
			}

		}else{
			printf("坐标错误！请重新输入\n");
		}
	}
}
//电脑下棋
void ComputerMove(char board[Row][Col],int row,int col)
{
 	printf("电脑走:>\n");
 	while(1){
	 	int x = rand()%row;
	 	int y = rand()%col;
	 	if(board[x][y] == ' '){
	 		board[x][y] = '#';
	 		break;
	 	}
 	}
}
//判断棋盘是否已满
int IsFull(char board[Row][Col],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(board[i][j]==' '){
				return 0;//棋盘没满
			}
		}
	}
	return 1;//棋盘满了
}
//判断游戏输赢状态
char IsWin(char board[Row][Col],int row,int col)
{
	int i = 0;
	int j = 0;
	//判断三行
	for(i=0;i<row;i++){
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]!=' '){
			return board[i][1];
		}
	}
	//判断三列
	for(i=0;i<col;i++){
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i]!=' '){
			return board[1][i];
		}
	}
	//判断对角线
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=' '){
		return board[1][1];
	}
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[1][1]!=' '){
		return board[1][1];
	}
	//判断平局
	//棋盘满了放回1，不满返回0
	int ret = IsFull(board,row,col);
	if(ret == 1){
		return 'Q';
	}
	//继续
	return 'c';

}
//游戏主体
void game()
{
	//存取数据 二维数组
	char board[Row][Col];
	//初始化棋盘 -初始化空格
	InitBoard(board,Row,Col);
	//打印棋盘 -本质是打印出数组的内容
	DisplayBoard(board,Row,Col);
	char ret = 0;//存放游戏状态
	//玩家走
	//电脑走
	while(1){
		//玩家下棋
		PlayerMove(board,Row,Col);
		DisplayBoard(board,Row,Col);
		//判断玩家是否赢得游戏
		ret = IsWin(board,Row,Col);
		if(ret != 'c'){
			break;
		}
		//电脑下棋
		ComputerMove(board,Row,Col);
		DisplayBoard(board,Row,Col);
		//判断电脑是否赢得游戏
		ret = IsWin(board,Row,Col);
		if(ret != 'c'){
			break;
		}

	}
	if(ret == '*'){
		printf("玩家赢了！\n");
	}else if(ret == '#'){
		printf("电脑赢了！\n");
	}else{
		printf("平局！\n");
	}
	DisplayBoard(board,Row,Col);
}
//主函数
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();//简易菜单打印
		printf("请选择:>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				//printf("三字棋游戏\n");
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，重新输入\n");
				break;

		}
	}while(input);
	return 0;
}