#include <stdio.h>
#include <stdlib.h>
#include "solving.c"

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
    srand((unsigned)time(NULL));
    count=0;
    printf("请选择分组: \n1 - 3 x 3 x 3 speed\n");
    scanf("%d",&group);
    getchar();
    do{
        //record_card=realloc(record_card,(count+1)*(21*sizeof(char)+21*sizeof(char)+1*sizeof(int)));
        //disturb(record_card[count].disturbsteps,record_card[count].disturbsteps_symbol);
        record_card=realloc(record_card,3*sizeof(int)+68*sizeof(char));
        record_card[count].group=group;
        printf("333打乱: ");
        disturb333sp();
        record_card[count].style=3331; //
        record_buff=calctime();
        printf("你的成绩为%-3d秒,是否保存(1/0):",record_buff);
        scanf("%d",&bakctu);
        getchar();
        record_card[count].keep=bakctu;
        count++;
    }while(!(bakctu==0));
    system("pause");
    return 0;
}