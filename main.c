#include <stdio.h>
#include <stdlib.h>
#include "solving.c"
#include "memerylib.c"

//tt
struct Record_card{ //�����ܴ�С 4*int + 5*char + 63*char = 12+68 = 90B
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

    srand((unsigned)time(NULL)); //�����ʼ������
    count=0;

    printf("��ǰĿ¼�������·���(��� - ���� - ģʽ): \n1 - 3 x 3 x 3 speed\n");
    do{
        printf("ѡ���㽫Ҫ����ķ���: ");
        scanf("%d",&group);
        getchar();
        if(group==0){
            system("pause");
            return 0;
        }
    }while(group!=1);
    printf("��ǰ�����ڵķ���:1 - 3 x 3 x 3 speed\n===============\n");
    
    do{
        record_card=realloc(record_card,3*sizeof(int)+68*sizeof(char));
        record_card[count].group=1; //������
        printf("333����: ");
        
        disturb333sp();
        memadd_disturb(record_card[count].disturbsteps);

        record_card[count].style=3331; //����ȷ

        record_buff=calctime();

        printf("��ĳɼ�Ϊ%3d��,�Ƿ񱣴�(1/0):",record_buff);
        scanf("%d",&bakctu);
        getchar();
        
        record_card[count].keep=bakctu;
        count++;
    }while(!(bakctu==0));

    free(record_card);
    system("pause");
    return 0;
}