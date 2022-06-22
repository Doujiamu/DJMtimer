#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "DIYfuncs.c"

/*本文件用于存放 还原过程中需要的模块，例如 打乱、计时*/

//void disturb(char array[],char array_symbol[]);
void disturb333sp();
int calctime();

void disturb333sp(){
    FILE *fp;
    char steps[6]={'R','L','U','D','F','B'};
    int i=0,stepnum=21,stepbuff;
    int buffer;//buffer为缓存变量
    
    if((fp=fopen("disturb_buff.txt","w"))==NULL){ //以只写形式打开文件
        printf("文件打开失败!请在根目录下创建 disturb_buff.txt 文件以解决问题");

    }

    while(i<stepnum){
        buffer=randnum(0,6);
        if(buffer==stepbuff){
            continue;
        }
        stepbuff=buffer;
        //array[i]=steps[buffer];
        fprintf(fp,"%c",steps[buffer]);
        printf("%c",steps[buffer]);
        buffer=randnum(0,3);
        switch(buffer){
            case 0:printf("' "),fprintf(fp,"' ");break;
            case 1:printf("2 "),fprintf(fp,"2 ");break;
            case 2:putchar(' '),fprintf(fp,"  ");break;
        }
        i++;
    }
    putchar('\n');
    fclose(fp);
}

int calctime(){
    //DWORD dwStart,dwEnd;
    int start,end,ch,time_mms=0;
    float time_all;
    printf("按下回车键开始/结束计时 ");
    getchar();
    //dwStart=GetTickCount();
    start=time(NULL);
    printf("还原中...");
    getchar();
    //dwEnd=GetTickCount();
    end=time(NULL);
    time_all=end-start;
    //printf("dw计时: %f\n",(dwEnd-dwStart)/1000);
    return time_all;
}