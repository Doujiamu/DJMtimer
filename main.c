#include <stdio.h>
#include <stdlib.h>
#include "solving.c"
#include "memerylib.c"

void TypeError(char ch);

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
    char ch;

    srand((unsigned)time(NULL)); //程序初始化部分
    count=0;

    while(1){ //一级目录 主目录
        system("cls");
        printf("DJMtimer >> \n\n");
        printf("1 -- 进入分组\n2 -- 制作组信息\n0 -- 退出程序\n===============\n");
        printf("> "); //提示符
        scanf("%c",&ch);
        getchar();
        if(ch=='0'){ //退出程序
            break;
        }
        else if(ch=='2'){  //
            printf("暂未开发...\n0 - 返回上级\n===============\n>");
            scanf("%c",&ch);
            getchar();
        }
        else if(ch=='1'){  //进入单个分组
            while(1){  //二级目录
                system("cls");
                printf("DJMtimer >> 分组\n\n");
                printf("1 -- 进入单个分组\n0 -- 返回上级\n===============\n");
                printf("> ");
                scanf("%c",&ch);
                getchar();
                if(ch=='1'){ //三级目录
                    while(1){ //三级目录
                        system("cls");
                        printf("DJMtimer >> 分组 >> %c分组\n\n",ch);
                        printf("1 -- 开始计时\n2 -- 列出成绩\ns -- 设置\n0 -- 返回上级\n");
                        printf("===============\n");
                        printf("> ");
                        scanf("%c",&ch);
                        getchar();
                        if(ch=='1'){ //四级目录
                            printf("DJMtimer >> 分组 >> %c分组 >> 计时模式\n\n=======计时模式=======",ch);
                            system("cls");
                            do{
                                record_card=realloc(record_card,3*sizeof(int)+68*sizeof(char));
                                record_card[count].group=1; //待更改
                                printf("333打乱: ");
                                
                                disturb333sp();
                                memadd_disturb(record_card[count].disturbsteps);

                                record_card[count].style=3331; //待商确

                                record_buff=calctime();

                                printf("你的成绩为%3d秒,是否保存(1/0)\n> ",record_buff);
                                scanf("%c",&ch);
                                getchar();
                                
                                if(ch=='1'){
                                    record_card[count].keep=1;
                                }
                                else if(ch=='0'){
                                    record_card[count].keep=0;
                                }
                                else{
                                    TypeError(ch);
                                }
                                count++;
                            }while(!(bakctu==0));
                        }
                        else if(ch=='2'){
                            system("cls");
                            printf("暂未开发...\n");
                            system("pause");
                            continue;
                        }
                        else if(ch=='s'){
                            system("cls");
                            printf("暂未开发...\n");
                            system("pause");
                            continue;
                        }
                        else if(ch=='0'){
                            break;
                        }
                        else{
                            TypeError(ch);
                        }
                    }
                    
                }
                else if(ch=='0'){
                    break;
                }
                else{
                    TypeError(ch);
                }
            }
            
        }
        else{
            TypeError(ch);
        }
    }



    /*printf("当前目录内有以下分组(编号 - 阶数 - 模式): \n1 - 3 x 3 x 3 speed\n");
    do{
        printf("选择你将要进入的分组: ");
        scanf("%d",&group);
        getchar();
        if(group==0){
            system("pause");
            return 0;
        }
    }while(group!=1);
    printf("当前你所在的分组:1 - 3 x 3 x 3 speed\n===============\n");*/
    

    free(record_card);
    system("pause");
    return 0;
}

void TypeError(char ch){
	printf(">>%c<<is not a correct command\n>>%c<<不是一个正确的命令!!!\n",ch,ch);
    system("pause");
}