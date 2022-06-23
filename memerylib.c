#include <stdio.h>

void memadd_disturb(char array[63]);

void memadd_disturb(char array[63]){
    FILE *fp=fopen("disturb_buff.bff","a"); //以只读方式打开
    char ch;
    int count=0;

    while(ch=fgetc(fp)!=EOF){
        array[count]=ch;
        count++;
    }
    
    fclose(fp);
}