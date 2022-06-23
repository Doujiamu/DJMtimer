#include <stdio.h>
#include <stdlib.h>
#include "solving.c"
#include "memerylib.c"

//tt
struct Record_card{ //单个总大小 4*int + 5*char + 63*char = 12+68 = 90B
    int group;
    int style;
    char disturbsteps[63];
    int record;
    int keep;
};

int main(void){
    //struct Record_card *record_card=NULL;
    struct Record_card *record_card=NULL;
    int record_buff,count;
    int group;
    int bakctu; //back or continue

    srand((unsigned)time(NULL)); //程序初始化部分
    count=0;

    printf("当前目录内有以下分组(编号 - 阶数 - 模式): \n1 - 3 x 3 x 3 speed\n");
    do{
        printf("选择你将要进入的分组: ");
        scanf("%d",&group);
        getchar();
        if(group==0){
            system("pause");
            return 0;
        }
    }while(group!=1);
    printf("当前你所在的分组:1 - 3 x 3 x 3 speed\n===============\n");
    
    do{
        record_card=realloc(record_card,3*sizeof(int)+68*sizeof(char));
        record_card[count].group=1; //待更改
        printf("333打乱: ");
        
        disturb333sp();
        memadd_disturb(record_card[count].disturbsteps);

        record_card[count].style=3331; //待商确

        record_buff=calctime();

        printf("你的成绩为%3d秒,是否保存(1/0):",record_buff);
        scanf("%d",&bakctu);
        getchar();
        
        record_card[count].keep=bakctu;
        count++;
    }while(!(bakctu==0));

    free(record_card);
    system("pause");
    return 0;
}