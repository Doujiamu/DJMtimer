#include <stdio.h>
#include <stdlib.h>
#include "solving.c"
#include "memerylib.c"

void TypeError(char ch);

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
    char ch;

    srand((unsigned)time(NULL)); //�����ʼ������
    count=0;

    while(1){ //һ��Ŀ¼ ��Ŀ¼
        system("cls");
        printf("DJMtimer >> \n\n");
        printf("1 -- �������\n2 -- ��������Ϣ\n0 -- �˳�����\n===============\n");
        printf("> "); //��ʾ��
        scanf("%c",&ch);
        getchar();
        if(ch=='0'){ //�˳�����
            break;
        }
        else if(ch=='2'){  //
            printf("��δ����...\n0 - �����ϼ�\n===============\n>");
            scanf("%c",&ch);
            getchar();
        }
        else if(ch=='1'){  //���뵥������
            while(1){  //����Ŀ¼
                system("cls");
                printf("DJMtimer >> ����\n\n");
                printf("1 -- ���뵥������\n0 -- �����ϼ�\n===============\n");
                printf("> ");
                scanf("%c",&ch);
                getchar();
                if(ch=='1'){ //����Ŀ¼
                    while(1){ //����Ŀ¼
                        system("cls");
                        printf("DJMtimer >> ���� >> %c����\n\n",ch);
                        printf("1 -- ��ʼ��ʱ\n2 -- �г��ɼ�\ns -- ����\n0 -- �����ϼ�\n");
                        printf("===============\n");
                        printf("> ");
                        scanf("%c",&ch);
                        getchar();
                        if(ch=='1'){ //�ļ�Ŀ¼
                            printf("DJMtimer >> ���� >> %c���� >> ��ʱģʽ\n\n=======��ʱģʽ=======",ch);
                            system("cls");
                            do{
                                record_card=realloc(record_card,3*sizeof(int)+68*sizeof(char));
                                record_card[count].group=1; //������
                                printf("333����: ");
                                
                                disturb333sp();
                                memadd_disturb(record_card[count].disturbsteps);

                                record_card[count].style=3331; //����ȷ

                                record_buff=calctime();

                                printf("��ĳɼ�Ϊ%3d��,�Ƿ񱣴�(1/0)\n> ",record_buff);
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
                            printf("��δ����...\n");
                            system("pause");
                            continue;
                        }
                        else if(ch=='s'){
                            system("cls");
                            printf("��δ����...\n");
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



    /*printf("��ǰĿ¼�������·���(��� - ���� - ģʽ): \n1 - 3 x 3 x 3 speed\n");
    do{
        printf("ѡ���㽫Ҫ����ķ���: ");
        scanf("%d",&group);
        getchar();
        if(group==0){
            system("pause");
            return 0;
        }
    }while(group!=1);
    printf("��ǰ�����ڵķ���:1 - 3 x 3 x 3 speed\n===============\n");*/
    

    free(record_card);
    system("pause");
    return 0;
}

void TypeError(char ch){
	printf(">>%c<<is not a correct command\n>>%c<<����һ����ȷ������!!!\n",ch,ch);
    system("pause");
}