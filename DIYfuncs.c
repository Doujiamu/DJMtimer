#include <stdlib.h>
#include <time.h>
#include <windows.h>

/*本文件用于储存自制便利模块*/

int randnum(int min,int max);
int randnum(int min,int max){
	//randnum(max,min) 范围:(min,max-min)(含min,不含max)
	int result;
	result=rand();
	result=result%(max-min)+min;
	Sleep(1);
	return result; 
}