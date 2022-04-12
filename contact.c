//通讯录
//1.能够存放一千个人的信息
//2.每个人的信息：名字，年龄，性别，电话，地址
//3.增加人的信息，删除人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.对通讯录的信息进行排序

/*
版本提交记录
版本1.静态内存版本
版本2.动态内存实现自动增长版本
	通讯录初始化之后可以，能存放3个人的信息
	当空间存满后，可以增加两个信息
	实现：3+2+2+2+2·····
版本3.当通讯录退出时把信息写到文件
	当通讯录初始化的时候，加载文件的信息到通讯录中

*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义一些符号
#define max_name 20
#define max_sex 10
#define max_tele 12
#define max_addr 30
#define max_data 1000
#define init_data 3
#define ins_sz 2
//类型的定义
struct Peoinfo
{
	char name[max_name];
	char sex[max_sex];
	int age;
	char tele[max_tele];
	char addr[max_addr];
};
//通讯类
struct Contact
{
	//struct Peoinfo data[max_data];//存放添加进来的人的信息
	struct Peoinfo *data;//指向动态内存申请的空间的起始地址
	int sz;//记录的是当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量
};
//初始菜单
void menu()
{
	printf("------通讯录管理系统------\n");
	printf("---1. add----2. del----\n");
	printf("---3. search-4. modify-\n");
	printf("---5. sort---6. print--\n");
	printf("--------0. exit--------\n");
	printf("-----------------------\n");
}
//定义一个枚举类型
enum Option
{
	out,
	add,
	del,
	search,
	modify,
	sort,
	print
};
//检测增容函数的实现
void CheckCapacity(struct Contact* pc)
{
	if(pc->sz == pc->capacity){
		//考虑增加动态内存的容量
		struct Peoinfo* ptr = realloc(pc->data,(pc->capacity+ins_sz)*sizeof(struct Peoinfo));
		if(ptr != NULL){
			pc->data =ptr;
			pc->capacity += ins_sz;
			printf("增容成功\n");
		}else{
			perror("AddContact");
			printf("增加联系人失败\n");
			return;
		}
	}
}
//加载文件函数的实现
void Loadcontact(struct Contact* pc)
{
	//打开文件
	FILE* pf = fopen("","r");
	if(NULL == pf)
	{
		perror("Loadcontact");
		return;
	}
	//读取文件
	struct Peoinfo tmp = {0};
	while(fread(&tmp,sizeof(struct Peoinfo),1,pf)){
		//是否需要增容
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp; 
		pc->sz++;
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}
//初始化通讯录函数的实现
void InitContact(struct Contact* pc)
{
	pc->data = (struct Peoinfo*)malloc(init_data*sizeof(struct Peoinfo));//申请动态内存空间
	if(pc->data == NULL){
		perror("InitContact");
		return;
	}
	pc->sz = 0;//初始化后默认为0
	//memset()：内存设置
	//memset(pc->data,0,sizeof(pc->data));
	pc->capacity = init_data;
	//加载文件
	Loadcontact(pc);
}
//增加联系人函数的实现
void AddContact(struct Contact* pc)
{
	// if(pc->sz==max_data){
	// 	printf("通讯类已满，无法添加\n");
	// 	return;
	// }
	// if(pc->sz == pc->capacity){
	// 	//考虑增加动态内存的容量
	// 	struct Peoinfo* ptr = realloc(pc->data,(pc->capacity+ins_sz)*sizeof(struct Peoinfo));
	// 	if(ptr != NULL){
	// 		pc->data =ptr;
	// 		pc->capacity += ins_sz;
	// 		printf("增容成功\n");
	// 	}else{
	// 		perror("AddContact");
	// 		printf("增加联系人失败\n");
	// 		return;
	// 	}
	// }
	CheckCapacity(pc);
	//请输入名字
	//增加一个信息
	printf("请输入名字:");
	scanf("%s",pc->data[pc->sz].name);//数组名本身就是一个地址，所以这里不需要取地址
	printf("请输入年龄:");
	scanf("%d",&pc->data[pc->sz].age);//变量需要取地址
	printf("请输入性别:");
	scanf("%s",pc->data[pc->sz].sex);
	printf("请输入电话:");
	scanf("%s",pc->data[pc->sz].tele);
	printf("请输入地址:");
	scanf("%s",pc->data[pc->sz].addr);
	pc->sz++;
	printf("增加成功\n"); 
}
//根据名字查找成员信息
int SearchByNameContact(struct Contact* pc,char name[])
{
	int i = 0;
	for(i=0;i<pc->sz;i++){
		if(strcmp(pc->data[i].name,name)==0){
			return i;//找到了返回下标
		}
	}
	return -1;//找不到的情况
}
//删除通讯录成员信息函数的实现
void DelContact(struct Contact* pc)
{
	char name[max_name] = {0};
	int i = 0;
	//判断通讯录是否为空
	if(pc->sz==0){
		printf("通讯录为空，无法删除");
		return;
	}
	printf("请输入要删除人的名字");
	scanf("%s",name);
	//1.查找要删除的人
	int pos = SearchByNameContact(pc,name);
	//2.查找的人是否存在
	if(pos==-1){
		printf("要删除的人不存在");
		return;
	}
	//3.删除
	for(i=pos;i<pc->sz-1;i++){
		pc->data[i] = pc->data[i+1];
	}
	pc->sz--;
	printf("删除成功\n");
}
//查找指定联系人
 void SearchContact(struct Contact* pc)
 {
 	char name[max_name] = {0}; 
 	printf("请输入要查找的联系人");
 	scanf("%s",name);
 	int pos = SearchByNameContact(pc,name);
	//2.查找的人是否存在
	if(pos==-1){
		printf("要查找的人不存在");
		return;
	}else{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}
//修改指定联系人
void ModifyContact(struct Contact* pc)
{
	char name[max_name] = {0};
	printf("请输入要修改人的名字");
	scanf("%s",name);
	int pos = SearchByNameContact(pc,name);
	//2.查找的人是否存在
	if(pos==-1){
		printf("要修改的人不存在");
		return;
	}else{
		printf("请输入名字:");
		scanf("%s",pc->data[pos].name);//数组名本身就是一个地址，所以这里不需要取地址
		printf("请输入年龄:");
		scanf("%d",&pc->data[pos].age);//变量需要取地址
		printf("请输入性别:");
		scanf("%s",pc->data[pos].sex);
		printf("请输入电话:");
		scanf("%s",pc->data[pos].tele);
		printf("请输入地址:");
		scanf("%s",pc->data[pos].addr);
	}
	printf("修改成功");
}
//排序所有联系人函数的实现(按年龄进行排序)
// void SortContact(struct Contact* pc)
// {
// 	printf("当前是按照年龄的大小进行生序排列的结果\n");
// 	int i = 0;
// 	struct Peoinfo tmp[1] = {0};
// 	for(i=0;i<pc->sz-1;i++){
// 		int j =0;
// 		int flag = 1;
// 		for(j=0;i<pc->sz-1-i;j++){
// 			if(pc->data[j].age>pc->data[j+1].age){
// 				struct Peoinfo tmp[1] = pc->data[j];
// 				pc->data[j] = pc->data[j+1];
// 				pc->data[j+1] = struct Peoinfo tmp[1];
// 				flag = 0;
// 			}
// 		}
// 		if(flag==1){
// 			break;
// 		}
// 	}
// 	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
// 	for(i=0;i<pc->sz;i++){
// 		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
// 			pc->data[i].name,
// 			pc->data[i].age,
// 			pc->data[i].sex,
// 			pc->data[i].tele,
// 			pc->data[i].addr);
// 	}
// }
//打印通讯录的信息函数的实现
void printCantact(const struct Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
	//打印数据
	for(i=0;i<pc->sz;i++){
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}
//销毁通讯录函数的实现
void DestoryContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}
//退出通讯录时保存信息到文件中函数的实现
void SaveContact(struct Contact* pc)
{
	//打开文件
	FILE* pf = fopen("contact.dat","w");
	if(NULL == pf){
		perror("SaveContact");
		return;
	}
	//写文件
	int i = 0;
	for(i=0;i<pc->sz,i++){
		fwrite(pc->data+i,sizeof(struct Peoinfo),1,pf);
	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

int main()
{
	int input = 0; 
	//创建通讯类
	struct Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);
	do{
		menu();
		printf("请选择>:");
		scanf("%d",&input);
		switch(input)
		{
			case add:
			//增加信息
				AddContact(&con);
				break;
			case del:
			//删除信息
				DelContact(&con);
				break;
			//查找成员信息
			case search:
				SearchContact(&con);
				break;
			case modify:
				ModifyContact(&con);
				break;
			case sort:
				// SortContact(&con);
				break;
			case print:
				printCantact(&con);
				break;
			case out:
				//保存信息到文件
				SaveContact(&con);
				//销毁通讯录
				DestoryContact(&con);
				printf("退出通讯录\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	}while(input);


	return 0;
}



















