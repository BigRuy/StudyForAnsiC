#include <stdio.h>
int main(){
    //清理缓冲区的数据，一直到为\n时结束循环
    int tmp = 0;
    while((tmp = getchar()) != '\n'){
        ;
    }
    return 0;
}