#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "DIYfuncs.c"

/*���ļ����ڴ�� ��ԭ��������Ҫ��ģ�飬���� ���ҡ���ʱ*/

//void disturb(char array[],char array_symbol[]);
void disturb333sp();
int calctime();

void disturb333sp(){
    FILE *fp;
    char steps[6]={'R','L','U','D','F','B'};
    int i=0,stepnum=21,stepbuff;
    int buffer;//bufferΪ�������
    
    if((fp=fopen("disturb_buff.txt","w"))==NULL){ //��ֻд��ʽ���ļ�
        printf("�ļ���ʧ��!���ڸ�Ŀ¼�´��� disturb_buff.txt �ļ��Խ������");

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
    printf("���»س�����ʼ/������ʱ ");
    getchar();
    //dwStart=GetTickCount();
    start=time(NULL);
    printf("��ԭ��...");
    getchar();
    //dwEnd=GetTickCount();
    end=time(NULL);
    time_all=end-start;
    //printf("dw��ʱ: %f\n",(dwEnd-dwStart)/1000);
    return time_all;
}