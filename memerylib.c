#include <stdio.h>

void addmem_disturb(struct Record_card array[63]);

void addmem_disturb(struct Record_card array[63]){
    FILE *fp=fopen("disturb_buff.txt","a"); //��ֻ����ʽ��

    
    fclose(fp);
}