#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*���ļ����ڴ������Ʊ���ģ��*/

int randnum(int min,int max);
int randnum(int min,int max){
	//randnum(max,min) ��Χ:(min,max-min)(��min,����max)
	int result;
	result=rand();
	result=result%(max-min)+min;
	Sleep(1);
	return result; 
}